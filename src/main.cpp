#include <ChapterOne.hpp>
#include <ChapterTwo.hpp>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    //ChapterOne::cppWay();
    //ChapterOne::qtWay();
    //ChapterOne::mixedWay();
    using namespace ChapterTwo;

    Test test;

    QObject::connect(&test, &Test::close, &app, &QCoreApplication::quit, Qt::QueuedConnection);

    test.doStuff();
    return app.exec();
}


