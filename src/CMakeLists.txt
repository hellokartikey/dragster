add_executable(
  ${PROJECT_NAME}
  main.cc
  mime.cc mime.h
  resources.qrc)

target_link_libraries(
  ${PROJECT_NAME}
  Qt5::Core
  Qt5::Widgets
  Qt5::Qml
  Qt5::Quick
  Qt5::QuickControls2)

