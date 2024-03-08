#include "backend.h"

#include <vector>
#include <memory>

#include <fmt/core.h>
#include <fmt/std.h>

Backend::Backend(QObject* parent) 
  : QObject(parent), m_mime_type(qobject_cast<QObject*>(this)) {}

Backend* Backend::inst(int argc, char* argv[]) {
  static Backend backend;

  auto file_path = fs::path{argv[1]};

  if (not fs::exists(file_path) or not fs::is_regular_file(file_path)) {
    fmt::print(
        stderr,
        "{}: file does not exists or is inaccessible: {}\n",
        argv[0],
        file_path
    );
  }

  backend.m_mime_type.setPath(file_path);

  return &backend;
}

MimeType* Backend::mimeType() {
  return &m_mime_type;
}

#include "moc_backend.cpp"

