#include "loggerview.h"
#include "ui_loggerview.h"

LoggerView::LoggerView(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoggerView)
{
    ui->setupUi(this);
}

LoggerView::~LoggerView()
{
    delete ui;
}

void LoggerView::appendtext(QString text){
    ui->textBrowser->append(text);
}
