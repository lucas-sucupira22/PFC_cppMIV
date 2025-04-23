import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import com.company.CommandController

ColumnLayout {
  id: root
  Layout.fillHeight: true
  Layout.fillWidth: true
  spacing: 20

  Text {
    text: "Comando:"
    font.pixelSize: 18
    color: "green"
  }

  RowLayout {
    Layout.fillWidth: true
    Layout.alignment: Qt.AlignHCenter

    TextField {
      id: textoBuscaField
      text: CommandController.commandText //propriedade, n usa () no final
      onTextChanged: CommandController.commandText = text
      placeholderText: "Digite o comando literal"
      Layout.fillWidth: true
      height: 40
      color: "black"
      placeholderTextColor: "#888"
      background: Rectangle {
        radius: 6
        color: "green"
        border.color: "#00ff00"
        border.width: 1
      }
    }
  }

  RowLayout {
    Layout.fillWidth: true
    Layout.alignment: Qt.AlignHCenter
    spacing: 10

    Rectangle {
      id: botaoGet
      width: 250
      height: 40
      color: "green"
      border.color: "#00ff00"
      radius: 10

      Text {
        text: "GET"
        anchors.centerIn: parent
        font.pixelSize: 18
        color: "black"
      }

      MouseArea {
        anchors.fill: parent
        onClicked: {
          CommandController.sendGetCommand() //Função (método ou slot), usa () no final
          animBotao1.running = true
        }
      }

      SequentialAnimation {
        id: animBotao1
        running: false
        PropertyAnimation {
          target: botaoGet
          property: "opacity"
          to: 0.5
          duration: 100
        }
        PropertyAnimation {
          target: botaoGet
          property: "opacity"
          to: 1.0
          duration: 100
        }
      }
    }

    Rectangle {
      id: botaoPush
      width: 250
      height: 40
      color: "green"
      border.color: "#00ff00"
      radius: 10

      Text {
        text: "PUSH"
        anchors.centerIn: parent
        font.pixelSize: 18
        color: "black"
      }

      MouseArea {
        anchors.fill: parent
        onClicked: {
          CommandController.sendPushCommand()
          animBotao2.running = true
        }
      }

      SequentialAnimation {
        id: animBotao2
        running: false
        PropertyAnimation {
          target: botaoPush
          property: "opacity"
          to: 0.5
          duration: 100
        }
        PropertyAnimation {
          target: botaoPush
          property: "opacity"
          to: 1.0
          duration: 100
        }
      }
    }
  }

  Text {
    text: "Histórico:"
    font.pixelSize: 18
    color: "green"
  }

  Text {
    text: "Status:"
    font.pixelSize: 18
    color: "green"
  }
}
