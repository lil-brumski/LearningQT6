#pragma once

#include <QObject>
#include <QDebug>
#include <QString>

class ChapterThree  : public QObject
{
	Q_OBJECT

public:
	explicit ChapterThree(QObject *parent);
	ChapterThree() {
		qInfo() << this << " default constructed ";
	}
	void message(QString var);

	~ChapterThree();
};

