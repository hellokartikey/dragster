import QtQuick
import QtQuick.Controls

ApplicationWindow {
  readonly property int buttonWidth: 256
  readonly property int buttonHeight: 48

  title: "Dragster"

  visible: true

  Shortcut {
    sequences: [ StandardKey.Quit, StandardKey.Cancel ]
    onActivated: Qt.quit()
  }
}

