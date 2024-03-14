import QtQuick
import QtQuick.Controls

ApplicationWindow {
  id: root

  title: "Dragster"

  visible: true

  Shortcut {
    sequences: [ StandardKey.Quit, StandardKey.Cancel ]
    onActivated: Qt.quit()
  }
}

