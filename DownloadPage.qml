import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import com.company.DownloadController

ColumnLayout {
  id: root
  spacing: 10
  Layout.alignment: Qt.AlignCenter
  Layout.fillWidth: true
  Layout.fillHeight: true

  Rectangle {
    id: botaoBaixarListaLogs
    width: 250
    height: 40
    anchors.horizontalCenter: parent.horizontalCenter
    color: "green"
    border.color: "#00ff00"
    radius: 10

    Text {
      text: "Baixar lista de logs"
      anchors.centerIn: parent
      font.pixelSize: 18
      color: "black"
    }

    MouseArea {
      anchors.fill: parent
      onClicked: {
        DownloadController.fetchLogs()
        animBotao.running = true
      }
    }

    SequentialAnimation {
      id: animBotao
      running: false
      PropertyAnimation {
        target: botaoBaixarListaLogs
        property: "opacity"
        to: 0.5
        duration: 100
      }
      PropertyAnimation {
        target: botaoBaixarListaLogs
        property: "opacity"
        to: 1.0
        duration: 100
      }
    }
  }

  RowLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    spacing: 10

    ColumnLayout {
      Layout.fillWidth: true
      Layout.fillHeight: true
      spacing: 8

      Text {
        text: "Lista de logs disponíveis para download"
        color: "green"
        font.pixelSize: 20
        Layout.alignment: Qt.AlignHCenter
      }

      Rectangle {
        Layout.fillWidth: true
        Layout.preferredHeight: root.height / 3
        color: "black"
        border.color: "green"
        radius: 10
        clip: true

        ListView {
          id: listaLogs
          anchors.fill: parent
          spacing: 4
          model: DownloadController.filteredLogs

          delegate: Item {
            width: listaLogs.width
            height: 40

            Rectangle {
              width: listaLogs.width / 4
              height: 40
              anchors.horizontalCenter: parent.horizontalCenter
              color: modelData === DownloadController.selectedLog ? "lightgreen" : "green"
              border.color: "lightgreen"
              radius: 10

              Text {
                anchors.centerIn: parent
                text: modelData
                color: "black"
                font.pixelSize: 18
              }

              MouseArea {
                anchors.fill: parent
                onClicked: {
                  DownloadController.selectedLog = (DownloadController.selectedLog
                                                    === modelData) ? "" : modelData
                }
              }
            }
          }
        }
      }
    }

    ColumnLayout {
      Layout.preferredWidth: 250
      Layout.alignment: Qt.AlignTop
      spacing: 10

      TextField {
        placeholderText: "Digite o nome do log que deseja procurar"
        text: DownloadController.filterText
        onTextChanged: DownloadController.filterText = text
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

      Text {
        text: "Log selecionado:"
        font.pixelSize: 18
        color: "green"
      }

      Rectangle {
        width: 250
        height: 40
        radius: 8
        color: "#1e1e1e"
        border.color: "green"

        Text {
          anchors.centerIn: parent
          text: DownloadController.selectedLog
                !== "" ? DownloadController.selectedLog : "Nenhum log selecionado"
          color: "lightgreen"
          font.pixelSize: 14
        }
      }
    }
  }

  Rectangle {
    id: botaoBaixarLogSelecionado
    width: 250
    height: 40
    anchors.horizontalCenter: parent.horizontalCenter
    color: "green"
    border.color: "#00ff00"
    radius: 10

    Text {
      text: "Baixar log selecionado"
      anchors.centerIn: parent
      font.pixelSize: 18
      color: "black"
    }

    MouseArea {
      anchors.fill: parent
      onClicked: {
        DownloadController.downloadSelectedLog()
        animBotao2.running = true
      }
    }

    SequentialAnimation {
      id: animBotao2
      running: false
      PropertyAnimation {
        target: botaoBaixarLogSelecionado
        property: "opacity"
        to: 0.5
        duration: 100
      }
      PropertyAnimation {
        target: botaoBaixarLogSelecionado
        property: "opacity"
        to: 1.0
        duration: 100
      }
    }
  }
}
