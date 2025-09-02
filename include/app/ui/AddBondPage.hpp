#pragma once
#include "app/ui/IPage.hpp"
#include <core/Portfolio.hpp>
#include <core/Bond.hpp>
#include <memory>
#include <string>

namespace app::ui {
class AddBondPage : public IPage {
public:
    void render() override;
    void handle_input() override;
    std::unique_ptr<IPage> next_page() override;

    void set_portfolio(core::Portfolio* portfolio);
    void set_menu_page(MenuPage* menu_page) { menu_page_ = menu_page; }
    bool should_go_back_to_menu() const { return go_back_to_menu_; }
    void reset_navigation_flag() { go_back_to_menu_ = false; }
private:
    std::unique_ptr<IPage> next_page_;
    core::Portfolio* portfolio_ = nullptr;
    MenuPage* menu_page_ = nullptr;
    bool go_back_to_menu_ = false;
};
}
