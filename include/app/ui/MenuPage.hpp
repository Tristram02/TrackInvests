#pragma once

#include <memory>

#include <app/ui/IPage.hpp>
#include <io/DataSerializer.hpp>
#include "app/ui/AddBondPage.hpp"

namespace core { class Portfolio; }

namespace app::ui
{

class MenuPage : public IPage
{

public:
    void render() override;
    void handle_input() override;
    std::unique_ptr<IPage> next_page() override;
    
    void set_data_serializer(io::DataSerializer* data_serializer);
    void set_portfolio(core::Portfolio* portfolio);
    bool should_show_portfolio() const { return show_portfolio_; }
    bool should_add_holding() const { return add_holding_; }
    bool should_edit_holding() const { return edit_holding_; }
    bool should_remove_holding() const { return remove_holding_; }
    bool should_search_symbol() const { return search_symbol_; }
    bool should_add_bond() const { return add_bond_; }
    core::Portfolio* get_portfolio() const { return portfolio_; }
    void reset_navigation_flag() {
        show_portfolio_ = false;
        add_holding_ = false;
        edit_holding_ = false;
        remove_holding_ = false;
        search_symbol_ = false;
    }
    void print_portfolio_names() const;
    core::Portfolio* pick_portfolio() const;

private:
    std::unique_ptr<IPage> next_page_;
    std::unique_ptr<AddBondPage> add_bond_page_;
    io::DataSerializer* data_serializer_;
    core::Portfolio* portfolio_;
    bool show_portfolio_ = false;
    bool add_holding_ = false;
    bool edit_holding_ = false;
    bool remove_holding_ = false;
    bool search_symbol_ = false;
    bool add_bond_ = false;
};

}