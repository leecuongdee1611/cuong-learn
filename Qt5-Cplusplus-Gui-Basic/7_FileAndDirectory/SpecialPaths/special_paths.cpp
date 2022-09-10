#include <QTextStream>
#include <QDir>

int main(void)
{
    QTextStream out{stdout};

    out << "Current Path: " << QDir::currentPath() << endl;
    out << "Home Path: " << QDir::homePath() << endl;
    out << "Temporary Path: " << QDir::tempPath() << endl;
    out << "Rooth Path: " << QDir::rootPath() << endl;

    return 0;
}