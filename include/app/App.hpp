#pragma once

#include <memory>

#include <app/ui/IPage.hpp>
#include <app/ui/MenuPage.hpp>
#include <app/ui/PortfolioPage.hpp>
#include <app/ui/AddBondPage.hpp>
#include <app/ui/AddHoldingPage.hpp>
#include <app/ui/EditHoldingPage.hpp>
#include <app/ui/RemoveHoldingPage.hpp>
#include <app/ui/SearchSymbolPage.hpp>
#include <io/DataSerializer.hpp>

namespace app
{

class App
{
public:
    App();

    void run();

private:
    ui::IPage* currentPage_;
    std::unique_ptr<io::DataSerializer> data_serializer_;
    std::unique_ptr<ui::MenuPage> menu_page_;
    std::unique_ptr<ui::PortfolioPage> portfolio_page_;
    std::unique_ptr<ui::AddHoldingPage> add_holding_page_;
    std::unique_ptr<ui::EditHoldingPage> edit_holding_page_;
    std::unique_ptr<ui::RemoveHoldingPage> remove_holding_page_;
    std::unique_ptr<ui::SearchSymbolPage> search_symbol_page_;
    std::unique_ptr<ui::AddBondPage> add_bond_page_;
};

}