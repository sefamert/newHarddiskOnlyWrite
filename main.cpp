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
	QDataStream stream(&file);
	QChar letter = 'a';
	int num = 0;
	QElapsedTimer timer;
	double num1,res,mb;
	int bytes = 10000000;
	file.open(QIODevice::WriteOnly);
	stream.setByteOrder(QDataStream::LittleEndian);

	qDebug("Time for writing");

	timer.start();

	while(num != 10000000)
	{
		stream << letter;
		num++;
	}


	num1 = timer.elapsed();
	qDebug() << "MiliSeconds : "<<num1;
	res = 10000000000/num1;
	mb = res/1048576;
	mb = mb * 2;
	qDebug() << "megabayt : "<<mb;

	file.close();
//--------------------------------------------------------------------------------------------
	qDebug("--------------------------------------------------------------------");
	qDebug("\nÇağlar abi bayadır uğraşıyorum çok farklı kombinasyonlar denedim ama sabah sana gösterdiğim hepsinden daha hızlı çalışıyor.");
	qDebug(" Aşağıda olan senin bugün yap dediğin eğer yanlış bir şey yapmamışsam. Bi bakarsan sevinirim.\n");
	QFile file2("hardisk2.dat");
		num = 0;
		int  Mb=1048576;
		double miliSeconds;

		file2.open(QIODevice::WriteOnly);
		QTextStream out(&file2);

		qDebug("Time for writing");

		timer.start();

		while(num != bytes)
		{
			out << letter;
			num++;
		}

		miliSeconds=timer.elapsed();

		qDebug()<<"MiliSeconds : "<<miliSeconds;
		res = (bytes * 100) / miliSeconds;
		double resMb = res / Mb;
		resMb = resMb * 2;
		qDebug()<<"megabayt : "<<resMb;

		file2.close();
	qDebug("------------------------------------------------------------------------");
//--------------------------------------------------------------------------------------------
	return 0;
}
