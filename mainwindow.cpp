#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"

#include <QKeyEvent>
#include <QString>

Calculator calculator;
QPalette buttonPalette;
bool autoCalculationState = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //buttonPalette = ui->pushButton_autoCalc->palette();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_1num_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '1');

}


void MainWindow::on_pushButton_2num_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '2');

}


void MainWindow::on_pushButton_3num_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '3');

}


void MainWindow::on_pushButton_4num_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '4');

}


void MainWindow::on_pushButton_5num_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '5');

}


void MainWindow::on_pushButton_6num_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '6');

}


void MainWindow::on_pushButton_7num_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '7');

}


void MainWindow::on_pushButton_8num_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '8');

}


void MainWindow::on_pushButton_9num_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '9');

}


void MainWindow::on_pushButton_0num_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '0');

}


void MainWindow::on_pushButton_rank_clicked()
{
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '.');

}


void MainWindow::on_pushButton_undo_clicked()
{
    if (ui->lineEdit_exp->text().length() > 0)
    {
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text().remove(ui->lineEdit_exp->text().length() - 1, 1));
    }

}


void MainWindow::on_pushButton_clear_clicked()
{
    ui->lineEdit_exp->clear();
    ui->label_calculationHistory->clear();

}


void MainWindow::on_pushButton_autoCalc_clicked()
{
    autoCalculationState = !autoCalculationState;
    if(autoCalculationState == true)
    {
        ui->pushButton_autoCalc->setStyleSheet("color: #4444FF;");
    }
    else
    {
        ui->pushButton_autoCalc->setStyleSheet("color: #000000;");
    }

}


void MainWindow::on_pushButton_divideRest_clicked()
{
    if(autoCalculationState == true)
        on_pushButton_calculate_clicked();
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '%');

}


void MainWindow::on_pushButton_divide_clicked()
{
    if(autoCalculationState == true)
        on_pushButton_calculate_clicked();
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '/');

}


void MainWindow::on_pushButton_multiply_clicked()
{
    if(autoCalculationState == true)
        on_pushButton_calculate_clicked();
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '*');

}


void MainWindow::on_pushButton_subtract_clicked()
{
    if(autoCalculationState == true)
        on_pushButton_calculate_clicked();
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '-');

}


void MainWindow::on_pushButton_add_clicked()
{
    if(autoCalculationState == true)
        on_pushButton_calculate_clicked();
    ui->lineEdit_exp->setText(ui->lineEdit_exp->text() + '+');

}


void MainWindow::on_pushButton_calculate_clicked()
{
    ui->label_calculationHistory->setText(ui->lineEdit_exp->text() + '=');
    ui->lineEdit_exp->setText(calculator.Calculate(ui->lineEdit_exp->text()));

}

void MainWindow::keyPressEvent(QKeyEvent *keyEvent)
{
    int key = keyEvent->key();
    switch(key)
    {
    case Qt::Key_Enter: case Qt::Key_Return:
        on_pushButton_calculate_clicked();
        break;
    case Qt::Key_0:
        on_pushButton_0num_clicked();
        break;
    case Qt::Key_1:
        on_pushButton_1num_clicked();
        break;
    case Qt::Key_2:
        on_pushButton_2num_clicked();
        break;
    case Qt::Key_3:
        on_pushButton_3num_clicked();
        break;
    case Qt::Key_4:
        on_pushButton_4num_clicked();
        break;
    case Qt::Key_5:
        on_pushButton_5num_clicked();
        break;
    case Qt::Key_6:
        on_pushButton_6num_clicked();
        break;
    case Qt::Key_7:
        on_pushButton_7num_clicked();
        break;
    case Qt::Key_8:
        on_pushButton_8num_clicked();
        break;
    case Qt::Key_9:
        on_pushButton_9num_clicked();
        break;
    case Qt::Key_Period:
        on_pushButton_rank_clicked();
        break;
    case Qt::Key_Plus:
        on_pushButton_add_clicked();
        break;
    case Qt::Key_Minus:
        on_pushButton_subtract_clicked();
        break;
    case Qt::Key_Slash:
        on_pushButton_divide_clicked();
        break;
    case Qt::Key_Percent:
        on_pushButton_divideRest_clicked();
        break;
    case Qt::Key_Asterisk:
        on_pushButton_multiply_clicked();
        break;
    case Qt::Key_Backspace:
        on_pushButton_undo_clicked();
        break;
    case Qt::Key_X:
        on_pushButton_clear_clicked();
        break;
    }
}

