#include "SoftPathTracing.h"

namespace unirender {
int SoftPathTracing::Init() { return OK; }

int SoftPathTracing::AddMesh(MeshData *meshData, ID &meshId) { return OK; }

int SoftPathTracing::AddMaterial(MaterialData *materialData, ID &materialId) {
  return OK;
}

int SoftPathTracing::AddLight(LightData *lightData, ID &lightId) { return OK; }

int SoftPathTracing::AddRadianceMap(RadianceData *radianceData,
                                    ID &radianceId) {
  return OK;
}

int SoftPathTracing::Remove(ID id) { return OK; }

int SoftPathTracing::Clear() { return OK; }

int SoftPathTracing::CommitScene() { return OK; }

int SoftPathTracing::Render(Camera *cam) { return OK; }
}  // namespace unirender