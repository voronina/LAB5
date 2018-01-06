#include "header.h"

// Расстояние между точками
double POINT::dist(POINT P)
{
	double res = pow((x - P.x), 2);
	res += pow((y - P.y), 2);
	res += pow((z - P.z), 2);
	return sqrt(res);
}

// Середина отрезка
POINT LINE::middle() { return POINT( ((P0.x + P1.x) / 2), ((P0.y + P1.y) / 2), ((P0.z + P1.z) / 2)); }

// Перемещение точки на указанный сдвиг
bool POINT::point_with_shift(double alpha, double s, POINT ST, POINT END, double R)
{
	x = x + s*cos(alpha);
	y = y + s*sin(alpha);

	if (x < ST.x + 1.001 * R || x > END.x - 1.001 * R) return false;
	if (y < ST.y + 1.001 * R || y > END.y - 1.001 * R) return false;
	if (z < ST.z + 1.001 * R || z > END.z - 1.001 * R) return false;

	return true;
}




