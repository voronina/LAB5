// Класс точки
class POINT {
public:
	double x, y, z;

	POINT() {};
	POINT(double new_x, double new_y, double new_z) : x(new_x), y(new_y), z(new_z) {};

	double dist(POINT P);
	bool point_with_shift(double alpha, double s, POINT ST, POINT END, double R);

	void print_point()
	{
		cout << "( " << x << "; " << y << "; " << z << ")" << endl;
	};
};

// Класс вектора
class VECT {
public:
	double x, y, z;

	VECT() {};
	VECT(double new_x, double new_y, double new_z) : x(new_x), y(new_y), z(new_z) {};
};

// Класс отрезка
class LINE {
public:
	POINT P0, P1;

	LINE() {};
	LINE(POINT O1, POINT O2) : P0(O1), P1(O2) { };

	POINT middle();
};