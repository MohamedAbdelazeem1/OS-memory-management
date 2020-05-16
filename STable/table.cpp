#include "table.h"
table::table(QWidget *parent) :
    QDialog(parent)
{
    mainLayout = new QVBoxLayout();
    bottomLayout = new QHBoxLayout();
    segmentsTable = new QTableWidget();
    draw();
    this->setStyleSheet("QPushButton{height:40px;font-size:20px;background:#ff6363;"
                        "border-radius:15px;"
                        "}QPushButton:hover{}"
                        "MainWindow{background-color:#ffbd69;}"
                        "QTableWidget{}"
                        "QChart{background-color:#ffbd69;}"
                        "QComboBox{height:33px;"
                        "font-size:20px;}"
                        "QLabel{font-size:20px;}"
                        "QLineEdit{font-size:11px;}");
}

table::~table()
{
}


void table::draw(){


    setLayout(mainLayout);

    mainLayout->addWidget(segmentsTable);
    segmentsTable ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    segmentsTable->setColumnCount(4);
    segmentsTable->setRowCount(results.size());
    segmentsTable->setHorizontalHeaderLabels({"PID","Segment Name","Base","Size"});
    for(int i=0;i<results.size();i++){
        segmentsTable->setItem(i,0,new QTableWidgetItem(QString::fromStdString(results[i][0])));
        segmentsTable->setItem(i,1,new QTableWidgetItem(QString::fromStdString(results[i][1])));
        segmentsTable->setItem(i,2,new QTableWidgetItem(QString::fromStdString(results[i][2])));
        segmentsTable->setItem(i,3,new QTableWidgetItem(QString::fromStdString(results[i][3])));

    }

    setWindowIcon(QIcon(":images/myappico.ico"));
    setWindowTitle("Process "+QString::fromStdString(results[0][0])+" Segments");
    resize(QDesktopWidget().availableGeometry(this).size() * 0.24);
}

