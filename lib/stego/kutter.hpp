#ifndef KUTTER_HPP
#define KUTTER_HPP

#include <QObject>
#include <QDebug>
#include <QRgb>
#include <QColor>
#include <QBitArray>
#include <QRandomGenerator>

#include <type_traits>
#include <random>

#include "abstractencoder.hpp"
#include "bits.hpp"
#include "skip.hpp"

class Kutter : public QObject, public AbstractEncoder
{
    Q_OBJECT
    Q_INTERFACES(AbstractEncoder)

    const QRandomGenerator *_generator;
    const double _q;
    const int _c;

private:
    QRgb delta(QColor color);

public:
    explicit Kutter(QObject *parent = nullptr);

    bool encode(QString data, QByteArray &container) override;
    bool encode(QString data, uchar *container, int size) override;

    QByteArray decode(const uchar *container, int size) override;
    QByteArray decode(const QByteArray &_init) override;
    QByteArray decode(int h, int w, const QByteArray &container);
};

#endif // KUTTER_HPP
