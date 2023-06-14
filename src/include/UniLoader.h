#pragma once

#include <filesystem>

#include "UniRender.h"

namespace unirender {
enum UniLoaderType { LOAD_OBJ };

class UniLoader {
 public:
  static UniLoader *CreateLoader(UniLoaderType type = LOAD_OBJ);

  virtual int Load(const std::filesystem::path &path) = 0;

  virtual MeshData *GetMeshData() = 0;

  virtual MaterialData *GetMaterialData() = 0;

  virtual LightData *GetLightData() = 0;

  virtual int Clear() = 0;
};
}  // namespace unirender