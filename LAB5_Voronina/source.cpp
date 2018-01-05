#include "header.h"

int main()
{
	double R = 0.2;			// Радиус трубки
	double T = 0.01;		// Толщина стенки трубки
	double PER = 0.1;		// Процентное содержание трубок
	double angle = 5;		// Угол наклона

	BOX B;
	
	MESH M(B, R, PER);

	FBR F(R,T);

	if (!F.start_placing(B, M)) return 1;

	/*F.C[1].O2.x += 1;
	F.C[1].O2.y += 1;
	F.C[1].cyl_refresh();*/

	cout << "DIST = " << F.C[1].L.min_dist(F.C[0].L) << endl;

	/*OBJ O(F, B.str);

	ofstream fout;
	fout.open("D://output.geo");
	fout << "algebraic3d" << endl;
	B.print_boxes(fout);
	fout << endl;
	F.print_fbr(fout);
	fout << endl;
	O.print_obj(fout);
	fout.close();*/

	system("PAUSE");

	return 0;
}


