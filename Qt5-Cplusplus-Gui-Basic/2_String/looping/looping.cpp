#include <QTextStream>

int main(void) {

  QTextStream out(stdout);

  QString str { "There are many stars." };

  for (QChar qc: str) {
    out << qc << " ";
  }

  out << endl;

  for (QChar *it=str.begin(); it!=str.end(); ++it) {
    out << *it << " " ;
  }

  out << endl;

  for (int i = 0; i < str.size(); ++i) {
    out << str.at(i) << " ";
  }

  // Test
  QChar *a=str.begin();
  out << *a << endl;
  out << str.begin() << endl;
  out << str.end() << endl;
  out << a << endl;
  out << &a << endl;
  out << str.end() - str.begin() << endl;

  out << endl;

  return 0;
}
