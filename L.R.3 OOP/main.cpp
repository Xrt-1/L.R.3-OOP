#include "Function.h"

int main() {
	setlocale(LC_ALL, "rus");
	Container<Object> cont;
	randomFill(10, cont);
	cont.DoSmth();
	Object* xx =new point(1,2);
	std::cout << xx->Name();
}