#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

#include <microsoft.ui.xaml.window.h>
namespace winrt::Calculator::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        auto windowNative{ this->try_as<::IWindowNative>() };
        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd);
        SetWindowPos(hWnd, NULL, 300, 500, 250, 300, NULL);     // 창 크기
        this->Title(L"Calculator");                             // 창 제목
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
using namespace std;
double va, vb, vc;
void winrt::Calculator::implementation::MainWindow::add_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    va = stod(a().Text().c_str());
    vb = stod(b().Text().c_str());
    vc = va + vb;
    c().Text(to_wstring(vc));
}


void winrt::Calculator::implementation::MainWindow::subtract_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    va = stod(a().Text().c_str());
    vb = stod(b().Text().c_str());
    vc = va - vb;
    c().Text(to_wstring(vc));
}


void winrt::Calculator::implementation::MainWindow::multiply_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    va = stod(a().Text().c_str());
    vb = stod(b().Text().c_str());
    vc = va * vb;
    c().Text(to_wstring(vc));
}


void winrt::Calculator::implementation::MainWindow::divide_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    va = stod(a().Text().c_str());
    vb = stod(b().Text().c_str());
    vc = va / vb;
    c().Text(to_wstring(vc));
}
