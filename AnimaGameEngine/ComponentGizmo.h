#ifndef __COMPONENT_GIZMO_H__
#define __COMPONENT_GIZMO_H__

#include "Component.h"
#include <vector>
#include <string>

class Shader;
class ModuleEditorCamera;

class ComponentGizmo : public Component
{
public:
	ComponentGizmo(const std::string& vertexPath, 
		const std::string &fragmentPath, 
		ComponentType type, 
		const std::string &name, 
		GameObject *ownerGO);

	~ComponentGizmo();

	void Update(float dt) override;

private:
	std::vector<float> vertices;
	unsigned int numVertices = 34;
	unsigned int VBO, VAO;
	Shader *shader = nullptr;
	const ModuleEditorCamera *camera = nullptr;

	void CreateShader(const std::string& vertexPath, const std::string &fragmentPath);
	void GenerateVertexData();
	void SetVertexBuffers();
	void ClearVertexBuffers();
	void ComputeNumVerticesToDraw();
	
};

#endif