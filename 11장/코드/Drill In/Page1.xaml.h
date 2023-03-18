#pragma once

#include "Page1.g.h"

namespace winrt::App11::implementation
{
    struct Page1 : Page1T<Page1>
    {
        Page1();

        int32_t MyProperty();
        void MyProperty(int32_t value);
    };
}

namespace winrt::App11::factory_implementation
{
    struct Page1 : Page1T<Page1, implementation::Page1>
    {
    };
}
