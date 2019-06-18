#ifndef RESULTVIEW_H
#define RESULTVIEW_H

#include <QMainWindow>

namespace Ui {
class ResultView;
}

class ResultView : public QMainWindow
{
    Q_OBJECT

public:
    explicit ResultView(QWidget *parent = 0);
    ~ResultView();
    void setl(QString str);

private:
    Ui::ResultView *ui;
};

#endif // RESULTVIEW_H
