#include "CartesianPoint.h"
#include "PriorityQueueSnippets.h"
#include <queue>

template<typename T>
bool isFurthestFromOrigin(const CartesianPoint<T>& lhs, const CartesianPoint<T>& rhs)
{
	auto lhsDistanceFromOrigin = sqrt(pow(lhs.X, 2) + pow(lhs.Y, 2));
	auto rhsDistanceFromOrigin = sqrt(pow(rhs.X, 2) + pow(lhs.Y, 2));

	return lhsDistanceFromOrigin > rhsDistanceFromOrigin;
}

template<typename T>
class FurthestFromOriginFunctor
{
public:
	bool operator()(const CartesianPoint<T>& lhs, const CartesianPoint<T>& rhs)
	{
		return isFurthestFromOrigin(lhs, rhs);
	}
};

template<typename T>
void PriorityQueueSnippets::usingLambda(const std::vector<CartesianPoint<T>>& points)
{
	auto cmp = [](CartesianPoint<T>& lhs, CartesianPoint<T>& rhs)
	{
		return isFurthestFromOrigin(lhs, rhs);
	};

	std::priority_queue<
		CartesianPoint<T>,
		std::vector<CartesianPoint<T>>,
		decltype(cmp)
	> heap(cmp);

	for (const CartesianPoint<T>& point : points)
	{
		heap.push({ point.X, point.Y });
	}

	while (!heap.empty())
	{
		auto point = heap.top();
		heap.pop();
		std::cout << point << std::endl;
	}
}

template<typename T>
void PriorityQueueSnippets::usingFunction(const std::vector<CartesianPoint<T>>& points)
{
	std::priority_queue<
		CartesianPoint<T>,
		std::vector<CartesianPoint<T>>,
		std::function<bool(CartesianPoint<T>, CartesianPoint<T>)> //OR decltype(&isFurthestFromOrigin)
	> heap(isFurthestFromOrigin<T>);

	for (const CartesianPoint<T>& point : points)
	{
		heap.push({ point.X, point.Y });
	}

	while (!heap.empty())
	{
		auto point = heap.top();
		heap.pop();
		std::cout << point << std::endl;
	}
}

template<typename T>
void PriorityQueueSnippets::usingFunctor(const std::vector<CartesianPoint<T>>& points)
{
	std::priority_queue<
		CartesianPoint<T>,
		std::vector<CartesianPoint<T>>,
		FurthestFromOriginFunctor<T>
	> heap;

	for (const CartesianPoint<T>& point : points)
	{
		heap.push({ point.X, point.Y });
	}

	while (!heap.empty())
	{
		auto point = heap.top();
		heap.pop();
		std::cout << point << std::endl;
	}
}