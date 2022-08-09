#pragma once

#include <iostream>

namespace cq
{
	template <class func, class... types>
	auto bind(func&& fn, types&&... args);
}
