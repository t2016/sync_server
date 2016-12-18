#ifndef REPOSITORY_H
#define REPOSITORY_H

#include <QString>
#include <QDir>
#include <QtAlgorithms>
#include <QDebug>

class Repository
{
    QString name;
    QString path;

public:

    Repository();
    Repository(QString pname, QString ppath);
    void init();

    QDir getPath();
    QString getPathQString();
    qint64 getLatestObjectID();
    QStringList getObjects();

    void recoveryFileInTemp();
};

#endif // REPOSITORY_H
