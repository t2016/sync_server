#include "repository.h"

Repository::Repository()
{

}

Repository::Repository(QString pname, QString ppath)
{
    this->name = pname;
    this->path = ppath;
}

void Repository::init()
{
    QDir dir(this->path);
    if (!dir.exists()) {
        dir.mkpath(this->path);
    }
}

QDir Repository::getPath()
{
    return QDir(this->path);
}

QString Repository::getPathQString()
{
    return this->path;
}

qint64 Repository::getLatestObjectID()
{
    QDir dir(this->path);
    dir.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    QStringList dirList = dir.entryList();
    QList<qint64> intList;
    for (int i=0; i<dirList.count(); i++) {
        QString e = dirList[i];
        bool ok;
        qint64 num = e.toLongLong(&ok, 10);
        if (ok) {
            intList.append(num);
        }
    }
    qSort(intList.begin(), intList.end());
    if (intList.size() > 0) {
        return intList.last();
    }
    else {
        return -1;
    }
}

QStringList Repository::getObjects()
{
    QDir dir(this->path);
    dir.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    QStringList dirList = dir.entryList();
    return dirList;
}

void Repository::recoveryFileInTemp()
{
    QStringList dirs = getObjects();
    for (int i=0; i<dirs.size(); i++) {
        qWarning() << "Object: " << dirs[i];
    }

/*
    QByteArray ibuffer;
    for (int i=0; i<100; i++)
    {

        QFile source("/opt/out/"+QString::number(i)+".bin");
        source.open(QIODevice::ReadOnly);
        QByteArray buffer;
        int chunksize = this->BLOCKSIZE;
        while ( !(buffer = source.read(chunksize)).isEmpty() ) {
            ibuffer.append(buffer);
        }
        source.close();
    }
    QFile dest("/opt/out/TEMP");
    dest.open(QIODevice::WriteOnly);
    dest.write(ibuffer);
    dest.close();
*/

}
