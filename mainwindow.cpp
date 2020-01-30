#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QStringList>
#include <QTableView>
#include <QTableWidget>
#include <QDesktopWidget>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QDebug>
#include <QString>
#include <QLineEdit>
#include <QTableWidget>
#include <QTableWidget>
#include <QWidget>
#include <QTabWidget>
#include <QTextEdit>
#include <QVBoxLayout>



QStandardItemModel *model;



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int counter = 0;


    auto w = new QWidget;

    //auto qtab = new QTableWidget;


    ui->tabWidget->addTab(w, "MyTab");









    QFile file_check("C:\\Qt\\Qt5.1.1\\Tools\\QtCreator\\bin\\untitled\\booklist.txt"); // reading the file


    QTextStream in_first(&file_check);
    while(!in_first.atEnd())
    {
           qDebug() << counter;
        counter = counter + 1;

    }


model = new QStandardItemModel(32,5,this);


 int row = 0;
 model->setHeaderData(0, Qt::Horizontal, tr("Book"));   // preparing the table
 model->setHeaderData(1, Qt::Horizontal, tr("Writer"));
 model->setHeaderData(2, Qt::Horizontal, tr("Kind"));
 model->setHeaderData(3, Qt::Horizontal, tr("Publisher"));
 model->setHeaderData(4, Qt::Horizontal, tr("Stock"));
    QFile file("C:\\Qt\\Qt5.1.1\\Tools\\QtCreator\\bin\\untitled\\booklist.txt");

    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
    while(!in.atEnd())
    {

        QString line = in.readLine();
        QStringList IstLine = line.split(",");

        for (int col = 0; col < 5; col++)
        {
            if (col == 0)
            {
                QModelIndex index = model->index(row,col,QModelIndex());
                model->setData(index,IstLine.at(0));
            }

            else if (col ==1)
            {
                QModelIndex index = model->index(row,col,QModelIndex());
                model->setData(index,IstLine.at(1));
            }

            else if (col == 2)
            {
                QModelIndex index = model->index(row,col,QModelIndex());
                model->setData(index,IstLine.at(2));

            }

            else if (col ==3)
            {
                QModelIndex index = model->index(row,col,QModelIndex());
                model->setData(index,IstLine.at(3));

            }

            else if (col == 4)
            {
                QModelIndex index = model->index(row,col,QModelIndex());
                model->setData(index,IstLine.at(4));
            }

        }
            row++;
    }


    ui->tableView->setModel(model);



}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_radioButton_clicked() // button for all classes
{

    if (ui->radioButton->isChecked())
    {

          for(int i = 0; i < 32; i++)
         {

              ui->tableView->showRow(i);

         }
    }


}

void MainWindow::on_radioButton_2_clicked() // second button for poetry category
{
    if (ui->radioButton_2->isChecked())
    {

          for(int i = 0; i < 32; i++)
         {

             if(model->item(i,2)->text() == " Poetry")
            {
                 ui->tableView->showRow(i);

             }
             else
             {
                 ui->tableView->hideRow(i);
             }
         }
    }



}


void MainWindow::on_radioButton_3_clicked() // third button for novel category
{

    if (ui->radioButton_3->isChecked())
    {

          for(int i = 0; i < 32; i++)
         {

             if(model->item(i,2)->text() == " Novel")
            {
                 ui->tableView->showRow(i);

             }
             else
             {
                 ui->tableView->hideRow(i);
             }
         }
    }
}



void MainWindow::on_radioButton_4_clicked() // fourth button for science category
{
    if (ui->radioButton_4->isChecked())
    {

          for(int i = 0; i < 32; i++)
         {

             if(model->item(i,2)->text() == " Science")
            {
                 ui->tableView->showRow(i);

             }
             else
             {
                 ui->tableView->hideRow(i);
             }
         }
    }
}

