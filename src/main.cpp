#include "info_box.hpp"
#include "project_name_box.hpp"
#include <filesystem>
#include <ftxui/component/component.hpp>
#include <ftxui/component/component_options.hpp>
#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>

using namespace ftxui;
namespace fs = std::filesystem;

int
main (int argc, char *argv[])
{
  auto project_name_box = snx::ProjectNameBox{};

  auto container = Container::Vertical ({ project_name_box.component () });

  auto renderer = Renderer (container, [&] {
    return vbox (text ("Configurator") | flex | center,
                 snx::InfoBox{ fs::current_path ().string (),
                               project_name_box.ref () }()
                     | border,
                 gridbox ({ { project_name_box () } }) | flex | border);
  });

  auto s = ScreenInteractive::Fullscreen ();
  s.Loop (renderer);
  s.Clear ();
  return 0;
}
