#include <ChapterOne.hpp>
#include <ChapterTwo.hpp>
#include <ChapterThree.hpp>
#include <QTimer>
#include <memory>

using namespace ChapterTwo;

void func(Test &var) {
    qInfo() << &var;
}

void func(Test* var) {
    qInfo() << var;
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    //ChapterOne::cppWay();
    //ChapterOne::qtWay();
    //ChapterOne::mixedWay();

    QTimer timer;
    timer.singleShot(3000, &app, &QCoreApplication::quit);
    //test.setObjectName("Brumski");
    //test.setParent(&app);
    std::unique_ptr<ChapterThree> cp3(new ChapterThree(&app));
    cp3->setObjectName("CP3");
    //cp3->setParent(&app);

    /*func(test);
    func(&test);*/
    std::unique_ptr<ChapterThree> test(new ChapterThree());
    test->setObjectName("TEST");
    test->setParent(cp3.get());
    //test.setParent(&cp3);
    //QObject::connect(&test, &Test::close, &app, &QCoreApplication::quit, Qt::QueuedConnection);

    //test.doStuff();
    return app.exec();
}


