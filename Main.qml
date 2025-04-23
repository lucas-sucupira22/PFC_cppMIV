import QtQuick
import QtQuick.Layouts
import "functions.js" as Functions
import com.company.CommandController

Window {
  id: root
  width: 640
  height: 480
  visible: true
  title: qsTr("MIV")
  color: "black"

  property var botaoSelecionado: null

  Rectangle {
    id: parteFixa
    color: "black"
    width: parent.width / 5
    height: parent.height
    anchors {
      top: parent.top
      left: parent.left
      bottom: parent.bottom
    }

    ColumnLayout {

      spacing: 10
      anchors.fill: parent

      BotaoMudarPagina {
        id: botaoHome
        texto: "Home"
        Layout.alignment: Qt.AlignHCenter
        aoClicar: function () {
          Functions.selecionarBotao(root, this)
          loadPage.source = "HomePage.qml"
        }
      }

      BotaoMudarPagina {
        id: botaoDownload
        texto: "Download"
        Layout.alignment: Qt.AlignHCenter
        aoClicar: function () {
          Functions.selecionarBotao(root, this)
          loadPage.source = "DownloadPage.qml"
        }
      }

      BotaoMudarPagina {
        id: botaoLeitura
        texto: "Leitura"
        Layout.alignment: Qt.AlignHCenter
        aoClicar: function () {
          Functions.selecionarBotao(root, this)
          loadPage.source = "ReadingPage.qml"
        }
      }

      BotaoMudarPagina {
        id: botaoComando
        texto: "Comando"
        Layout.alignment: Qt.AlignHCenter
        aoClicar: function () {
          Functions.selecionarBotao(root, this)
          loadPage.source = "CommandPage.qml"
        }
      }

      BotaoMudarPagina {
        id: botaoAnalise
        texto: "Análise"
        Layout.alignment: Qt.AlignHCenter
        aoClicar: function () {
          Functions.selecionarBotao(root, this)
          loadPage.source = "AnalysisPage.qml"
        }
      }

      BotaoMudarPagina {
        id: botaoRelatorio
        texto: "Relatório"
        Layout.alignment: Qt.AlignHCenter
        aoClicar: function () {
          Functions.selecionarBotao(root, this)
          loadPage.source = "ReportPage.qml"
        }
      }
    }
  }

  Rectangle {
    id: parteAlternavel

    width: parent.width * 4 / 5
    height: parent.height
    color: "black"

    anchors {
      top: parent.top
      right: parent.right
      bottom: parent.bottom
    }

    Loader {
      id: loadPage
      anchors.fill: parent
    }
  }

  //Impondo o programa a inicializar na Pagina Home
  Component.onCompleted: {
    Qt.callLater(function () {
      loadPage.source = "HomePage.qml"
      Functions.selecionarBotao(root, botaoHome)
    })
  }
}
