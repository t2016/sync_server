#include "tree.h"

Tree::Tree()
{

}

void Tree::scanDir(QDir dir)
{
    //dir.setNameFilters(QStringList("*.txt"));
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot | QDir::NoSymLinks);

    //qWarning() << "Scanning: " << dir.path();
    QStringList fileList = dir.entryList();
    for (int i=0; i<fileList.count(); i++)
    {
        fList.append(dir.path()+'/'+fileList[i]);
    }

    dir.setFilter(QDir::AllDirs | QDir::NoDotAndDotDot | QDir::NoSymLinks);
    QStringList dirList = dir.entryList();
    for (int i=0; i<dirList.size(); ++i)
    {
        dList.append(dir.path()+'/'+dirList[i]);
        QString newPath = QString("%1/%2").arg(dir.absolutePath()).arg(dirList.at(i));
        scanDir(QDir(newPath));
    }
}

QStringList Tree::getFileList()
{
    return fList;
}

QStringList Tree::getDirList()
{
    return dList;
}

void Tree::printfList()
{
    for (int i=0; i<fList.count(); i++)
    {
        QFileInfo fi(fList[i]);
        QString size = QString::number(fi.size());
        qWarning() << "Found file: " << fList[i]+' '+size;
    }
}

void Tree::printdList()
{
    for (int i=0; i<dList.count(); i++)
    {
        qWarning() << "Found dir: " << dList[i];
    }
}

