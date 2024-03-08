import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

ApplicationWindow {
  id: root

  SystemPalette {
    id: myPalette
    colorGroup: SystemPalette.Active
  }

  readonly property int buttonWidth: 256
  readonly property int buttonHeight: 64

  width: buttonWidth
  height: buttonHeight

  minimumWidth: buttonWidth
  minimumHeight: buttonHeight

  maximumWidth: buttonWidth
  maximumHeight: buttonHeight

  title: "Dragster"

  visible: true

  Shortcut {
    sequences: [ StandardKey.Quit ]
    onActivated: Qt.quit()
  }

  Button {
    id: button

    implicitWidth: root.buttonWidth
    implicitHeight: root.buttonHeight

    anchors.centerIn: parent

    text: backend.mime.file_name

    icon.name: backend.mime.icon_name
    icon.height: 48
    icon.width: 48

    Drag.dragType: Drag.Automatic
    Drag.supportedActions: Qt.CopyAction
    Drag.mimeData: { "text/uri-list": backend.mime.uri }

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
}

