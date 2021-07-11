#ifndef BRUYNDONCKX_HPP
#define BRUYNDONCKX_HPP

#include <QObject>
#include <QDataStream>
#include <QRandomGenerator>

#include <random>

#include "bits.hpp"
#include "abstractencoder.hpp"

namespace Stg
{
    class Langelaar : public QObject, public AbstractEncoder
    {
        Q_OBJECT
        Q_INTERFACES(Stg::AbstractEncoder)

        bool _mask[8][8];

    public:
        explicit Langelaar(QObject *parent = nullptr);
        ~Langelaar() override = default;

        bool encode(QString data, QByteArray &container) override;

        QByteArray decode(const QByteArray &container) override;
    };

} // namespace Stg

#endif //BRUYNDONCKX_HPP
