import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4

Item {
    TextField {
        id: textField1

        background: Rectangle {
            color: control.enabled ? "transparent" : "#353637"
            border.color: control.enabled ? "#21be2b" : "transparent"
        }
        topPadding: 1
        font.pointSize: 14
        bottomPadding: 1
        placeholderText: "Your text here"
        renderType: Text.QtRendering
        onTextChanged: backend.text = text
    }

    TextField {
        id: textField2

        background: Rectangle {
            color: control.enabled ? "transparent" : "#353637"
            border.color: control.enabled ? "#21be2b" : "transparent"
        }
        anchors.top: textField1.bottom
        topPadding: 1
        font.pointSize: 14
        bottomPadding: 1
        placeholderText: "Your text here"
        renderType: Text.QtRendering
        onTextChanged: backend.text = text
    }

    TextField {
        id: textField3

        background: Rectangle {
            color: control.enabled ? "transparent" : "#353637"
            border.color: control.enabled ? "#21be2b" : "transparent"
        }
        anchors.top: textField2.bottom
        topPadding: 1
        font.pointSize: 14
        bottomPadding: 1
        placeholderText: "Your text here"
        renderType: Text.QtRendering
        onTextChanged: backend.text = text
    }

    TextField {
        id: textField4

        background: Rectangle {
            color: control.enabled ? "transparent" : "#353637"
            border.color: control.enabled ? "#21be2b" : "transparent"
        }
        anchors.top: textField3.bottom
        topPadding: 1
        font.pointSize: 14
        bottomPadding: 1
        placeholderText: "Your text here"
        renderType: Text.QtRendering
        onTextChanged: backend.text = text
    }

    TextField {
        id: textField5

        background: Rectangle {
            color: control.enabled ? "transparent" : "#353637"
            border.color: control.enabled ? "#21be2b" : "transparent"
        }
        anchors.top: textField4.bottom
        topPadding: 1
        font.pointSize: 14
        bottomPadding: 1
        placeholderText: "Your text here"
        renderType: Text.QtRendering
        onTextChanged: backend.text = text
    }
}
