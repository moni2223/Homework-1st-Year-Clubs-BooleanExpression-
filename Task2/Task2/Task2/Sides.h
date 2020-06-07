#pragma once
#include "Expression.h"
class Side : public Expression 
{
public:
	Side(bool ch);
	bool getValue();
	void setValue(bool ch);

	void print() override;
	bool eval() override;

	Expression* clone() override;

	bool Equals(Expression* other) override;

private:
	bool ch;

};