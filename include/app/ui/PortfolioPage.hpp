#pragma once

#include "app/ui/IPage.hpp"

#include <memory>

#include <api/StooqClient.hpp>

#include <api/fwd.hpp>

namespace core { class Portfolio; }

namespace app::ui
{

class PortfolioPage : public IPage
{
public:
    void render() override;
    void handle_input() override;
    std::unique_ptr<IPage> next_page() override;

    void createApiClient();
    void set_portfolio(core::Portfolio* portfolio);
    void set_menu_page(MenuPage* menu_page) { menu_page_ = menu_page; }
    bool should_go_back_to_menu() const { return go_back_to_menu_; }
    void reset_navigation_flag() { go_back_to_menu_ = false; }
private:
    StooqClientPtr client_;
    std::unique_ptr<IPage> next_page_;
    core::Portfolio* portfolio_;
    MenuPage* menu_page_;
    bool go_back_to_menu_ = false;
};

}