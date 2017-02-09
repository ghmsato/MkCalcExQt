#ifndef DIVRESULTWINDOW_H
#define DIVRESULTWINDOW_H

#include <QTextEdit>

class DivResultWindow : public QTextEdit
{
    Q_OBJECT

public:
    DivResultWindow(int a, int b, int l, int v, int f);

private:
    void randsort_f(int l, int v, int* fa);
    void mkitem(int a, int b, int f, quint32* re);
};

#endif // DIVRESULTWINDOW_H
