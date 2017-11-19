// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#include <cstring>
#include <cstdlib>
#include  <cctype>
#include "stack.h"
#include <iostream>

using namespace std;
typedef enum Lextype {op_br,cl_br,var,val,oper};

class Lexem // лексем
{
	char str[10];
	Lextype type;
public:
	Lexem();
	Lexem(const Lexem &l);
	Lexem& operator =(const Lexem&l);
	bool operator ==(const Lexem&l);
	void setlex(char* s)
	{
		for (int i = 0; i < strlen(s);i++)
			str[i] = s[i];
	}
	void settype(Lextype t) { type = t; }
};
class Variable // переменна€ и ее значение
{
	char name[10];
	double value;
public:
		Variable();
		~Variable();
};
class Arithmetic
{
	char* input;
	Lexem* lex;
	int nLex;
	Lexem* polish;
	int np;
	Variable*vars;
	int nvars;
public:
	Arithmetic(char*s);
	int check();
	void print_polish();
	void set_vars();
	double calculate();
};
