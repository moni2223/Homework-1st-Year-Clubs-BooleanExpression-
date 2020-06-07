#include <iostream>
#include "Sides.h"
#include "Operation.h"
#include "Expression.h"
using namespace std;
int main()
{
    Expression* expr1 = new Operation(' ', new Side(0), 'V', '!', new Side(0));//A or not A
    cout <<"Answer is:"<< expr1->eval() << endl;//1
    cout <<"Is this tautology:"<< expr1->isTautology() << endl;//1
    cout << "Is this contradiction:" << expr1->isContradiction() << endl;
    cout << "Variables count is: "; expr1->Variablescount();//2
    expr1->print();
    cout << endl;
    cout << "----" << endl;
    expr1->clearoldcount();//clears objCnt in Expression class for next expression

    Expression* expr2 = new Operation(' ',
        new Operation(' ', new Side(0), 'I', ' ', new Side(0)),
        'X',
        ' ',
        new Operation('!', new Side(1), 'I', '!', new Side(1)));//if A implies B, then not-B implies not-A
    cout <<"Answer is: "<< expr2->eval() << endl;//1
    cout <<"Is this tautology: "<< expr2->isTautology() << endl;//1
    cout << "Is this contradiction:" << expr2->isContradiction() << endl;//0
    cout << "Variables count is: "; expr2->Variablescount();//6
    cout << endl;
    expr2->print();
    cout << endl;
    expr2->clearoldcount();
    cout << "----" << endl;
    
    Expression* expr3 = new Operation(' ', new Side(1), '&', '!', new Side(1));
    cout << "Answer is: " << expr3->eval() << endl;//1
    cout << "Is this tautology: " << expr3->isTautology() << endl;//0
    cout << "Is this contradiction:" << expr3->isContradiction() << endl;//1
    cout << "Is this contingency: " << expr3->isContingency() << endl;//0
    cout << "Variables count is: "; expr3->Variablescount();//2
    cout << endl;
    expr3->print();
    cout << endl;
    expr3->clearoldcount();
    cout << "----" << endl;

    Expression* expr4 = new Operation(' ', new Side(1), '^', ' ', new Side(1));
    cout << "Answer is: " << expr4->eval() << endl;//0
    cout << "Is this tautology: " << expr4->isTautology() << endl;//0
    cout << "Is this contradiction:" << expr4->isContradiction() << endl;//0
    cout << "Is this contingency: " << expr4->isContingency() << endl;//1
    cout << "Variables count is: "; expr4->Variablescount();//2
    cout << endl;
    expr4->print();
    cout << endl;
    expr4->clearoldcount();
}
