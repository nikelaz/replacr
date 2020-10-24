#include "presetswindow.h"
#include "ui_presetswindow.h"

#include "createpresetwindow.h"

PresetsWindow::PresetsWindow(QWidget *parent, MainWindow* mainWindow) :
    QDialog(parent),
    ui(new Ui::PresetsWindow),
    model(PresetModel::getInstance()),
    m_mainWindow(mainWindow)
{
    ui->setupUi(this);
    initTableView();
}

PresetsWindow::~PresetsWindow()
{
    delete ui;
}

void PresetsWindow::initTableView()
{
    ui->tableView->setModel(model.getModel());
    ui->tableView->hideColumn(0);
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->horizontalHeader()->setMinimumSectionSize(150);
}

void PresetsWindow::on_pushButton_clicked()
{
    CreatePresetWindow* createPresetWindow = new CreatePresetWindow(this);
    close();
    createPresetWindow->open();
}

void PresetsWindow::on_pushButton_deletePreset_clicked()
{
    QModelIndex index = ui->tableView->currentIndex();
    model.getModel()->removeRow(index.row());
}

void PresetsWindow::on_buttonBox_rejected()
{
    m_mainWindow->updateActivePreset();
}
