#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "longinform.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->showPlayList->hide();
    ui->playBtn->setIcon(QIcon(":/player/logo/播放.png"));
    ui->pushButton->setIcon(QIcon(":/player/logo/音量.png"));
    MaplayerInit();
    ui->volumeSlider->setValue(50);
    ui->playProgressSlider->setEnabled(false);
    this->setWindowTitle("DasiyMusicPlayer");
    this->setWindowIcon(QIcon(":/player/logo/logoMax.png"));
    ui->usernameLB->setText(name);

    playIndex = 0;
    showListBtnState = false;
    playBtnState = false;
    playState = false;
    volumeOn = true;
    isReady = false;
}

MainWindow::~MainWindow()
{
    delete ui;
}

//获取本地歌曲
void MainWindow::on_scanLocalFileBtn_clicked()
{
    QString fileNameDir = QFileDialog::getExistingDirectory(this,"选择音乐文件","/home");
    if(fileNameDir.isEmpty()) return;
    //利用带路径的目录名构造目录类对象
    QDir dir(fileNameDir);
    QStringList formatList;
    //过滤文件的格式
    formatList << "*.mp3" << "*.mp4" << "*.wma";
    //文件信息列表
    QFileInfoList infoList;
    //按照格式过滤文件,选择合适格式的文件
    infoList = dir.entryInfoList(formatList);
    if(infoList.isEmpty()) return;
    QIcon musicMap(QPixmap(":/player/logo/音乐.png"));
    for(int i = 0;i < infoList.count(); i++)
    {
        //需要检测是否重复
        if(playListString.contains(infoList[i].filePath(),Qt::CaseSensitive))
            continue;
        playListString << infoList[i].filePath();
        QListWidgetItem *songNameList =
                new QListWidgetItem(musicMap,infoList[i].fileName());
        songNameList->setSizeHint(QSize(400,40));
        ui->showPlayList->addItem(songNameList);
    }
    ui->showPlayList->setCurrentRow(playIndex);
    isReady = true;
}

//  显示/隐藏歌单
void MainWindow::on_showPlayListBtn_clicked()
{
    showListBtnState = !showListBtnState;
    switch (showListBtnState) {
    case true:
        ui->showPlayList->show();
        break;
    case false:
        ui->showPlayList->hide();
    default:
        break;
    }
}



void MainWindow::MaplayerInit()
{
    //创建播放进程
    playProcess = new QProcess(this);
    playProcess->setProcessChannelMode(QProcess::MergedChannels);
    program = "mplayer";
    playState = false;
    playBtnState = false;
    playIndex = 0;

    connect(playProcess,SIGNAL(started()),this,SLOT(onStartedSlot()));
    connect(playProcess,SIGNAL(error(QProcess::ProcessError)),this,SLOT(onErrorSlot()));

    connect(playProcess,SIGNAL(readyReadStandardOutput()),this,SLOT(onReadDataSlot()));
    connect(playProcess,SIGNAL(finished(int)),this,SLOT(onPlayProcessFinshedSlot()));

    //创建定时器
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(onTimeoutSlot()));
}

void MainWindow::on_playBtn_clicked()
{
    if(!isReady)
    {
        QMessageBox::warning(this, tr("警告"),tr("歌曲列表为空!"),QMessageBox::Ok,NULL);
        return;
    }
    playBtnState = !playBtnState;
    switch (playBtnState) {
    case true:
        if(!playState)
        {
            playMusic();
        }
        else if(oldPlayIndex != playIndex)
        {
            oldPlayIndex = playIndex;
            playMusic();
            return;
        }
        else
        {
            playProcess->write("pause\n");
            oldPlayIndex = playIndex;

        }
        timer->start(); //暂停后再次启动播放时启动定时器
        ui->playBtn->setIcon(QIcon(":/player/logo/暂停.png"));
        break;
    case false:

        playProcess->write("pause\n");
        timer->stop();
        ui->playBtn->setIcon(QIcon(":/player/logo/播放.png"));

        break;
    }
}

//播放函数
void MainWindow::playMusic()
{
    playProcess->close();
    args.clear();
    args << "-slave"; //使用slave模式
    args << " -quiet"; //不要输出冗余信息
    args << playListString[playIndex];
    QString str = "正在播放:"+ui->showPlayList->currentItem()->text();
    ui->songNameLB->clear();
    ui->songNameLB->setText(str);
    playProcess->start(program,args);
    playProcess->write("volume 50 1\n");
    playState = true;
    playBtnState = true;
    ui->playBtn->setIcon(QIcon(":/player/logo/暂停.png"));
    ui->playProgressSlider->setEnabled(true);
    //定时器开启
    timer->start(100);
    getLrcList();
    connect(playProcess,SIGNAL(finished(int)),
            this,SLOT(onPlayProcessFinishedSlot()));
    connect(ui->playProgressSlider,SIGNAL(sliderMoved(int)),
            this,SLOT(updateSongSeekSlot(int)));
    connect(ui->playProgressSlider,SIGNAL(sliderReleased()),
            this,SLOT(updateSongSeekReleasedSlot()));

}

