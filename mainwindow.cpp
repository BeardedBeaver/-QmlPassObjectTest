#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QObject *MainWindow::object()
{
    return new Object("single");
}

QList<QObject *> MainWindow::objects()
{
    QList <QObject *> result;
    for (int i = 0; i < 5; i++)
    {
        result.append(new Object("list"));
    }
    return result;
}

void MainWindow::on_actionevaluate_triggered()
{
    QString script = ui->textEdit->toPlainText();
    engine = new QQmlEngine(this);
    QJSValue api = engine->newQObject(this);
    engine->setObjectOwnership(this, QQmlEngine::CppOwnership);
    engine->globalObject().setProperty("api", api);
    QJSValue result = engine->evaluate(script);
    if (result.isError())
        qDebug() << result.toString();
    else
        qDebug() << "ok";
    engine->collectGarbage();
    engine->deleteLater();
}
