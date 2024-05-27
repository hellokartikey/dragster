import QtQuick
import QtQuick.Controls

import Dragster

Dragster {
    id: root

    readonly property int buttonWidth: 192
    readonly property int buttonHeight: 48

    maximumWidth: Math.max(flick.implicitWidth, buttonWidth)
    maximumHeight: buttonHeight * Backend.size

    minimumWidth: maximumWidth

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
        }
    }
}
