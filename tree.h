#ifndef TREE_H
#define TREE_H

#include <QDir>
#include <QDebug>
#include <QDataStream>

//#include <iostream>
//using namespace std;

class Tree
{
    QStringList fList, dList;
public:
    Tree();
    void scanDir(QDir dir);
    void printfList();
    void printdList();
    QStringList getFileList();
    QStringList getDirList();

};

#endif // TREE_H
