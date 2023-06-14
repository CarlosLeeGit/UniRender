#include "UniRender.h"
#include "render/RenderFactory.h"

namespace unirender {
    UniRender *UniRender::CreateRender(UniRenderType type) {
        return RenderFactory::Create(type);
    }
}