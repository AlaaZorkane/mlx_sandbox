#include "vector.h"

t_vector create_vector(t_point a, t_point b) {
	t_vector vector;

	vector.a = a;
	vector.a = b;

	return (vector);
}

t_vector add_vectors(t_vector vec1, t_vector vec2) {
	t_vector result;

	// c = (8,13) + (26,7) = (8+26,13+7) = (34,20)
	result.a = vec1.a.x + vec2.a.y; 

	return (vector);
}

t_point create_point(int x, int y) {
	t_point point;

	point.x = x;
	point.y = y;
	return (point);
}
