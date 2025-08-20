#include "app/App.hpp"

#include <iostream>

#include <io/DataSerializer.hpp>

namespace app
{
    App::App()
    {
        this->data_serializer_ = std::make_unique<io::DataSerializer>();
    }

    void App::run()
    {
        menu_page_ = std::make_unique<ui::MenuPage>();
        portfolio_page_ = std::make_unique<ui::PortfolioPage>();
        add_holding_page_ = std::make_unique<ui::AddHoldingPage>();
        edit_holding_page_ = std::make_unique<ui::EditHoldingPage>();
        remove_holding_page_ = std::make_unique<ui::RemoveHoldingPage>();
        search_symbol_page_ = std::make_unique<ui::SearchSymbolPage>();

        menu_page_->set_data_serializer(data_serializer_.get());
        portfolio_page_->set_menu_page(menu_page_.get());
        add_holding_page_->set_menu_page(menu_page_.get());
        edit_holding_page_->set_menu_page(menu_page_.get());
        remove_holding_page_->set_menu_page(menu_page_.get());
        search_symbol_page_->set_menu_page(menu_page_.get());

        currentPage_ = menu_page_.get();

        while (true)
        {
            currentPage_->render();
            currentPage_->handle_input();

            // MenuPage navigation
            if (auto menu = dynamic_cast<ui::MenuPage*>(currentPage_)) {
                if (menu->should_show_portfolio()) {
                    portfolio_page_->set_portfolio(menu->get_portfolio());
                    currentPage_ = portfolio_page_.get();
                    menu->reset_navigation_flag();
                    continue;
                }
                if (menu->should_add_holding()) {
                    add_holding_page_->set_portfolio(menu->get_portfolio());
                    currentPage_ = add_holding_page_.get();
                    menu->reset_navigation_flag();
                    continue;
                }
                if (menu->should_edit_holding()) {
                    edit_holding_page_->set_portfolio(menu->get_portfolio());
                    currentPage_ = edit_holding_page_.get();
                    menu->reset_navigation_flag();
                    continue;
                }
                if (menu->should_remove_holding()) {
                    remove_holding_page_->set_portfolio(menu->get_portfolio());
                    currentPage_ = remove_holding_page_.get();
                    menu->reset_navigation_flag();
                    continue;
                }
                if (menu->should_search_symbol()) {
                    currentPage_ = search_symbol_page_.get();
                    menu->reset_navigation_flag();
                    continue;
                }
            }
            // PortfolioPage navigation
            if (auto portfolio = dynamic_cast<ui::PortfolioPage*>(currentPage_)) {
                if (portfolio->should_go_back_to_menu()) {
                    currentPage_ = menu_page_.get();
                    portfolio->reset_navigation_flag();
                    continue;
                }
            }
            // AddHoldingPage navigation
            if (auto add = dynamic_cast<ui::AddHoldingPage*>(currentPage_)) {
                if (add->should_go_back_to_menu()) {
                    currentPage_ = menu_page_.get();
                    add->reset_navigation_flag();
                    continue;
                }
            }
            // EditHoldingPage navigation
            if (auto edit = dynamic_cast<ui::EditHoldingPage*>(currentPage_)) {
                if (edit->should_go_back_to_menu()) {
                    currentPage_ = menu_page_.get();
                    edit->reset_navigation_flag();
                    continue;
                }
            }
            // RemoveHoldingPage navigation
            if (auto remove = dynamic_cast<ui::RemoveHoldingPage*>(currentPage_)) {
                if (remove->should_go_back_to_menu()) {
                    currentPage_ = menu_page_.get();
                    remove->reset_navigation_flag();
                    continue;
                }
            }
            // SearchSymbolPage navigation
            if (auto search = dynamic_cast<ui::SearchSymbolPage*>(currentPage_)) {
                if (search->should_go_back_to_menu()) {
                    currentPage_ = menu_page_.get();
                    search->reset_navigation_flag();
                    continue;
                }
            }
        }
    }

}// namespace app
