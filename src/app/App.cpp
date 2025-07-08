#include "app/App.hpp"

#include <iostream>

#include "app/ui/ManuPage.hpp"

namespace app
{

    void App::run()
    {
        currentPage_ = std::make_unique<ui::MenuPage>();
        while(true)
        {
            currentPage_->render();
            currentPage_->handle_input();
            auto next = currentPage_->next_page();

            if (next)
            {
                currentPage_ = std::move(next);
            }
        }
    }

}// namespace app
