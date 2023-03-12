// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include <ctime>
#pragma warning(disable : 4996)
#include <string>

using namespace std;
using namespace winrt;
using namespace Microsoft::UI::Xaml;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App1::implementation
{
    MainWindow::MainWindow()
    {
        InitializeComponent();
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
hstring current_time()
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    char buffer[128];
    strftime(buffer, sizeof(buffer), "%m-%d-%Y %X", now);
    return to_hstring(buffer);
}

string selectedL;
hstring text1;
hstring text2;
hstring text3;
hstring text4;

void winrt::App1::implementation::MainWindow::Button_Click(winrt::Windows::Foundation::IInspectable const& /*sender*/, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& /*e*/)
{
    //저장 버튼 눌렸을 때 실행될 함수
    if (selectedL == "scheduleL")
    {
        text1 = text1 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
        scheduleL().Text(text1);
    }
    else if (selectedL == "todoL")
    {
        text2 = text2 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
        todoL().Text(text2);
    }
    else if (selectedL == "goalL")
    {
        text3 = text3 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
        goalL().Text(text3);
    }
    else
    {
        text4 = text4 + (nameInput().Text() + L"\t" + current_time() + L"\n\n");
        importantL().Text(text4);
    }
}

void winrt::App1::implementation::MainWindow::ComboBox_SelectionChanged(winrt::Windows::Foundation::IInspectable const& /*sender*/, winrt::Microsoft::UI::Xaml::Controls::SelectionChangedEventArgs const& /*e*/)
{
    //카테고리 변경 시 실행될 함수
    if (schedule().IsSelected()) selectedL = "scheduleL";
    else if (todo().IsSelected()) selectedL = "doL";
    else if (goal().IsSelected()) selectedL = "goalL";
    else selectedL = "importantL";
}
