#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQmlEngine>
#include <QJSEngine>

#include "object.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    Q_INVOKABLE QObject * object();
    Q_INVOKABLE QList <QObject *> objects();

private slots:
    void on_actionevaluate_triggered();

private:
    Ui::MainWindow *ui;

    QQmlEngine * engine;
};
#endif // MAINWINDOW_H
