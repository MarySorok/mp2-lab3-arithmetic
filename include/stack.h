// ���������� � ���������� ���������� �����
// ���� ������������ ��������: 
// - ������� ��������, 
// - ���������� ��������, 
// - �������� �������� �������� (��� ��������)
// - �������� �� �������, 
// - ��������� ���������� ��������� � �����
// - ������� �����
// ��� ������� � ������ ���� ������ �������������� ������

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
	// ����� ��� ������, ���� ���� ����������
	p[topindex] = a;
	topindex += 1;	
}
template <class ValType>
void Stack<ValType>::clean()
{
	//��������, ����� ������� ��� ��������, ������� ������ � �����
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