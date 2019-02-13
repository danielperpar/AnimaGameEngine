#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

#include <string>
#include <vector>
#include "Component.h"
//#include "Gizmo.h"
#include "libraries/glm/glm.hpp"


struct aiNode;
struct aiMesh;
struct aiScene;
//class ComponentMaterial;
class ComponentTransform;
class Mesh;
class Shader;
class ComponentCamera;
class ModuleEditorCamera;

class GameObject
{
public:

	GameObject(const std::string &name, const aiNode *node = nullptr);
	virtual ~GameObject();

	virtual void Update(float dt);
	void UpdateWorldTransform();

	void Translate(const glm::vec3 &translation);
	void Rotate(float angle, const glm::vec3 &axis);
	void Scale(const glm::vec3 &scale);

	ComponentTransform *GetTransform();
	const ComponentTransform *GetTransform() const;

	//Component *CreatePrimitiveMeshComp(ComponentMaterial *mat, float *vertices, float *normals, float *uv);
	//Component *CreatePrimitiveMatComp(float *ambient, float *diffuse, float *specular, float shininess);

	//Component* CreateLoadedMeshComp(ComponentMaterial *mat, aiMesh *mesh);
	//Component* CreateLoadedMaterialComp(aiMesh *mesh, const aiScene *scene, const char *file_name);
	Component* AddMeshRenderer(const Mesh *mesh, const Shader *shader, const ComponentCamera *camera);
	Component* AddCameraComponent();
	Component* AddEditorCameraComponent();
	Component* AddGizmoComponent(const std::string& vertexPath, const std::string &fragmentPath);
	//Component* CreateBehaviour(const std::string &behav_name);
	//Component* CreateTorsoBehaviour(const std::string &behav_name);
	//Component* CreateAmbientLight();
	//Component* CreateDirectionalLight();
	//Component* CreatePointLight();

	const std::string& GetName() const;
	const std::vector<GameObject*>& GetChildrenGO() const;

	GameObject *GetParentGO() const;
	void SetParentGO(GameObject *parentGO);

	void AddChildGO(GameObject *childGO);
	
	Component *FindComponentByType(ComponentType type);
	
	void SetDirty();
	bool IsDirty() const;

	//GUI can modify this value
	bool active = true;

	const std::vector<Component*>& GetComponents() const;

private:

	ComponentTransform *transform = nullptr;

	bool dirty = true;
	GameObject *parentGO = nullptr;
	std::string name;
	std::vector<Component*> components;
	std::vector<GameObject*> childrenGO;

	bool selectedGO = true;

	void LoadTransform(const aiNode *node);
	void CombineTransform(GameObject *parentGO);
	void Clear();
	//Gizmo gizmo;
};



#endif
