#include "header.h"

void main()
{
	string start_str = "algebraic3d";

	BOX B(initialize_box());

	ofstream fout;
	fout.open("output_geo.txt");

	cout << start_str << endl;
	fout << start_str << endl;
	
	B.print_boxes();


	
	
	fout.close();

	system("PAUSE");
}

vector<PLANE> initialize_box(void)
{
	vector<PLANE> P;
	vector<double> curr_vec(6);

	double M[6][6] = 
	{ {0,0,0,-1,0,0},
	{0,0,0,0,-1,0},
	{0,0,0,0,0,-1},
	{1,1,1,1,0,0},
	{1,1,1,0,1,0},
	{1,1,1,0,0,1} };

	curr_vec.clear();
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 6; j++) curr_vec.push_back(M[i][j]);
		P.push_back(PLANE(curr_vec, 0));
		curr_vec.clear();
	}

	return P;
}