import QtQuick
import QtQuick.Controls

Button {
  id: button

  required property string fileName
  required property string iconName
  required property string fileUri

  text: fileName

  icon.name: iconName
  icon.height: 48
  icon.width: 48

  Drag.dragType: Drag.Automatic
  Drag.supportedActions: Qt.CopyAction
  Drag.mimeData: { "text/uri-list": fileUri }

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

