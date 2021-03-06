#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <model-node.h>
#include <QGL>
#include <QtOpenGL>

#include "GL/gl.h"
#include "GL/glu.h"
//#include "GL/glaux.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:


Node* node;
Link* links;
 std::set<Link*> graph_links;

    void /*WINAPI*/  display(void);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
