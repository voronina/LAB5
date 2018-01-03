#include "header.h"

#define A 3
#define R 0.5
#define T 0.01

void main()
{
	BOX B(initialize_box());
	
	FBR F(R, T);

	CYL C1 ( { 0,0,0 }, { 0,0,A }, 1);
	CYL C2(  { A,A,0 }, { A,A,A }, 1);
	CYL C3(  {1.5,  1.5,0 }, { 1.5,1.5,A }, 1);
	F.C.push_back(C1);	
	F.C.push_back(C2);
	F.C.push_back(C3);

	OBJ O(F, B.str);

	ofstream fout;
	fout.open("D://output.geo");
	fout << "algebraic3d" << endl;
	B.print_boxes(fout);
	fout << endl;
	F.print_fbr(fout);
	fout << endl;
	O.print_obj(fout);
	fout.close();

	//system("PAUSE");
}

vector<PLANE> initialize_box(void)
{
	vector<PLANE> P;
	vector<double> curr_vec(6);

	double M[6][6] = 
	{{0,0,0,	0,0,-A},
	{0,0,0,		0,-A,0},
	{0,0,0,		-A,0,0},
	{A,A,A,		A,0,0},
	{A,A,A,		0,A,0},
	{A,A,A,		0,0,A} };

	curr_vec.clear();
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) curr_vec.push_back(M[i][j]);
		P.push_back(PLANE(curr_vec, 10));
		curr_vec.clear();
	}

	return P;
}

