#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtSql/QSqlDatabase>
#include <QSqlQuery>
#include <QTime>
#include <QMainWindow>
#include <QPixmap>
#include <QIcon>
#include <QString>
#include <QStringList>
#include <QFileDialog>
#include <QDir>
#include <QListWidgetItem>
#include <QFileInfoList>
#include <QProcess>
#include <QTimer>
#include <QByteArray>
#include <QTextStream>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QFile>
#include <QImage>
#include <string.h>
#include <QtDebug>
#include <QIODevice>
#include <QVector>
#include <QMessageBox>
#include <QMatrix>
#include <QPixmap>
#include <QGraphicsProxyWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTransform>
#include <QGraphicsRotation>

typedef struct tLrcFormat{
     double t;
     QString lrc;
}LrcFormat;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QString name;
    typedef enum
    {
        ListPlay = 0,
        SingleSongLoop = 1,
        PlayListLoop = 2,
        RandomPlay = 3

    }PlayModel;
signals:
    //发送改变的信号
    void playConcentChanged(int index);
private slots:
    void on_scanLocalFileBtn_clicked();

    void on_showPlayListBtn_clicked();

    void on_playBtn_clicked();

    void playMusic();

    void MaplayerInit();

    void on_showPlayList_doubleClicked(const QModelIndex &index);

    void onStartedSlot();

    void onReadDataSlot();

    void onTimeoutSlot();

    void on_preSongBtn_clicked();

    void on_playModelCbox_currentIndexChanged(int index);

    void on_volumeSlider_sliderMoved(int position);

    void updateShowPlayListRow(int row);

    void updateSongTitleSlot();

    void on_nextSongBtn_clicked();

    void onPlayProcessFinshedSlot();

    void updateSongSeekSlot(int);

    void updateSongSeekReleasedSlot();

    void on_pushButton_clicked();

    void getLrcList();

    void startShowlrc(double);

    void clearLrc();

    void on_showPlayList_clicked(const QModelIndex &index);


    void on_preSongBtn_2_clicked();

    void on_exitBtn_clicked();

    void arroundPic();
private:
    QStringList playListString;
    QStringList args;
    QProcess *playProcess;
    QString program;
    QTimer *timer;
    QVector<LrcFormat> lrcList;
    QVector<LrcFormat>::iterator it;
    PlayModel playModel;
    QMatrix matrix;
    QImage image = QImage(":/player/logo/R-C.jpg");
    QGraphicsRotation rotation;

    int oldPlayIndex;
    int playIndex;
    int tlength;
    int moveSliderVal;
    int picConf;

    bool showListBtnState;
    bool playBtnState;
    bool playState;
    bool volumeOn;
    bool isReady;
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
