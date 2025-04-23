#ifndef READINGCONTROLLER_H
#define READINGCONTROLLER_H

#include <QObject>
#include <QStringList>

class ReadingController : public QObject
{
    Q_OBJECT

    // Propriedade que representa os sinais do veiculo selecionados no QML
    Q_PROPERTY(QStringList selectedVehicleSignals READ selectedVehicleSignals WRITE setselectedVehicleSignals NOTIFY selectedVehicleSignalsChanged)

    // Propriedade que expõe todos os sinais do veiculo disponíveis
    Q_PROPERTY(QStringList vehicleSignals READ vehicleSignals NOTIFY vehicleSignalsChanged)

    // Propriedade que mostra os sinais do veiculo filtrados de acordo com o texto de filtro
    Q_PROPERTY(QStringList filteredVehicleSignals READ filteredVehicleSignals NOTIFY filteredVehicleSignalsChanged)

    //READ	filterText() – ler o valor no QML
    //WRITE	setFilterText() – escrever ou alterar o valor a partir do QML
    //NOTIFY filterTextChanged() – sinal que o QML escuta para saber se algo mudou

    // Propriedade que representa o texto atual do filtro de busca
    Q_PROPERTY(QString filterText READ filterText WRITE setFilterText NOTIFY filterTextChanged)



public:
    explicit ReadingController(QObject *parent = nullptr);

    QStringList vehicleSignals() const;

    QStringList filteredVehicleSignals() const;

    QString filterText() const;
    void setFilterText(const QString &newFilterText);

    QStringList selectedVehicleSignals() const;
    void setselectedVehicleSignals(const QStringList &newSelectedVehicleSignals);

public slots:
    // Slot chamado para simular a ação de gerar grafico dos sinais escolhidos (click do botao)
    void generateGraph();

    void toggleVehicleSignalSelection(const QString &signalName);

    void clearSelectedSignals();

signals:

    void vehicleSignalsChanged();

    void filteredVehicleSignalsChanged();

    void filterTextChanged();

    void selectedVehicleSignalsChanged();

private:

    // Aplica o filtro baseado em `m_filterText` sobre `m_vehicleSignals`
    void applyFilter();

    QStringList m_vehicleSignals;
    QStringList m_filteredVehicleSignals;
    QString m_filterText;
    QStringList m_selectedVehicleSignals;
};

#endif // READINGCONTROLLER_H
