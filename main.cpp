main.cpp
-------------------------------------------------------

#include <QApplication>
#include "main_window.h"
#include "browser_app.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    // Initialize CEF
    CefMainArgs mainArgs(GetModuleHandle(NULL));
    CefRefPtr<SimpleApp> appInstance(new SimpleApp());
    CefSettings settings;
    settings.no_sandbox = true; // Disable sandbox for simplicity
    CefInitialize(mainArgs, settings, appInstance.get(), nullptr);

    MainWindow window;
    window.resize(1024, 768);
    window.show();

    int result = app.exec();

    // Clean up CEF
    CefShutdown();

    return result;
}