//双击切歌
void MainWindow::on_showPlayList_doubleClicked(const QModelIndex &index)
{
    int row = ui->showPlayList->currentRow();
    playIndex = row;
    playState = false;
    playBtnState = false;
//    playMusic();
    ui->playBtn->click();
}

void MainWindow::onStartedSlot()
{
    playProcess->write("get_time_length\n");

}

//进度条
void MainWindow::onReadDataSlot()
{
    while (playProcess->bytesAvailable()) {
        QByteArray arr = playProcess->readLine();
        QString str = QString::fromLocal8Bit(arr);
        if(str.contains("ANS_LENGTH"))
        {
            str.remove("\n");
            str.remove("\r");
            str.remove("ANS_LENGTH=");
            int t = str.toDouble();
            int m = t / 60;
            int s = t % 60;
            tlength = m * 60 + s;
            ui->playProgressSlider->setMinimum(0);
            ui->playProgressSlider->setMaximum(tlength);
            ui->playProgressSlider->setSingleStep(1);
            QString timeLength;
            timeLength.sprintf("%02d:%02d",m,s);
            ui->edtimeLB->setText(timeLength);
            clearLrc();
        }

        if(arr.contains("ANS_TIME_POSITION"))
        {
            str.remove("\n");
            str.remove("\r");
            double t = QString(str.split("=").at(1)).toDouble();

            int m = t / 60;
            int s = (int)(t+0.5) % 60;
            QString timePos;
            timePos.sprintf("%02d:%02d",m,s);
            ui->bgtimeLB->setText(timePos);
            //设置播放进度条的值
            int now = m * 60 + s;
            ui->playProgressSlider->setValue(now);
            startShowlrc(t);
        }

//        QString songInfo(arr);
//        //qDebug() << songInfo;
//        if(songInfo.startsWith("ANS_META_ARTIST"))
//        {
//            QString artist = "歌手: ";
//            artist += songInfo.mid(17);
//            ui->titleLB_1->setText(artist);

//        }

//        if(songInfo.startsWith("ANS_META_ALBUM"))
//        {
//            QString artist = "专辑: " + songInfo.mid(16);
//            ui->titleLB_1->setText(artist);
//        }

    }
}

void MainWindow::onTimeoutSlot()
{
    playProcess->write("get_time_pos\n");//时间
//    playProcess->write("get_meta_album\n");//专辑

//    playProcess->write("get_meta_artist\n");//歌手

}


//调节音量
void MainWindow::on_volumeSlider_sliderMoved(int position)
{
    QString str = QString("volume ");
    if(playProcess->isOpen())
    {
        QString buf;
        buf.setNum(position);
        str += buf + " 1\n";
        playProcess->write(str.toLocal8Bit());

    }
}

//播放模式设置
void MainWindow::on_playModelCbox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        playModel = ListPlay; //顺序播放
        break;
    case 1:
        playModel = SingleSongLoop; //单曲循环
        break;
    case 2:
        playModel = PlayListLoop; //列表循环
        break;
    case 3:
        playModel = RandomPlay; //随机播放
        break;
    default:
        break;
    }
}

//上一首
void MainWindow::on_preSongBtn_clicked()
{
    if(!isReady)
    {
        QMessageBox::warning(this, tr("警告"),tr("歌曲列表为空!"),QMessageBox::Ok,NULL);
        return;
    }
    if(playIndex > 0)
    {
        if(playModel == RandomPlay)
        {
            qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
            playIndex = qrand() % (playListString.count()-1);
        }
        else{
            playIndex--;
        }
    }
    else{
        if(playModel == RandomPlay)
        {
            qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
            playIndex = qrand() % (playListString.count()-1);
        }
        else{
            playIndex = playListString.count()-1;
        }
    }
    connect(this,SIGNAL(playConcentChanged(int)),
            this,SLOT(updateShowPlayListRow(int)));
    connect(ui->showPlayList,SIGNAL(doubleClicked(QModelIndex)),
            this,SLOT(updateSongTitleSlot()));
    playState = false;
    playBtnState = false;
    playMusic();
    emit playConcentChanged(playIndex);
}

