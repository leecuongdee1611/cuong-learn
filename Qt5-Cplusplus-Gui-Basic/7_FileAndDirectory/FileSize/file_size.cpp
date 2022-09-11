/*
    QDir, QFile, QFileInfo
*/

#include <QTextStream>
#include <QFileInfo>

int main(int argc, char *argv[])
{
    QTextStream out{stdout};
    if (argc != 2)
    {
        qWarning("Can not read file name");
        return 1;
    }

    QString filename = argv[1];
    QFile f{filename};
    if (!f.exists())
    {
        qWarning("The file does not exist");
        return 1;
    }

    QFileInfo fileinfo{filename};
    qint64 size = fileinfo.size();
    out << "The " << filename << " have size is " << size << " bytes" << endl;

    return 0;
}
