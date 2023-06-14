#include "OptixPathTracing.h"

namespace unirender {

int OptixPathTracing::Init() { return OK; }

int OptixPathTracing::AddMesh(MeshData *meshData, ID &meshId) { return OK; }

int OptixPathTracing::AddMaterial(MaterialData *materialData, ID &materialId) {
  return OK;
}

int OptixPathTracing::AddLight(LightData *lightData, ID &lightId) { return OK; }

int OptixPathTracing::AddRadianceMap(RadianceData *radianceData,
                                     ID &radianceId) {
  return OK;
}

int OptixPathTracing::Remove(ID id) { return OK; }

int OptixPathTracing::Clear() { return OK; }

int OptixPathTracing::CommitScene() { return OK; }

int OptixPathTracing::Render(Camera *cam) { return OK; }
}  // namespace unirender