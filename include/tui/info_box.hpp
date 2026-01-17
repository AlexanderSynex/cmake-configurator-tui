#pragma once

#include "placholders.hpp"
#include <filesystem>
#include <ftxui/dom/elements.hpp>
#include <functional>
#include <string>
#include <string_view>

namespace snx
{

struct InfoBox
{
  InfoBox (std::string_view folder_path, const std::string &project_name)
      : folder{ folder_path }, project_name{ std::cref (project_name) } {};

  ftxui::Element
  operator() ()
  {
    return ftxui::vbox (ftxui::text ("Settings") | ftxui::center | ftxui::flex,
                        ftxui::hbox (ftxui::text ("Project path: "),
                                     ftxui::text (path ()) | ftxui::bold));
  }

  std::string
  path () const
  {
    if (project_name.get ().empty ())
      return (folder
              / std::filesystem::path{ std::string{
                                           snx::placeholders::project_name }
                                       + '/' })
          .string ();
    return (folder / std::filesystem::path{ project_name.get () + '/' })
        .string ();
  }

private:
  std::filesystem::path folder = std::filesystem::current_path ();
  std::reference_wrapper<const std::string> project_name;
};

}
