#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include "resultview.h"
#include "loggerview.h"

QString filename;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_pushButton_clicked()
{
    ui->textEdit_2->setReadOnly(true);
    filename = QFileDialog::getExistingDirectory();
    ui->textEdit_2->setText(filename);
}

void MainWindow::on_pushButton_2_clicked()
{
        QString phrase=ui->textEdit->toPlainText();
        QString combovalue= ui->comboBox->currentText();
        bool logcheck=ui->checkBox->isChecked();

        ResultView * r=new ResultView ();
        r->show();

        LoggerView * l=new LoggerView();
        if (logcheck){
            l->show();
        }


//        if(filename==""){
//           filename = QFileDialog::getExistingDirectory();

//        }
//        std::string dir = filename.toStdString();
//        std::unique_ptr<IndexStore> indStore(IndexStore::getInstance());
//        indStore->loadDir(dir);
//        std::string query=phrase.toStdString();;
//        InputParser inputParser(query);
//        Output output(std::move(indStore),inputParser);
//        QString display;
//        if(combovalue=="Horizontal Collation"){
//            display=QString::fromStdString(output.getHorizontalCollation());
//        }
//        else{
//            display=QString::fromStdString(output.getVerticalCollation());
//        }
//        r->setl(display);
}
