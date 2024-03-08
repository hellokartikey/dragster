#include "backend.h"

#include <fmt/core.h>
#include <fmt/std.h>

#include "mime.h"

Backend::Backend(int argc, char* argv[], QObject* parent) : QObject(parent) {
  for (std::size_t idx = 1; idx < argc; idx++) {
    auto file_path = fs::path{argv[idx]};

    if (not fs::exists(file_path)) {
      fmt::print(stderr, "{}: file does not exists or is inaccessible: {}\n",
                 argv[0], file_path);
      continue;
    }

    m_model.append(new Mime(file_path, qobject_cast<QObject*>(this)));
  }
}

auto Backend::inst(int argc, char* argv[]) -> Backend* {
  static Backend backend(argc, argv);

  return &backend;
}

auto Backend::mimeModel() -> MimeList { return m_model; }

auto Backend::size() const -> qsizetype { return m_model.size(); }

#include "moc_backend.cpp"
