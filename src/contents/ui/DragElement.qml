import QtQuick
import QtQuick.Controls

ItemDelegate {
  id: button

  required property string fileName
  required property string iconName
  required property string fileUri

  text: fileName

  icon.name: iconName
  icon.height: 32
  icon.width: 32

  Drag.dragType: Drag.Automatic
  Drag.supportedActions: Qt.CopyAction
  Drag.mimeData: { "text/uri-list": fileUri }

  background: Item {
    SystemPalette {
      id: palette
      colorGroup: SystemPalette.Active
    }

    property real radius: 2

    Rectangle {
      anchors.fill: parent

      radius: parent.radius

      color: palette.button
      opacity: 1

      border.color: button.hovered ? palette.highlight : palette.mid
      border.width: 1
    }

    Rectangle {
      anchors.fill: parent

      radius: parent.radius

      color: palette.highlight
      opacity: button.pressed ? 0.5 : 0
    }

    Rectangle {
      anchors.fill: parent

      radius: parent.radius

      color: palette.mid
      opacity: button.pressed ? 0 : button.hovered ? 0.5 : 0
    }
  }

  DragHandler {
    id: dragHandler

    onActiveChanged: {
      if (active) {
        button.grabToImage(function(result) {
          button.Drag.imageSource = result.url
          button.Drag.active = true
        })
      } else {
        button.Drag.active = false
      }
    }
  }
}

