// объявление и реализация шаблонного стека
// стек поддерживает операции: 
// - вставка элемента, 
// - извлечение элемента, 
// - просмотр верхнего элемента (без удаления)
// - проверка на пустоту, 
// - получение количества элементов в стеке
// - очистка стека
// при вставке в полный стек должна перевыделяться память

template <class ValType>
class Stack
{
	ValType *p;
	int topindex;
	int size;
public:
	Stack(int s=1000);
	~Stack();
	void push(ValType a);
	ValType pop();
	ValType top();
	bool isempty();
	void clean();
	int getquantity() { return topindex; }
};

template <class ValType>
Stack<ValType>::Stack(int s= 1000)
{
	topindex = 0;
	size = s;
	p = new ValType[s];
}
template <class ValType>
Stack<ValType>::~Stack()
{
	delete[]p;
}
template <class ValType>
void Stack<ValType>::push(ValType a)
{
	// здесь что делаем, если стек переполнен
	p[topindex] = a;
	topindex += 1;	
}
template <class ValType>
void Stack<ValType>::clean()
{
	//возможно, нужно удалить все значения, которые лежали в стеке
	topindex = 0;
}
template <class ValType>
bool Stack<ValType>::isempty()
{
	if (topindex == 0)
		return true;
}
template <class ValType>
ValType Stack<ValType>::pop()
{
	if (topindex == 0)
		throw ("Error. Stack is empty");
	topindex -= 1;
	return p[topindex];
}
template <class ValType>
ValType Stack<ValType>::top()
{
	if (topindex == 0)
		throw ("Error. Stack is empty");
	return p[topindex-1];
}