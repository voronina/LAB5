// Составляющие куба
class PLANE {
public:
	vector<double> param;
	int bc = 1;

	PLANE(vector<double> new_param, int new_bc) : param(new_param), bc(new_bc) {};


	void print_plane (ofstream &fout, string obj_name, int obj_num, int in_num);
};

// Куб
class BOX {
public:
	string str = "box";
	vector<PLANE> P;

	BOX(vector<PLANE> new_P) : P(new_P) {};

	void print_boxes(ofstream &fout);
};



// Трубка
class CYL {
public:
	vector<double> O1;
	vector<double> O2;
	int bc = 1;

	CYL(vector<double> new_O1, vector<double> new_O2, int new_bc) : O1(new_O1), O2(new_O2), bc(new_bc) {};

};


// Волокна
class FBR {
public:
	string str_F = "fiber";
	string str_C = "cyl";
	string str_H = "hole";

	vector<CYL> C; // Вектор трубок
	double RC, RH; // Радиус трубки и дырки
	double T; // Толщина стенок трубок

	FBR(double new_RC, double new_T) : RC(new_RC), T(new_T) { RH = RC - T; };

	void print_cyl(ofstream &fout, string obj_name, int obj_num);
	void print_cyl_with_hole(ofstream &fout, int obj_num);
	void print_or(ofstream &fout, string str);
	void print_fbr(ofstream &fout);

};


// Полный объект
class OBJ {
public:
	string str_M = "matrix";
	string str_O = "obj";
	string str_G = "gas";

	string str_F, str_C, str_H, str_B;

	OBJ(FBR F, string new_str_B) : str_B(new_str_B)
	{
		str_F = F.str_F;
		str_C = F.str_C;
		str_H = F.str_H;
	};

	void print_obj(ofstream &fout);
};