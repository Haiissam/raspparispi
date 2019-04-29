#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "custombutton.h"
#include "apievenementsmv.h"
#include "pharmapi.h"
#include "apibornes_elec.h"
#include "apiquefaire.h"
#include "sanisette.h"
#include "apiratp_station.h"
#include "apiratp_global.h"
#include "uiratp.h"
#include "theatre.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initButtons();

private slots:
    void dataReceived(QList<Abstract_API::GeoObj> list);
    void dialog();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
