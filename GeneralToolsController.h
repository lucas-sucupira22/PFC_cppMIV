#ifndef GENERALTOOLSCONTROLLER_H
#define GENERALTOOLSCONTROLLER_H

#include <QObject>
//tem que completar com a funçao applyFilter, nao eh prioridade agora
//tem outras funçoes que podem que estao dobradas tambem, como a de selecionar item de lista
class GeneralToolsController : public QObject
{
    Q_OBJECT

    // Propriedade que representa o texto atual do filtro de busca
    //READ	filterText() – ler o valor no QML
    //WRITE	setFilterText() – escrever ou alterar o valor a partir do QML
    //NOTIFY filterTextChanged() – sinal que o QML escuta para saber se algo mudou
    Q_PROPERTY(QString filterText READ filterText WRITE setFilterText NOTIFY filterTextChanged)

public:
    explicit GeneralToolsController(QObject *parent = nullptr);

    QString filterText() const;
    void setFilterText(const QString &newFilterText);

signals:
    void filterTextChanged();
private:
    QString m_filterText;
};

#endif // GENERALTOOLSCONTROLLER_H
