#pragma once
#include <ctime>
#include "Classes.h"
#include "Container.h"
#include "Chrono"

void randomFill(int count, Container<Object>& cont) {
	srand(time(NULL));
	for (int i = 0; i < count; i++) {
		int r = rand();
		if (r % 2 == 0) {
			int r1 = rand();
			if (r1 % 2 == 0) {
				integer a = integer(i);
				cont.push_back(a);
			}
			else {
				point a = point(i, i+1);
				cont.push_back(a);
			}
		}
		else {
			point p1(i, i+1), p2(i+2, i+3);
			line a = line(p1, p2);
			cont.push_back(a);
		}
	}
}
Object* randomObject() {
	int r = rand() % 3;
	Object* obj = nullptr;
	switch (r) {
	case(0):
		obj = new integer(rand() % 100);
		break;
	case(1):
		obj = new point(rand() % 100, rand() % 100);
		break;
	case(2):
		obj = new line(rand() % 100, rand() % 100, rand() % 100, rand() % 100);
		break;
	}
	return obj;
}
void randomActions(int count, Container<Object>& cont) {
	srand(time(NULL));
	int r = 0;
	Object* obj;
	auto start = std::chrono::high_resolution_clock::now();
	for (int i = 0; i < count; i++) {
		switch (r) {
		case(0):
			obj = randomObject();
			cont.push_back(*obj);
			break;
		case(1):
			obj = randomObject();
			cont.push_forward(*obj);
			break;
		case(2):
			if (cont.GetSize() > 0) {
				obj = randomObject();
				cont.push_inside(*obj, rand() % (cont.GetSize()));
			}
			break;
		case(3):
			if (cont.GetSize() > 0) {
				cont.pop_front();
			}
			break;
		case(4):
			if (cont.GetSize() > 0) {
				cont.remove(rand() % (cont.GetSize()));
			}
			break;
		case(5):
			if (cont.GetSize() > 0) {
				cont.DoSmth();
			}
			break;
		case(6):
			if (cont.GetSize() > 0) {
				cont.DoSmthExclusive();
			}
			break;
		}
		std::cout<<"Итерация под номером " << i+1 << "; Выполнено действие " << r << "\n";
		r = rand() % 7;
	}
	auto end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds> (end - start);
	std::cout << "Затраченное время на " << count << " итераций: " << duration.count() << " микросекунд\n";

}
