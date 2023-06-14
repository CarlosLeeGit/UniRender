#include <iostream>

#include "UniLoader.h"
#include "UniRender.h"

int main() {
  unirender::MeshData meshData;
  size_t meshId = 0;
  unirender::BlinnMaterialData materialData;
  size_t materialId = 0;

#ifdef OPTIX
  auto type = unirender::UniRenderType::OPTIX_PATH_TRACING;
#else
  auto type = unirender::UniRenderType::SOFT_PATH_TRACING;
#endif
  auto render = unirender::UniRender::CreateRender(type);
  if (render == nullptr) {
    std::cout << "Create render " << type << " failed" << std::endl;
    return -1;
  }

  std::cout << "Create render success" << std::endl;
  
  auto ret = render->Init();
  if (ret != unirender::OK) {
    std::cout << "Init render failed, ret " << ret << std::endl;
    return -1;
  }
  std::cout << "Init render success" << std::endl;

  render->AddMaterial(&materialData, materialId);
  render->AddMesh(&meshData, meshId);
  render->CommitScene();

  std::cout << "Commit scene over" << std::endl;
  unirender::Camera camera;
  camera.position.dv = {0, 0, 0};
  camera.forward.dv = {0, 0, -1};
  camera.up.dv = {0, 1, 0};
  std::cout << "Start render" << std::endl;
  render->Render(&camera);
  std::cout << "End render" << std::endl;
  return 0;
}