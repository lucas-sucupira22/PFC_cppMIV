import QtQuick
import QtQuick.Layouts

Rectangle {
  id: botaoMudarPagina
  color: selecionado ? "#4C531F" : "#1A1F0F" //sim : nao
  Behavior on color {
    ColorAnimation {
      duration: 150
    }
  }
  height: 50
  width: 120
  radius: 10
  Layout.alignment: Qt.AlignHCenter
  border.color: "white" // borda
  border.width: 1

  property alias texto: label.text
  property var aoClicar
  property bool selecionado: false

  Text {
    id: label
    anchors.centerIn: parent
    color: "white"
    font.pixelSize: 18
  }

  MouseArea {
    anchors.fill: parent
    onClicked: {
      if (aoClicar) {
        aoClicar()
      }
    }
  }
}
