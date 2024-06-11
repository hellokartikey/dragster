import QtQuick
import QtQuick.Controls

import Dragster

ApplicationWindow {
  id: root

  property int buttonWidth: 256
  property int buttonHeight: 48

  title: "Dragster - " + Backend.size

  visible: true

  maximumWidth: buttonWidth
  maximumHeight: buttonHeight * Backend.size

  minimumWidth: buttonWidth
  minimumHeight: Math.min(maximumHeight, buttonHeight * 10)

  Shortcut {
    sequences: [StandardKey.Quit, StandardKey.Cancel]
    onActivated: Qt.quit()
  }

  ScrollView {
    anchors.fill: parent

    ScrollBar.vertical.interactive: false

    Column {
      Repeater {
        id: repeater

        model: Backend.mimeModel

        delegate: Item {
          id: itemDelegate

          required property var model

          width: buttonWidth
          height: buttonHeight

          Component.onCompleted: {
            buttonWidth = Math.max(buttonWidth, element.implicitWidth)
          }

          DragElement {
            id: element

            anchors.fill: parent
            model: itemDelegate.model
          }

          Rectangle {
            id: seperator

            width: parent.width
            height: 1
            visible: repeater.index !== (repeater.count - 1)
            color: palette.mid
          }
        }
      }
    }
  }
}
