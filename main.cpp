#include <QCoreApplication>
#include <tree.h>
#include <repository.h>
#include <cxxfile.h>

const QString STORAGE_DIR = "/root/owss/new";
const QString REPO_DIR = "/backend";

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Repository repo("special", REPO_DIR);
    repo.init();

    Tree tree;
    QDir dir(STORAGE_DIR);
    tree.scanDir(dir);
    //tree.printfList();


    qWarning() << QString::number(repo.getLatestObjectID());
    QStringList files = tree.getFileList();
    for (int i=0; i<files.count(); i++)
    {
        QFile qfile(files[i]);
        CXXFile cxxfile(qfile.fileName(), files[i]);
        cxxfile.splitFile(repo.getPathQString(), repo);

    }

    repo.recoveryFileInTemp();

    return 0;
}
