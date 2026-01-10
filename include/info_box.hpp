#pragma once

#include <ftxui/dom/elements.hpp>
#include <string_view>

namespace snx
{

struct InfoBox
{
  InfoBox (std::string_view folder_path) : folder{ folder_path } {};

  ftxui::Element
  operator() ()
  {
    return ftxui::vbox (ftxui::hbox (ftxui::text ("Folder: ") | ftxui::bold,
                                     ftxui::text (folder)));
  }

private:
  std::string folder = {};
};

}
