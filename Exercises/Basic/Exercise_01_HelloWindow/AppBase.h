#pragma once

#include <chrono>
#include <vector>

#include "RefCntAutoPtr.hpp"
#include "RenderDevice.h"
#include "DeviceContext.h"
#include "SwapChain.h"
#include "RenderStateNotationLoader.h"
#include "BasicMath.hpp"

#include "../../../DiligentSamples/ThirdParty/glfw/include/GLFW/glfw3.h"

namespace Diligent
{

class AppBase
{
public:
    AppBase();
    virtual ~AppBase();

    //
    // Public API
    //

    IEngineFactory* GetEngineFactory() { return m_pDevice->GetEngineFactory(); }
    IRenderDevice*  GetDevice() { return m_pDevice; }
    IDeviceContext* GetContext() { return m_pImmediateContext; }
    ISwapChain*     GetSwapChain() { return m_pSwapChain; }

    void Quit();

    //
    // Interface
    //

    virtual bool Initialize() = 0;

    virtual void Update(float dt) = 0;
    virtual void Draw()           = 0;

    enum class Key
    {
        Esc   = GLFW_KEY_ESCAPE,
        Space = GLFW_KEY_SPACE,
        Tab   = GLFW_KEY_TAB,

        W = GLFW_KEY_W,
        A = GLFW_KEY_A,
        S = GLFW_KEY_S,
        D = GLFW_KEY_D,

        // arrows
        Left  = GLFW_KEY_LEFT,
        Right = GLFW_KEY_RIGHT,
        Up    = GLFW_KEY_UP,
        Down  = GLFW_KEY_DOWN,

        // numpad arrows
        NP_Left  = GLFW_KEY_KP_4,
        NP_Right = GLFW_KEY_KP_6,
        NP_Up    = GLFW_KEY_KP_8,
        NP_Down  = GLFW_KEY_KP_2,

        // mouse buttons
        MB_Left   = GLFW_MOUSE_BUTTON_LEFT,
        MB_Right  = GLFW_MOUSE_BUTTON_RIGHT,
        MB_Middle = GLFW_MOUSE_BUTTON_MIDDLE,
    };
    enum class KeyState
    {
        Release = GLFW_RELEASE,
        Press   = GLFW_PRESS,
        Repeat  = GLFW_REPEAT,
    };
    virtual void KeyEvent(Key key, KeyState state) = 0;

    virtual void MouseEvent(float2 pos) = 0;

private:
    bool CreateWindow(const char* Title, int Width, int Height, int GlfwApiHint);
    bool InitEngine(RENDER_DEVICE_TYPE DevType);
    bool ProcessCommandLine(int argc, const char* const* argv, RENDER_DEVICE_TYPE& DevType);
    void Loop();
    void OnKeyEvent(Key key, KeyState state);

    static void GLFW_ResizeCallback(GLFWwindow* wnd, int w, int h);
    static void GLFW_KeyCallback(GLFWwindow* wnd, int key, int, int state, int);
    static void GLFW_MouseButtonCallback(GLFWwindow* wnd, int button, int state, int);
    static void GLFW_CursorPosCallback(GLFWwindow* wnd, double xpos, double ypos);
    static void GLFW_MouseWheelCallback(GLFWwindow* wnd, double dx, double dy);

    friend int GlfwMain(int argc, const char* const* argv);

private:
    RefCntAutoPtr<IRenderDevice>  m_pDevice;
    RefCntAutoPtr<IDeviceContext> m_pImmediateContext;
    RefCntAutoPtr<ISwapChain>     m_pSwapChain;
    GLFWwindow*                   m_Window = nullptr;

    struct ActiveKey
    {
        Key      key;
        KeyState state;
    };
    std::vector<ActiveKey> m_ActiveKeys;

    using TClock   = std::chrono::high_resolution_clock;
    using TSeconds = std::chrono::duration<float>;

    TClock::time_point m_LastUpdate = {};
};

AppBase* CreateApp();

int GlfwMain(int argc, const char* const* argv);

} // namespace Diligent
