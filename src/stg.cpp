#include "stg.hpp"

namespace Stg
{
    Stg::Stg()
    {
    }

	template<typename T>
    bool encode(const char *data, uchar *container, int32_t size)
    {
    	return T().T::Base::encode(data, container, size);
    }

    template<typename T>
    int32_t decode(const uchar *container, int32_t size, const char *&data)
	{
		auto decoded = QString(T().T::Base::decode(container, size).data());
		data = decoded.toLocal8Bit().data();
		return decoded.length();
	}

} // namespace Stg

