#ifndef STG_HPP
#define STG_HPP

#include <cstdint>
#include <QtGlobal>
#include <QString>

#include "lsb.hpp"
#include "kutter.hpp"

namespace Stg
{
    class Stg : QObject
    {
		Q_OBJECT

    public:
		enum class EncoderType : size_t
		{
			Lsb,
			Kutter,
			Default = Lsb,
		};
		Q_ENUM(EncoderType);

        Stg();
    };

    template<typename T>
    bool encode(const char *data, uchar *container, int32_t size);

    template<typename T>
    int32_t decode(const uchar *container, int32_t size, const char *&data);

} // namespace Stg

#endif // STG_HPP
