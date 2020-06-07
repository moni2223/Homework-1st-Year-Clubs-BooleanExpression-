#pragma once

#include <iostream>
class Expression 
{
	int type;//0 - SIDE, 1-OP
public:
	static int objCnt;
	int exprcount();
	void Variablescount();

	Expression(int type);
	int getType();
	virtual void print() = 0;
	virtual bool eval() = 0;
	virtual Expression* clone() = 0;

	static int countoftautologies;
	int set_counttaut();
	static void printObjCount(void);
	static int printcounttaut();
	bool tautology = 0;
	bool checktaut();
	bool isTautology();

	void clearoldcount();

	static int countofcontradiction;
	int set_countcontra();
	static int printcountcontra();
	bool contradiction = 0;
	bool checkcontra();
	bool isContradiction();

	bool isContingency();
	virtual bool Equals(Expression* other) = 0;

	virtual ~Expression() {};
};
