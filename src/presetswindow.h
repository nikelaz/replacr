#ifndef PRESETSWINDOW_H
#define PRESETSWINDOW_H

#include <QDialog>

#include "presetmodel.h"
#include "mainwindow.h"

namespace Ui {
class PresetsWindow;
}

class PresetsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PresetsWindow(QWidget *parent = nullptr, MainWindow* mainWindow = nullptr);
    ~PresetsWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_deletePreset_clicked();

    void on_buttonBox_rejected();

private:
    Ui::PresetsWindow *ui;
    void initTableView();
    PresetModel& model;
    MainWindow* m_mainWindow;
};

#endif // PRESETSWINDOW_H
