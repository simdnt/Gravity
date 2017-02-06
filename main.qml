import QtQuick 2.5
import QtQuick.Window 2.2
import Gravity 0.1
import QtQuick.Controls 1.4

Window {
    id: root
    visible: true
    width: Screen.width
    height: Screen.height
    color: "black"

    GBall {
        id: centerBall
        x: root.width/2 - radius
        y: root.height/2 - radius
        radius: 100
    }
    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton

        onClicked: {
            if(mouse.button == Qt.LeftButton)
            {
                var component = Qt.createComponent("GBall.qml");
                var object = component.createObject(root,{"x": mouse.x-15,"y":mouse.y-15});
                ctrl.addGBall(object);
            }
            if(mouse.button == Qt.RightButton)
            {
                ctrl.stop();
                Qt.quit();
            }
        }
    }
    Controller {
        id: ctrl
        onGBallPositionChanged:{
            ball.x = x;
            ball.y = y;
        }
    }
}
