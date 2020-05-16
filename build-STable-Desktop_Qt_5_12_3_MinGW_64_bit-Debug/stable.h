#ifndef STABLE_H
#define STABLE_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QVector>
#include <string>
#include <QMessageBox>
#include <Source2_1.h>
#include <QtDebug>
#include <QtCore/QCoreApplication>
QT_BEGIN_NAMESPACE
namespace Ui { class STable; }
QT_END_NAMESPACE

class STable : public QDialog
{
    Q_OBJECT

public:
    STable(QWidget *parent = nullptr);
    ~STable();
    vector < vector<string> >data ;
    vector<vector<float>> result;


   // QVector <QTableWidgetItem> data ;
private slots:
    //void on_pushButton_clicked();
    //void on_tableWidget_itemChanged(QTableWidgetItem *item);

    //void on_pushButton_2_clicked();

private:

};
#endif // STABLE_H
