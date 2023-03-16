#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::PicassoInsideMe::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
        px = 200;
        py = 200;
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

using namespace winrt::Microsoft::Graphics::Canvas::UI::Xaml;
struct winrt::Windows::UI::Color col = winrt::Microsoft::UI::Colors::Green();
void winrt::PicassoInsideMe::implementation::MainWindow::CanvasControl_PointerMoved(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::Input::PointerRoutedEventArgs const& e)
{
    CanvasControl canvas = sender.as<CanvasControl>();
    px = e.GetCurrentPoint(canvas).Position().X;
    py = e.GetCurrentPoint(canvas).Position().Y;
    canvas.Invalidate();
}


void winrt::PicassoInsideMe::implementation::MainWindow::CanvasControl_Draw(winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasControl const& sender, winrt::Microsoft::Graphics::Canvas::UI::Xaml::CanvasDrawEventArgs const& args)
{
    //args.DrawingSession().DrawEllipse(px, py, 80, 60, col, 8);
    args.DrawingSession().DrawCircle(150, 150, 100, col, 5);
    args.DrawingSession().DrawLine(700, 350, 900, 250, col, 5);
    args.DrawingSession().DrawRectangle(100, 300, 200, 100, col, 5);
    args.DrawingSession().DrawRoundedRectangle(650, 400, 100, 200, 20, 20, col, 5);
    //args.DrawingSession().DrawText(L"Hello!", px - 25, py - 15, winrt::Microsoft::UI::Colors::Yellow());

    args.DrawingSession().FillEllipse(800, 150, 200, 50, col);
    args.DrawingSession().FillCircle(400, 150, 100, col);
    args.DrawingSession().FillRectangle(400, 300, 200, 100, col);
    args.DrawingSession().FillRoundedRectangle(800, 400, 100, 200, 20, 20, col);

    args.DrawingSession().FillRoundedRectangle(100, 450, 100, 150, 20, 20, col);    //1
    args.DrawingSession().FillRoundedRectangle(250, 450, 100, 150, 50, 20, col);    //2
    args.DrawingSession().FillRoundedRectangle(400, 450, 100, 150, 20, 50, col);    //3
}
