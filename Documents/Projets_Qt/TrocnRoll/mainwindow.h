#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <set>

#include "message.h"
#include "listobjets.h"
#include "xmlobjetsreader.h"
#include "xmlobjetswriter.h"
#include "frameaddparam.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_Objets_Btn_add_param_clicked();
    void suppParametre(FrameAddParam* _widget);

    void on_Objets_Btn_add_clicked();

private:
    Ui::MainWindow *ui;
    std::set<FrameAddParam*> frames_param;
    ListObjets* list_objets;

    void SetupFenetre();
    void SetupMessages();
    void SetupObjets();
};

#endif // MAINWINDOW_H
