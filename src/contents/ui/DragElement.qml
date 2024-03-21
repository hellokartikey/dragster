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
      // Hover background
      anchors.fill: parent

      radius: parent.radius

      color: palette.button

      border.color: button.hovered ? palette.highlight : palette.mid
      border.width: 1
    }

    Rectangle {
      // Pressed background
      anchors.fill: parent

      radius: parent.radius

      color: palette.highlight
      opacity: button.down ? 0.5 : 0
    }

    Rectangle {
      // Border
      anchors.fill: parent

      radius: parent.radius

      color: palette.mid
      opacity: button.down ? 0 : button.hovered ? 0.5 : 0
    }
  }

  DragHandler {
    id: dragHandler

    onActiveChanged: {
      if (active) {
        button.grabToImage(function(result) {
          button.Drag.imageSource = result.url
          button.Drag.active = true
          button.down = false
        })
      } else {
        button.Drag.active = false
      }
    }
  }
}

