#pragma once

#include "control_box.hpp"
#include "placholders.hpp"
#include <cctype>
#include <cwctype>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>

namespace snx
{
struct ProjectNameBox : public ControlBox
{
public:
  ProjectNameBox ()
  {
    input |= ftxui::CatchEvent ([&] (ftxui::Event event) {
      return event.is_character () and std::iswspace (event.character ()[0]);
    });

    input |= ftxui::CatchEvent ([&] (ftxui::Event event) {
      if (not project_name.empty ())
        return false;
      return event.is_character () and std::isdigit (event.character ()[0]);
    });
  }
  ftxui::Component &
  component () override
  {
    return input;
  }

  ftxui::Element
  operator() () const override
  {
    return ftxui::vbox (ftxui::text ("Project name"), input->Render ());
  }

  std::string
  name () const
  {
    if (project_name.empty ())
      return snx::placeholders::project_name;
    return project_name;
  }

  const std::string &
  ref ()
  {
    return project_name;
  }

private:
  std::string project_name = {};
  ftxui::Component input
      = ftxui::Input (&project_name, snx::placeholders::project_name);
};
}
