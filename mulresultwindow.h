#ifndef MULRESULTWINDOW_H
#define MULRESULTWINDOW_H

#include <QTextEdit>

class MulResultWindow : public QTextEdit
{
    Q_OBJECT

public:
    MulResultWindow(int a, int b, int c, int d, int l);

private:
    void mkitem(int a, int b, quint32* re);
};

#endif // MULRESULTWINDOW_H
