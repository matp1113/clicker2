import QtQuick 2.0
import QtQuick.Controls 2.5

Window{
    property int size: myAppRoot.getPoints()

    id: settingWindow
    width: 620
    height: 480
    color: "white"
    visible: true

//    Loader{
//        id: loading
//    }
    Label{
        id: spinerLabel
        text: "Game's window size:   "
        anchors.right: spiner.left
        anchors.verticalCenter: parent.verticalCenter
    }

    SpinBox{
        id: spiner
        from: 100
        to: 800
        value: 400
        anchors.margins: 5
        anchors.centerIn: parent
        onValueChanged: myAppRoot.setPoints(spiner.value)
    }

    Label{
        id: pointSpinLabel
        text: "Pointer's size:   "
        anchors.right: pointSpin.left
        anchors.verticalCenter: pointSpin.verticalCenter
    }

    SpinBox{
        id: pointSpin
        from: spiner.value/40
        to: spiner.value/10
        value: spiner.value/20
        anchors.margins: 5
        anchors.top: spiner.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        //onValueChanged:
    }

    Label{
        id: velocitySpinLabel
        text: "velocity:   "
        anchors.right: velocitySpin.left
        anchors.verticalCenter: velocitySpin.verticalCenter
    }

    SpinBox{
        id: velocitySpin
        from: 5
        to: 20
        value: 10
        anchors.margins: 5
        anchors.top: pointSpin.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        //onValueChanged:
    }

    Button{
        text: "exit settings"
        anchors.bottom: parent.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        onClicked: {
//            loading.source = "main.qml"
//            loading.item.size = spiner.value
//            settingWindow.visible = false
            myAppRoot.exitSettings();
            settingWindow.close();
        }
    }
}
