#include "stable.h"
//#include "ui_stable.h"

STable::STable(QWidget *parent)
    :QDialog(parent)
{
    //ui->setupUi(this);

    //ui->data->setTitle("<b>Data</b>");
    /*ui->pre->setDisabled(true);
    ui->nonpre->setDisabled(true);
    ui->lineEdit->setDisabled(true);
    connect(ui->SJF,SIGNAL(toggled(bool)),ui->pre,SLOT(setEnabled(bool)));
    connect(ui->SJF,SIGNAL(toggled(bool)),ui->nonpre,SLOT(setEnabled(bool)));
    connect(ui->Priority,SIGNAL(toggled(bool)),ui->pre,SLOT(setEnabled(bool)));
    connect(ui->Priority,SIGNAL(toggled(bool)),ui->nonpre,SLOT(setEnabled(bool)));
*/


}

STable::~STable()
{
    //delete ui;
}

/*
void STable::on_pushButton_clicked()
{
     static int  i = 1 ;
     ui->tableWidget->setRowCount(i) ;
     i++;

     data.resize(data.size()+1);
     data[data.size()-1].resize(4);
}

void STable::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    QTableWidgetItem *s =new QTableWidgetItem(*item);
    ui->tableWidget->setItem(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn(),s);
    QString temp  =item->text();
    data[ui->tableWidget->currentRow()][ui->tableWidget->currentColumn()] =  temp.toStdString().c_str();

    //QMessageBox messageBox;
    //messageBox.critical(0,"Error",data[ui->tableWidget->currentRow()][ui->tableWidget->currentColumn()].c_str());
    //messageBox.setFixedSize(500,200);
}

void STable::on_pushButton_2_clicked()
{
    if(ui->RR->isChecked())
    {
        result = R_R(data,stof(ui->lineEdit->text().toStdString().c_str()));
        for(int i=0;i<result.size();i++)
        {
             for(int j=0;j<result[i].size();j++)
             {
                     qDebug() << result[i][j] << " ";
             }
                 qDebug() << endl;
         }

    }


    if(ui->Priority->isChecked())
    {
        if(ui->pre->isChecked())
        {
           result= priority_pre_emitive(data);
        }

        else if(ui->nonpre->isChecked())
        {
            result=priority_non_pre_emitive(data) ;

        }

    }


    if(ui->FCFS->isChecked())
    {
       result = fcfs(data);

    }


    if(ui->SJF->isChecked())
    {
         if(ui->pre->isChecked())
         {
             result=sjf_pre_emitive(data);

         }

         if(ui->nonpre->isChecked())
         {
             result=sjf_non_pre_emitive(data);

         }
    }

}
*/
