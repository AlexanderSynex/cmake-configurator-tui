#pragma once

#include <cassert>
#include <cstdlib>
#include <filesystem>
#include <optional>
#include <set>
#include <sstream>
#include <string>
#include <string_view>
namespace cmake
{
namespace builders
{
struct BuildSystem
{
private:
  static std::optional<std::set<std::string>>
  get_path_folders ()
  {
    auto path_ptr = std::getenv ("PATH");
    if (not path_ptr)
      {
        return {};
      }

#ifdef _WIN32
    constexpr auto separator = ';';
#else
    constexpr auto separator = ':';
#endif

    auto path_stream = [&path_ptr] () -> std::stringstream {
      auto str = std::stringstream{};
      str << path_ptr;
      return str;
    }();
    auto folders = std::set<std::string>{};
    for (auto folder = std::string{};
         std::getline (path_stream, folder, separator); folder.append (folder))
      ;
    return { folders };
  }

//   static std::optional<std::string>
//   find_executable_in_folder (std::string_view folder,
//                              std::string_view executable)
//   {
//   }

  static std::optional<std::string>
  file_in_path (std::string_view target)
  {
    namespace fs = std::filesystem;
    if (fs::exists (target))
      return { std::string{ target } };

    auto folders = get_path_folders ();
    if (not folders.has_value ())
      {
        return {};
      }

    for (auto folder : folders.value ())
      {
        auto file = fs::path{folder}.append(target);

        if (fs::exists(file)) return {file};
      }
    return {};
  }

public:
  BuildSystem (std::string_view name, std::string_view executable)
  {
    assert (file_in_path (executable).has_value ());
  }

  virtual ~BuildSystem () = default;

private:
  std::string path = {};
};
}
}
