#pragma once
#include "Expression.h"

class Operation : public Expression
{
public:
	Operation(char op3,Expression* left,char op, char op2, Expression* right);
	void print() override;
	bool eval() override;
	Expression* clone() override;
	bool Equals(Expression* other) override;
	~Operation();
private:
	void setOperator(char op);
	void setsecondOperator(char op2);
	void setthirdOperator(char op3);
	char op;
	char op2;
	char op3;
	Expression* left;
	Expression* right;
};