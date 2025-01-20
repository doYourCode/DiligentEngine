#pragma once

#include "AppBase.h"

namespace Diligent
{
class App final : public AppBase
    {
    public:
        virtual bool Initialize() override;
        virtual void Update(float dt) override;
        virtual void Draw() override;
        virtual void KeyEvent(Key key, KeyState state) override;
        virtual void MouseEvent(float2 pos) override;

    private:
        float4 m_ClearColor = {0.0f, 0.0f, 0.0f, 1.0f};
    };
} // namespace Diligent
