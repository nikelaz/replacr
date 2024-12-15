#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlTableModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QDebug>

#include "presetswindow.h"
#include "presetmodel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setupPresetComboBox();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setupPresetComboBox()
{
    QSqlTableModel* model = PresetModel::getInstance().getModel();

    ui->presetComboBox->setModel(model);
    ui->presetComboBox->setModelColumn(1);
}

void MainWindow::on_actionClose_triggered()
{
    close();
}

void MainWindow::on_textEdit_textChanged()
{
    updateOutput();
}

void MainWindow::on_pushButton_clicked()
{
    openPresetsWindow();
}

void MainWindow::on_presetComboBox_currentIndexChanged()
{
    updateActivePreset();
}

void MainWindow::updateActivePreset()
{
    int index = ui->presetComboBox->currentIndex();
    QSqlTableModel* model = PresetModel::getInstance().getModel();
    search_str = model->record(index).field("search_str").value().toString();
    replace_str = model->record(index).field("replace_str").value().toString();
    updateOutput();
}

void MainWindow::updateOutput()
{
    QString inputString = ui->textEdit->toPlainText();
    ui->textEdit_2->setPlainText(inputString.replace(search_str, replace_str));
}

void MainWindow::openPresetsWindow()
{
    PresetsWindow* presetWindow = new PresetsWindow(this, this);
    presetWindow->open();
}

void MainWindow::on_actionManage_Presets_triggered()
{
    openPresetsWindow();
}
