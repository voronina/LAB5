#include "header.h"

#define M_PI 3.14159265358979323846

int BOX::get_amo(double R, double PER)
{
	double SC = M_PI * pow(R, 2);
	double SB = END[0] * END[1];
	double SPER = SB * PER;
	double AMO = SPER/SC + 1;
	/*cout << "SC = " << SC << endl;
	cout << "SB = " << SB << endl;
	cout << "SPER = " << SPER << endl;
	cout << "AMO = " << AMO << endl;*/
	return (int)AMO;
}