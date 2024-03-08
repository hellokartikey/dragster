#include "backend.h"

#include <fmt/core.h>
#include <fmt/std.h>

#include <memory>
#include <vector>

Backend::Backend(int argc, char* argv[], QObject* parent)
    : QObject(parent), m_mime_type(qobject_cast<QObject*>(this)) {
  auto file_path = fs::path{argv[1]};

  if (not fs::exists(file_path) or not fs::is_regular_file(file_path)) {
    fmt::print(stderr, "{}: file does not exists or is inaccessible: {}\n",
               argv[0], file_path);
  }

  m_mime_type.setPath(file_path);
}

Backend* Backend::inst(int argc, char* argv[]) {
  static Backend backend(argc, argv);

  return &backend;
}

MimeType* Backend::mimeType() { return &m_mime_type; }

#include "moc_backend.cpp"
