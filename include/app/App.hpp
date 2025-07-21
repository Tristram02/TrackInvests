#pragma once

#include <memory>

#include <app/ui/IPage.hpp>
#include <io/DataSerializer.hpp>

namespace app
{

class App
{
public:
    App();

    void run();

private:
    std::unique_ptr<ui::IPage> currentPage_;
    std::unique_ptr<io::DataSerializer> data_serializer_;
};

}