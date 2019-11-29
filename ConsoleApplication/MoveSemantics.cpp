#include "MoveSemantics.h"

CartesianPoint<int> MoveSemantics::newCartesianPoint()
{
	CartesianPoint<int> p(9, 9);
	return p;
}

void MoveSemantics::fillVector(std::vector<CartesianPoint<int>>& v)
{
	// Calls Move constructor
	CartesianPoint<int> p = newCartesianPoint();
	// Calls Move constructor
	CartesianPoint<int> q = newCartesianPoint();
	// Calls Move Constructor
	v.push_back(std::move(p));
	// Calls Move Constructor
	// Calls Move Assignment
	p = newCartesianPoint();
	// Calls Copy Constructor
	// Calls Move Constructor
	v.push_back(p);
	// Calls Copy Assignment
	p = q;
	// Calls Move Constructor thrice
	v.push_back(CartesianPoint<int>(1, 1));
}