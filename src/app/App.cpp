#include "app/App.hpp"

#include <iostream>

#include <app/ui/MenuPage.hpp>
#include <io/DataSerializer.hpp>

namespace app
{
    App::App()
    {
        this->data_serializer_ = std::make_unique<io::DataSerializer>();
    }

    void App::run()
    {
        currentPage_ = std::make_unique<ui::MenuPage>();
        auto menu = dynamic_cast<ui::MenuPage*>(currentPage_.get());
        if (menu)
        {
            menu->set_data_serializer(std::move(data_serializer_.get()));
        }
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
