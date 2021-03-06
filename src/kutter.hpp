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
#include "cross.hpp"

namespace Stg
{
    class Kutter : public QObject, public AbstractEncoder
    {
        Q_OBJECT
        Q_INTERFACES(Stg::AbstractEncoder)

    public:
        using Base = AbstractEncoder;

    private:
        const QRandomGenerator *_generator;
        const double _q;
        const int _c;

    private:
        QRgb delta(QColor color);

    public:
        explicit Kutter(QObject *parent = nullptr);

        bool encode(QString data, QByteArray &container) override;

        QByteArray decode(const QByteArray &_init) override;
        QByteArray decode(const QByteArray &container, int h, int w);


        QByteArray decode(const uchar *container, int size, int h, int w)
        {
            QByteArray bytes = QByteArray::fromRawData((const char*)container, size);
            return decode(bytes, h, w);
        }
    };

} // namespace Stg

#endif // KUTTER_HPP
