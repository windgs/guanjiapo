#include "saftui.h"
#include <QtGui/QApplication>
#include <QTextCodec>
#include <QFile>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//QTextCodec::setCodecForCStrings(QTextCodec::codecForName("gb18030"));
	QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
  SaftUI w;
  //w.SetPluginPath(qApp->applicationDirPath());
	w.show();
	return a.exec();
}
