#pragma once
#include <UniRender.h>

#include <functional>
#include <string>
#include <unordered_map>

namespace unirender {

using CreateFunc = std::function<UniRender *()>;

class RenderFactory {
 public:
  static void Register(UniRenderType type, const CreateFunc &func);

  static UniRender *Create(UniRenderType type);

 private:
  static std::unordered_map<UniRenderType, CreateFunc> createFuncList;
};

class RenderRegister {
 public:
  RenderRegister(UniRenderType type, const CreateFunc &func);
};

#define REGISTER_RENDER(type, clazz) \
  RenderRegister g_##type##_register_render(type, []() { return new clazz(); });

}  // namespace unirender