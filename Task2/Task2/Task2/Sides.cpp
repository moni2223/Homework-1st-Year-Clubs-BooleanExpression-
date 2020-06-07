#pragma once
#include "Sides.h"
using namespace std;
Side::Side(bool ch) : Expression(0) //default constr
{
	setValue(ch);
}
bool Side::getValue() 
{
	return ch;
}
void Side::setValue(bool ch) 
{
	this->ch = ch;
}
void Side::print() 
{
	cout << ch;
}
bool Side::eval() 
{
	return ch;
}

Expression* Side::clone() 
{
	Side* cloned = new Side(*this);
	return cloned;

}
bool Side::Equals(Expression* other) 
{
	if (other->getType() != 0)
		return false;
	Side* otherPtr = (Side*)other;
	return ch == otherPtr->ch;
}