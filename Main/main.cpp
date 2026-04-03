#include "UI/CalculatorUI.hpp"
#include <QtWidgets/QApplication>
#include <QIcon>

#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <shobjidl.h>

// 应用程序图标
static void ApplyWindowIcons(HWND hwnd)
{
    HMODULE mod = GetModuleHandleW(nullptr);

    HICON bigIcon = (HICON)LoadImageW(mod, MAKEINTRESOURCEW(101), IMAGE_ICON, 256, 256, LR_DEFAULTCOLOR);
    HICON smallIcon = (HICON)LoadImageW(mod, MAKEINTRESOURCEW(101), IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);

    if (bigIcon)
    {
        SendMessageW(hwnd, WM_SETICON, ICON_BIG, (LPARAM)bigIcon);
        SetClassLongPtrW(hwnd, GCLP_HICON, (LONG_PTR)bigIcon);
    }
    if (smallIcon)
    {
        SendMessageW(hwnd, WM_SETICON, ICON_SMALL, (LPARAM)smallIcon);
        SetClassLongPtrW(hwnd, GCLP_HICONSM, (LONG_PTR)smallIcon);
    }
}

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    // 设置应用程序图标
    const QIcon appIcon(":/icons/app.ico");
    app.setWindowIcon(appIcon);

    CalculatorUI window;
    window.setWindowIcon(appIcon);
    window.show();

    ApplyWindowIcons(reinterpret_cast<HWND>(window.winId()));

    return app.exec();
}