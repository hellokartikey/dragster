import QtQuick
import QtQuick.Controls

import Dragster

ApplicationWindow {
    id: root

    title: "Dragster - " + Backend.size

    visible: true

    Shortcut {
        sequences: [StandardKey.Quit, StandardKey.Cancel]
        onActivated: Qt.quit()
    }
}
