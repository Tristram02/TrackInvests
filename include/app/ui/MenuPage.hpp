#pragma once

#include <memory>

#include <app/ui/IPage.hpp>
#include <io/DataSerializer.hpp>

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

private:
    std::unique_ptr<IPage> next_page_;
    io::DataSerializer* data_serializer_;
    core::Portfolio* portfolio_;
};

}