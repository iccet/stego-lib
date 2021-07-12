#include "langelaar.hpp"

namespace Stg
{
    Langelaar::Langelaar(QObject *parent)
    : QObject(parent)
    , _mask{false}
    {
        fill_v3((bool *)_mask, sizeof(_mask));
    }

    QByteArray Langelaar::decode(const QByteArray &container)
    {
        return QByteArray();
    }

    bool Langelaar::encode(QString data, QByteArray &container)
    {

        for (auto & i : _mask) {

            for (bool j : i) {

                qDebug() << j;
            }
        }
        return false;
    }

    void Langelaar::fill_v1(bool *mask, size_t size)
    {
        std::uniform_int_distribution<size_t> distribution (0, 1);
        auto f = [&]() -> bool { return distribution(*QRandomGenerator::global()); };
        std::generate_n((bool*)mask, size, f);
    }

    void Langelaar::fill_v2(bool *p, size_t size)
    {
        auto f = [&]() { return byteMask() & QRandomGenerator::global()->generate64(); };
        std::generate_n((size_t *)p, size / sizeof(size_t), f);
    }

    void Langelaar::fill_v3(bool *p, size_t size)
    {
        bool *i = p;
        size_t bit = QRandomGenerator::global()->generate64();
        while(bit && std::distance(i, p) != size)
        {
            *i++ = bit & 1;
            bit >>= 1;
        }
    }

    constexpr size_t Langelaar::byteMask(size_t shift)
    {
        size_t r = 1;

        for (int i = 0; i < sizeof(size_t); ++i)
        {
            r <<= CHAR_BIT + shift;
            r |= 1;
        }
        return r;
    }

} // namespace Stg
