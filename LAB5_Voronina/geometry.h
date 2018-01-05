// Класс точки
class POINT {
public:
	double x, y, z;

	POINT() {};
	POINT(double new_x, double new_y, double new_z) : x(new_x), y(new_y), z(new_z) {};

	double dist(POINT P);

	void print_point()
	{
		cout << "( " << x << "; " << y << "; " << z << ")" << endl;
	};
};

// Класс линии
class LINE {
public:
	POINT M, N;

	double l, m, n;
	double under;
	double cos_a, cos_b, cos_g;
	
	LINE() {};
	LINE(POINT O1, POINT O2) : M(O1), N(O2) { line_refresh(); };

	void line_refresh();
	double min_dist(LINE L);

	bool check_parallel(LINE L);
	double parallel_dist(LINE L);

	double det(double a, double b, double c, double d);
	double non_parallel_dist(LINE L);

	
};

