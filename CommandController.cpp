#include "CommandController.h"
#include <QDebug>

CommandController::CommandController(QObject *parent)
    : QObject{parent}
{}

QString CommandController::commandText() const
{
    return m_commandText;
}

void CommandController::setCommandText(const QString &newCommandText)
{
    if (m_commandText == newCommandText)
        return;
    m_commandText = newCommandText;
    emit commandTextChanged();
}

void CommandController::sendGetCommand()
{
    qDebug() << "GET command sent with:" << m_commandText;
    emit commandSent("GET");
}

void CommandController::sendPushCommand() //sendPushCommand É uma função membro da classe CommandController que executa a ação de enviar um comando
//tipo "PUSH". E emite um sinal (commandSent) para avisar outras partes do app que isso aconteceu.
{
    qDebug() << "PUSH command sent with:" << m_commandText; //imprime no console uma mensagem de depuração,
    //m_commandText é um atributo da classe que contém o texto atual do comando digitado pelo usuário.
    emit commandSent("PUSH");
}
