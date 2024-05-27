import QtQuick
import QtQuick.Controls

import Dragster

Dragster {
    id: root

    readonly property int buttonWidth: 256
    readonly property int buttonHeight: 48

    maximumWidth: Math.max(flick.implicitWidth, buttonWidth)
    maximumHeight: Math.min(buttonHeight * Backend.size, buttonHeight * 10)

    minimumWidth: buttonWidth
    minimumHeight: buttonHeight

    height: maximumHeight

    ListView {
        id: flick

        anchors.fill: parent

        model: Backend.mimeModel

        ScrollBar.vertical: ScrollBar {
            id: scroll

            interactive: false
        }

        delegate: Item {
            id: itemDelegate
            required property var model

            width: Math.max(element.implicitWidth, flick.width)
            height: root.buttonHeight

            DragElement {
                id: element

                anchors.fill: parent

                model: itemDelegate.model
            }

            Rectangle {
                id: seperator

                width: parent.width;
                height: 1;
                visible: (flick.index !== (flick.count - 1))
                color: palette.mid
            }
        }
    }
}
