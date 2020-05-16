#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include "Source2_1.h"
#include <math.h>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QProcess>
#include <QComboBox>
#include <QTableWidget>
#include <QPushButton>
#include <QProgressBar>
#include <QLineEdit>
#include <QTableWidget>
#include <QSlider>
#include <QLabel>
#include <QScrollArea>
#include <QFormLayout>
#include <QHeaderView>
#include <QMap>
#include <QPair>
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
#include "stable.h"
QT_CHARTS_USE_NAMESPACE

class MainWindow : public QMainWindow{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *mainWidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout * topLayout;
    QVBoxLayout * leftLayout;
    QTableWidget * myTable;
    QComboBox * algorithm;
    QLabel * Quantum;
    QLineEdit * quantumValue;
    QPushButton * add;
    QPushButton * start;
    QPushButton * remove;
    QPushButton * reset;
    QTableWidget * ganttChart;
    QMap<int,QColor> ProcessColors;

    vector <vector<string> >data ;
    vector <vector<float>> result;
    void draw();
private slots:
    void on_add_clicked();
    void on_remove_clicked();
    void on_myTable_itemChanged(QTableWidgetItem *item);
    void on_start_clicked();
    void on_reset_clicked();
    void on_algorithm_change(int);
};
#endif // MAINWINDOW_H