//更新显示
void MainWindow::updateShowPlayListRow(int row)
{
    ui->showPlayList->setCurrentRow(row);
    updateSongTitleSlot();
}

void MainWindow::updateSongTitleSlot()
{
    QString name = ui->showPlayList->currentItem()->text();
    QString str = "正在播放:"+name;
    ui->songNameLB->setText(str);
}

//下一首
void MainWindow::on_nextSongBtn_clicked()
{
    if(!isReady)
    {
        QMessageBox::warning(this, tr("警告"),tr("歌曲列表为空!"),QMessageBox::Ok,NULL);
        return;
    }
    if(playIndex < playListString.count()-1 )
    {
        if(playModel == RandomPlay)
        {
            qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
            playIndex = qrand() % (playListString.count()-1);
        }
        else{
            playIndex++;
        }
    }
    else{
        if(playModel == RandomPlay)
        {
            qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
            playIndex = qrand() % (playListString.count()-1);
        }
        else{
            playIndex = 0;
        }
    }
    connect(this,SIGNAL(playConcentChanged(int)),
            this,SLOT(updateShowPlayListRow(int)));
    connect(ui->showPlayList,SIGNAL(doubleClicked(QModelIndex)),
            this,SLOT(updateSongTitleSlot()));
    playState = false;
    playBtnState = false;
    playMusic();
    emit playConcentChanged(playIndex);
}

//自动播放
void MainWindow::onPlayProcessFinshedSlot()
{
    //关闭定时器
    timer->stop();
    playBtnState = false;

    if(ui->playProgressSlider->value()
            != ui->playProgressSlider->maximum())
        return;
    switch (playModel) {
    case ListPlay: //顺序播放
        if(playIndex == playListString.count()-1)
        {
            //状态清零
            ui->playProgressSlider->setValue(0);
            playState = false; //停止播放
            ui->songNameLB->setText("无歌曲");
            ui->bgtimeLB->setText("00:00");
            ui->edtimeLB->setText("00:00");
            playIndex = 0;

            ui->showPlayList->setCurrentRow(playIndex);
            return;
        }
        playIndex++;
        break;
    case PlayListLoop:
        if(playIndex == playListString.count()-1)
            playIndex = 0;
        playIndex++;
        break;
    case SingleSongLoop:
        break;
    case RandomPlay:
        //设置时间种子
        qsrand(QTime(0,0,0).msecsTo(QTime::currentTime()));
        playIndex = qrand() % (playListString.count()-1);
        break;
    }
    playState = false;
    playBtnState = false;
    playMusic();
    emit playConcentChanged(playIndex);
}

void MainWindow::updateSongSeekSlot(int seek)
{
    disconnect(playProcess,SIGNAL(readyReadStandardOutput()),
               this,SLOT(onReadDataSlot()));//断开读取数据的槽,否则出BUG
    moveSliderVal = seek; //记录滑块的值
}

//快进
void MainWindow::updateSongSeekReleasedSlot()
{
    int seek = (moveSliderVal * 100)/ tlength;
    playProcess->write("pause\n");
    QString str = QString("seek ");
    if(playProcess->isOpen())
    {
        QString buf;
        buf.setNum(seek);
        str += buf + " 1\n";
        playProcess->write(str.toLocal8Bit());
    }

    //重新连接读取数据的槽
    connect(playProcess,SIGNAL(readyReadStandardOutput()),
            this,SLOT(onReadDataSlot()));
}

//静音
void MainWindow::on_pushButton_clicked()
{
    if(!playState)
        return;
    if(!volumeOn)
        {playProcess->write("mute 0\n");
        ui->pushButton->setIcon(QIcon(":/player/logo/音量.png"));
        ui->volumeSlider->setEnabled(true);
        volumeOn = true;
    }
    else
    {playProcess->write("mute 1\n");
    ui->pushButton->setIcon(QIcon(":/player/logo/音量关闭.jpg"));
    ui->volumeSlider->setEnabled(false);
    volumeOn = false;
    }
}

