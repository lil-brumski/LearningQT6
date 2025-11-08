#include "ChapterThree.hpp"

ChapterThree::ChapterThree(QObject *parent)
	: QObject(parent)
{
	qInfo() << this << " constructed " << parent;
}

void ChapterThree::message(QString var) {
	qInfo() << this << " " << var;
}

ChapterThree::~ChapterThree()
{
	Q_FOREACH(QObject* child, children()) {
		qInfo() << this << " destroyed child" << child;
	}
	qInfo() << this << " destroyed " << parent();
}

