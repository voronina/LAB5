#include "header.h"

void BOX::initialize_box(void)
{
	double A = AA;			// Параметры куба

	double M[6][6] =
	{ { 0,0,0,	0,0,-A },
	{ 0,0,0,		0,-A,0 },
	{ 0,0,0,		-A,0,0 },
	{ A,A,A,		A,0,0 },
	{ A,A,A,		0,A,0 },
	{ A,A,A,		0,0,A } };

	for (int i = 0; i < 6; i++)
	{
		P.push_back(PLANE(POINT(M[i][0],M[i][1],M[i][2]), VECT(M[i][3],M[i][4],M[i][5]), 10));
	}
}