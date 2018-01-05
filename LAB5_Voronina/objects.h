// Составляющие куба
class PLANE {
public:
	POINT p;	
	vector<double> v;
	int bc = 1;

	PLANE(POINT new_point, vector<double> new_vect, int new_bc) : p(new_point), v(new_vect), bc(new_bc) {};

	// Вывод в GEO одной плоскости
	void print_plane (ofstream &fout, string obj_name, int obj_num, int in_num);
};


// Куб
class BOX {
public:
	string str = "box";
	vector<PLANE> P;
	POINT ST, END;

	BOX()
	{
		initialize_box();
		ST = P[0].p;
		END = P[3].p;	
	};

	void initialize_box();

	// Вывод в GEO данных о теле
	void print_boxes(ofstream &fout);
	
};


// Класс сетки
class MESH {
public:
	int AMO;
	int step_on_side1, step_on_side2;
	int delta;
	int** map;

	MESH(BOX B, double R, double PER) 
	{ 
		get_params(B, R, PER); 
		get_map();
	};

	// Необходимое количество трубок
	void get_params(BOX B, double R, double PER);
	void get_map();

	//  Получение шага дробления
	void step_and_delta();
};

// Трубка
class CYL {
public:
	POINT O1, O2;
	LINE L;
	int bc = 1;

	CYL(POINT new_O1, POINT new_O2, int new_bc) : O1(new_O1), O2(new_O2), bc(new_bc) {	cyl_refresh(); };

	void cyl_refresh()
	{
		L.M = O1; L.N = O2;
		L.line_refresh();
	}
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

	bool start_placing(BOX B, MESH M);

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