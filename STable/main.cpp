#include "mainwindow.h"
#include <QApplication>
#include <QApplication>
#include <QProcess>
#include "renderarea.h"
#include "mainwindow.h"
#include "memory_management.h"
#include <set>

vector <vector<QString>> segments={{"17","1","0","300"},
{"16","2","300","200"},
{"","3","500","500"},
{"15","4","1000","400"},
{"16","4","1400","200"},
{"","4","1600","100"},
{"17","4","1700","100"},
{"","2","1950","50"}};
QMap<int,QColor> ProcessColors;
QVector<QColor> Palette;
vector <vector<string> >segmentTableData ;
vector <vector<string> >holeTableData;
vector <vector<float>> result;
set <QString> PIDS;
int numOfUsedColors=0;
int notSize;
int memorySizeInt=2000;
vector<vector<string>>memory;
vector<vector<string>>notSizeProcess;




int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
