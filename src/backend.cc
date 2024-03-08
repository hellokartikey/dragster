#include "backend.h"

#include <fmt/core.h>
#include <fmt/std.h>

#include "mime.h"

Backend::Backend(int argc, char* argv[], QObject* parent) : QObject(parent) {
  for (std::size_t idx = 1; idx < argc; idx++) {
    auto file_path = fs::path{argv[idx]};

    if (not fs::exists(file_path) or not fs::is_regular_file(file_path)) {
      fmt::print(stderr, "{}: file does not exists or is inaccessible: {}\n",
                 argv[0], file_path);
    }

    m_mime_types.push_back(new Mime(file_path, qobject_cast<QObject*>(this)));
  }
}

auto Backend::inst(int argc, char* argv[]) -> Backend* {
  static Backend backend(argc, argv);

  return &backend;
}

auto Backend::mimeType() -> Mime* { return m_mime_types[0]; }

auto Backend::mimeList() const -> MimeList { return m_mime_types; }

auto Backend::size() const -> qsizetype { return m_mime_types.size(); }

#include "moc_backend.cpp"
