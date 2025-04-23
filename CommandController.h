#ifndef COMMANDCONTROLLER_H
#define COMMANDCONTROLLER_H

#include <QObject>

class CommandController : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString commandText READ commandText WRITE setCommandText NOTIFY commandTextChanged)

public:
    explicit CommandController(QObject *parent = nullptr);

    QString commandText() const;
    void setCommandText(const QString &newCommandText);

public slots:

    void sendGetCommand();
    void sendPushCommand();

signals:

    void commandTextChanged();
    void commandSent(const QString &commandType);

private:

    QString m_commandText ;
};

#endif // COMMANDCONTROLLER_H
