#include "info_box.hpp"
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
  auto container = Container::Horizontal ({});
  auto renderer = Renderer (container, [&] {
    return vbox (text ("Configurator") | flex | center,
                 snx::InfoBox{ fs::current_path ().string () }() | border,
                 gridbox ({}) | border | flex);
  });

  auto s = ScreenInteractive::Fullscreen ();
  s.Loop (renderer);

  return 0;
}
