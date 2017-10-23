#ifndef __COMPONENT_TRANSFORM_H__
#define __COMPONENT_TRANSFORM_H__

#include "Component.h"
#include "libraries/assimp/include/assimp/vector3.h"
#include "libraries/assimp/include/assimp/quaternion.h"

class GameObject;
class ComponentTransform : public Component
{

public:
	ComponentTransform(component_type t, bool act, GameObject *go);
	virtual ~ComponentTransform();

	virtual void Update();
	virtual void Enable();
	virtual void Disable();

	aiVector3D position;
	aiVector3D scale;
	aiQuaternion rotation;

};




#endif
