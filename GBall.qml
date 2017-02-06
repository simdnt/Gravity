import QtQuick 2.0
import QtGraphicalEffects 1.0

Item {
    id: root
    property real radius: 15

    Rectangle{
        id: ball
        width: root.radius + root.radius
        height: root.radius + root.radius
        radius: root.radius
        color: "transparent"

        signal positionChanged(real aX, real aY)

        onPositionChanged: {
            root.x = aX -root.radius
            root.y = aY -root.radius
        }

        RadialGradient {
            anchors.fill: parent
            gradient: Gradient{
                GradientStop { position: 0.0; color: "white" }
                GradientStop { position: 0.5; color: "transparent" }
            }
        }
    }

}
