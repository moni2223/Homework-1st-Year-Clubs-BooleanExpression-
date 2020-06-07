#pragma once
#include "Expression.h"
using namespace std;

int Expression::objCnt = 0;
int Expression::countoftautologies = 0;
int Expression::countofcontradiction = 0;

Expression::Expression(int type)
{
	this->type = type;
}
int Expression::exprcount() 
{
	objCnt++;
	return 1;
}
int Expression::getType()
{
	return type;
}
bool Expression::checktaut()
{
	this->tautology = 1;
	return 1;
}
bool Expression::checkcontra()
{
	this->contradiction = 1;
	return 1;
}
bool Expression::isContradiction() 
{
	int newvarcount = 0;
	if (objCnt >= 2)
	{
		newvarcount = (objCnt - 1) * 2;
	}
	else if (objCnt <= 1) newvarcount = objCnt;
	if (printcountcontra() == newvarcount)checkcontra();
	bool contraadiction = contradiction;
	contradiction = 0;
	return contraadiction;
}
bool Expression::isTautology() 
{
	int newvarcount = 0;
	if (objCnt >= 2)
	{
		newvarcount = (objCnt - 1) * 2;
	}
	else if(objCnt <= 1) newvarcount = objCnt;
	if (printcounttaut() == objCnt) 
		checktaut();
	bool tauutology = tautology;
	tautology = 0;
	return tauutology;
}
void Expression::printObjCount(void)
{
	cout << "count:" << objCnt << "\n";
}
void Expression::Variablescount(void) 
{
	cout << objCnt * 2 << endl;
}
int Expression::set_counttaut() 
{
	countoftautologies++;
	return 1;
}
int Expression::set_countcontra()
{
	countofcontradiction++;
	return 1;
}
int Expression::printcounttaut(void) 
{
	return countoftautologies;
}
int Expression::printcountcontra(void) 
{
	return countofcontradiction;
}
bool Expression::isContingency() 
{
	if (isTautology() == 1 || isContradiction() == 1) return 0;
	else return 1;
}
void Expression::clearoldcount() 
{
		countoftautologies = 0;
		countofcontradiction = 0;
		objCnt = 0;
		return;
}