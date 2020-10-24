#ifndef CREATEPRESETWINDOW_H
#define CREATEPRESETWINDOW_H

#include <QDialog>

namespace Ui {
class CreatePresetWindow;
}

class CreatePresetWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreatePresetWindow(QWidget *parent = nullptr);
    ~CreatePresetWindow();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::CreatePresetWindow *ui;
};

#endif // CREATEPRESETWINDOW_H
