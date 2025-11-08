#include "ChapterThree.hpp"

ChapterThree::ChapterThree(QObject *parent)
	: QObject(parent)
{
	qInfo() << this << " constructed " << parent;
}

ChapterThree::~ChapterThree()
{
	Q_FOREACH(QObject* child, children()) {
		qInfo() << this << " destroyed child" << child;
	}
	qInfo() << this << " destroyed " << parent();
}

