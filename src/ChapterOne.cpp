#include <ChapterOne.hpp>

using namespace std::chrono_literals;

namespace ChapterOne {
    void cppWay() {
        std::string userName;
        std::cout << "Please enter your name." << std::endl;
        std::this_thread::sleep_for(1s);
        std::cout << "My name is: ";
        std::getline(std::cin >> std::ws, userName);
        std::cout << "Hi, " << userName << "!" << std::endl;
    }

    void qtWay() {
        QTextStream qin(stdin);
        QTextStream qout(stdout);

        qout << "Please enter your name.\n";
        qout.flush();

        qout << "My name is: ";
        qout.flush();

        std::this_thread::sleep_for(1s);

        QString userName = qin.readLine();
        qout << "Hi, " << userName << "!\n";
        qout.flush();
    }

    void mixedWay() {
        QTextStream qin(stdin);

        qInfo() << "Please enter your name.";
        std::this_thread::sleep_for(1s);
        qInfo() << "My name is: ";
        QString userName = qin.readLine();
        qInfo() << "Hi, " << userName << "!";
    }
}