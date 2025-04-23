#include "DownloadController.h"
#include <QDebug>

// Construtor da classe DownloadController
DownloadController::DownloadController(QObject *parent)
    : QObject{parent}           // Inicializa o objeto base (QObject)
{
    // Inicializa a lista de logs com alguns valores fictícios
    m_logs = {"log1", "log2", "log3", "log4", "log5"};

    applyFilter();              // Aplica o filtro inicial (nesse caso, vazio)
}

// Getter que retorna a lista completa de logs
QStringList DownloadController::logs() const {
    return m_logs;
}

// Getter que retorna a lista de logs filtrados
QStringList DownloadController::filteredLogs() const {
    return m_filteredLogs;
}

// Getter que retorna o log atualmente selecionado
QString DownloadController::selectedLog() const {
    return m_selectedLog;
}

// Getter que retorna o texto de filtro atual
QString DownloadController::filterText() const {
    return m_filterText;
}

// Setter para o log selecionado
void DownloadController::setSelectedLog(const QString &log) {
    // Verifica se o novo valor é diferente do atual
    if (log != m_selectedLog) {
        m_selectedLog = log;           // Atualiza o valor
        emit selectedLogChanged();     // Emite sinal informando a mudança
    }
}

// Setter para o texto de filtro
void DownloadController::setFilterText(const QString &text) {
    // Verifica se o novo texto é diferente do atual
    if (text != m_filterText) {
        m_filterText = text;            // Atualiza o filtro
        emit filterTextChanged();       // Emite sinal de mudança
        applyFilter();                  // Reaplica o filtro com o novo texto
    }
}

// Função privada para aplicar o filtro baseado em m_filterText
void DownloadController::applyFilter() {
    m_filteredLogs.clear();  // Limpa a lista filtrada
    // Percorre todos os logs e adiciona os que contêm o texto do filtro
    for (const QString &log : m_logs) {
        if (log.contains(m_filterText, Qt::CaseInsensitive)) {
            m_filteredLogs.append(log);
        }
    }
    emit filteredLogsChanged();  // Emite sinal informando que a lista filtrada mudou
}

// Simula a obtenção de uma nova lista de logs (como se viesse de uma API)
void DownloadController::fetchLogs() {
    qDebug() << "Fetching log list...";  // Imprime no console (debug)

    // Substitui os logs existentes por novos valores simulados
    m_logs = {"logA", "logB", "logC"};

    emit logsChanged();  // Informa que a lista completa de logs mudou
    applyFilter();       // Aplica o filtro na nova lista
}

// Simula o download do log selecionado
void DownloadController::downloadSelectedLog() {
    // Verifica se há algum log selecionado
    if (!m_selectedLog.isEmpty()) {
        qDebug() << "Downloading log:" << m_selectedLog;  // Log de debug
        emit logDownloaded();  // Emite sinal indicando que o download foi iniciado
    }
}
