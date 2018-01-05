#include "header.h"

double POINT::dist(POINT P)
{
	double res = pow((x - P.x), 2);
	res += pow((y - P.y), 2);
	res += pow((z - P.z), 2);
	return sqrt(res);
}

// Перерасчет коэффициентов отрезка
void LINE::line_refresh()
{
	l = N.x - M.x;
	m = N.y - M.y;
	n = N.z - M.z;

	under = pow(l, 2) + pow(m, 2) + pow(n, 2);
	cos_a = l / sqrt(under);
	cos_b = m / sqrt(under);
	cos_g = n / sqrt(under);
};


double LINE::min_dist(LINE L)
{
	/*cout << " L1: O1"; M.print_point();
	cout << " L1: O2"; N.print_point();
	cout << " L2: O1"; L.M.print_point();
	cout << " L2: O2"; L.N.print_point();

	cout << " TEST DIST = " << M.dist(L.M) << endl;

	cout << "ANS = " << check_parallel(L) << endl;*/
	if (check_parallel(L)) return parallel_dist(L);
	return 0;
}


// Проверка на параллельность
bool LINE::check_parallel(LINE L)
{
	if( abs(cos_a - L.cos_a) > E ) return false;
	if( abs(cos_b - L.cos_b) > E ) return false;
	if( abs(cos_g - L.cos_g) > E ) return false;
	return true;
}

// Расчет расстояния между двумя параллельными
double LINE::parallel_dist(LINE L)
{
	double t1 = (l * M.x + m * M.y + n * M.z) / under;
	POINT K1( (M.x + l * t1), ( M.y + m * t1), ( M.z + n * t1 ));

	double t2 = (L.l * L.M.x + L.m * L.M.y + L.n * L.M.z) / under;
	POINT K2((L.M.x + L.l * t2), (L.M.y + L.m * t2), (L.M.z + L.n * t2));

	return K1.dist(K2);
}

// Определитель
double LINE::det(double a, double b, double c, double d)
{
	return a*d - b*c;
}

// Расчет расстояния между двумя не параллельными
double LINE::non_parallel_dist(LINE L)
{
	double ll = det(m, n, L.m, L.n);
	double mm = det(n, l, L.n, L.l);
	double nn = det(l, m, L.l, L.m);

	double d1 = det(m, n, mm, nn);
	double d2 = det(n, l, nn, ll);
	double d3 = det(l, m, ll, mm);

	double p1 = -(d1 * M.x + d2 * M.y + d3 * M.z);

	double d4 = det(L.m, L.n, mm, nn);
	double d5 = det(L.n, L.l, nn, ll);
	double d6 = det(L.l, L.m, ll, mm);

	double p2 = -(d4 * L.M.x + d5 * L.M.y + d6 * L.M.z);


	


}