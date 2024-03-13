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
	x.push_back(11);
	std:: cout << x[0];
}