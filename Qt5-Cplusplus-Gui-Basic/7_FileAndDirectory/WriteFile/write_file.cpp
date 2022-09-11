/*
    If file exist -> delete all data and write new data
    If file not exist -> create new file and write data
*/
#include <QTextStream>
#include <QFile>

int main(void)
{
    QTextStream out{stdout};

    QString filename = "distros.txt";
    QFile f{filename};

    if (f.open(QIODevice::WriteOnly))
    {
        QTextStream w{&f}; 
        w << "Xununtu" << endl;
        w << "Arch" << endl;
        w << "Debian" << endl;
        w << "Redhat" << endl;
        w << "Slackware" << endl;
    }
    else
    {
        qWarning("Could not open file");
    }

    return 0;
}