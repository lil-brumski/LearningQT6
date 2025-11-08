#include <ChapterOne.hpp>
#include <ChapterTwo.hpp>
#include <ChapterThree.hpp>
#include <QTimer>
#include <QScopedPointer>

using namespace ChapterTwo;

void funcOne(QCoreApplication& app);
QList<ChapterThree*> funcTwo();
void displayFuncTwo(QList<ChapterThree*>& obj);
void funcTwoMain();
void testingScopePtr(QCoreApplication& app);

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    //funcOne(app);
    //funcTwoMain()
    testingScopePtr(app);

    return app.exec();
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


