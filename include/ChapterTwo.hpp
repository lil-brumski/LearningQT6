#pragma once

#include <QObject>
#include <QDebug>

namespace ChapterTwo {
	class Test : public QObject {
		Q_OBJECT
	public:
		Test() = default;
		explicit Test(QObject* parent);
		~Test();
	signals:
		void close();
	public slots:
		void doStuff();
	};


}