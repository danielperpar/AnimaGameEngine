#include "EditorSceneHierarchyWidget.h"
#include "libraries/ImGui/imgui.h"
#include "Application.h"
#include "ModuleScene.h"
#include "GameObject.h"
#include "Globals.h"

EditorSceneHierarchyWidget::EditorSceneHierarchyWidget(const char* title, 
	int x, 
	int y, 
	unsigned int width, 
	unsigned int height) : title(title), pos_x(x), pos_y(y), width(width), height(height) {} 


EditorSceneHierarchyWidget::EditorSceneHierarchyWidget(){}

EditorSceneHierarchyWidget::~EditorSceneHierarchyWidget() {}

void EditorSceneHierarchyWidget::Draw()
{
	ImGui::SetNextWindowSize(ImVec2(width, height), ImGuiSetCond_FirstUseEver);
	ImGui::SetNextWindowPos(ImVec2(pos_x, pos_y), ImGuiSetCond_FirstUseEver);

	static void *selected_go = nullptr;

	ImGui::Begin(title);
	
	for (GameObject *go : App->scene->game_objects)
	{
		DrawNode(go, selected_go);
	}

	ImGui::End();
}

void EditorSceneHierarchyWidget::DrawNode(GameObject *go, void* &selected_go)
{
	ImGuiTreeNodeFlags node_flags = ImGuiTreeNodeFlags_OpenOnArrow
		| ImGuiTreeNodeFlags_OpenOnDoubleClick | (go == selected_go ? ImGuiTreeNodeFlags_Selected : 0);

	bool node_open = ImGui::TreeNodeEx(go, node_flags, go->name.c_str());
	if (ImGui::IsItemClicked())
	{
		selected_go = go;
	}

	if (node_open)
	{
		for (GameObject *child_go : go->children_go)
		{
			DrawNode(child_go, selected_go);
		}

		ImGui::TreePop();
	}
}