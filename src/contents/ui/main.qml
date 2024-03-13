import QtQuick

Dragster {
  id: root

  minimumWidth: Math.max(content.width, root.buttonWidth)
  minimumHeight: content.height

  maximumWidth: minimumWidth
  maximumHeight: minimumHeight

  Column {
    id: content

    spacing: 1

    Repeater {
      id: repeater

      model: backend.mimeModel

      Item {
        id: delegate

        required property var model

        width: Math.max(element.implicitWidth, root.width)
        height: root.buttonHeight

        DragElement {
          id: element

          anchors.fill: parent

          fileName: model.fileName
          iconName: model.iconName
          fileUri: model.fileUri
        }
      }
    }
  }
}

