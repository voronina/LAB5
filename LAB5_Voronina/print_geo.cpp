#include "header.h"

string SO = "solid ";
string BC = ") -bc = ";

void PLANE::print_plane(ofstream &fout, string obj_name, int obj_num, int in_num)
{
	if ( in_num == -1 ) 	fout << SO << obj_name << obj_num << " = plane(";
	else fout << SO << obj_name << obj_num << in_num << " = plane(";

	fout << point[0] << ", " << point[1] << ", " << point[2] << "; ";
	fout << vect[0] << ", " << vect[1] << ", " << vect[2] ;

	fout << BC << bc << ";" << endl;
}

void print_field(ofstream &fout, vector<PLANE> P, string obj_name, int obj_num)
{
	fout << SO << obj_name << " = ";

	for (int i = 0; i < P.size() - 1; i++) fout << obj_name << i + 1 << " and ";
	fout << obj_name << P.size() << ";" << endl;
}

void BOX::print_boxes(ofstream &fout)
{
	for (int i = 0; i < P.size(); i++) P[i].print_plane(fout, str, i + 1, -1);
	print_field(fout, P, str, 0);
}

void FBR::print_cyl(ofstream &fout, string obj_name, int obj_num)
{
	fout << SO << obj_name << "_" << obj_num+1 << " = cylinder(";

	fout << C[obj_num].O1[0] << ", " << C[obj_num].O1[1] << ", " << C[obj_num].O1[2] << "; ";
	fout << C[obj_num].O2[0] << ", " << C[obj_num].O2[1] << ", " << C[obj_num].O2[2] << "; ";

	if (obj_name == "cyl") fout << RC;
	else fout << RH;

	fout << BC << C[obj_num].bc << ";" << endl;
}

void FBR::print_cyl_with_hole(ofstream &fout, int obj_num)
{
	print_cyl(fout, str_C, obj_num);
	print_cyl(fout, str_H, obj_num);
	fout << SO << str_F << "_" << obj_num+1 << " = " << str_C << "_" << obj_num+1 << " and not " << str_H << "_" << obj_num+1 << ";" << endl;
}

void FBR::print_or(ofstream &fout, string str)
{
	fout << SO << str << "s = ";
	for (int i = 0; i < C.size() - 1; i++) fout << str << "_" << i+1 << " or ";
	fout << str << "_" << C.size() << ";" << endl;
}


void FBR::print_fbr(ofstream &fout)
{
	for (int i = 0; i < C.size(); i++) print_cyl_with_hole(fout, i);

	print_or(fout, str_C);
	print_or(fout, str_H);
	print_or(fout, str_F);

}

void OBJ::print_obj(ofstream &fout)
{
	fout << SO << str_M << " = " << str_B << " and not " << str_C << "s;" << endl;
	fout << SO << str_O << " = " << str_B << " and " << str_F << "s;" << endl;
	fout << SO << str_G << " = " << str_B << " and " << str_H << "s;" << endl;

	fout << "tlo " << str_O << " -col=[1,1,0];" << endl;
	fout << "tlo " << str_G << " -col=[0,1,1] -transparent;" << endl;
	fout << "tlo " << str_M << " -col=[0,0,1] -transparent;" << endl;
}