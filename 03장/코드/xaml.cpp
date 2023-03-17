#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"

#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

#include<microsoft.ui.xaml.window.h>
namespace winrt::caculator::implementation
{
     MainWindow::MainWindow()
    {
        InitializeComponent();
        auto windowNative{ this->try_as<::IWindowNative>() };
        HWND hWnd{ 0 };
        windowNative->get_WindowHandle(&hWnd);
        SetWindowPos(hWnd, NULL, 300, 500, 550, 550, NULL); //크기
        this->Title(L"Caculator"); // 창 제목
    }
    int32_t MainWindow::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void MainWindow::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }
  using namespace std;
    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        double a, b, c;
        a = stod(va().Text().c_str());
        b = stod(vb().Text().c_str());
        c = a + b;
        vc().Text(to_wstring(c));
    }
}
void winrt::caculator::implementation::MainWindow::myButton1_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    double a, b, c;
    a = stod(ca().Text().c_str());
    b = stod(cb().Text().c_str());
    c = a - b;
    cc().Text(to_wstring(c));
}

void winrt::caculator::implementation::MainWindow::myButton2_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    double a, b, c;
    a = stod(qa().Text().c_str());
    b = stod(qb().Text().c_str());
    c = a * b;
    qc().Text(to_wstring(c));
}

void winrt::caculator::implementation::MainWindow::myButton3_Click(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    double a, b, c;
    a = stod(ra().Text().c_str());
    b = stod(rb().Text().c_str());
    c = a / b;
    rc().Text(to_wstring(c));
}
