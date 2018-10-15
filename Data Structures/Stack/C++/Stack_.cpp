#include <vector>
#include <iostream>

class Stack
{

private:
	std::vector<int> data;
	int tos = -1; 

public:
	Stack(int capacity);

	Stack(); 

	virtual int top();

	virtual int pop(); 

	virtual void push(int item);

	virtual bool isEmpty();

	virtual void display();

	virtual int size();

};



Stack::Stack(int capacity)
{
	this->data = std::vector<int>(capacity);
}

Stack::Stack() : Stack(5)
{
}

int Stack::top()
{
	if (this->tos == -1)
	{
		std::wcout << L"Stack UnderFlow" << std::endl;
		return -1;
	}
	int value = this->data[this->tos];
	return value;
}

int Stack::pop()
{

	if (this->tos == -1)
	{
		std::wcout << L"Stack UnderFlow" << std::endl;
		return -1;
	}
	int value = this->data[this->tos];
	this->data[this->tos] = 0;
	this->tos--;
	return value;

}

void Stack::push(int item)
{
	
	if (this->tos == this->data.size() - 1)
	{
		std::wcout << L"Stack OverFlow" << std::endl;
		return;
	}
	this->tos++;
	this->data[this->tos] = item;
}

bool Stack::isEmpty()
{
	if (this->size() == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Stack::display()
{
	for (int i = tos; i >= 0; i--)
	{
		std::wcout << this->data[i] << L" ";
	}
	std::wcout << std::endl;
}

int Stack::size()
{
	return this->tos + 1;
}
