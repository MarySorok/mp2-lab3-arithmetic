// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"


char operat[] = "+-*/";
char open_br[] = "(";
char close_br[] = ")";

Lexem::Lexem(){}
Lexem::Lexem(const Lexem &l)
{

}
Lexem& Lexem::operator =(const Lexem&l)
{

}
bool Lexem::operator ==(const Lexem&l)
{

}
Variable::Variable(){}
Variable:: ~Variable()
{

}
Arithmetic::Arithmetic(char*s)
{
	int nvars=0;
	int n = strlen(s);
	input = new char[n];
	for (int i = 0; i < n; i++)
	{
		input[i] = s[i];
	}
	lex = new Lexem[n];
	//находим число переменных
	for (int i = 0; i < n; i++)
	{
		if (isalpha(input[i]) == true)
			nvars+=1;
	}
	vars = new Variable[nvars];
	char *pos1, *pos2, *pos3;
	//разбиваем на лексемы
	int i=0;
	while (i<n)
	{
		pos1 = strchr(open_br, input[i]);
		if (pos1!=NULL)
		{
			lex[i].setlex(&input[i]);
			lex[i].settype(op_br);
		}
		pos2 = strchr(close_br, input[i]);
		if (pos2!=NULL) 
		{
			lex[i].setlex(&input[i]);
			lex[i].settype(cl_br);
		}
		pos3 = strchr(operat, input[i]);
		if (pos3!=NULL) 
		{
			lex[i].setlex(&input[i]);
			lex[i].settype(oper);
		}
		if (isalpha(input[i]) == true)
		{
			
		}
		if (isdigit(input[i]) == true)
		{

		}

	}

}
int Arithmetic::check()
{

}
void Arithmetic::print_polish()
{

}
void Arithmetic::set_vars()
{

}
double Arithmetic::calculate() 
{

}