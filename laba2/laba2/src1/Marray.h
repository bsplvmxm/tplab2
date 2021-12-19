#pragma once
#include <string>

template <class T>
class Marray
{
private:
	int size;
	T* data;

public:
	Marray() : size(0), data(nullptr) {}
	Marray(const Marray<T>& myArray);
	~Marray() { clear(); }

	void clear();
	void sort();
	const int getSize() { return size; }
	T& operator[](int);
	Marray<T>& operator+=(const T& obj);
	Marray<T>& operator-=(const int index);
	Marray<T>& operator=(const Marray<T>& myArray);
};

template <class T>
Marray<T>::Marray(const Marray<T>& myArray) {
	data = new T[myArray.size];
	size = myArray.size;
	for (int i = 0; i < myArray.size; i++)
		data[i] = myArray.data[i];
}

template <class T>
T& Marray<T>::operator[](int index)
{
	std::string err = "Index " + std::to_string(index) + " does not exist";
	if (index < 0 || index >= size)
		throw err;
	return data[index];
}

template<class T>
Marray<T>& Marray<T>::operator+=(const T& obj) {
	T* tmp = data;
	size++;
	data = new T[size];
	for (int i = 0; i < size - 1; i++)
		data[i] = tmp[i];
	data[size - 1] = obj;
	return *this;
}

template<class T>
Marray<T>& Marray<T>::operator-=(const int index) {
	std::string err = "Index " + std::to_string(index) + " does not exist";
	if (index < 0 || index >= size)
		throw err;
	T* tmp = new T[size - 1];
	int k = 0;
	for (int i = 0; i < size; i++)
		if (i != index)
			tmp[k++] = data[i];
	size--;
	data = tmp;
	return *this;
}

template <class T>
Marray<T>& Marray<T>::operator=(const Marray<T>& myArray)
{
	if (this == &myArray)
		return *this;
	delete[] data;
	data = new T[myArray.size];
	size = myArray.size;
	for (int i = 0; i < myArray.size; i++)
		data[i] = myArray.data[i];
	return *this;
}

template <class T>
void Marray<T>::sort() {
	for (int i = 1; i < size; i++)
		for (int j = 0; j < size - i; j++)
			if (data[j] > data[j + 1])
				std::swap(data[j], data[j + 1]);
}

template <class T>
void Marray<T>::clear() {
	delete[] data;
	data = nullptr;
	size = 0;
}