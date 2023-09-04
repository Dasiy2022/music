#ifndef MUSICPLAY_H
#define MUSICPLAY_H

#include <QWidget>

namespace Ui {
class musicPlay;
}

class musicPlay : public QWidget
{
    Q_OBJECT

public:
    explicit musicPlay(QWidget *parent = 0);
    ~musicPlay();


private:
    Ui::musicPlay *ui;
};

#endif // MUSICPLAY_H
