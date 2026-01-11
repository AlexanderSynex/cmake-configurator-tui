#pragma once

#include "control_box.hpp"
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>
namespace snx
{
struct ProjectBuildSystemBox : public ControlBox
{
  ftxui::Element
  operator() () const override
  {
    return ftxui::vbox (ftxui::text ("Build system"), selector->Render ());
  }

  ftxui::Component &
  component () override
  {
    return selector;
  }

  int selected = 0;
  std::vector<std::string> build_systems = { "Make", "Ninja" };
  ftxui::Component selector = ftxui::Radiobox (build_systems, &selected);
};

}
