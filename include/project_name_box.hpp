#pragma once

#include <cctype>
#include <cwctype>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_base.hpp>
#include <ftxui/component/event.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/node.hpp>

namespace snx
{
struct ProjectNameBox
{
private:
  static constexpr auto placeholder = "my_project";

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
  input_field ()
  {
    return input;
  }

  ftxui::Element
  operator() ()
  {
    return ftxui::hbox (ftxui::text ("Project name "), input->Render ());
  }

  std::string
  name () const
  {
    if (project_name.empty ())
      return placeholder;
    return project_name;
  }

private:
  std::string project_name = {};
  ftxui::Component input = ftxui::Input (&project_name, placeholder);
};
}
