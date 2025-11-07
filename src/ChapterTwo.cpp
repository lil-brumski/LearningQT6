#include "ChapterTwo.hpp"

namespace ChapterTwo {
	Test::Test(QObject* parent)
		: QObject(parent)
	{
	}

	Test::~Test()
	{
	}

	void Test::doStuff() {
		qInfo() << "Hey, Mr. Tamaratare";
		emit close();
	}


}