// Copyright (c) Microsoft Corporation and Contributors.
// Licensed under the MIT License.

#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "winrt/Microsoft.UI.Xaml.Media.Imaging.h" //image
#include "MainWindow.g.cpp"
#endif

using namespace winrt;
using namespace Microsoft::UI::Xaml;
using namespace Microsoft::UI::Xaml::Controls; //PersonPicture
using namespace Microsoft::UI::Xaml::Media::Imaging; //image
//using namespace Microsoft::UI::Xaml::Media;
using namespace Windows::Foundation; //URI
using namespace std;

// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::profile_image::implementation
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


void winrt::profile_image::implementation::MainWindow::ProfileImageRadio_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    BitmapImage bimg;
    Uri uri = Uri(to_hstring("https://docs.microsoft.com/windows/uwp/contacts-and-calendar/images/shoulder-tap-static-payload.png"));
    bimg.UriSource(uri);
    personPicture().ProfilePicture(bimg);
}


void winrt::profile_image::implementation::MainWindow::DisplayNameRadio_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    personPicture().ProfilePicture(NULL);
    personPicture().Initials(to_hstring(""));
    personPicture().DisplayName(to_hstring("Jane Doe"));
}


void winrt::profile_image::implementation::MainWindow::InitialsRadio_Checked(winrt::Windows::Foundation::IInspectable const& sender, winrt::Microsoft::UI::Xaml::RoutedEventArgs const& e)
{
    personPicture().ProfilePicture(NULL);
    personPicture().Initials(to_hstring("SB"));
}
