#include <QtTest>

#include "langelaar.hpp"

using namespace Stg;

class MaskTestCase : public QObject
{
    Q_OBJECT

    bool _array[8][8] { false };

private slots:
    void fill_v1TestCase();
    void fill_v2TestCase();
    void fill_v3TestCase();
};

void MaskTestCase::fill_v1TestCase()
{
    QBENCHMARK
    {
        Langelaar::fill_v1((bool *)_array, sizeof(_array));
    }
}

void MaskTestCase::fill_v2TestCase()
{
    QBENCHMARK
    {
        Langelaar::fill_v2((bool *)_array, sizeof(_array));
    }
}

void MaskTestCase::fill_v3TestCase()
{
    QBENCHMARK
    {
        Langelaar::fill_v3((bool *)_array, sizeof(_array));
    }
}

QTEST_APPLESS_MAIN(MaskTestCase)

#include "tst_masktestcase.moc"
