#include "divresultwindow.h"
#include <QTextEdit>
#include <QFont>
#include <QString>
#include <QtGlobal>
#include <QTime>
#include <cmath>

DivResultWindow::DivResultWindow(QWidget *parnet)
{
}

DivResultWindow::~DivResultWindow()
{
}

DivResultWindow::DivResultWindow(int a, int b, int l, int v, int f)
{
    // Set Window Size
    QString bt;
    if ((a + b) == 2) {
        this->resize(400, 600);
        bt = "\t";
    } else if ((a + b) < 9) {
        this->resize(500, 600);
        bt = "\t\t";
    } else if ((a + b) < 14) {
        this->resize(600, 600);
        bt = "\t\t\t";
    } else {
        this->resize(600, 600);
        bt = "\t\t\t\t";
    }
    if (f != 0) {
        this->resize(this->width() + 100, 600);
    }

    // Set Window Title
    QString string = QString::fromLocal8Bit("作成された問題");
    this->setWindowTitle(string);

    // Set Font
    QFont wf;
    wf.setFamily("Meiryo UI");
    wf.setPointSize(12);
    this->setFont(wf);

    // Put Contents
    QString hl1 = QString::fromLocal8Bit("番号\t問題");
    QString hl2 = QString::fromLocal8Bit("答");
    hl1.append(bt);
    hl1.append(hl2);
    this->append(hl1);

    int* far = new int[l];
    if (f == 2) {
        randsort_f(l, v, far);
    } else {
        for (int i = 0; i < l; i++) {
            far[i] = f;
        }
    }

    QString str;
    quint32* r = new quint32[4];
    for (int i = 0; i < l; i++) {
        mkitem(a, b, far[i], r);
        str = QString("(%1)\t%2 ").arg(i + 1).arg(r[0]);
        str.append(QString::fromLocal8Bit("÷"));
        str.append(QString(" %1\t= %2").arg(r[1]).arg(r[2]));
        if (far[i] == 1) {
            str.append(QString("\t... %1").arg(r[3]));
        }
        this->append(str);
    }
}


//
// private functions
//
void DivResultWindow::randsort_f(int l, int v, int* fa)
{
    fa[0] = 1;
    for (int i = 1; i < l; i++) {
        int j = qrand() % i;
        if (j != i) {
           fa[i] = fa[j];
        }
        fa[j] = (i < v)? 1 : 0;
    }
}

quint32 DivResultWindow::qrand32(void)
{
    return (quint32)qrand() | ((quint32)qrand() << 15);
}

quint32 DivResultWindow::ipow10(int a)
{
    if (a == 0) {
        return 1;
    } else {
        quint32 r = 10;
        for (int i = 1; i < a; i++) {
            r = r * 10;
        }
        return r;
    }
}

void DivResultWindow::mkitem(int a, int b, int f, quint32* re)
{
    quint32 x, y, r, s;

    x = qrand32() % (ipow10(a) - ipow10(a - 1)) + ipow10(a - 1);
    if ((b == 1) && (f == 1)) {
        y = qrand32() % 8 + 2;
    } else {
        y = qrand32() % (ipow10(b) - ipow10(b - 1)) + ipow10(b - 1);
    }

    if (f == 0) {
        r = x / y;
        if ((y * r) < ipow10(a - 1)) {
            r = r + 1;
        }
        x = y * r;
        s = 0;
    } else {
        r = x / y;
        s = x - (y * r);
        if (s == 0) {
            int high = qMin(y, ipow10(a) - (y * r));
            if (high < 3) {
                s = 1;
            } else {
                s = qrand32() % (high - 2) + 1;
            }
            x = y * r + s;
        }
    }
    re[0] = x;
    re[1] = y;
    re[2] = r;
    re[3] = s;
}
