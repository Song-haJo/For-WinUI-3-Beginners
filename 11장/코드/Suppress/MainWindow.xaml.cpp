#include "pch.h"
#include "MainWindow.xaml.h"

#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#include <winrt/Windows.UI.Xaml.Interop.h>
#include <microsoft.ui.xaml.window.h>
#include <winrt/Microsoft.UI.Xaml.Media.h>
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

using namespace Microsoft::UI::Xaml::Navigation;
using namespace Microsoft::UI::Xaml::Media::Animation;
using namespace Microsoft::UI::Xaml::Controls;

namespace winrt::App11::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        auto windowNative{ this->try_as<::IWindowNative>() };
        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd);
        SetWindowPos(hWnd, NULL, 200, 200, 950, 750, NULL);  // 위치 200, 200 크기 950, 750

        ContentFrame1().Navigate(xaml_typename<Page1>());
    }

    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
}
void winrt::App11::implementation::MainWindow::ForwardButton1_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
{
    if (flag1)
    {
        ContentFrame1().Navigate(xaml_typename<Page2>());
        flag1 = false;
    }
    else
    {
        ContentFrame1().Navigate(xaml_typename<Page1>());
        flag1 = true;
    }
}

void winrt::App11::implementation::MainWindow::BackwardButton1_Click(winrt::Windows::Foundation::IInspectable const&, winrt::Microsoft::UI::Xaml::RoutedEventArgs const&)
{
    if (ContentFrame1().BackStackDepth() > 0)
    {
        ContentFrame1().GoBack();
        if (flag1){ flag1 = false; }
        else{ flag1 = true; }
    }
}
