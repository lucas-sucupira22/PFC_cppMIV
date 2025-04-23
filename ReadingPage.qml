import QtQuick
import QtQuick.Layouts
import QtQuick.Controls
import com.company.ReadingController

ColumnLayout {
  spacing: 5
  Layout.alignment: Qt.AlignHCenter
  Layout.fillWidth: true
  Layout.fillHeight: true

  Rectangle {
    id: procurarSinal
    color: "black"
    Layout.fillWidth: true
    height: 30
    Layout.alignment: Qt.AlignHCenter

    TextField {
      id: campoBusca
      height: 30
      width: 300
      text: ReadingController.filterText
      onTextChanged: ReadingController.filterText = text
      anchors.horizontalCenter: parent.horizontalCenter
      placeholderText: "Digite qual sinal deseja procurar"
      color: "black"
      placeholderTextColor: "#888"
      selectionColor: "red"
      background: Rectangle {
        radius: 6
        color: "green"
        border.color: "#00ff00"
        border.width: 1
      }
    }
  }

  RowLayout {
    id: listas
    spacing: 5
    Layout.fillWidth: true
    Layout.fillHeight: true

    ColumnLayout {
      Layout.fillHeight: true
      Layout.preferredWidth: parent.width / 3

      Text {
        text: "Sinais disponíveis"
        font.pixelSize: 18
        color: "green"
        horizontalAlignment: Text.AlignHCenter
        Layout.alignment: Qt.AlignHCenter
      }

      Rectangle {
        Layout.fillWidth: true
        Layout.preferredHeight: 250
        color: "black"
        border.color: "green"
        radius: 10
        clip: true

        ListView {
          id: listaSinais
          anchors.fill: parent
          model: ReadingController.filteredVehicleSignals
          spacing: 4
          clip: true

          delegate: Item {
            width: listaSinais.width
            height: 40

            Rectangle {
              width: listaSinais.width / 2
              height: 40
              anchors.horizontalCenter: parent.horizontalCenter

              function isSelected(item) {
                return ReadingController.selectedVehicleSignals.includes(item)
              }

              color: isSelected(modelData) ? "#90ee90" : "green"

              border.color: "#00ff00"
              radius: 10

              Text {
                anchors.centerIn: parent
                text: modelData
                color: "black"
              }

              MouseArea {
                anchors.fill: parent
                onClicked: {
                  ReadingController.toggleVehicleSignalSelection(modelData)
                }
              }
            }
          }
        }
      }
    }

    ColumnLayout {
      Layout.fillHeight: true
      Layout.preferredWidth: parent.width / 3

      Text {
        text: "Sinais selecionados"
        font.pixelSize: 18
        color: "green"
        horizontalAlignment: Text.AlignHCenter
        Layout.alignment: Qt.AlignHCenter
      }

      Rectangle {
        Layout.fillWidth: true
        Layout.preferredHeight: 250
        color: "black"
        border.color: "green"
        radius: 10
        clip: true

        ListView {
          id: itensSelecionados
          anchors.fill: parent
          model: ReadingController.selectedVehicleSignals
          spacing: 4

          delegate: Item {
            //Usar Item como delegate da mais estrutura e flexibilidade
            width: itensSelecionados.width
            height: 40

            Rectangle {
              width: itensSelecionados.width / 2
              height: 40
              anchors.horizontalCenter: parent.horizontalCenter
              color: "green"
              border.color: "lightgreen"
              radius: 10

              Text {
                anchors.centerIn: parent
                text: modelData
                color: "black"
              }
            }
          }
        }
      }
    }

    ColumnLayout {
      Layout.fillHeight: true
      Layout.preferredWidth: parent.width / 3

      Item {
        height: 40
      }

      Rectangle {
        id: botaoLimpar
        width: 150
        height: 40
        color: "#aa0000"
        radius: 10
        border.color: "#ff0000"
        Layout.alignment: Qt.AlignHCenter

        Text {
          anchors.centerIn: parent
          text: "Desselecionar tudo"
          color: "white"
          font.pixelSize: 16
        }

        MouseArea {
          anchors.fill: parent
          onClicked: {
            ReadingController.clearSelectedSignals()
            animLimpar.running = true
            console.log("Seleção limpa")
          }
        }

        ToolTip {
          text: "Limpar todos os sinais selecionados"
          visible: botaoLimpar.containsMouse
        }

        SequentialAnimation {
          id: animLimpar
          running: false
          PropertyAnimation {
            target: botaoLimpar
            property: "opacity"
            to: 0.5
            duration: 100
          }
          PropertyAnimation {
            target: botaoLimpar
            property: "opacity"
            to: 1.0
            duration: 100
          }
        }
      }
    }
  }

  Rectangle {
    id: botaoGerarGrafico
    color: "green"
    height: 35
    width: 120
    radius: 10
    Layout.alignment: Qt.AlignHCenter
    border.color: "#00ff00"
    border.width: 1

    Text {
      anchors.centerIn: parent
      color: "black"
      font.pixelSize: 18
      text: "Gerar Gráfico"
    }

    MouseArea {
      anchors.fill: parent
      onClicked: {
        ReadingController.generateGraph()
        animBotao.running = true
      }
    }

    SequentialAnimation {
      id: animBotao
      running: false
      PropertyAnimation {
        //botao muda
        target: botaoGerarGrafico
        property: "opacity"
        to: 0.5
        duration: 100
      }
      PropertyAnimation {
        //botao volta ao normal
        target: botaoGerarGrafico
        property: "opacity"
        to: 1.0
        duration: 100
      }
    }
  }

  Rectangle {
    id: graficoGerado
    color: "black"
    border.color: "green"
    Layout.fillWidth: true
    height: 200
    radius: 10
    Layout.preferredHeight: parent.height / 2

    Text {
      anchors.centerIn: parent
      text: "O gráfico gerado vai aparecer aqui."
      font.pixelSize: 30
      color: "green"
    }
  }
}
