#ifndef CXXFILE_H
#define CXXFILE_H

#include <QString>
#include <QFileInfo>
#include <QDebug>
#include <QByteArray>
#include <QCryptographicHash>

#include <repository.h>

class CXXFile
{
    QString fileName;
    QString filePath;
    QString fragPath;
    QByteArray checksum;
    QByteArrayList fragChecksums;

    const int BLOCKSIZE = 4194304;

public:

    CXXFile();
    CXXFile(QString filename, QString filepath);

    void splitFile(QString repoDir, Repository& repo);
    QString makeDir(QString repoDir, Repository& repo);
    QByteArray getHashOfFile();
    void writeHashToFile(QByteArray hash);
    void writePathToFile(QString path);

};

#endif // CXXFILE_H
