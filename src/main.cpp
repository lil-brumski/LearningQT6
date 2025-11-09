#include <ChapterOne.hpp>
#include <ChapterTwo.hpp>
#include <ChapterThree.hpp>
#include <QTimer>
#include <QScopedPointer>
#include <QDate>
#include <QSysInfo>
#include <QStorageInfo>
#include <QDir>
#include <QFileInfo>
#include <QFileInfoList>
#include <cmath>

using namespace ChapterTwo;

void funcOne(QCoreApplication& app);
QList<ChapterThree*> funcTwo();
void displayFuncTwo(QList<ChapterThree*>& obj);
void funcTwoMain();
void testingScopePtr(QCoreApplication& app);
void workingWithQString(QCoreApplication& app);
void workingWithQDebug(QCoreApplication& app);
void workingWithQStorageInfo();
void workingWithQDir(QString path, bool rec = false);

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    //funcOne(app);
    //funcTwoMain()
    //testingScopePtr(app);
    //workingWithQString(app);
    //workingWithQDebug(app);
    workingWithQDir("C:/Users/HP/Desktop");

    QTimer timer;
    timer.singleShot(3000, &app, &QCoreApplication::quit);
    return app.exec();
}

void workingWithQDir(QString path, bool rec) {
    qInfo() << QDir::currentPath();
    QDir dir(path);

    if (dir.exists()) qInfo() << "Path exists!";
    else {
        qWarning() << "Path does not exist lil bro";
        return;
    } 

    QFileInfoList listof = dir.entryInfoList(QDir::Filter::NoDotAndDotDot | QDir::AllEntries);
    for (QFileInfo& aa : listof) {
        qInfo() << "File: " << aa.absoluteFilePath();
        qInfo() << "File creation time: " << aa.birthTime().toString();
        qInfo() << "File size: " << aa.size() / 1024 / 1024 << "MB";

        QString type = (aa.isDir()) ? "Folder" : "File";
        qInfo() << type;
        if (type == "Folder") rec = true;

        if (rec && aa.isDir()) workingWithQDir(aa.absoluteFilePath());
    }
    //qInfo() << "HI";

}

void workingWithQStorageInfo() {
#if defined(Q_OS_WIN)
    qInfo() << QSysInfo::kernelType();
    qInfo() << QSysInfo::prettyProductName();

    QStorageInfo dev = QStorageInfo::root();
    qInfo() << "Device name: " << dev.name();
    qInfo() << "Device root path: " << dev.rootPath();

    for (auto& s : dev.mountedVolumes()) {
        qInfo() << "Mounted devices: " << s;//dev.mountedVolumes();
    }

    qInfo() << "Device filesystem type: " << dev.fileSystemType();
    qInfo() << "Device total space: " << dev.bytesTotal() / std::pow(1024, 3) << "GB";
    qInfo() << "Device free space: " << dev.bytesAvailable() / std::pow(1024, 3) << "GB";
#elif defined(Q_OS_ANDROID)
    qInfo() << QSysInfo::
#endif
}

void workingWithQDebug(QCoreApplication& app) {
    qInfo() << "Date: " << QDate::currentDate();
    QTimer timer;
    timer.singleShot(3000, &app, &QCoreApplication::quit);
}

void workingWithQString(QCoreApplication& app) {
    QString name;
    name = "David Tamaratare Oghenebrume\r\nBrumski";
    qInfo() << "Hi, " << name;
    /*for (const auto& c : name) {
        qInfo() << c;
    }*/
    /*qInfo() << name.compare("david");
    qInfo() << name.startsWith('d', Qt::CaseInsensitive);
    qInfo() << name.startsWith('d', Qt::CaseSensitive);
    qInfo() << name.indexOf("David");*/

    QStringList aaa = name.split("\n");
    Q_FOREACH(QString q, aaa) {
        qInfo() << "item: " << q.trimmed();
    }

    int me = 234;
    int maxi = 546;
    QString stat = QString("S/N %1 of %2").arg(me).arg(maxi);
    qInfo() << stat;

    QTimer timer;
    timer.singleShot(3000, &app, &QCoreApplication::quit);
}

void testingScopePtr(QCoreApplication& app) {
    QScopedPointer<ChapterThree> sPtr(new ChapterThree());
    sPtr->message("Hey there, how are you doing?");
    sPtr->setObjectName("Brumski");
    sPtr->setParent(&app);
}

void funcTwoMain() {
    QList<ChapterThree*> list = funcTwo();
    displayFuncTwo(list);
    qDeleteAll(list);
    list.clear();
}

void displayFuncTwo(QList<ChapterThree*>& obj) {
    Q_FOREACH(ChapterThree * cp3, obj) {
        qInfo() << cp3;
    }
}

QList<ChapterThree*> funcTwo() {
    QList<ChapterThree*> list;
    for (int x = 0; x < 10; x++) {
        list.append(new ChapterThree());
        list.last()->setObjectName("Chap " + QString::number(x));
    }
    return list;
}

void funcOne(QCoreApplication& app) {
    ChapterThree* cp3 = new ChapterThree();
    cp3->setObjectName("CP3");
    cp3->setParent(&app);

    ChapterThree* test = new ChapterThree();
    test->setObjectName("TEST");
    test->setParent(cp3);

    QTimer timer;
    timer.singleShot(3000, &app, &QCoreApplication::quit);
}


