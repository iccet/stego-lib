#include <QtTest>

#include "langelaar.hpp"

using namespace Stg;

class LangelaarEncodingTestCase : public QObject
{
    Q_OBJECT

    Langelaar *_encoder;

public:
    LangelaarEncodingTestCase() = default;
    ~LangelaarEncodingTestCase() = default;

private slots:
    void initTestCase();
    void initTestCase_data();

    void encodingTestCase_data();
    void encodingTestCase();

    void cleanupTestCase();
};

void LangelaarEncodingTestCase::initTestCase_data() {
    QTest::addColumn<QString>("data");

    QTest::newRow("Small string") << "test";
    QTest::newRow("Single char") << "p";
    QTest::newRow("Phrase") << "Hello world";
}

void LangelaarEncodingTestCase::initTestCase() {
    _encoder = new Langelaar(this);
}

void LangelaarEncodingTestCase::encodingTestCase_data()
{
    QTest::addColumn<QByteArray>("container");

    QTest::newRow("Empty container") << QByteArray(1000, 0);
    QTest::newRow("Filled container") << QByteArray(1000, 0xf1);
    QTest::newRow("Random byte container") << QByteArray(1000, QRandomGenerator::global()->generate());
}

void LangelaarEncodingTestCase::encodingTestCase()
{
    QFETCH_GLOBAL(QString, data);
    QFETCH(QByteArray, container);
    QVERIFY(_encoder->encode(data, container));
    QVERIFY(container.count());
}

void LangelaarEncodingTestCase::cleanupTestCase()
{
    delete _encoder;
}

QTEST_APPLESS_MAIN(LangelaarEncodingTestCase)

#include "tst_langelaarencodingtestcase.moc"
