import QtQuick 2.11
import QtQuick.Window 2.11
import Union.Lotto.Gemini 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")
    color: "white"
    MouseArea {
        anchors.fill: parent
        onClicked: {
            gemini.begin()
            gemini.stop()
            gemini.ballNumber = 10
//            console.info("x坐标",mouse.x)    //按键释放时的坐标
//            console.info("y坐标",mouse.y)
        }
        onPressed: {
            console.info("x坐标",mouse.x)    //按键按下时的坐标
            console.info("y坐标",mouse.y)
        }
        onReleased: {
            console.info("弹起x坐标",mouse.x)//按键释放时的坐标
            console.info("弹起y坐标",mouse.y)
        }
        onPositionChanged: {
            console.info("----x坐标",mouse.x)    //按键移动时的坐标
            console.info("----y坐标",mouse.y)
        }
    }
    Gemini {
        id: gemini
        onBegin: doSomething(Gemini.BALL_COLOR_RED)
        onBallNumberChanged: console.log("new ball number is", ballNumber) // 10
        Component.onCompleted: console.log("default ball number is", ballNumber) // 0
    }
}
