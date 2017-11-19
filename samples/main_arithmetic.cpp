// реализация пользовательского приложения
#include <iostream>
#include "arithmetic.h"
#include "stack.h"
#include <string>
#include <cstring>
#include  <cctype>
using namespace std;
int main()
{
	string s;
	char* str;
	char oper[] = "+-*/";
	char op_br[] = "([";
	char cl_br[] = ")]";
	char parentheses[] = "()";
	char square_br[] = "[]";
	char *pos1, *pos2, *pos3,*pos4,*pos5,*pos6;
	bool correct = true;
	cout << "Enter the arithmetic expression:\n";
	do {
		getline(cin, s);
		str = new char[s.length()];
		for (int i = 0;i < s.length();i++)
		str[i] = s[i];
		// Здесь проверка строки на корректность:

		// проверка числа скобочек:
		Stack <char> S(100);
		for (int i = 0; i < s.length();i++)
		{
			pos3 = strchr(op_br, str[i]);
			pos4 = strchr(cl_br, str[i]);
			pos5 = strchr(parentheses, str[i]);
			
			if (pos3!=NULL)
				S.push(str[i]);
			else
			{
				if (pos4!=NULL)
				{
					if (S.isempty() == true)
					{
						correct = false;
						cout << "Error. Can't pop from empty stack. It means that you put closing bracket before opening.";
						break;
					}
					pos6 = strchr(parentheses, S.top());

					if (((pos5==NULL)&&(pos6!=NULL))||((pos6==NULL)&&(pos5!=NULL)))
					{
						correct = false;
						cout << "There is a mistake. You can't put different closing bracket here: symbol number"<< i <<".";
						break;
					}
		
					S.pop();
				}
			}

		}
		if (S.isempty() != true)
		{
			correct = false;
			cout << "Error. Stack is not empty, it means, that you put more opening brackets than closing.";
		}

		/**/

		for (int i = 0; i < s.length();i++)
		{
			//проверка на отсутствие пробелов
			if (str[i] == ' ')
			{
				cout << "Error. Your expression mustn't contain spaces.";
				correct = false;
			}

			pos1 = strchr(oper, str[i]);

			pos2 = strchr(oper, str[i + 1]);

			//выражений: "(+","(*","(/" 
			if ((str[i] == '(')&&(pos2 != NULL)&&(str[i + 1] != '-'))
			{
				cout << "There is a mistake. You can't put " << str[i + 1] << " after" << str[i] << ". Try to correct the expression.";
				correct = false;
			}
			//2-ух знаков операции подряд
			if ((pos1 != NULL)&&(pos2 != NULL))
			{
				cout << "There is a mistake. You can't put two operators at a stretch. Like that:" << str[i] << str[i + 1];
				correct = false;
			}

			//выражений "-)","+)","/)","*)"
			if ((pos1 != NULL)&&(str[i + 1] == ')'))
			{
				cout << "There is a mistake. You can't put " << str[i] << " before" << str[i + 1] << ". Try to correct the expression.";
				correct = false;
			}

		}
		char *pos = strchr(oper, str[s.length() - 1]);

		// проверка, что в конце не знак операции
		if (pos != NULL)
		{
			cout << "There is a mistake. You can't put an operator in the end of expression, like that:" << str[s.length() - 1];
			correct = false;
		}
		/**/
		cout << "So, hopefully, you got it. Let's try to enter the expression again.";
	} while (correct == false);

	Arithmetic Exp(str);
  return 0;
}
