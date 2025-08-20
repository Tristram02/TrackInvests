#pragma once

#include "app/ui/IPage.hpp"

namespace app::ui
{

class SearchSymbolPage : public IPage
{
public:
    void render() override;
    void handle_input() override;
    std::unique_ptr<IPage> next_page() override;
    void set_menu_page(MenuPage* menu_page) { menu_page_ = menu_page; }
    bool should_go_back_to_menu() const { return go_back_to_menu_; }
    void reset_navigation_flag() { go_back_to_menu_ = false; }

private:
    std::unique_ptr<IPage> next_page_;
    MenuPage* menu_page_;
    bool go_back_to_menu_ = false;
};

}