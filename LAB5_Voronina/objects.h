// ������������ ����
class PLANE {
public:
	vector<double> point;	
	vector<double> vect;
	int bc = 1;

	PLANE(vector<double> new_point, vector<double> new_vect, int new_bc) : point(new_point), vect(new_vect), bc(new_bc) {};

	// ����� � GEO ����� ���������
	void print_plane (ofstream &fout, string obj_name, int obj_num, int in_num);
};

// ���
class BOX {
public:
	string str = "box";
	vector<PLANE> P;
	vector<double> ST;
	vector<double> END;

	BOX(vector<PLANE> new_P) : P(new_P) 
	{
		ST = P[0].point;
		END = P[3].point;	
	};

	// ����������� ���������� ������
	int get_amo(double R, double PER);

	// ����� � GEO ������ � ����
	void print_boxes(ofstream &fout);
};



// ������
class CYL {
public:
	vector<double> O1;
	vector<double> O2;
	int bc = 1;

	// ��� ���� ���������� ��������� ��� ��������� ������

	CYL(vector<double> new_O1, vector<double> new_O2, int new_bc) : O1(new_O1), O2(new_O2), bc(new_bc) {};

};


// �������
class FBR {
public:
	string str_F = "fiber";
	string str_C = "cyl";
	string str_H = "hole";

	vector<CYL> C; // ������ ������
	double RC, RH; // ������ ������ � �����
	double T; // ������� ������ ������

	FBR(double new_RC, double new_T) : RC(new_RC), T(new_T) { RH = RC - T; };

	void print_cyl(ofstream &fout, string obj_name, int obj_num);
	void print_cyl_with_hole(ofstream &fout, int obj_num);
	void print_or(ofstream &fout, string str);
	void print_fbr(ofstream &fout);

};


// ������ ������
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