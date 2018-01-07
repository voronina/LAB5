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
	x = x + s*cos(alpha * M_PI / 180);
	y = y + s*sin(alpha * M_PI / 180);

	/*print_point();
	system("PAUSE");*/
	/*cout << " ST.x + 1.01*R = " << ST.x + 1.01*R << endl;
	cout << " ST.y + 1.01*R = " << ST.y + 1.01*R << endl;

	cout << " END.x - 1.01*R = " << END.x - 1.01*R << endl;
	cout << " END.y - 1.01*R = " << END.y - 1.01*R << endl;*/

	if ( abs(x-(ST.x+ 1.01*R))<E &&  abs(x-(END.x- 1.01*R))<E  && abs(y-(ST.y+ 1.01*R))<E && abs(y-(END.y- 1.01*R))<E ) return true;

	return false;
}




