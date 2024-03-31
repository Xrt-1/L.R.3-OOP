#include "Function.h"

int main() {
	setlocale(LC_ALL, "rus");
	Container<Object> cont;
	integer a(4);
	integer b(5);
	point p1(4, 2);
	point p2(3, 2);
	line l1(p1, p2);
	cont.push_back(b);
	cont.push_forward(a);
	cont.push_inside(p1, 2);//-
	cont.push_back(p2);
	cont.push_back(l1);
	cont.DoSmth();
	printf("--------------------------------\n");
	cont.DoSmthExclusive();
	///�������� ���������:
	/*Object** arr = new Object * [3];
	arr[0] = &a;
	arr[1] = &b;
	arr[2] = &p1;
	if (auto p = dynamic_cast<point*>(arr[2])) {
		std::cout << p->Name() << std::endl;
	}
	else {
		std::cout << "�� ������� �������� ��������� � ���� point" << std::endl;
	}*/
	///�������� �����������:
	/*Object * arr = new Object[3];
	arr[0] = a;
	arr[1] = b;
	arr[2] = p1;
	if (auto p = dynamic_cast<point*>(&(arr[2]))) {
		std::cout << p->Name() << std::endl;
	}
	else {
		std::cout << "�� ������� �������� ��������� � ���� point" << std::endl;
	}
	std::cout << p1.Name() << std::endl;*/
}