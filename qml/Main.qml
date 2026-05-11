import QtQuick

Window {
    width: 640
    height: 480
    visible: true
    color: "#cabbbb"
    title: qsTr("Soap Calculator")
    BaseInput{ x: 162;y: 105}
    BaseInput{ x: 162;y: 59}
    BaseInput{ x: 162;y: 13}

    Text {
        id: _text
        x: 47
        y: 21
        text: qsTr("Общая масса")
        font.pixelSize: 18
    }

    Text {
        id: _text1
        x: 47
        y: 67
        text: qsTr("Вода")
        font.pixelSize: 18
    }

    Text {
        id: _text2
        x: 47
        y: 113
        text: qsTr("Пережир")
        font.pixelSize: 18
    }

    BaseButton {
        x: 47;
        y: 159;
        width: 315;
        height: 44;
        text: "Передать в InputBuilder"
        onClicked: {

        }
    }
}
