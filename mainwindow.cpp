#include "mainwindow.h"
#include "./ui_mainwindow.h"
 #include <QTableWidget>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QSpinBox>
QStringList labels;
int rowCounter = -1;
int columnCounter = 0;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_insertColumn_clicked()
{
    columnCounter++;
    ui->tableWidget->setColumnCount(columnCounter);
    QString label = ui->columnLabelEdit->text();
    labels<<label;
    ui->tableWidget->setHorizontalHeaderLabels(labels);
    ui->columnLabelEdit->clear();
}


void MainWindow::on_changeColumnLabelButton_clicked()
{
    int index = ui->indexSpinBox->value();
    QString Label = ui->newLabelEdit->text();
    labels[index - 1] = Label;
    ui->tableWidget->setHorizontalHeaderLabels(labels);
}


void MainWindow::on_pushButton_4_clicked()
{
    int index = ui->deletedColumnIndex->value();
    labels.removeAt(index -1);
    columnCounter--;
    ui->tableWidget->setColumnCount(columnCounter);
    ui->tableWidget->setHorizontalHeaderLabels(labels);

}


void MainWindow::on_insertItem_clicked()
{
    rowCounter++;
    ui->tableWidget->insertRow(rowCounter);
}


void MainWindow::on_pushButton_clicked()
{
    rowCounter--;
    int index = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(index);
}


void MainWindow::on_tableWidget_cellDoubleClicked(int row, int column)
{
    QTableWidgetItem *cell  = ui->tableWidget->item(row, column);
    ui->tableWidget->editItem(cell);
}

