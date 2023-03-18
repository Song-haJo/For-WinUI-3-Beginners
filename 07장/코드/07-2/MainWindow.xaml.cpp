#include "pch.h"
#include "MainWindow.xaml.h"

#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#include <microsoft.ui.xaml.window.h>
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

namespace winrt::App7::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();

        auto windowNative{ this->try_as<::IWindowNative>() };
        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd);
        SetWindowPos(hWnd, NULL, 200, 200, 600, 300, NULL);  // 위치 200, 200 크기 600, 300
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
void winrt::App7::implementation::MainWindow::MenuFlyoutItem_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    TBlock().Text(L"You Clicked : Save");
}
