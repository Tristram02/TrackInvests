#pragma once

#include <memory>

#include "app/ui/IPage.hpp"

namespace core { class Portfolio; }

namespace app::ui
{

class EditHoldingPage : public IPage
{
public:
    void render() override;
    void handle_input() override;
    std::unique_ptr<IPage> next_page() override;

    void set_portfolio(core::Portfolio* portfolio);
private:
    std::unique_ptr<IPage> next_page_;
    core::Portfolio* portfolio_;
};

}