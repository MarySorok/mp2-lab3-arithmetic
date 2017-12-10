// реализация пользовательского приложения

#include "arithmetic.h"
#include <string>

int main()
{
	string s;
	int f;

	cout << "Your arithmetic expression:\n"; 
	do {
		getline(cin, s);
		Arithmetic Exp(s);
		f = Exp.check();
       } while (f==0);
	Arithmetic Arr(s);
	Arr.Polish();
	Arr.print_polish();
	Arr.set_vars();
	double res = Arr.calculate();
	cout << res;
  return 0;
}
