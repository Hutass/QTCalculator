#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QKeyEvent>
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

private slots:
    void on_pushButton_1num_clicked();

    void on_pushButton_2num_clicked();

    void on_pushButton_3num_clicked();

    void on_pushButton_4num_clicked();

    void on_pushButton_5num_clicked();

    void on_pushButton_6num_clicked();

    void on_pushButton_7num_clicked();

    void on_pushButton_8num_clicked();

    void on_pushButton_9num_clicked();

    void on_pushButton_0num_clicked();

    void on_pushButton_rank_clicked();

    void on_pushButton_undo_clicked();

    void on_pushButton_clear_clicked();

    void on_pushButton_autoCalc_clicked();

    void on_pushButton_divideRest_clicked();

    void on_pushButton_divide_clicked();

    void on_pushButton_multiply_clicked();

    void on_pushButton_subtract_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_calculate_clicked();

private:
    Ui::MainWindow *ui;
protected:
    virtual void keyPressEvent(QKeyEvent *keyEvent);
};
#endif // MAINWINDOW_H
