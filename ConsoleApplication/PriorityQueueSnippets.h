#pragma once
#include <vector>
#include <functional>


namespace PriorityQueueSnippets
{
	template <typename T>
	void usingLambda(const std::vector<CartesianPoint<T>>& points);
	template <typename T>
	void usingFunctor(const std::vector<CartesianPoint<T>>& points);
	template <typename T>
	void usingFunction(const std::vector<CartesianPoint<T>>& points);
	// TODO Figure out how to forego these
	template void usingLambda<double>(const std::vector<CartesianPoint<double>>& points);
	template void usingFunctor<double>(const std::vector<CartesianPoint<double>>& points);
	template void usingFunction<double>(const std::vector<CartesianPoint<double>>& points);
}