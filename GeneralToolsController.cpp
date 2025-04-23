#include "GeneralToolsController.h"

GeneralToolsController::GeneralToolsController(QObject *parent)
    : QObject{parent}
{}

QString GeneralToolsController::filterText() const
{
    return m_filterText;
}

void GeneralToolsController::setFilterText(const QString &newFilterText)
{
    if (m_filterText == newFilterText)
        return;
    m_filterText = newFilterText;
    emit filterTextChanged();
}
