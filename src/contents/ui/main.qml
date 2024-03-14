import QtQuick
import QtQuick.Controls

Dragster {
  id: root

  readonly property int buttonWidth: 192
  readonly property int buttonHeight: 48

  minimumWidth: flick.implicitWidth

  maximumWidth: minimumWidth
  maximumHeight: buttonHeight * backend.size

  ListView {
    id: flick

    anchors.fill: parent

    model: backend.mimeModel

    implicitWidth: Math.max(root.buttonWidth, contentItem.childrenRect.width)

    boundsBehavior: Flickable.StopAtBounds

    ScrollBar.vertical: ScrollBar {
      id: scroll

      interactive: false
    }

    spacing: 1

    delegate: Item {
        required property var model;

        width: Math.max(element.implicitWidth, flick.width)
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

