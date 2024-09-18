main_window.h
-------------------------------------------------------
#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QMainWindow>
#include <QTabWidget>
#include <QWidget>

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

private slots:
    void addTab();

private:
    QTabWidget* tabWidget;
    void initializeCEF();
};

#endif // MAIN_WINDOW_H
