#include "util.h"

#include <utility>

#define STD ::std::

namespace cq
{
	template <class func, class... types>
	auto bind(func&& fn, types&&... args)
	{
		return[fn, &args...]
		{
			return fn(STD forward<types>(args)...);
		};
	}
}