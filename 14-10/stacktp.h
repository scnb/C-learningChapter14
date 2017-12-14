#pragma once
#ifndef STACKTP_H_
#define STACKTP_H_

template<class Type>

class Stack
{
private:
	enum { MAX = 10 };
	Type items[MAX];//声明为Type类型的
	int top;
public:
	Stack();
	bool isempty();
	bool iffull();
	bool push(const Type & item);//声明为Type类型的
	bool pop(Type & item);//声明为Type类型的
};

template<class Type>
Stack<Type>::Stack()
{
	top = 0;
}

template<class Type>
bool Stack<Type>::isempty()
{
	return top == 0;
}

template<class Type>
bool Stack<Type>::isfull()
{
	return top == MAX;
}

template<class Type>
bool Stack<Type>::push(const Type & item)
{
	if (top < MAX)
	{
		items[top++] = item;
		return true;
	}
	else
	{
		return false;
	}
}

template<class Type>
bool Stack<Type>::pop(Type & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
	{
		return false;
	}
}

#endif