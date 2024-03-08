import QtQuick

Dragster {
  id: root

  Column {
    anchors.fill: parent

    Repeater {
      model: backend.mimeModel

      Item {
        id: delegate
        required property var model

        implicitWidth: root.buttonWidth
        implicitHeight: root.buttonHeight

        DragElement {
          anchors.fill: parent
          fileName: model.fileName
          iconName: model.iconName
          fileUri: model.fileUri
        }
      }
    }
  }
}

