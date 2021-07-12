#ifndef LANGELAAR_HPP
#define LANGELAAR_HPP

#include <QObject>
#include <QDataStream>
#include <QRandomGenerator>

#include <random>

#include "bits.hpp"
#include "abstractencoder.hpp"

//pre declare for unit testing
class MaskTestCase;

namespace Stg
{
    class Langelaar : public QObject, public AbstractEncoder
    {
        friend MaskTestCase;

        Q_OBJECT
        Q_INTERFACES(Stg::AbstractEncoder)

    private:
        bool _mask[8][8];

    private:
        /**
         * Call rand() `size` times
         *
         * @param p Pointer to container.
         * @param size Size of container.
         */
        static void fill_v1(bool *p, size_t size);

        /**
         * Call rand() `size` / sizeof(size_t) times
         *
         * @param p Pointer to container.
         * @param size Size of container.
         */
        static void fill_v2(bool *p, size_t size);

        /**
         * Call rand() once
         *
         * @param p Pointer to container.
         * @param size Size of container.
         */
        static void fill_v3(bool *p, size_t size);

        /**
         * Generate byteMask
         * @param shift Shift times.
         * @return 0x0101010101010101 by default
         */
        constexpr static size_t byteMask(size_t shift = 0);

    public:
        explicit Langelaar(QObject *parent = nullptr);
        ~Langelaar() override = default;

        bool encode(QString data, QByteArray &container) override;

        QByteArray decode(const QByteArray &container) override;
    };

} // namespace Stg

#endif //LANGELAAR_HPP
