#include "header.h"

int main()
{
	double R = 0.1;			// Радиус трубки
	double T = 0.01;		// Толщина стенки трубки
	double PER = 0.3;		// Процентное содержание трубок
	double angle = 10;		// Угол наклона

	/*POINT A1(0, 0, 0);	POINT B1(0, 0, 5);	POINT A2(1, 4, 0);	POINT B2(1, 4, 5);
	LINE S1(A1, B1);	LINE S2(A2, B2);
	cout << "ANS = " << dist3D_LINE_to_LINE(S1, S2) << endl;*/

	BOX B;
	
	MESH M(B, R, PER);

	FBR F(R,T);

	if (!F.start_placing(B, M))
	{
		cout << "Error!" << endl;
		system("PAUSE");
		return 1;
	}

	F.cyl_tilt(angle, M, B);

	OBJ O(F, B.str);

	system("PAUSE");

	ofstream fout;
	fout.open("D://output.geo");
	fout << "algebraic3d" << endl;
	B.print_boxes(fout);
	fout << endl;
	F.print_fbr(fout);
	fout << endl;
	O.print_obj(fout);
	fout.close();

	system("PAUSE");

	return 0;
}


