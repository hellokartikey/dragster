ecm_setup_version(${PROJECT_VERSION}
  VARIABLE_PREFIX DRAGSTER
  VERSION_HEADER version.h)

add_executable(
  ${PROJECT_NAME}
  main.cc
  mime.cc mime.h
  backend.cc backend.h
  resources.qrc)

target_link_libraries(
  ${PROJECT_NAME}
  fmt::fmt
  Qt6::Core
  Qt6::Widgets
  Qt6::Qml
  Qt6::Quick
  Qt6::QuickControls2)

install(TARGETS ${PROJECT_NAME} ${KDE_INSTALL_TARGETS_DEFAULT_ARGS})
