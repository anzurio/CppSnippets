#pragma once
#include <iostream>

template<typename T>
class CartesianPoint
{
public:
	T X;
	T Y;

	CartesianPoint() : X(0), Y(0)
	{
	}

	CartesianPoint(T x, T y) : X(x), Y(y)
	{
	}

	CartesianPoint(const CartesianPoint<T>& other) : X(other.X), Y(other.Y)
	{
#ifdef TRACE_MOVE_SEMANTICS
		std::cout << __FUNCSIG__ << std::endl;
#endif // TRACE_MOVE_SEMANTICS
	}

	CartesianPoint(CartesianPoint<T>&& other) noexcept
	{
#ifdef TRACE_MOVE_SEMANTICS
		std::cout << __FUNCSIG__ << std::endl;
#endif // TRACE_MOVE_SEMANTICS
		X = std::move(other.X);
		Y = std::move(other.Y);
	}

	CartesianPoint<T>& operator=(const CartesianPoint<T>& other)
	{
#ifdef TRACE_MOVE_SEMANTICS
		std::cout << __FUNCSIG__ << std::endl;
#endif // TRACE_MOVE_SEMANTICS
		X = other.X;
		Y = other.Y;
		return *this;
	}

	CartesianPoint<T>& operator=(CartesianPoint<T>&& other)
	{
#ifdef TRACE_MOVE_SEMANTICS
		std::cout << __FUNCSIG__ << std::endl;
#endif // TRACE_MOVE_SEMANTICS
		if (this != &other)
		{
			X = std::move(other.X);
			Y = std::move(other.Y);
		}
		return *this;
	}

	~CartesianPoint() = default;

	friend std::ostream& operator<<(std::ostream& os, const CartesianPoint<T>& cp)
	{
		os << "(" << cp.X << ", " << cp.Y << ")";
		return os;
	}
};

