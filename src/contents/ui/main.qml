import QtQuick
import QtQuick.Controls

import Dragster

ApplicationWindow {
  id: root

  readonly property int buttonWidth: 256
  readonly property int buttonHeight: 48

  maximumWidth: Math.max(flick.width, buttonWidth)
  maximumHeight: Math.min(buttonHeight * Backend.size, buttonHeight * 10)

  minimumWidth: maximumWidth
  minimumHeight: buttonHeight

  height: maximumHeight
  width: maximumWidth

  title: "Dragster - " + Backend.size

  visible: true

  Shortcut {
    sequences: [StandardKey.Quit, StandardKey.Cancel]
    onActivated: Qt.quit()
  }

  ListView {
    id: flick

    width: contentItem.childrenRect.width
    height: Math.min(root.height, contentItem.childrenRect.height)

    model: Backend.mimeModel

    ScrollBar.vertical: ScrollBar {
      id: scroll

      interactive: false
    }

    delegate: Item {
      id: itemDelegate
      required property var model

      width: Math.max(element.implicitWidth, buttonWidth)
      height: root.buttonHeight

      DragElement {
        id: element

        anchors.fill: parent

        model: itemDelegate.model
      }

      Rectangle {
        id: seperator

        width: parent.width
        height: 1
        visible: (flick.index !== (flick.count - 1))
        color: palette.mid
      }
    }
  }
}
