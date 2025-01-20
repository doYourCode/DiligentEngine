#include "App.h"

namespace Diligent
{

AppBase* CreateApp()
{
    return new App{};
}

bool App::Initialize()
{
    return true;
}

void App::Update(float dt)
{
    this->m_ClearColor.r += dt * 0.1f;
    if (this->m_ClearColor.r > 1.0f)
        this->m_ClearColor.r = 0.0f;
}

void App::Draw()
{
    auto* pContext   = GetContext();
    auto* pSwapchain = GetSwapChain();

    ITextureView* pRTV = pSwapchain->GetCurrentBackBufferRTV();
    pContext->SetRenderTargets(1, &pRTV, nullptr, RESOURCE_STATE_TRANSITION_MODE_TRANSITION);

    const float ClearColor[4] = {this->m_ClearColor.r, m_ClearColor.g, m_ClearColor.b, m_ClearColor.a};
    
    pContext->ClearRenderTarget(pRTV, ClearColor, RESOURCE_STATE_TRANSITION_MODE_VERIFY);

    pContext->Flush();
    pSwapchain->Present();
}



void App::KeyEvent(Key key, KeyState state)
{
    if (state == KeyState::Press || state == KeyState::Repeat)
    {
        switch (key)
        {
            case Key::W:
            case Key::Up:
            case Key::NP_Up:

            case Key::S:
            case Key::Down:
            case Key::NP_Down:

            case Key::D:
            case Key::Right:
            case Key::NP_Right:

            case Key::A:
            case Key::Left:
            case Key::NP_Left:

            case Key::Space:

            case Key::Esc:
                Quit();
                break;

            default:
                break;
        }
    }

    if (key == Key::MB_Left)
    {

    }

    // generate new map
    //if (state == KeyState::Release && key == Key::Tab)

        //LoadNewMap();
}

void App::MouseEvent(float2 pos)
{
    //m_Player.MousePos = pos;
}


} // namespace Diligent
