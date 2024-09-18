browser_app.h

#ifndef BROWSER_APP_H
#define BROWSER_APP_H

#include "include/cef_app.h"
#include "include/cef_client.h"

// Implement the CEF client with security features
class SimpleClient : public CefClient, public CefDisplayHandler, public CefLifeSpanHandler {
public:
    SimpleClient();

    CefRefPtr<CefDisplayHandler> GetDisplayHandler() override;
    CefRefPtr<CefLifeSpanHandler> GetLifeSpanHandler() override;
    void OnTitleChange(CefRefPtr<CefBrowser> browser, const CefString& title) override;
    bool OnBeforeBrowse(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefRequest> request, bool is_redirect) override;

    IMPLEMENT_REFCOUNTING(SimpleClient);
};

// Implement the CEF application with security features
class SimpleApp : public CefApp, public CefBrowserProcessHandler {
public:
    SimpleApp();

    CefRefPtr<CefBrowserProcessHandler> GetBrowserProcessHandler() override;
    void OnContextInitialized() override;
    void OnBeforeCommandLineProcessing(const CefString& process_type, CefRefPtr<CefCommandLine> command_line) override;

    IMPLEMENT_REFCOUNTING(SimpleApp);
};

#endif // BROWSER_APP_H
