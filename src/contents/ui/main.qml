import QtQuick

Dragster {
  id: root

  minimumWidth: content.implicitWidth
  minimumHeight: content.implicitHeight

  maximumWidth: minimumWidth
  maximumHeight: minimumHeight

  Column {
    id: content

    anchors.fill: parent

    width: repeater.implicitWidth
    height: repeater.implicitHeight

    spacing: 1

    Repeater {
      id: repeater

      model: backend.mimeModel

      Item {
        id: delegate

        required property var model

        width: Math.max(element.implicitWidth, parent.width)
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

