#pragma once

#include "UniLoader.h"

namespace unirender {
class ObjLoader : public UniLoader {
 public:
  int Load(const std::filesystem::path &path) override;

  MeshData *GetMeshData() override;

  MaterialData *GetMaterialData() override;

  LightData *GetLightData() override;

  int Clear() override;
};
}  // namespace unirender