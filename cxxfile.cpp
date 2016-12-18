#include "cxxfile.h"

CXXFile::CXXFile()
{

}

CXXFile::CXXFile(QString pfilename, QString pfilepath)
{
    this->fileName = pfilename;
    this->filePath = pfilepath;
}

void CXXFile::splitFile(QString repoDir, Repository& repo)
{
        //QFileInfo finfo(filepath);
        //QString size_str = QString::number(finfo.size());

        QString binPath = makeDir(repoDir, repo);
        this->fragPath = binPath;
        this->fragPath.replace("/binary","");
        QByteArray hash = getHashOfFile();
        writeHashToFile(hash);
        writePathToFile(this->filePath);

        QFile source(this->filePath);
        source.open(QIODevice::ReadOnly);
        QByteArray buffer;

        int id = 0;
        while ( !(buffer = source.read(this->BLOCKSIZE)).isEmpty() ) {
            QFile dest(binPath + "/" + QString::number(id));
            dest.open(QIODevice::WriteOnly);
            dest.write(buffer);
            dest.close();
            id++;
        }
        buffer.clear();
        source.close();
}

QString CXXFile::makeDir(QString repoDir, Repository& repo)
{
    qint64 num = repo.getLatestObjectID() + 1;
    QString binPath = repoDir + "/" + QString::number(num) + "/binary";
    qWarning() << "MKDIR " << binPath;
    QDir dirBinary(binPath);
    if (!dirBinary.exists()) {
        dirBinary.mkpath(binPath);
    }
    return binPath;
}

void CXXFile::writeHashToFile(QByteArray hash)
{
    QFile dest(this->fragPath + "/" + "CHECKSUM");
    dest.open(QIODevice::WriteOnly);
    dest.write(hash);
    dest.close();

}

void CXXFile::writePathToFile(QString path)
{
    QFile dest(this->fragPath + "/" + "PATH");
    dest.open(QIODevice::WriteOnly);
    QTextStream stream( &dest );
    stream << path;
    dest.close();
}

QByteArray CXXFile::getHashOfFile()
{
    QCryptographicHash crypto(QCryptographicHash::Sha1);
    QFile file(this->filePath);
    file.open(QFile::ReadOnly);
    while(!file.atEnd()){
      crypto.addData(file.read(8192));
    }
    QByteArray hash = crypto.result();
    return hash;
}
