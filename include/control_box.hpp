#pragma once

#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/node.hpp>
namespace snx {
    struct ControlBox {
        virtual ftxui::Element operator()() const = 0;
        virtual ftxui::Component& component() = 0;
    };
}
