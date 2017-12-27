// —оставл€ющие куба
class PLANE {
public:
	vector<double> param;
	int bc = 0;

	PLANE(vector<double> new_param, int new_bc) : param(new_param), bc(new_bc) {};
};

//  уб
class BOX {
public:
	vector<PLANE> P;

	BOX(vector<PLANE> new_P) : P(new_P) {};

	void print_boxes();
};