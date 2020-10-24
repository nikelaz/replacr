#ifndef PRESETMODEL_H
#define PRESETMODEL_H

#include <QSqlTableModel>

class PresetModel
{
private:
    PresetModel();
    QSqlTableModel* m_model;

public:
    static PresetModel& getInstance();
    QSqlTableModel* getModel();
};

#endif // PRESETMODEL_H
