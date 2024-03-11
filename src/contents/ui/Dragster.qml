import QtQuick
import QtQuick.Controls

ApplicationWindow {
  SystemPalette {
    id: myPalette
    colorGroup: SystemPalette.Active
  }

  readonly property int buttonWidth: 256
  readonly property int buttonHeight: 64

  minimumWidth: buttonWidth
  minimumHeight: buttonHeight * backend.size

  maximumWidth: minimumWidth
  maximumHeight: minimumHeight

  title: "Dragster"

  visible: true

  Shortcut {
    sequences: [ StandardKey.Quit, StandardKey.Cancel ]
    onActivated: Qt.quit()
  }
}

