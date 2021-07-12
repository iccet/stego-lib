#include <QtTest>

#include <random>

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
    auto container = QByteArray(8 * 8 * 100, 0);

    std::generate(container.begin(), container.end(),
        []() { return QRandomGenerator::global()->generate(); });

    QTest::newRow("Random container") << container;
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
