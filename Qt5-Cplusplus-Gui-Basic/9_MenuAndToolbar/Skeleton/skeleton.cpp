#include "skeleton.h"
#include <QToolBar>
#include <QIcon>
#include <QAction>
#include <QMenuBar>
#include <QMenu>
#include <QStatusBar>
#include <QTextEdit>

Skeleton::Skeleton(QWidget *parent) : QMainWindow(parent)
{
    QPixmap newpix("new.png");
    QPixmap openpix("open.png");
    QPixmap quitpix("quit.png");

    // Menubar
    auto *quit = new QAction("&Quit", this);
    QMenu *file;
    file = menuBar()->addMenu("&File");
    file->addAction(quit);
    connect(quit, &QAction::triggered, qApp, &QApplication::quit);

    // Toolbar
    QToolBar *toolbar = addToolBar("main toolbar");
    toolbar->addAction(QIcon(newpix), "New File");
    toolbar->addAction(QIcon(openpix), "Open File");
    toolbar->addSeparator();

    QAction *quit2 = toolbar->addAction(QIcon(quitpix), "Quit Application");
    connect(quit2, &QAction::triggered, qApp, &QApplication::quit);

    // Edit box
    auto *edit = new QTextEdit(this);
    setCentralWidget(edit);

    // Status bar
    statusBar()->showMessage("Ready");
}