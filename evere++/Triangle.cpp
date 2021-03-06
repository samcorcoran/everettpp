#include <iostream>
#include <memory>
#include <math.h>
#include <string>

#include "Triangle.h"
#include "Point.h"


using namespace std;

size_t Triangle::triangle_counter = 1;

Triangle::Triangle(shared_ptr<Point> p1, shared_ptr<Point>p2, shared_ptr<Point>p3) : p1(p1), p2(p2), p3(p3), id(triangle_counter) {
	triangle_counter++;
	//cout << "New triangle (" << std::to_string(id) << "): " << p1->to_string() << ", " << p2->to_string() << ", " << p3->to_string() << '\n';
}

void Triangle::print() {
	cout << p1->to_string() << "\t" << p2->to_string() << "\t" << p3->to_string() << '\n';
}

std::shared_ptr<Point> Triangle::create_centre_point() const {
	auto x = (p1->x + p2->x + p3->x) / 3;
	auto y = (p1->y + p2->y + p3->y) / 3;
	auto z = (p1->z + p2->z + p3->z) / 3;
	return make_shared<Point>(x, y, z);
}
