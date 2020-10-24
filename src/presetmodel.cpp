#include "presetmodel.h"

#include <QSqlTableModel>

#include "connection.h"

PresetModel::PresetModel()
{
    // Establish DB Connection
    Connection conn = Connection::getInstance();

    // Setup preset model
    m_model = new QSqlTableModel(nullptr, conn.getDB());
    m_model->setTable("presets");
    m_model->setEditStrategy(QSqlTableModel::OnFieldChange);
    m_model->select();
}

PresetModel& PresetModel::getInstance()
{
    static PresetModel instance;
    return instance;
}

QSqlTableModel* PresetModel::getModel()
{
    return m_model;
}
