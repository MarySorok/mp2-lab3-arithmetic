// реализация функций и классов для вычисления арифметических выражений
#include "arithmetic.h"



string op = "+*-/";
string opbr = "([";
string clbr = "])";
string sqbr = "[]";
string rbr = "()";

Variable& Variable::operator =(const Variable&v)
{
	name = v.name;
	value = v.value;
	return *this;
}
Lexem& Lexem::operator =(const Lexem&l)
{
	s = l.s;
	type = l.type;
	return *this;
}
bool Lexem::operator ==(const Lexem&l)
{
	if (l.type != type)
		return false;
	else
	{
		if (s != l.s)
			return false;
		return true;
	}
}
int Lexem::priority()

{
	int p;
	if (s == "(")
		p = 0;
	if ((s == "+")||(s=="-"))
		p = 1;
	if ((s == "*")||(s=="/"))
		p = 2;
	return p;
}
Arithmetic::Arithmetic(string str)
{
	s = str;
	lex = new Lexem[s.size()];
	nLex = 0;
	vars = new Variable[10];
	nvars = 0;
	size_t p, p1, p2, p3;
	int nbr=0;

	//унарный минус (допускается "(-" и "-" в начале)

	if (s[0] == '-')
	{
		s.insert(0, "0");
	}
	for (int i = 1; i < s.length(); i++)
	{
		p = opbr.find(s[i - 1]);
		if ((s[i] == '-') && (p!=std::string::npos))
		{
			s.insert(i, "0");
		}
	}
	/**/

	int i=0;
	//разбиваем на лексемы:
	while (i < s.size())
	{
		//открывающие скобочки:
		p1 = opbr.find(s[i]);
		if (p1!= std::string::npos)
		{
			string opbrs;
			opbrs = s[i];
			lex[nLex].setlex(opbrs);
			lex[nLex].settype(op_br);
			nLex += 1;
			nbr += 1;
		}
		//закрывающие скобочки:
		p2 = clbr.find(s[i]);
		if (p2!= std::string::npos)
		{
			string clbrs;
			clbrs = s[i];
			lex[nLex].setlex(clbrs);
			lex[nLex].settype(cl_br);
			nLex += 1;
			nbr += 1;
		}
		//операции:
		p3 = op.find(s[i]);
		if (p3 != std::string::npos)
		{
			string ops;
			ops = s[i];
			lex[nLex].setlex(ops);
			lex[nLex].settype(oper);
			nLex += 1;
		}
		//переменные:
		if (isalpha(s[i]) != 0)
		{
			nvars += 1;
			char a[10];
			string as;
			int j = 0;
			while ((isalpha(s[i])!=0))
			{
				a[j] = s[i];
				j++;
				i++;
				if ((i<s.size())&&(s[i] == '['))
				{
					do
					{
						a[j] = s[i];
						i++;
						j++;
					} while (s[i] != ']');

					a[j] = s[i];
					j++;
				}
				
			 }
			i--;
			as = a;
			as.erase(j);
			vars[nvars - 1].setname(as);
			lex[nLex].setlex(as);
			lex[nLex].settype(var);
			nLex += 1;
		}
		//цифры:
		if (isdigit(s[i]) != 0)
		{
			char c[16];
			string cs;
			int j = 0;
			while ((isdigit(s[i]) != 0)||(s[i]=='.'))
			{
				c[j] = s[i];
				j++;
				i++;
				if (i >= s.size())
					break;
			}
			i--;
			cs = c;
			cs.erase(j);
			lex[nLex].setlex(cs);
			lex[nLex].settype(val);
			nLex += 1;
		}
		i++;
	}
	//конечный массив лексем:
	Lexem* l1;
	l1 = new Lexem[nLex];
	for (int i = 0;i < nLex;i++)
		l1[i] = lex[i];
	delete[] lex;
	lex = new Lexem[nLex];
	for (int i = 0;i < nLex;i++)
		lex[i] = l1[i]; 
	//конечный массив переменных:
	Variable* v1;
	v1 = new Variable[nvars];
	for (int i = 0;i < nvars;i++)
		v1[i] = vars[i];
	delete[] vars;
	vars = new Variable[nvars];
	for (int i = 0;i < nvars;i++)
		vars[i] = v1[i];
	//создали поле для перевода в польскую
	polish = new Lexem[nLex - nbr];
	np = 0;
}
int Arithmetic::check()  
{
	
	size_t p1,p2,p3,p4,p5,p6;
	//проверка числа скобочек:
	Stack <char> S(100);
		for (int i = 0; i < s.length();i++)
		{
			p1 = opbr.find(s[i]);
			p2 = clbr.find(s[i]);
			p3 = rbr.find(s[i]);
			p6 = sqbr.find(s[i]);

			if (p1!= std::string::npos)
			    S.push(s[i]);
			else
			{
		    	if (p2!= std::string::npos)
				{
					if (S.isempty() == true)
					{
						cout << "Error. Can't pop from empty stack. It means that you put closing bracket before opening.";
						return 0;
					}

					p4 = rbr.find(S.top());
					p5 = sqbr.find(S.top());

					if (!(((p3 != std::string::npos) && (p4 != std::string::npos)) || ((p6 != std::string::npos) && (p5 != std::string::npos))))
					{
						cout << "There is a mistake. You can't put different closing bracket here: symbol number" << i << ".";
						return 0;
					}
				else
					S.pop();
			     }
			}
        }
	 if (S.isempty() != true)
		{
		    cout << "Error. Stack is not empty, it means, that you put more opening brackets than closing.";
			return 0;
		}
	 /**/
	 for (int i = 0; i < s.length();i++)
		{
			//проверка на отсутствие пробелов
			if (s[i] == ' ')
			{
				cout << "Error. Your expression shouldn't contain spaces.";
				return 0;
			}
			if(i!=(s.length()-1))
			{
			p1 = op.find (s[i]);
			p2 = op. find (s[i+1]);

			//выражений: "(+","(*","(/" 
			if ((s[i] == '(')&&(p2 != std::string::npos)&&(s[i + 1] != '-'))
			{
				cout << "There is a mistake. You can't put " << s[i + 1] << " after" << s[i] << ". Try to correct the expression.";
				return 0;
			}
			//2-ух знаков операции подряд
			if ((p1 != std::string::npos)&&(p2 != std::string::npos))
			{
				cout << "There is a mistake. You can't put two operators at a stretch. Like that:" << s[i] << s[i + 1];
				return 0;
			}

			//выражений "-)","+)","/)","*)"
			if ((p1 != std::string::npos)&&(s[i + 1] == ')'))
			{
				cout << "There is a mistake. You can't put " << s[i] << " before" << s[i + 1] << ". Try to correct the expression.";
				return 0;
			}
			}

		}

	 // проверка, что в конце не знак операции
		int p = op.find(s[s.length()-1]);
		if (p != std::string::npos)
		{
			cout << "There is a mistake. You can't put an operator in the end of expression, like that:" << s[s.length() - 1];
			return 0;
		}	

		return 1;
}
void Arithmetic::print_polish()
{
	for (int i = 0; i < np;i++)
		cout << polish[i].getstr();
}
void Arithmetic::Polish()
{
	Lexem c;
	Stack <Lexem> st;
	Lexem x;
	int i = 0;
	while (i < nLex)
	{
		c = lex[i];
		if ((c.gettypy() == val) || (c.gettypy() == var))
		{
			polish[np] = c;
			np += 1;
	    }
		if (c.gettypy() == op_br)
			st.push(c);
		if (c.gettypy() == oper)
		{
			if (st.isempty())
				st.push(c);
			else
			{
				x = st.top();
				while (c.priority() <= x.priority())
				{
					x = st.pop();
					polish[np] = x;
					np += 1;
					x = st.top();
				}
				st.push(c);
			}
		}
			if (c.getstr() == ")")
			{
				x = st.pop();
				while (x.getstr() != "(")
				{
					polish[np] = x;
					np+=1;
					x = st.pop();
				}
			}
		i++;
	}
	while (!st.isempty())
	{
		x = st.pop();
		polish[np] = x;
		np+=1;
	}
}
void Arithmetic::set_vars()
{
	double tmp;
	for (int i = 0;i < nvars;i++)
	{
		string str = vars[i].getname();
		cout << "Please, enter the value of the variable "<< str << endl;
		cin >>tmp;
		vars[i].setvalue(tmp);
	}
}
double Arithmetic::calculate() 
{
	double res;
	Stack <double> st;
	double x;
	int nvar=0;
	for (int i = 0; i < np;i++)
	{
		if (polish[i].gettypy() == val) 
		{
			x = atof(polish[i].getstr().c_str());
			st.push(x);
		}
		if (polish[i].gettypy() == var)
		{
			x = vars[nvar].getvalue();
			st.push(x);
			nvar += 1;
		}
		if (polish[i].gettypy() == oper)
		{
			double c, b = st.pop();
			double a = st.pop();
			if (polish[i].getstr() == "+")
				c = a + b;
			if (polish[i].getstr() == "-")
				c = a - b;
			if (polish[i].getstr() == "*")
				c = a*b;
			if (polish[i].getstr() == "/")
				c = a/b;
			st.push(c);
		}
	}
	res = st.pop();
	if (!st.isempty())
		throw "something went wrong";
	return res;
}
