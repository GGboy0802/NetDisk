#ifndef CKERNEL_H
#define CKERNEL_H
#include"maindialog.h"
#include"packdef.h"
#include <QObject>
#include"logindialog.h"
#include"common.h"
#include"csqlite.h"
#include"playerdialog.h"
//核心处理类
//单例
//1.构造 拷贝构造 析构 私有化 2.提供静态的公有的获取对象的方法

//协议映射表


//类成员函数指针
class CKernel;
typedef void (CKernel::*PFUN)(  unsigned int lSendIP , char* buf , int nlen );


//#include"INetMediator.h"
class INetMediator;

//#define USE_SERVER  1

class CKernel : public QObject
{
    Q_OBJECT
private:
    explicit CKernel(QObject *parent = nullptr);
    explicit CKernel(const CKernel & kernel){}
    ~CKernel(){}

    void loadIniFile();
    void setNetPackMap();
    void setSystemPath();
signals:
    void SIG_updateUploadFileProgress(int timestamp,int pos);
    void SIG_updateDownloadFileProgress(int timestamp,int pos);
public:
    static CKernel* GetInstance()
    {
        static CKernel kernel;
        return &kernel;
    }
private slots:
    //普通槽函数
    void slot_destory();
    void slot_registerCommit(QString tel,QString password,QString name);
    void slot_loginCommit(QString tel,QString password);

    void slot_uploadFile(QString path,QString dir);
    void slot_uploadFolder(QString path,QString dir);
    void slot_getCurDirFileList();

    //什么文件id，什么目录下的文件 下载
    void slot_downloadFile(int fileid,QString dir);
    //什么文件id，什么目录下的文件夹 下载
    void slot_downloadFolder(int fileid,QString dir);

    //什么路径下创建什么名字的文件夹
    void slot_addFolder( QString name,QString dir);
    //改变路径
    void slot_changeDir(QString dir);
    //分享 什么目录下的文件列表
    void slot_shareFile(QVector<int> fileidArray,QString dir);
    //获取个人所有共享
    void slot_getMyShare();
    //获取共享文件
    void slot_getShareByLink(int code,QString dir);
    //发送删除文件请求
    void slot_deleteFile(QVector<int> fileidArray,QString dir);
    //发送上传暂停/开始
    void slot_setUploadPause(int timestamp,int isPause);
    //发送下载暂停/开始
    void slot_setDownloadPause(int timestamp,int isPause);

    //播放视频
    void slot_playVideo(QString fileName,QString dir);

    //网络响应槽函数
    void slot_dealClientData(  unsigned int lSendIP , char* buf , int nlen );
    void slot_dealLoginRs(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealRegisterRs(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealUploadFileRs(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealFileContentRs(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealGetFileInfoRs(unsigned int lSendIP, char *buf, int nlen);
    void slot_dealFileHeaderRq(unsigned int lSendIP, char *buf, int nlen);

    void slot_dealFileContentRq(unsigned int lSendIP, char *buf, int nlen);

    void slot_dealAddFolderRs(unsigned int lSendIP, char *buf, int nlen);

    void slot_dealQuickUploadRs(unsigned int lSendIP, char *buf, int nlen);

    void slot_dealShareFileRs(unsigned int lSendIP, char *buf, int nlen);

    void slot_dealMyShareRs(unsigned int lSendIP, char *buf, int nlen);

    void slot_dealGetShareRs(unsigned int lSendIP, char *buf, int nlen);

    void slot_dealFolderHeadRq(unsigned int lSendIP, char *buf, int nlen);

    void slot_dealDeleteFileRs(unsigned int lSendIP, char *buf, int nlen);

    void slot_dealContinueUploadRs(unsigned int lSendIP, char *buf, int nlen);

    void GetUploadPos(FileInfo & info);

    void slot_dealGetUpLoadPosRs(unsigned int lSendIP, char *buf, int nlen);
#ifdef USE_SERVER
    void slot_dealServerData(  unsigned int lSendIP , char* buf , int nlen );
#endif
private:

    void SendData(char * buf,int len);
private:
    MainDialog* m_mainDialog;
    LoginDialog* m_loginDialog;
    PlayerDialog* m_playerDialog;
    QString m_ip;
    QString m_port;

    QString m_name;
    int m_id;
    QString m_curDir;//网盘当前目录
    QString m_sysPath;//默认存储的系统路径(绝对路径)exe同级下 NetDisk文件夹下



    INetMediator* m_tcpClient;

#ifdef USE_SERVER
    INetMediator* m_tcpServer;
#endif

    //key 时间戳 hhmmsszzz
    std::map<int,FileInfo>m_mapTimestampToFileInfo;

    PFUN m_netPackMap[_DEF_PACK_COUNT];

    //退出标志
    bool m_quit;

    CSqlite* m_sql;

private:
    //登入之后，初始化数据
    void InitDatabase(int id);
    //缓存上传的任务
    void slot_writeUploadTask(FileInfo& info);
    //缓存下载的任务
    void slot_writeDownloadTask(FileInfo& info);
    //完成任务，删除上传记录
    void slot_deleteUploadTask(FileInfo& info);
    //完成任务，删除下载记录
    void slot_deleteDownloadTask(FileInfo& info);
    //加载上传任务
    void slot_getUploadTask(QList<FileInfo>&infoList);
    //加载下载任务
    void slot_getDownloadTask(QList<FileInfo>&infoList);
};

#endif // CKERNEL_H
