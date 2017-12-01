// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#pragma once
#include <string>
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
	string getstr() { return s;}
	Lextype gettypy() { return type; }
	Lexem& operator =(const Lexem&l);
	bool operator ==(const Lexem&l);
	void setlex(string s1){ s = s1; }
	void settype(Lextype t) { type = t; }
	int priority();
};
class Variable // переменна€ и ее значение
{
	string name;
	double value;
public:
	Variable() {};
	string getname() 
	{ 
		return name;
	}
	void setvalue(double v) { value = v; };
	double getvalue() { return value; };
	Variable& operator =(const Variable&v);
	void setname(string a) { name=a;}
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
	void Polish();
};
