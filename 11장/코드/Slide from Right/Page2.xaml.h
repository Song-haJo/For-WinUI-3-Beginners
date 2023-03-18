#pragma once

#include "Page2.g.h"

namespace winrt::App11::implementation
{
    struct Page2 : Page2T<Page2>
    {
        Page2();

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::App11::factory_implementation
{
    struct Page2 : Page2T<Page2, implementation::Page2>
    {
    };
}
