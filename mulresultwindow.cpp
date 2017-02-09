#include "mulresultwindow.h"
#include "mkcalcexqt_common.h"
#include <QTextEdit>
#include <QFont>
#include <QString>
#include <QtGlobal>
#include <QTime>
#include <cmath>


//
// Constructor
//
// a: number of digits for 1st number
// b: number of digits for 2nd number
// c: number of decimal places in 1st number
// d: number of decimal places in 2nd number
// l: number of items
//
MulResultWindow::MulResultWindow(int a, int b, int c, int d, int l)
{
    // Set Window Size
    QString bt;
    if ((a + b + c + d) == 2) {
        this->resize(400, 600);
        bt = "\t";
    } else if ((a + b + c + d) < 9) {
        this->resize(500, 600);
        bt = "\t\t";
    } else if ((a + b + c + d) < 14) {
        this->resize(600, 600);
        bt = "\t\t\t";
    } else if (((a + b + c + d) == 18) && ((c + d) != 0)) {
        this->resize(900, 600);
        bt = "\t\t\t\t\t";
    } else {
        this->resize(800, 600);
        bt = "\t\t\t\t";
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

    QString str;
    QString sx, sy, sr;
    quint32* r = new quint32[3];
    for (int i = 0; i < l; i++) {
        mkitem(a + c, b + d, r);
        sx.setNum(r[0]);
        sy.setNum(r[1]);
        sr.setNum(r[2]);
        str = QString("(%1)\t").arg(i + 1);
        if (c != 0) {
            sx.insert(sx.length() - c, QString("."));
        }
        str.append(sx);
        str.append(QString(" "));
        str.append(QString::fromLocal8Bit("×"));
        str.append(QString(" "));
        if (d != 0) {
            sy.insert(sy.length() - d, QString("."));
        }
        str.append(sy);
        str.append(QString("\t= "));
        if ((c + d) != 0) {
            sr.insert(sr.length() - c - d, QString("."));
        }
        str.append(sr);
        this->append(str);
    }
}


//
// private functions
//

//
// Make one item based on paramters
//
// a: number of digits for 1st number
// b: number of digits for 2nd number
// re: pointer to result array
//     (re[0] - 1st number, re[1] - 2nd number, re[3] - product
//
void MulResultWindow::mkitem(int a, int b, quint32* re)
{
    quint32 x, y;

    x = qrand32() % (ipow10(a) - ipow10(a - 1)) + ipow10(a - 1);
    if ((x % 10) == 0) {
        x = x + qrand32() % 8 + 1;
    }
    y = qrand32() % (ipow10(b) - ipow10(b - 1)) + ipow10(b - 1);
    if ((y % 10) == 0) {
        y = y + qrand32() % 8 + 1;
    }
    re[0] = x;
    re[1] = y;
    re[2] = x * y;
}
