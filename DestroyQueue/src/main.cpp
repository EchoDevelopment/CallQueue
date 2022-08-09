#include <functional>
#include <iostream>

void sum(int x, int y)
{
	std::cout << x + y << std::endl;
}

#define STD ::std::

template <class func, class... types>
class FuncArg
{
public:
	using tupleType = STD tuple<STD _Unrefwrap_t<types>...>;
private:
	func _function;
	tupleType _args;

public:
	FuncArg(func&& fn, size_t level, tupleType args)
	{
		_function = STD forward<func>(fn);
		_args = STD forward<tupleType>(args);
	}

	void call()
	{
		STD apply(STD forward<func>(_function), STD forward<tupleType>(_args));
	}
};

template <class func, class... types>
FuncArg<func, types...>&& addQueue(func&& fn, size_t level, types&&... args)
{

	// New plan: store args
	// Bind args and call function at the same time
	// Keep binding if function is called multiple times
	// Destroy vars when queue or that level of the queue should be destroyed

	FuncArg<func, types...> funcArg(&sum, 4, STD make_tuple((args)...));
	return STD forward<FuncArg<func, types...>>(funcArg);
} 

int main(void)
{
	int a = 8;

	auto func = addQueue(&sum, 4, a, 10);

	a = 10;

	func.call();
}