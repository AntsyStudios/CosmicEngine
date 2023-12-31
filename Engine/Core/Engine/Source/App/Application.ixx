module;
#include "cspch.hpp"
export module Cosmic.App.Application;

import Cosmic.Base.Types;
import Cosmic.Base.Tuples;
import Cosmic.App.Events;
import Cosmic.App.WindowInfo;
import Cosmic.App.IWindow;

namespace Cosmic
{

    export struct ApplicationInfo
    {
        const char*       Name;
        DesktopWindowInfo WindowInfo;
    };

    export class Application
    {
    public:
        Application();
        ~Application();

        void Close();

    protected:
        void Init(ApplicationInfo&& info);

    private:
        void Run();

    protected:
        // Make this method protected so that the class that derives from this class
        // can call this method when it overrides it.
        virtual void OnEvent(const WindowEvent& e);

    private:
        void OnWindowResize(const WindowResizeEvent& e);
        void OnWindowClose(const WindowCloseEvent& e);

    public:
        static Application& Get() { return *sInstance; }

    private:
        inline static Application* sInstance = nullptr;
        bool                       mRunning  = true;
        ApplicationInfo            mInfo;
        Scope<IDesktopWindow>      mWindow;
    };

}