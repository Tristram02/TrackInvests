#pragma once

#include <memory>

#include <app/ui/IPage.hpp>

namespace app
{

class App
{
public:
    void run();

private:
    std::unique_ptr<ui::IPage> currentPage_;
};

}