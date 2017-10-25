#include "Importer.h"

std::auto_ptr<Assimp::Importer> Importer::instance;

Importer::Importer(){}

Importer::~Importer(){}

Assimp::Importer *Importer::GetInstance()
{
	if (instance.get() == nullptr)
		instance.reset(new Assimp::Importer());

	return instance.get();
}

