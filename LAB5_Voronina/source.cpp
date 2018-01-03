#include "header.h"

#define AA 3;

void main()
{
	double R = 0.05;			// Радиус трубки
	double T = 0.01;		// Толщина стенки трубки
	double PER = 0.025;		// Процентное содержание трубок

	BOX B(initialize_box());

	int AMO = B.get_amo(R,PER);
	cout << "AMO = " << AMO << endl;

	FBR F(R,T);

	F = initialize_fibers(F, B, AMO);

	OBJ O(F, B.str);

	ofstream fout;
	fout.open("output.geo");
	fout << "algebraic3d" << endl;
	B.print_boxes(fout);
	fout << endl;
	F.print_fbr(fout);
	fout << endl;
	O.print_obj(fout);
	fout.close();

	system("PAUSE");
}

vector<PLANE> initialize_box(void)
{
	double A = AA;			// Параметры куба
	vector<PLANE> P;

	double M[6][6] = 
	{{0,0,0,	0,0,-A},
	{0,0,0,		0,-A,0},
	{0,0,0,		-A,0,0},
	{A,A,A,		A,0,0},
	{A,A,A,		0,A,0},
	{A,A,A,		0,0,A} };

	for (int i = 0; i < 6; i++)
	{
		P.push_back(PLANE({ M[i][0],M[i][1],M[i][2] }, { M[i][3],M[i][4],M[i][5] }, 10));
	}

	return P;
}


FBR initialize_fibers(FBR F, BOX B, int AMO)
{
	/*CYL C1 ( { 0,0,0 }, { 0,0,A }, 1);
	CYL C2(  { A,A,0 }, { A,A,A }, 1);
	CYL C3(  {1.5,  1.5,0 }, { 1.5,1.5,A }, 1);
	F.C.push_back(C1);
	F.C.push_back(C2);
	F.C.push_back(C3);*/

	double x, y;
	srand(time(NULL));

	int step = 0;
	int num_of_try = 0;
	int i = 0;
	while(i < AMO)
	{
		
		x = (double)(rand() % ((int)(B.END[0] * EPS))) / EPS;
		y = (double)(rand() % ((int)(B.END[1] * EPS))) / EPS;
		//cout << "i = " << i << " x = " << x << " y = " << y << endl;
		//system("PAUSE");
		if (check_new(F, B, x, y))
		{
			F.C.push_back(CYL({ x,y,0 }, { x,y,B.END[2] }, 1));
			i++;
			cout << "i = " << i << " step = " << step << endl;
			step = 0;
		}
		if (step > 10000)
		{
			if (num_of_try > 10) return F;
			cout << "num_of_try = " <<  num_of_try << endl << endl;
			F.C.clear();
			i = 0;
			step = 0;
			num_of_try++;
		}
		step++;
	}
	

	return F;
}

bool check_new(FBR F, BOX B, double x, double y)
{
	if(~F.C.empty())
		for (int i = 0; i < F.C.size(); i++)
		{
			if( abs(x - F.C[i].O1[0]) <= 2*F.RC ) return false;
			if (abs(x - B.END[0]) <= F.RC) return false;
			if (abs(x - B.ST[0]) <= F.RC) return false;
			if (abs(y - F.C[i].O1[1]) <= 2 * F.RC ) return false;
			if (abs(y - B.END[1]) <= F.RC) return false;
			if (abs(y - B.ST[1]) <= F.RC) return false;
		}
	return true;
}


