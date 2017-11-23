// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#pragma once
#include <cstring>
#include <cstdlib>
#include  <cctype>
#include "stack.h"
#include <iostream>

using namespace std;

enum Lextype {op_br,cl_br,var,val,oper};

class Lexem // лексем
{
	string s;
	Lextype type;
public:
	Lexem() {};
	Lexem& operator =(const Lexem&l);
	bool operator ==(const Lexem&l);
	void setlex(char* s1){ s = s1; }
	void settype(Lextype t) { type = t; }
};
class Variable // переменна€ и ее значение
{
	char name[10];
	double value;
public:
	Variable() {};
	string getname() 
	{ 
		string s;
		s = name; 
		return s;
	}
	void setvalue(double v) { value = v; };
	double getvalue() { return value; };
	Variable& operator =(const Variable&v);
	void setname(char* a) { strcpy(name, a);}
};
class Arithmetic
{
	string s;

	Lexem* lex;
	int nLex;

	Lexem* polish;
	int np;

	Variable* vars;
	int nvars;
public:
	Arithmetic(string str);
	int check();
	void print_polish();
	void set_vars();
	double calculate();
};
