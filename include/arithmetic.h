// объ€вление функций и классов дл€ вычислени€ арифметических выражений
#include <cstring>
#include <cstdlib>
#include  <cctype>
#include "stack.h"
#include <iostream>

using namespace std;
typedef enum Lextype {op_br,cl_br,var,val,oper};

struct Lexem // лексем
{
	char str[20];
	Lextype type;
public:
	Lexem(char*s, Lextype t);
	Lexem(const Lexem &l);
	Lexem& operator =(const Lexem&l);
	bool operator ==(const Lexem&l);
};
struct Variable // переменна€ и ее значение
{
	char name[10];
	double value;
};
class Arithmetic
{
	char* inputstr;
	Lexem* lexems;
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
