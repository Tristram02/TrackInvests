#pragma once

#include "app/ui/IPage.hpp"

namespace app::ui
{

class MenuPage : public IPage
{
public:
    void render() override;
    void handle_input() override;
    std::unique_ptr<IPage> next_page() override;

private:
    std::unique_ptr<IPage> next_page_;
};

}