#ifndef LOGGERVIEW_H
#define LOGGERVIEW_H

#include <QMainWindow>

namespace Ui {
class LoggerView;
}

class LoggerView : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoggerView(QWidget *parent = 0);
    ~LoggerView();
    void appendtext(QString text);

private:
    Ui::LoggerView *ui;
};

#endif // LOGGERVIEW_H
