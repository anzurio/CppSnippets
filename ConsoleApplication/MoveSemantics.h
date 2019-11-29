#pragma once

#define TRACE_MOVE_SEMANTICS
#include "CartesianPoint.h"
#include <vector>

namespace MoveSemantics
{
	CartesianPoint<int> newCartesianPoint();
	void fillVector(std::vector<CartesianPoint<int>>& v);
}
