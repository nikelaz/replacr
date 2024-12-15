#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void updateActivePreset();

private slots:
    void on_actionClose_triggered();

    void on_textEdit_textChanged();

    void on_pushButton_clicked();

    void on_presetComboBox_currentIndexChanged();

    void on_actionManage_Presets_triggered();

private:
    Ui::MainWindow *ui;
    void setupPresetComboBox();
    QString search_str;
    QString replace_str;
    void updateOutput();
    void openPresetsWindow();
};
#endif // MAINWINDOW_H
