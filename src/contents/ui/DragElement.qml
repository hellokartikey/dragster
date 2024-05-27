import QtQuick
import QtQuick.Controls

import Dragster

CheckBox {
    id: button

    required property var model

    text: model.fileName

    icon.name: model.iconName
    icon.height: 32
    icon.width: 32

    Drag.dragType: Drag.Automatic
    Drag.supportedActions: Qt.CopyAction
    Drag.mimeData: {
        "text/uri-list": Backend.isMultipleSelected ? Backend.multiMimeData : model.fileUri
    }

    checked: model.isChecked

    nextCheckState: function () {
        if (checkState === Qt.Checked) {
            model.isChecked = false;
            return Qt.Unchecked;
        } else {
            model.isChecked = true;
            return Qt.Checked;
        }
    }

    DragHandler {
        id: dragHandler

        onActiveChanged: {
            if (active) {
                button.grabToImage(function (result) {
                    button.Drag.imageSource = result.url;
                    button.Drag.active = true;
                    button.down = false;
                });
            } else {
                button.Drag.active = false;
            }
        }
    }
}
