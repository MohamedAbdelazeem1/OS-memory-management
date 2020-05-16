#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

   mainWidget = new QWidget;
   mainLayout = new QVBoxLayout;
   topLayout = new QHBoxLayout;
   leftLayout = new QVBoxLayout;
   algorithm = new QComboBox(this);
   myTable = new QTableWidget(this);
   add = new QPushButton;
   start = new QPushButton;
   remove = new QPushButton;
   reset = new QPushButton;
   ganttChart = new QTableWidget;
   Quantum = new QLabel;
   quantumValue=new QLineEdit;
   quantumValue->setDisabled(true);


   draw();
   connect(add,SIGNAL(pressed()),this,SLOT(on_add_clicked()));
   connect(reset,SIGNAL(pressed()),this,SLOT(on_reset_clicked()));
   connect(remove,SIGNAL(pressed()),this,SLOT(on_remove_clicked()));
   connect(myTable,SIGNAL(itemChanged(QTableWidgetItem *)),this,SLOT(on_myTable_itemChanged(QTableWidgetItem *)));
   connect(start,SIGNAL(pressed()),this,SLOT(on_start_clicked()));
   connect(algorithm,SIGNAL(activated(int)),this,SLOT(on_algorithm_change(int)));
}

void MainWindow::draw(){


    myTable->setColumnCount(3);
    myTable->setHorizontalHeaderLabels({"PID","Arrival Time","Burst Time"});

    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);
    mainLayout->addLayout(topLayout);
    topLayout->addLayout(leftLayout);
    leftLayout->addWidget(algorithm);
    //algorithm->addItem("Please Select The Algorithm",20);
    algorithm->addItem("First Come First Served",0);
    algorithm->addItem("Priority (Preemptive)",1);
    algorithm->addItem("Priority (Non Preemptive)",2);
    algorithm->addItem("Round Robin",3);
    algorithm->addItem("Shortest Job First (Preemptive)",4);
    algorithm->addItem("Shortest Job First (Non Preemptive)",5);
    add->setText("Add");
    start->setText("Start");
    remove->setText("Remove");
    reset->setText("Reset");
    //Quantum->setText("Enter Quantum Value");
    leftLayout->addWidget(Quantum);
    leftLayout->addWidget(quantumValue);
    leftLayout->addWidget(start);
    leftLayout->addWidget(add);
    leftLayout->addWidget(remove);
    leftLayout->addWidget(reset);
    topLayout->addWidget(myTable);
    mainLayout->addWidget(ganttChart);
    ganttChart->horizontalHeader()->hide();
    ganttChart->verticalHeader()->hide();

    ganttChart->setRowCount(2);
    ganttChart->setColumnWidth(0,2);
    ganttChart->setRowHeight(1,150);

    //mainLayout->addWidget(chartView);


}


MainWindow::~MainWindow(){
}



void MainWindow::on_add_clicked(){


    myTable->setRowCount(myTable->rowCount()+1);
    data.resize(data.size()+1);
    int index = algorithm->currentIndex();
    if(index==0 ||index==3||index==4||index==5){
        data[data.size()-1].resize(4);
    }
    else{
        data[data.size()-1].resize(4);
    }
}

void MainWindow::on_remove_clicked(){
    if(!data.empty()){
        myTable->setRowCount(myTable->rowCount()-1);
        data.resize(data.size()-1);
    }
}


void MainWindow::on_myTable_itemChanged(QTableWidgetItem *item)
{
    QString temp  =item->text();
    data[myTable->currentRow()][myTable->currentColumn()] =  temp.toStdString().c_str();
}

void MainWindow::on_start_clicked(){
    QVariant selected = algorithm->itemData(algorithm->currentIndex());
    if(selected ==0){
        result = fcfs(data);
    }
    else if(selected ==1){
        result= priority_pre_emitive(data);
    }
    else if(selected ==2){
        result=priority_non_pre_emitive(data) ;
    }
    else if(selected ==3){
        result = R_R(data,stof(quantumValue->text().toStdString().c_str()));
    }
    else if(selected == 4){
        result=sjf_pre_emitive(data);
    }
    else if(selected ==5){
        result=sjf_non_pre_emitive(data);
    }
    for(int i=0;i<result.size();i++){

        if(ProcessColors.find(result[i][0]) == ProcessColors.end()){
            ProcessColors[result[i][0]]= QColor((23+70*i)%255,(23+35*i)%255,(2+10*i)%255,(163+1*i)%255);
        }
        for(int y=10*result[i][1];y<10*result[i][2];y++){
            ganttChart->setColumnCount(y+1);
            ganttChart->setItem(0,y,new QTableWidgetItem(QString::number(result[i][0])));
            ganttChart->setItem(1, y, new QTableWidgetItem);
            ganttChart->item(1, y)->setBackground(ProcessColors[result[i][0]]);
        }
        ganttChart->setRowCount(3);
        for(int z=0;z<ganttChart->columnCount();z++){
             ganttChart->setColumnWidth(z,1);
             ganttChart->setItem(2,z,new QTableWidgetItem(QString::number(z/10.0)));
             //ganttChart->item(1,z)->setText(QString::number(z/10.0));
        }
    }
}


void MainWindow::on_algorithm_change(int index){
    //data.clear();
    //myTable->setRowCount(0);
    if(index==0 ||index==3||index==4||index==5){
        myTable->setColumnCount(3);
    }
    else{
         myTable->setColumnCount(4);
          myTable->setHorizontalHeaderLabels({"PID","Arrival Time","Burst Time","Piriority"});
    }
    if(index==3){
        quantumValue->setDisabled(false);
        quantumValue->setPlaceholderText("Enter Quantum Value");
    }
    else{
        quantumValue->setDisabled(true);
        quantumValue->setPlaceholderText("");

    }
}

void MainWindow::on_reset_clicked(){

    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
/*
    myTable->setRowCount(0);
    myTable->setColumnCount(0);
    data.clear();
    result.clear();
    ganttChart->setRowCount(0);
    ganttChart->setColumnCount(0);
    draw();*/
}
