#include <functional>
#include <iostream>

void sum(int* x, int* y)
{
	std::cout << *x + *y << std::endl;
}

template <class func, class... types>
std::function<void()> addQueue(func&& fn, size_t level, types&&... args)
{
	// Get ptr to args
	// Create function that when the queue level is called it derefrences args and passes them to the actual function
	// Return created function, bound properly

	return std::_Binder<std::_Unforced, func, types...>(std::forward<func>(fn), std::forward<types>(args)...);
}

int main(void)
{
	int a = 8;
	auto sumFunc = addQueue(&sum, 8, a, 7);
	a = 10;
	sumFunc();
}