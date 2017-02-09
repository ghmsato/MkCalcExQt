#ifndef DIVRESULTWINDOW_H
#define DIVRESULTWINDOW_H

#include <QTextEdit>

class DivResultWindow : public QTextEdit
{
    Q_OBJECT

public:
    explicit DivResultWindow(QWidget *parent = 0);
    explicit DivResultWindow(int a, int b, int l, int v, int f);
    ~DivResultWindow();

private:
    void randsort_f(int l, int v, int* fa);
    quint32 qrand32(void);
    quint32 ipow10(int a);
    void mkitem(int a, int b, int f, quint32* re);
};

#endif // DIVRESULTWINDOW_H
