import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Window 2.15

Window {
  SystemPalette {
    id: myPalette
    colorGroup: SystemPalette.Active
  }

  minimumWidth: 256
  minimumHeight: 64

  width: 256
  height: 64
  title: "Dragster"

  visible: true

  Button {
    id: dragAction

    width: parent.width
    height: parent.height
    anchors.centerIn: parent

    text: mime_icon.file_name

    icon.name: mime_icon.icon_name
    icon.height: 48
    icon.width: 48
  }
}