int i;
//加载歌词
void MainWindow::getLrcList()
{
    lrcList.clear();
    QString lrcPath = playListString[playIndex].mid(
                0,playListString[playIndex].lastIndexOf(".")) + ".lrc";
    QFile lrcFile(lrcPath);
    bool ok = lrcFile.open(QIODevice::ReadOnly);
    if(!ok)
    {
        ui->lrcLB_4->setText("该歌曲没有歌词文件");
        return;
    }
    QTextStream in(&lrcFile);
    QString readStr = in.readAll();
    QRegularExpression rex("\\[(\\d+)?:(\\d+\\.\\d+)?\\]");
    // 去掉 匹配到的第一个时间戳前的无用字符串
    QRegularExpressionMatch match = rex.match(readStr);
    readStr = readStr.mid(match.capturedStart(),
                          readStr.length() - match.capturedStart());
    qDebug() << readStr;
    while(true)
    {
        LrcFormat lrc;
        lrc.t = static_cast<double>((match.captured(1).toDouble() * 60 + match.captured(2).toDouble())); // 秒
        lrc.lrc = readStr.mid(match.capturedLength(), readStr.indexOf("\n") - match.capturedLength() + 1).simplified(); // 歌词
        readStr = readStr.mid(readStr.indexOf("\n") + 1, readStr.length() - readStr.indexOf("\n")); // 截取 已解析的字符串

        match = rex.match(readStr);
        lrcList.append(lrc); // QVector<LrcFormat> 结构体容器
        qDebug() << lrc.t << "  "<<lrc.lrc;
        if( readStr.indexOf("\n") < 0 ) // 结尾
        {
            LrcFormat end;
            end.t = static_cast<double>((match.captured(1).toDouble() * 600 + match.captured(2).toDouble()));
            end.lrc = readStr.mid(match.capturedLength(), readStr.indexOf("\n") - match.capturedLength() + 1).simplified();
            lrcList.append(end);
            break;
        }
    }

    lrcFile.close();
    it = lrcList.begin();
    clearLrc();
    picConf = 0;
}

void MainWindow::startShowlrc(double postion)
{
    it = lrcList.begin();
    while (it != lrcList.end())
    {
        if(postion-0.2<=it->t && postion+0.2>=it->t)
        {
            int j=0;
            if(it != lrcList.begin())
            {
                it--;
                ui->lrcLB_3->setText(it->lrc);
                j++;
            }
            if(it != lrcList.begin())
            {
                it--;
                ui->lrcLB_2->setText(it->lrc);
                j++;

            }

            if(it != lrcList.begin())
            {
                it--;
                ui->lrcLB_1->setText(it->lrc);
                j++;

            }
            for(;j>0;j--)
            {
                it++;
            }
            //中间
            ui->lrcLB_4->setText(it->lrc);
            it++;
            if(it != lrcList.end())
            {
                ui->lrcLB_5->setText(it->lrc);
            }
            else
            {
                ui->lrcLB_5->setText("");
                return;
            }
            it++;
            if(it != lrcList.end())
            {
                ui->lrcLB_6->setText(it->lrc);
            }
            else
            {
                ui->lrcLB_6->setText("");
                return;
            }
            it++;
            if(it != lrcList.end())
            {
                ui->lrcLB_7->setText(it->lrc);
            }
            else
            {
                ui->lrcLB_7->setText("");
                return;
            }

        }
        it++;
    }

}

void MainWindow::clearLrc()
{
    ui->lrcLB_1->clear();
    ui->lrcLB_2->clear();
    ui->lrcLB_3->clear();
    ui->lrcLB_4->clear();
    ui->lrcLB_5->clear();
    ui->lrcLB_6->clear();
    ui->lrcLB_7->clear();
}

void MainWindow::on_showPlayList_clicked(const QModelIndex &index)
{
    playIndex = ui->showPlayList->currentRow();
}

void MainWindow::on_preSongBtn_2_clicked()
{
    QString fileNameDir = "../mp3";
    QDir dir(fileNameDir);
    QStringList formatList;
    //过滤文件的格式
    formatList << "*.mp3" << "*.mp4" << "*.wma";
    //文件信息列表
    QFileInfoList infoList;
    //按照格式过滤文件,选择合适格式的文件
    infoList = dir.entryInfoList(formatList);
    if(infoList.isEmpty()) return;
    QIcon musicMap(QPixmap(":/player/logo/音乐.png"));
    for(int i = 0;i < infoList.count(); i++)
    {
        //需要检测是否重复
        if(playListString.contains(infoList[i].filePath(),Qt::CaseSensitive))
            continue;
        playListString << infoList[i].filePath();
        QListWidgetItem *songNameList =
                new QListWidgetItem(musicMap,infoList[i].fileName());
        songNameList->setSizeHint(QSize(400,40));
        ui->showPlayList->addItem(songNameList);
    }
    ui->showPlayList->setCurrentRow(playIndex);
    ui->showPlayListBtn->click();
    isReady = true;
}

void MainWindow::on_exitBtn_clicked()
{
    this->close();
}

