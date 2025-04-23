import QtQuick

Item {
  id: root

  Rectangle {
    id: botaoMudarPagina
    color: "green"
    radius: 10

    property alias texto: label.text
    property var aoCliclar

    Text {
      id: label
      anchors.centerIn: parent
      color: "black"
      font.pixelSize: 18
    }

    MouseArea {
      anchors.fill: parent
      onClicked: {
        if (aoCliclar) aoCliclar()
      }
    }
  }

}
