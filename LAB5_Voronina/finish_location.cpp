#include "header.h"

// «начение сдвига точки
double shift(double angle, double l) { return abs( (l / 2) * tan(angle * M_PI / 180)); }

bool FBR::cyl_tilt(double angle, MESH M, BOX B)
{
	double a = 0;									// ”гол отлонени€ цилиндра по z		
	double b = 0;									// ”гол отлонени€ цилиндра по x и y	(нижн€€ грань)
	double с = 0;									// ”гол отлонени€ цилиндра по x и y	(верхн€€ грань)
	double len = abs(C[0].L.P1.z - C[0].L.P0.z);	// ƒлина цилиндра
	double sh = 0;									// «начение смещени€ точки
	int RAN = 10; int koef = 1;
	vector<int> neig;
	bool flag = false;
	int step = 0;
	POINT K0, K1;

	srand(time(NULL));

	for (int i = 0; i < C.size(); i++)
	{
		K0 = C[i].L.P0;
		K1 = C[i].L.P1;

		while (!flag && step < TRY_AMO)
		{
			flag = true;

			a = (double)(rand() % ((int)((angle)* EPS))) / EPS;
			sh = shift(a, len);
			b = (double)(rand() % ((int)((360)* EPS))) / EPS;

			if (rand() % RAN > 2)
			{
				flag = C[i].L.P0.point_with_shift(b, sh, B.ST, B.END, RC);
				koef = 1;
			}
			else koef = 2;

			с = b - 180;

			if (с < 0) с = 360 + с;
			if (rand() % (koef*RAN) > 2)
			{
				flag = C[i].L.P1.point_with_shift(с, sh, B.ST, B.END, RC);
			}

			neig = M.neighbors(i);
			for (int j = 0; j < neig.size(); j++) if (!check_dist(C[i].L, C[neig[j]].L)) flag = false;
			
			if (!flag)
			{
				C[i].L.P0 = K0;
				C[i].L.P1 = K1;
				step++;
			}
		}

		flag = false;
		step = 0;
		cout << "i = " << i << " a = " << a << " sh = " << sh << endl;
	}

	return true;
}

bool FBR::check_dist(LINE L1, LINE L2)
{
	if ( (dist3D_LINE_to_LINE(L1, L2) - 2 * 1.001*RC) < E) return false;
	return true;
}

vector<int> MESH::neighbors(int n)
{
	int i = (int)n / step_on_side2;
	int j = n - i * step_on_side2;

	int d = step_on_side1 - delta;

	if (delta > 0 && d*step_on_side2 < n)
	{
		i =  d + (int)( (n - d*step_on_side2) / (step_on_side2-1) );
		j = n - d*step_on_side2 - (i - d)*(step_on_side2 - 1);
	}

	vector<int> ii = { i - 1, i, i + 1 };
	vector<int> jj = { j - 1, j, j + 1 };

	vector<int> res;

	for (int k = 0; k < 3; k++)
	{
		for (int p = 0; p < 3; p++)
		{
			if (check_nei(ii[k], jj[p]) && ( k != 1 || p !=1 )) res.push_back(map[ii[k]][jj[p]]);
		}
	}

	return res;
}

bool MESH::check_nei(int i, int j)
{
	if (i < 0 || i > (step_on_side1 - 1)) return false;
	if (j < 0 || j > (step_on_side2 - 1)) return false;
	if ( map[i][j] == -1 ) return false;
	return true;
}