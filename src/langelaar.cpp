#include "langelaar.hpp"

namespace Stg
{
    Langelaar::Langelaar(QObject *parent)
    : QObject(parent)
    , _mask{false}
    {
        std::uniform_int_distribution<size_t> d (0, 1);

        //maybe optimize inefficient calling times 64 -> 8
        auto f = [&]() -> bool { return d(*QRandomGenerator::global()); };
        std::generate_n((bool*)_mask, sizeof(_mask), f);
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

} // namespace Stg
