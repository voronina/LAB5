#include "header.h"

void main()
{
	double R = 0.2;		// Радиус трубки
	double T = 0.01;		// Толщина стенки трубки
	double PER = 0.2;		// Процентное содержание трубок

	BOX B (initialize_box());
	
	MESH M(B, R, PER);

	FBR F(R,T);

	F.start_placing(B, M);

	cout << "SIZE = " << F.C.size() << endl;

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

	cout << "FIN" << endl;

	system("PAUSE");
}


