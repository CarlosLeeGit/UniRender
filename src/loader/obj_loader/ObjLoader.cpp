#include "ObjLoader.h"

namespace unirender {
int ObjLoader::Load(const std::filesystem::path &path) { return OK; }

MeshData *ObjLoader::GetMeshData() { return nullptr; }

MaterialData *ObjLoader::GetMaterialData() { return nullptr; }

LightData *ObjLoader::GetLightData() { return nullptr; }

int ObjLoader::Clear() { return OK; }
}  // namespace unirender