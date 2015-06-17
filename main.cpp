#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>
#include <QDateTime>
#include <QVariant>
#include <errno.h>

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
	QDateTime startTime = QDateTime::currentDateTime();
	qDebug("Time for writing");
	qDebug() << startTime;
	while(num != 100000000)
	{
		stream << letter;
		num++;
	}
	file.close();
	QDateTime finishTime = QDateTime::currentDateTime();
	qDebug() << finishTime;
	double num1,num2,num3;
	num1=startTime.toTime_t();
	num2=finishTime.toTime_t();
	num3=num2-num1;
	qDebug()<<"Seconds : "<<num3;
	double res=100000000/num3;
	double mb=res/104850;
	qDebug()<<"megabayt : "<<mb;

	QFile file2("hardisk.dat");
	if (!file2.open(QIODevice::ReadOnly | QIODevice::Text))
	{
		return -1;
	}
	QDataStream stream2(&file2);
	stream2.setByteOrder(QDataStream::LittleEndian);

	QChar letter2;
	startTime = QDateTime::currentDateTime();
	qDebug("Time for reading");
	qDebug() << startTime;
	while(!file2.atEnd())
	{
		stream2>>letter2;
		//qDebug()<<letter2;
	}
	finishTime = QDateTime::currentDateTime();
	qDebug() << finishTime;
	num1=startTime.toTime_t();
	num2=finishTime.toTime_t();
	num3=num2-num1;
	qDebug()<<"Seconds : "<<num3;
	res=100000000/num3;
	mb=res/104850;
	qDebug()<<"megabayt : "<<mb;
	file2.close();
	return 0;
}
