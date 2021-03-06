﻿/*******************************************************************/

/* Original File Name: Stack.h                                     */

/* Date: ‎12-09-2018                                                */

/* Developer: Dionysus Benstein                                    */

/* Copyright © 2018 Dionysus Benstein. All rights reserved.        */

/* Description: Реализация стэка посредством динамического массива.*/

/*******************************************************************/

#pragma once
#include <iostream>

using namespace std;

template <typename T>
class Stack
{
public:
	//Constructors
	Stack()
	{
		data = nullptr;
		size = 0;
	}

	~Stack()
	{
		delete[] data;
	}

	//Operators
	friend ostream& operator<<(ostream& os, const Stack& other)
	{
		for (int i = 0; i < other.getSize(); i++)
			os << other.data[i] << " ";

		return os;
	}

	//Public methods
	void push(const T value)
	{
		T* data = new T[size + 1];

		for (int i = 0; i < size; i++)
			data[i] = this->data[i];

		delete[] this->data;
		data[size++] = value;
		this->data = data;
		data = nullptr;
	}

	void pop()
	{
		T* data = new T[size--];

		for (int i = 0; i < size; i++)
		{
			data[i] = this->data[i];
		}

		delete[] this->data;
		this->data = data;
		data = nullptr;
	}

	size_t getSize() const
	{
		return this->size;
	}

	bool empty() const
	{
		return size == 0;
	}

	T& top()
	{
		return data[size - 1];
	}

private:
	T* data;
	size_t size;
};