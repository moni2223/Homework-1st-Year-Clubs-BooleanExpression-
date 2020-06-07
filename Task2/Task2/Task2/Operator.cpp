#pragma once
#include "Operation.h"
using namespace std;

Operation::Operation(char op3,Expression* left,char op,char op2, Expression* right) :Expression(1)
{
	this->left = left;
	this->right = right;
	setOperator(op);
	setsecondOperator(op2);
	setthirdOperator(op3);
}
void Operation::print()
{
	switch (op) 
	{
	case 'V': 
	{
		if (op3 == '!') { cout << "reversed "; left->print(); }
		else if(op3==' ')left->print();
		cout << " or ";
		if (op2 == '!') { cout << "reversed "; right->print(); }
		else if (op2 == ' ')right->print();
		break;
	}//or
	case '&': 
	{
		if (op3 == '!') { cout << "reversed "; left->print(); }
		else if (op3 == ' ')left->print();
		cout << " and ";
		if (op2 == '!') { cout << "reversed "; right->print(); }
		else if (op2 == ' ')right->print();
		break;
	}//and
	case '^': 
	{
		if (op3 == '!') { cout << "reversed "; left->print(); }
		else if (op3 == ' ')left->print();
		cout << " Exclusive or ";
		if (op2 == '!') { cout << "reversed "; right->print(); }
		else if (op2 == ' ')right->print();
		break;
	}//XOR
	case 'X': 
	{
		if (op3 == '!') { cout << "reversed "; left->print(); }
		else if (op3 == ' ')left->print();
		cout << " Exclusive NOR ";
		if (op2 == '!') { cout << "reversed "; right->print(); }
		else if (op2 == ' ')right->print();
		break;
	}//XNOR(opposite of XOR)
	case 'I': 
	    {
		if (op3 == '!') { cout << "reversed "; left->print(); }
		else if (op3 == ' ')left->print();
		cout << "->";
		if (op2 == '!') { cout << "reversed "; right->print(); }
		else if (op2 == ' ')right->print();
		break;
	    }//IMPLICATION
	}
}
bool Operation::eval()
{
	int lhs = left->eval();
	int rhs = right->eval();
	if (op2 == '!')
		rhs = !rhs;
	if (op3 == '!') lhs = !lhs;
	switch (op)
	{
	case 'V': {
		if (op2 == '!' || op3 == '!')//checking for tautology 
		{
			set_counttaut();
		}
		if (lhs == rhs && lhs == 0) 
		{

		}
		return lhs || rhs;
		break;
	}//or
	case '&': 
	{
		if (op2 == '!' || op3 == '!')
		{
			if (isTautology() == 1);
			else 
			{
				if (lhs != rhs) set_countcontra();
			}
		}
		else;
		return lhs && rhs; break;
	}  //and ---no chance for tautology
	case '^': { 
		if (lhs != rhs) 
	   {
		set_counttaut();
	   }
		return lhs ^ rhs;
		break;
	}//XOR
	case 'X': {
		if (lhs == rhs) 
		{
			set_counttaut();
		}
		return !(lhs ^ rhs); 
		break; 
	}//XNOR(opposite of XOR)
	case 'I': {
		if (lhs == 1 && rhs == 0);
		else set_counttaut();
		return lhs ? rhs : true;
		break;
	}//IMPLICATION--- no chance for tautology
	}
	return 0;
}
void Operation::setOperator(char op)
{

	if (op != 'V' && op != '&' && op != 'X' && op != '^' && op != 'I')
		cout << "Invalid operation" << endl;

	exprcount();
	this->op = op;

}
void Operation::setsecondOperator(char op2)
{

	if (op2 != '!' && op2!= ' ')
		cout << "Invalid operator" << endl;

	this->op2 = op2;

}
void Operation::setthirdOperator(char op3)
{

	if (op3 != '!' && op3 != ' ')
		cout << "Invalid operator" << endl;

	this->op3 = op3;

}
Expression* Operation::clone()
{
	Operation* cloned = new Operation(*this);
	return cloned;
}
bool Operation::Equals(Expression* other)
{
	if (other->getType() != 1)
		return false;
	Operation* otherPTR = (Operation*)other;
	return op == otherPTR->op
		&& left->Equals(otherPTR->left)
		&& right->Equals(otherPTR->right);

}
Operation::~Operation()
{
	delete left;
	delete right;
}