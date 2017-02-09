#include "mkcalcexqt_common.h"
#include <QtGlobal>

//
// Generate 30-bit random number
//
quint32 qrand32()
{
    return (quint32)qrand() | ((quint32)qrand() << 15);
}

//
// Make 10 to the a-th power
//
quint32 ipow10(int a)
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
