#ifndef MULRESULTWINDOW_H
#define MULRESULTWINDOW_H

#include <QTextEdit>

class MulResultWindow : public QTextEdit
{
    Q_OBJECT

public:
    explicit MulResultWindow(QWidget *parent = 0);
    explicit MulResultWindow(int a, int b, int c, int d, int l);
    ~MulResultWindow();

private:
    quint32 qrand32(void);
    quint32 ipow10(int a);
    void mkitem(int a, int b, quint32* re);
};

#endif // MULRESULTWINDOW_H
