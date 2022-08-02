import QtQuick
import QtQuick.Controls 2.5

ApplicationWindow {
    property int size

    id: root
    width: 800
    height: 600
    visible: true
    title: qsTr("Hello World")

//    Loader{
//        id: loading
//    }

    Rectangle{
        id: rootRect
        anchors.fill: parent
        color: "white"
        clip: true

        Rectangle{
            id: rect
            Image{
                source: "qrc:/images/clicker.png"
                anchors.fill: parent
            }

            anchors.top: parent.top
            anchors.bottom: enter.top
            anchors.right: parent.right
            anchors.left: parent.left
            anchors.margins: 30
        }

        Button{
            id: enter
            text: "Come on let's go"
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            anchors.margins: 10

            onClicked: {
    //            loading.source = "game.qml"
    //            loading.item.size = size
    //            root.visible = false
                myAppRoot.enterGame();
            }
        }

        Button{
            id: settings
            text: "Let's change something"
            anchors.bottom: parent.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.margins: 10

            onClicked: {
    //            loading.source = "settings.qml"
    //            root.visible = false
                myAppRoot.openSettings();
            }
        }

        Button{
            id: leave
            text: "get me out of there"
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            anchors.margins: 10

            onClicked: {
                root.close();
            }
        }
    }


}
