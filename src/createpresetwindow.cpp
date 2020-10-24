#include "createpresetwindow.h"
#include "ui_createpresetwindow.h"

#include <QSqlRecord>
#include <QSqlField>

#include "presetswindow.h"
#include "presetmodel.h"

CreatePresetWindow::CreatePresetWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreatePresetWindow)
{
    ui->setupUi(this);
}

CreatePresetWindow::~CreatePresetWindow()
{
    delete ui;
}

void CreatePresetWindow::on_buttonBox_accepted()
{
    // Fetch preset field values
    QString title = ui->lineEdit_title->text();
    QString search_str = ui->textEdit_searchString->toPlainText();
    QString replace_str = ui->textEdit_replaceString->toPlainText();

    // Create Preset
    QSqlRecord newPreset;

    newPreset.insert(0, QSqlField("title", QVariant::String));
    newPreset.insert(1, QSqlField("search_str", QVariant::String));
    newPreset.insert(2, QSqlField("replace_str", QVariant::String));

    newPreset.setValue("title", title);
    newPreset.setValue("search_str", search_str);
    newPreset.setValue("replace_str", replace_str);

    QSqlTableModel* model = PresetModel::getInstance().getModel();

    model->insertRecord(-1, newPreset);

    // Open Presets Dialog
    PresetsWindow* presetsWindow = new PresetsWindow(parentWidget());
    presetsWindow->open();
}
