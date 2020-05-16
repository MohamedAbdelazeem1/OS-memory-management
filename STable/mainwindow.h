#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <QWidget>
#include <QDesktopWidget>
#include <math.h>
#include <QScrollBar>
#include <QHBoxLayout>
#include <vector>
#include <QVBoxLayout>
#include <QProcess>
#include <QComboBox>
#include <QBarLegendMarker>
#include <QTableWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QLineEdit>
#include <QTableWidget>
#include <QSlider>
#include <QLabel>
#include <QScrollArea>
#include <QSpinBox>
#include <QFormLayout>
#include <QHeaderView>
#include <QMessageBox>
#include <QMap>
#include <QPair>
#include <QPainter>
#include <QDebug>
#include <QComboBox>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/qchartview.h>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QValueAxis>
#include <renderarea.h>
#include <set>
#include "table.h"
#include "memory_management.h"

QT_CHARTS_USE_NAMESPACE
using namespace  std;

extern QMap<int,QColor> ProcessColors;
extern QVector<QColor> Palette;
extern vector <vector<string> >segmentTableData ;
extern vector <vector<string> >holeTableData;
extern vector<vector<string>>results;
extern vector <vector<QString>> segments;
extern int numOfUsedColors;
extern set <QString> PIDS;
extern int notSize;
extern vector<vector<string>>memory;
extern int memorySizeInt;
extern vector<vector<string>>notSizeProcess;

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *mainWidget;
    QHBoxLayout *mainLayout;
    QVBoxLayout * firstLayout;
    QVBoxLayout * secondLayout;
    QHBoxLayout * processLayout;
    QVBoxLayout * thirdLayout;


    QHBoxLayout * editFieldsLayout;





    QComboBox * algorithm;
    QLineEdit * memorySize;
    QLineEdit * holesNumber;
    QTableWidget * holeTable;
    QPushButton * drawHoles;
    QPushButton * removeLastProcess;
    QPushButton * reset;



    QLineEdit * processID;
    QLineEdit * processSegmentsNumber ;
    QTableWidget * myTable;
    QPushButton * addProcess;
    QLabel * processSelectLabel;
    QComboBox * processSelect;
    QPushButton* deallocateProcess;

    QTableWidget * segmentTable;
    QPushButton * addToMemory;
    QLabel * processViewSelectLabel;
    QComboBox * processViewSelect ;
    QPushButton * processViewButton;



//===========================================

    RenderArea *renderArea;



    table * myDialog;



//=============================================


    void draw();
private slots:
    void on_holesNumber_Changed(const QString &text);
    void on_memorySize_Changed(const QString &text);
    void on_addProcess_clicked();
    void on_addToMemory_clicked();
    void on_removeLastProcess_clicked();
    void on_myTable_itemChanged(QTableWidgetItem *item);
    void on_drawHoles_clicked();
    void on_reset_clicked();
    void submitTables();
    void on_algorithm_change(int);
    void on_processSelect_change(int);
    void on_processViewSelect_change(int);
    void on_deallocateProcess_clicked();
    void on_processViewButton_clicked();
};

void colorGenerator(int colorsNumber);
QColor getAndAssignColor(int pid);
vector<vector<QString>> strToQStr(vector<vector<string>> vec);
vector<vector<string>> QStrToStr(vector<vector<QString>> vec);


#endif // MAINWINDOW_H