void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{


    QString str = ui->lineEdit->text();


    if (ui->radioButton_4->isChecked())
    {
        for (int i= 0; i<32;i++)
        {
             if(model->item(i,2)->text() == " Science" && model->item(i,1)->text().contains(str))
             {
                  ui->tableView->showRow(i);
             }

             else
             {

                 ui->tableView->hideRow(i);
             }

        }


    }


    else if (ui->radioButton_3->isChecked())
    {
        for (int i= 0; i<32;i++)
        {
             if(model->item(i,2)->text() == " Novel" && model->item(i,1)->text().contains(str))
             {
                  ui->tableView->showRow(i);
             }

             else
             {

                 ui->tableView->hideRow(i);
             }

        }


    }

    else if (ui->radioButton_2->isChecked())
    {
        for (int i= 0; i<32;i++)
        {
             if(model->item(i,2)->text() == " Poetry" && model->item(i,1)->text().contains(str))
             {
                  ui->tableView->showRow(i);
             }

             else
             {

                 ui->tableView->hideRow(i);
             }

        }


    }


    else
    {



    for (int i= 0; i<32 ; i++)
    {

    if (model->item(i,1)->text().contains(str))
    {

        ui->tableView->showRow(i);

    }

    else
    {

        ui->tableView->hideRow(i);
    }

}

}
}

void MainWindow::on_lineEdit_2_textChanged(const QString &arg1) // HEPSINE BURDAKINI UYARLAMAK LAZIM
{

    QString str = ui->lineEdit_2->text();

    if (str.length()>0)
    {


    if (ui->radioButton_4->isChecked())
    {
        for (int i= 0; i<32;i++)
        {
             if(model->item(i,2)->text() == " Science" && model->item(i,0)->text().contains(str) && str.at(0) == model->item(i,0)->text().at(0))
             {
                  ui->tableView->showRow(i);
             }


             else
             {

                 ui->tableView->hideRow(i);
             }

        }


    }


    else if (ui->radioButton_3->isChecked())
    {
        for (int i= 0; i<32;i++)
        {

             if(model->item(i,2)->text() == " Novel" && model->item(i,0)->text().contains(str)&& str.at(0) == model->item(i,0)->text().at(0))
             {
                  ui->tableView->showRow(i);
             }


             else
             {

                 ui->tableView->hideRow(i);
             }

        }


    }

    else if (ui->radioButton_2->isChecked())
    {
        for (int i= 0; i<32;i++)
        {
             if(model->item(i,2)->text() == " Poetry" && model->item(i,0)->text().contains(str)&& str.at(0) == model->item(i,0)->text().at(0))
             {
                  ui->tableView->showRow(i);
             }

             else
             {

                 ui->tableView->hideRow(i);
             }

        }

    }


    else

    {



    for (int i= 0; i<32 ; i++)
    {

    if (model->item(i,0)->text().contains(str))
    {

        ui->tableView->showRow(i);

    }

    else
    {

        ui->tableView->hideRow(i);
    }


}
    }
}

else
    {
        for (int i = 0 ; i<32; i++)
            ui->tableView->showRow(i);
    }


}

void MainWindow::on_lineEdit_3_textChanged(const QString &arg1)
{
    QString str = ui->lineEdit_3->text();




    if (ui->radioButton_4->isChecked())
    {
        for (int i= 0; i<32;i++)
        {
            if(model->item(i,2)->text() == " Science" && model->item(i,3)->text().contains(str))
             {
                  ui->tableView->showRow(i);
             }

             else
             {

                 ui->tableView->hideRow(i);
             }

        }


    }

    else if (ui->radioButton_3->isChecked())
    {
        for (int i= 0; i<32;i++)
        {
             if(model->item(i,2)->text() == " Novel" && model->item(i,3)->text().contains(str))
             {
                  ui->tableView->showRow(i);
             }

             else
             {

                 ui->tableView->hideRow(i);
             }

        }

    }


    else if (ui->radioButton_2->isChecked())
    {

        for (int i= 0; i<32;i++)
        {
             if(model->item(i,2)->text() == " Poetry" && model->item(i,3)->text().contains(str))
             {
                  ui->tableView->showRow(i);
             }

             else
             {

                 ui->tableView->hideRow(i);
             }

        }
    }


    else
    {

    for (int i= 0; i<32 ; i++)
    {

    if (model->item(i,3)->text().contains(str))
    {

        ui->tableView->showRow(i);

    }

    else
    {

        ui->tableView->hideRow(i);
    }

}

}
}

void MainWindow::on_pushButton_clicked()
{


    if (ui->pushButton->isChecked())
    {

    }
}



