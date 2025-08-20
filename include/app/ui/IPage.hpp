#pragma once

#include <memory>

namespace app::ui
{

class MenuPage;

class IPage
{
public:
    virtual ~IPage() = default;
    virtual void render() = 0;
    virtual void handle_input() = 0;
    virtual std::unique_ptr<IPage> next_page() { return nullptr; }
};

}