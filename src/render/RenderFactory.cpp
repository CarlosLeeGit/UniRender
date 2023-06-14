#include "RenderFactory.h"

#include "optix_path_tracing/OptixPathTracing.h"
#include "soft_path_tracing/SoftPathTracing.h"

namespace unirender {
void RenderFactory::Register(UniRenderType type, const CreateFunc &func) {
  createFuncList[type] = func;
}

UniRender *RenderFactory::Create(UniRenderType type) {
  auto item = createFuncList.find(type);
  if (item == createFuncList.end()) {
    return nullptr;
  }

  return item->second();
}

std::unordered_map<UniRenderType, CreateFunc> RenderFactory::createFuncList;

RenderRegister::RenderRegister(UniRenderType type, const CreateFunc &func) {
  RenderFactory::Register(type, func);
}

REGISTER_RENDER(SOFT_PATH_TRACING, SoftPathTracing);
REGISTER_RENDER(OPTIX_PATH_TRACING, OptixPathTracing);

}  // namespace unirender