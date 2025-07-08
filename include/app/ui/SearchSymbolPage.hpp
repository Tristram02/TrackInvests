#pragma once

#include "app/ui/IPage.hpp"

namespace app::ui
{

class SearchSymbolPage : public IPage
{
public:
    void render() override;
    void handle_input() override;
};

}