#pragma once

#include "UniRender.h"

namespace unirender {
class SoftPathTracing : public UniRender {
 public:
  int Init() override;

  int AddMesh(MeshData *meshData, ID &meshId) override;

  int AddMaterial(MaterialData *materialData, ID &materialId) override;

  int AddLight(LightData *lightData, ID &lightId) override;

  int AddRadianceMap(RadianceData *radianceData, ID &radianceId) override;

  int Remove(ID id) override;

  int Clear() override;

  int CommitScene() override;

  int Render(Camera *cam) override;
};
}  // namespace unirender