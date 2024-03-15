#include "Classes.h"
#include "Container.h"

int main() {
	/*integer x;
	integer y(x);
	x.Name();
	Point p1;
	Point p2(p1);
	Object* arr = new Object[1];
	arr[0].Name();
	arr[0] = p1;
	arr[0].Name();*/
	Container<int> x;
	x.push_back(1);
	x.push_forward(0);
	x.push_forward(-1);
	x.push_back(2);
	x.show_values();
	x.push_inside(3, 0);

	int c = x[2];
	x.show_values();
	std::cout << c;
	int f = x.TakeObject(2);
	x.show_values();
}