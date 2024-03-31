#pragma once
#include <iostream>

template <typename T>
class Container 
{
private:
	int size;
	template <typename T>
	class Node {
	public:
		T* value;
		Node<T>* NextObj;
		Node<T>(T& val = nullptr, Node* next = nullptr) {
			value = &val;
			NextObj = next;
		}
	};
	Node<T>* firstObj;
public:
	Container<T>() {
		firstObj = nullptr;
		size = 0;
	}
	Container<T>(T object) {
		firstObj = new Node<T>(object) ;
		size = 1;
	}
	~Container<T>() {
		Node<T>* elem = firstObj;
		Node<T>* r;
		while (elem != nullptr) {
			r = elem->NextObj;
			delete elem;
			elem = r;
		}
	}
	int GetSize() {
		return size;
	}
	void push_back(T& value) {
		if (firstObj == nullptr) {
			firstObj = new Node<T>(value);
		}
		else {
			Node<T>* elem = firstObj;
			while (((elem->NextObj) != nullptr) && (elem != nullptr)) {
				elem = (elem->NextObj);
			}
			(elem->NextObj) = new Node<T>(value);
		}
		size++;
	}
	void push_forward(T& value) {
		if (firstObj == nullptr) {
			firstObj = new Node<T>(value);
		}
		else {
			Node<T>* oldFirst = firstObj;
			firstObj = new Node<T>(value);
			firstObj->NextObj = oldFirst;
		}
		size++;
	}
	void push_inside(T& value,const int index) {  //вставляет элемент на индекс index, передвигая тот, что был там
		Node<T>* r = firstObj;
		Node<T>* prev = nullptr;
		Node<T>* next = nullptr;
		int count = 0;
		if (index == 0) {
			firstObj = new Node<T>(value);
			firstObj->NextObj = r;
			size++;
		}
		else if (index <= size && index >= 0)
		{
			while (r != nullptr) {
				if (count == (index - 1)) {
					next = r->NextObj;
					r->NextObj = new Node<T>(value, next);
				}
				r = r->NextObj;
				count++;
			}
			size++;
		}
	}

	void pop_front() {
		Node<T> newFirst = firstObj->NextObj;
		delete firstObj;
		firstObj = newFirst;

	}
	void remove(int index) {
		int c = 0;
		Node<T>* elem = firstObj, prev = nullptr, next = nullptr;
		if (index == 0) {
			pop_front();
		}
		else {
			while (elem != nullptr) {
				if (c == index - 1) {
					prev = elem;
					next = (prev->NextObj)->NextObj;
					delete elem;
					prev->NextObj = next;
					size--;
				}
			}
		}
	}

	void show_values() {
		Node<T>* elem = firstObj;
		if (std::is_same<T, int>::value or std::is_same<T, char>::value)
		{
			std::cout << "contained elements: ";
			for (int i = 0; i < size;) {
				std::cout << elem->value << "; ";
				elem = elem->NextObj;
				i += 1;
			}
			std::cout << "\n";
		}
	}

	T& TakeObject(const int index) {//изымает объект
		Node<T>* elem = firstObj;
		Node<T>* taked = nullptr;
		int count = 0;
		T* take;
		if (index < size && index >= 0)
		{
			while (elem != nullptr) {
				if (count == index - 1) {
					Node<T>* taked = elem->NextObj;
					take = (elem->NextObj)->value;
					elem->NextObj = (elem->NextObj)->NextObj;
					delete taked;
					size--;
					return *take;
				}
				elem = elem->NextObj;
				count++;
			}
		}
	}
	T& operator [](const int index) {
		Node<T>* elem = firstObj;
		int count = 0;
		while (elem != nullptr) {
			if (count == index) {
				return *(elem->value);
			}
			elem = elem->NextObj;
			count++;
		}
	}

	void DoSmthExclusive()
	{
		Node<T>* elem = firstObj;
		int count = 0;
		while (elem != nullptr) {
			if ((elem->value)->isA("point")) {
				int x, y;
				point* obj = static_cast<point*> (elem->value);
				obj->GetCoords(x, y);
				std::cout << "Координаты точки под номером " << count << ": x = " << x << "; y = " << y << "\n";
				count++;
			}
			else if ((elem->value)->isA("integer")) {
				integer* obj = static_cast<integer*>(elem->value);
				std::cout << "Значение элемента под номером " << count << " равно " << obj->GetInt() << "\n";
				count++;
				
			}
			else if ((elem->value)->isA("line")) {
				int x, y, x1, y1;
				line* obj = dynamic_cast<line*>(elem->value);
				obj->GetCoords(x, y, x1, y1);
				std::cout << "Первая точка отрезка под номером " << count << " имеет координаты(" << x << ";" << y << ");  Вторая точка этого отрезка имеет координаты(" << x1 << "; " << y1 << ")\n";
				count++;
			}
			elem = elem->NextObj;
		}
	
	}

	void DoSmth() {//делает то, что есть во всех потомках класса
		Object* obj = NULL;
		Node<T>* elem = firstObj;
		if (dynamic_cast<Object*> (elem->value) != nullptr) 
		{
			while (elem != nullptr)
			{
				if (dynamic_cast<point*> (elem->value) != nullptr) obj = dynamic_cast<point*> (elem->value);
				else if (dynamic_cast<line*> (elem->value) != nullptr) obj = dynamic_cast<line*> (elem->value);
				else if (dynamic_cast<integer*> (elem->value) != nullptr) obj = dynamic_cast<integer*> (elem->value);
				else if (dynamic_cast<Object*> (elem->value) != nullptr) obj = dynamic_cast<Object*> (elem->value);
				std::string name = obj->Name();
				std::cout << "Название класса: " << name << "\n";
				elem = elem->NextObj;
			}
		}
	}
};