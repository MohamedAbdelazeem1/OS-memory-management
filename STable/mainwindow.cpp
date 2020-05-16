#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){

   mainWidget = new QWidget;
   mainLayout = new QHBoxLayout;
   firstLayout = new QVBoxLayout;
   editFieldsLayout = new QHBoxLayout;
   secondLayout = new QVBoxLayout; 
   processLayout = new QHBoxLayout;
   thirdLayout = new QVBoxLayout;

   algorithm = new QComboBox(this);
   memorySize=new QLineEdit;
   holesNumber = new QLineEdit;
   holeTable = new QTableWidget(this);
   holeTable ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   drawHoles = new QPushButton;
   removeLastProcess = new QPushButton;
   reset = new QPushButton;


   processID = new QLineEdit();
   processSegmentsNumber = new QLineEdit();
   myTable = new QTableWidget(this);
   myTable ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   addProcess = new QPushButton;
   processSelectLabel = new QLabel();
   processSelect = new QComboBox(this);
   deallocateProcess = new QPushButton;


   segmentTable = new QTableWidget(this);
   segmentTable ->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
   addToMemory= new QPushButton;
   processViewSelectLabel = new QLabel();
   processViewSelect = new QComboBox(this);
   processViewButton = new QPushButton();


   memorySize->setPlaceholderText("Enter Memory Size");
   holesNumber->setPlaceholderText("Enter Number of Holes");
   algorithm->addItem("First Fit",0);
   algorithm->addItem("Best Fit",1);
   addProcess->setText("Add Process");
   processSelectLabel->setText("Select a Process to Deallocate");
   processID->setPlaceholderText("Enter Process ID");
   processSegmentsNumber->setPlaceholderText("Enter Number of Segments");
   drawHoles->setText("Draw Holes");
   deallocateProcess->setText("Deallocate Process");
   removeLastProcess->setText("Remove Last Process");
   reset->setText("Reset");
   addToMemory->setText("Add To Memory");
   processViewSelectLabel->setText("Select a Process to show its Table");
   processViewButton->setText("View Process");
   //====================================


    renderArea = new RenderArea;
    renderArea->setShape(RenderArea::Rect);
    renderArea->setPen(QPen(Qt::blue, 1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    renderArea->setBrush(QBrush(Qt::green, Qt::SolidPattern	));
   //=====================================

   draw();
   connect(addProcess,SIGNAL(pressed()),this,SLOT(on_addProcess_clicked()));
   connect(holesNumber,SIGNAL(textChanged(const QString)),this,SLOT(on_holesNumber_Changed(QString)));
   connect(memorySize,SIGNAL(textChanged(const QString)),this,SLOT(on_memorySize_Changed(QString)));
   connect(reset,SIGNAL(pressed()),this,SLOT(on_reset_clicked()));
   connect(removeLastProcess,SIGNAL(pressed()),this,SLOT(on_removeLastProcess_clicked()));
   connect(addToMemory,SIGNAL(pressed()),this,SLOT(on_addToMemory_clicked()));
   connect(myTable,SIGNAL(itemChanged(QTableWidgetItem *)),this,SLOT(on_myTable_itemChanged(QTableWidgetItem *)));
   connect(drawHoles,SIGNAL(pressed()),this,SLOT(on_drawHoles_clicked()));
   connect(algorithm,SIGNAL(activated(int)),this,SLOT(on_algorithm_change(int)));
   connect(processSelect,SIGNAL(activated(int)),this,SLOT(on_processSelect_change(int)));

   connect(deallocateProcess,SIGNAL(pressed()),this,SLOT(on_deallocateProcess_clicked()));
   connect(processViewSelect,SIGNAL(activated(int)),this,SLOT(on_processViewSelect_change(int)));
   connect(processViewButton,SIGNAL(pressed()),this,SLOT(on_processViewButton_clicked()));

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

void MainWindow::draw(){


    myTable->setColumnCount(2);
    myTable->setHorizontalHeaderLabels({"PID","Number of Segments"});


    holeTable->setColumnCount(3);
    holeTable->setHorizontalHeaderLabels({"Hole Number","Base","Limit"});

    segmentTable->setColumnCount(3);
    segmentTable->setHorizontalHeaderLabels({"PID","Segment Name","size"});

    this->setCentralWidget(mainWidget);
    mainWidget->setLayout(mainLayout);




    mainLayout->addLayout(firstLayout);
    firstLayout->addWidget(algorithm);
    firstLayout->addLayout(editFieldsLayout);

    editFieldsLayout->addWidget(memorySize);
    editFieldsLayout->addWidget(holesNumber);


    firstLayout->addWidget(holeTable);
    firstLayout->addWidget(drawHoles);

    firstLayout->addWidget(reset);
    mainLayout->addLayout(secondLayout);
    secondLayout->addLayout(processLayout);
    processLayout->addWidget(processID);
    processLayout->addWidget(processSegmentsNumber);


    secondLayout->addWidget(myTable);
    myTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
    secondLayout->addWidget(addProcess);
    secondLayout->addWidget(removeLastProcess);
    secondLayout->addWidget(processSelectLabel);
    secondLayout->addWidget(processSelect);
    secondLayout->addWidget(deallocateProcess);



    mainLayout->addLayout(thirdLayout);
    thirdLayout->addWidget(segmentTable);
    thirdLayout->addWidget(addToMemory);
    thirdLayout->addWidget(processViewSelectLabel);
    thirdLayout->addWidget(processViewSelect);
    thirdLayout->addWidget(processViewButton);


    //segmentTable->verticalScrollBar()->setDisabled(true);

    mainLayout->addWidget(renderArea);
    setWindowIcon(QIcon(":images/myappico.ico"));
    setWindowTitle("Memory Manager");
    resize(QDesktopWidget().availableGeometry(this).size() * 0.75);
    segments.clear();
    renderArea->update();
    colorGenerator(10);

}


MainWindow::~MainWindow(){
}




void MainWindow::on_holesNumber_Changed(const QString &text){

    holeTable->setRowCount(text.toInt());
}

void MainWindow::on_addProcess_clicked(){
    QString ID  =processID->text();
    QString Number = processSegmentsNumber->text();

    QIntValidator v(1,10000000);
    int pos =0;

    if(v.validate(Number,pos) == QValidator::Invalid || v.validate(Number,pos) == QValidator::Intermediate || ID=="" ){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","Please enter a valid Integer Number");
        processSegmentsNumber->setText("");
    }
    else{
        //segmentTable->setRowCount(segmentTable->rowCount() + temp.toInt());
        if(PIDS.find(ID) != PIDS.end()){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","You Have Entered a duplicate PID\nPlaese Enter a Unique PID");
            processID->setText("");
        }
        else{
            PIDS.insert(ID);
            segmentTable->setRowCount(Number.toInt()+segmentTable->rowCount());
            processSelect->addItem(ID);
            if(deallocateProcess->text()=="Deallocate Process"){
                deallocateProcess->setText("Deallocate Process "+ID);
            }
            myTable->setRowCount(myTable->rowCount()+1);
            myTable->setItem(myTable->rowCount()-1,0,new QTableWidgetItem(ID));
            myTable->setItem(myTable->rowCount()-1,1,new QTableWidgetItem(Number));
            for(int i=0;i<Number.toInt();i++){
                segmentTable->setItem(segmentTable->rowCount()-i-1,0,new QTableWidgetItem(ID));
            }
            processID->setText("");
            processSegmentsNumber->setText("");
            processID->setDisabled(true);
            processSegmentsNumber->setDisabled(true);
        }
    }
}

void MainWindow::on_removeLastProcess_clicked(){

    if(myTable->rowCount()>0){
        QString lastProcess=myTable->item(myTable->rowCount()-1,0)->text();
        for (int i=0;i<segmentTableData.size();i++) {
            if(segmentTableData[i][0]==lastProcess.toStdString()){
                //void QTableWidgetItem::setBackground(const QBrush &brush)
                //segmentTable->currentItem()->setBackgroundColor(Qt::black);
                segmentTable->item(i,0)->setBackgroundColor(Qt::black);
                segmentTable->item(i,1)->setBackgroundColor(Qt::black);
                segmentTable->item(i,2)->setBackgroundColor(Qt::black);
            }
        }
        PIDS.erase(PIDS.find(lastProcess));
        processSelect->removeItem(processSelect->findText(lastProcess));
        deallocateProcess->setText("Deallocate Process " +processSelect->currentText());
        myTable->setRowCount(myTable->rowCount()-1);
    }

}

void MainWindow::on_myTable_itemChanged(QTableWidgetItem *item)
{
//    QString temp  =item->text();
//    int pos =0;

//    QIntValidator v(1,100000);


//    if(myTable->currentColumn() ==0){
//        if(PIDS.find(temp) != PIDS.end() || temp=="" ){
//            QMessageBox messageBox;
////          messageBox.setFixedSize(1200,800);
//            messageBox.critical(0,"Error","You Have Entered a duplicate PID\nPlaese Enter a Unique PID");
//            item->setText("edit PID");
//        }
//        else if(temp!="edit PID"){
//            PIDS.insert(temp);
//            processSelect->addItem(temp);
//            if(deallocateProcess->text()=="Deallocate Process"){
//                deallocateProcess->setText("Deallocate Process "+temp);
//            }
//        }

//    }
//    else{
//        if(v.validate(temp,pos) == QValidator::Invalid || v.validate(temp,pos) == QValidator::Intermediate){
//            QMessageBox messageBox;
////            messageBox.setFixedSize(800,400);
//            messageBox.critical(0,"Error","Please enter a valid Integer Number");
//            item->setText("1");
//        }
//        else{
//            //segmentTable->setRowCount(segmentTable->rowCount() + temp.toInt());
//        }
//    }

    //data[myTable->currentRow()][myTable->currentColumn()] =  temp.toStdString().c_str();
}

void MainWindow::submitTables(){
    segmentTableData.clear();
    segmentTableData.resize(segmentTable->rowCount());

    for(int i=0;i<segmentTableData.size();i++){
        segmentTableData[i].resize(3);
        segmentTableData[i][0] = segmentTable->item(i,0)->text().toStdString();
        segmentTableData[i][1] = segmentTable->item(i,1)->text().toStdString();
        segmentTableData[i][2] = segmentTable->item(i,2)->text().toStdString();
    }

}

void MainWindow::on_memorySize_Changed(const QString &text){

}

void MainWindow::on_drawHoles_clicked(){


        QString temp = memorySize->text();
        int pos =0;
        QIntValidator v(1,100000000000);

        if(v.validate(temp,pos) == QValidator::Invalid || v.validate(temp,pos) == QValidator::Intermediate){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Please enter a valid Integer Number");
            memorySize->setText("1");
        }
        initializeMemory(memorySize->text().toStdString());
        memorySizeInt = memorySize->text().toInt();



        holeTableData.clear();
        holeTableData.resize(holeTable->rowCount());
        for(int i=0;i<holeTableData.size();i++){
            holeTableData[i].resize(3);
            holeTableData[i][0] = holeTable->item(i,0)->text().toStdString();
            holeTableData[i][1] = holeTable->item(i,1)->text().toStdString();
            holeTableData[i][2] = holeTable->item(i,2)->text().toStdString();

        }
        segments = strToQStr(setHoles(holeTableData));
        renderArea->update();
}

void MainWindow::on_algorithm_change(int index){
    //data.clear();
    //myTable->setRowCount(0);
    if(index==0 ||index==3||index==4||index==5){
    }
    else{
    }

}

void MainWindow::on_processSelect_change(int index){
    deallocateProcess->setText(QString("Deallocate Process ")+ processSelect->currentText());
}

void MainWindow::on_processViewSelect_change(int index){
    processViewButton->setText(QString("View Process ")+ processViewSelect->currentText());
}

void MainWindow::on_deallocateProcess_clicked(){


//    for (int i=0;i<segmentTable->rowCount();i++) {
//        if(segmentTableData[i][0]==processSelect->currentText().toStdString()){
//            //void QTableWidgetItem::setBackground(const QBrush &brush)
//            //segmentTable->currentItem()->setBackgroundColor(Qt::black);
//            segmentTable->item(i,0)->setBackgroundColor(Qt::black);
//            segmentTable->item(i,1)->setBackgroundColor(Qt::black);
//            segmentTable->item(i,2)->setBackgroundColor(Qt::black);
//        }
//    }
    PIDS.erase(PIDS.find(processSelect->currentText()));
    myTable->removeRow(myTable->findItems(processSelect->currentText(),Qt::MatchExactly)[0]->row());
    segments =strToQStr(deleteProcess(processSelect->currentText().toStdString()));


    if(algorithm->currentIndex()==0){
            vector <vector<string>> temp = FirstFit(memory,notSizeProcess,segmentTableData );
            segments = strToQStr(temp);
            renderArea->update();
        }
    if(algorithm->currentIndex()==1){
        vector <vector<string>> temp = BestFit(memory, notSizeProcess,segmentTableData  );
        segments = strToQStr(temp);
        renderArea->update();
    }
    processViewSelect->removeItem(processViewSelect->findText(processSelect->currentText()));
    processViewButton->setText("View Process "+ processViewSelect->currentText());
    processSelect->removeItem(processSelect->currentIndex());
    deallocateProcess->setText("Deallocate Process " +processSelect->currentText());
    qDebug() << processSelect->currentText();
    renderArea->update();
    //segments = deleteProcess(processSelect->currentText());
}

void MainWindow::on_addToMemory_clicked(){
    submitTables();
    processID->setDisabled(false);
    processSegmentsNumber->setDisabled(false);

    if(algorithm->currentIndex()==0){
        vector <vector<string>> temp = FirstFit(memory,segmentTableData ,notSizeProcess);
        segments = strToQStr(temp);
        renderArea->update();
    }
    if(algorithm->currentIndex()==1){
        vector <vector<string>> temp = BestFit(memory,segmentTableData , notSizeProcess );
        segments = strToQStr(temp);
        renderArea->update();
    }
    if(notSize==0){
        QMessageBox messageBox;
        messageBox.critical(0,"Error","No Enough Space for Process Allocation");
    }
    processViewSelect->addItem(segmentTable->item(0,0)->text());
    if(processViewButton->text()=="View Process"){
        processViewButton->setText("View Process "+segmentTable->item(0,0)->text());
    }


    segmentTableData.clear();
    segmentTable->setRowCount(0);
}

void MainWindow::on_processViewButton_clicked(){

    results=showProcess(QStrToStr(segments),processViewSelect->currentText().toStdString());
    myDialog = new table(this);
    myDialog->exec();
}

void MainWindow::on_reset_clicked(){

    segmentTable->setRowCount(0);
    holeTable->setRowCount(0);
    myTable->setRowCount(0);
    holeTableData.clear();
    segmentTableData.clear();
    processSelect->clear();
    processViewSelect->clear();
    processViewButton->setText("View Process");
    processID->setText("");
    memorySize->setText("");
    segments.clear();
    memory.clear();
    notSize=0;
    notSizeProcess.clear();
    renderArea->update();
/*
    myTable->setRowCount(0);
    myTable->setColumnCount(0);
    data.clear();
    result.clear();
    ganttChart->setRowCount(0);
    ganttChart->setColumnCount(0);
    draw();*/
}

QColor getAndAssignColor(int pid){
    if(ProcessColors.find(pid) == ProcessColors.end()){
        ProcessColors[pid]= QColor(Palette[numOfUsedColors%Palette.size()]);
        return Palette[numOfUsedColors++%Palette.size()];
    }
    else {
        return ProcessColors[pid];
    }
}

void colorGenerator(int colorsNumber){
    Palette.clear();
    ProcessColors.clear();
    numOfUsedColors =0;
    for(unsigned int i=0;i<colorsNumber;i++){
        unsigned int degree = 360 /colorsNumber*i;
        Palette.push_back(QColor::fromHsv(degree,255,255));
    }
}

vector<vector<QString>> strToQStr(vector<vector<string>> vec){
    vector<vector<QString>> result(vec.size());
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            result[i].push_back(QString::fromStdString(vec[i][j]));
        }
    }
    return result;
}

vector<vector<string>> QStrToStr(vector<vector<QString>> vec){
    vector<vector<string>> result(vec.size());
    for(int i=0;i<vec.size();i++){
        for(int j=0;j<vec[i].size();j++){
            result[i].push_back((vec[i][j]).toStdString());
        }
    }
    return result;
}
