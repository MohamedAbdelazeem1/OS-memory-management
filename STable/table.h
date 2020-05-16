#ifndef TABLE_H
#define TABLE_H
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
#include <QDialog>
#include "renderarea.h"
using namespace std;


extern QMap<int,QColor> ProcessColors;
extern QVector<QColor> Palette;
extern vector <vector<string> >segmentTableData ;
extern vector <vector<string> >holeTableData;
extern vector <vector<QString>> segments;
extern int numOfUsedColors;
extern set <QString> PIDS;
extern int notSize;
extern vector<vector<string>>memory;
extern int memorySizeInt;
extern vector<vector<string>>notSizeProcess;
extern vector<vector<string>>results;

class table : public QDialog
{
    Q_OBJECT

public:
    explicit table(QWidget *parent = nullptr);
    ~table();

private:
    QVBoxLayout *mainLayout;
    QHBoxLayout * bottomLayout;
    QTableWidget * segmentsTable;


    void draw();
};

#endif // TABLE_H
