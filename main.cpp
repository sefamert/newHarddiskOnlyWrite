#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QVariant>
#include <errno.h>
#include <QTimer>
#include <QElapsedTimer>

#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	QFile file("hardisk.dat");
	file.open(QIODevice::WriteOnly);
	QDataStream stream(&file);
	stream.setByteOrder(QDataStream::LittleEndian);
	QChar letter = 'a';
	int num=0;
	QElapsedTimer timer;
	qDebug("Time for writing");
	timer.start();
	while(num != 10000000)
	{
		stream << letter;
		num++;
	}


	double num1=timer.elapsed();
	qDebug()<<"MiliSeconds : "<<num1;
	double res=10000000000/num1;
	double mb=res/1048576;
	qDebug()<<"megabayt : "<<mb;
	file.close();

	QFile file2("hardisk.dat");
	if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return -1;
	}
	QDataStream stream2(&file2);
	stream2.setByteOrder(QDataStream::LittleEndian);

	QChar letter2;

	qDebug("Time for reading");
	timer.start();
	while(!file2.atEnd())
	{
		stream2>>letter2;
		//qDebug()<<letter2;
	}
	 num1=timer.elapsed();
	qDebug()<<"Seconds : "<<num1;
	res=10000000000/num1;
	mb=res/1048576;
	qDebug()<<"megabayt : "<<mb;
	file2.close();
	return 0;
}
