#ifndef DOWNLOADCONTROLLER_H
#define DOWNLOADCONTROLLER_H

#include <QObject>
#include <QStringList>

class DownloadController : public QObject
{
    Q_OBJECT

    // Propriedade que representa o log selecionado no QML
    Q_PROPERTY(QString selectedLog READ selectedLog WRITE setSelectedLog NOTIFY selectedLogChanged)

    // Propriedade que expõe todos os logs disponíveis
    Q_PROPERTY(QStringList logs READ logs NOTIFY logsChanged)

    // Propriedade que mostra os logs filtrados de acordo com o texto de filtro
    Q_PROPERTY(QStringList filteredLogs READ filteredLogs NOTIFY filteredLogsChanged)

    // Propriedade que representa o texto atual do filtro de busca
    Q_PROPERTY(QString filterText READ filterText WRITE setFilterText NOTIFY filterTextChanged)

public:
    // Construtor explícito que recebe um QObject pai opcional
    explicit DownloadController(QObject *parent = nullptr);

    // Getter para a lista de todos os logs
    QStringList logs() const;

    // Getter para a lista de logs filtrados
    QStringList filteredLogs() const;

    // Getter para o log selecionado
    QString selectedLog() const;

    // Getter para o texto de filtro
    QString filterText() const;

    // Setter para definir qual log está selecionado
    void setSelectedLog(const QString &log);

    // Setter para definir o texto do filtro e disparar nova filtragem
    void setFilterText(const QString &text);

public slots:
    // Slot chamado para simular a ação de "baixar" a lista de logs (click do botao)
    void fetchLogs();

    // Slot chamado para simular o download de um log selecionado (click do botao)
    void downloadSelectedLog();

signals:
    // Sinal emitido quando a lista de logs muda
    void logsChanged();

    // Sinal emitido quando o log selecionado muda
    void selectedLogChanged();

    // Sinal emitido quando um log for baixado
    void logDownloaded();

    // Sinal emitido quando a lista filtrada muda
    void filteredLogsChanged();

    // Sinal emitido quando o texto do filtro muda
    void filterTextChanged();

private:
    // Aplica o filtro baseado em `m_filterText` sobre `m_logs`
    void applyFilter();

    // Lista completa de logs (simulados ou baixados)
    QStringList m_logs;

    // Lista de logs filtrados com base no texto de busca
    QStringList m_filteredLogs;

    // Log atualmente selecionado
    QString m_selectedLog;

    // Texto de busca para filtrar os logs
    QString m_filterText;
};

#endif // DOWNLOADCONTROLLER_H
