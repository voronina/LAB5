#include "header.h"

#define M_PI 3.14159265358979323846

void MESH::get_params(BOX B, double R, double PER)
{
	double SC = M_PI * pow(R, 2);
	double SB = B.END[0] * B.END[1];
	double SPER = SB * PER;
	AMO = SPER/SC + 1;
	step_and_delta();
	/*cout << "SC = " << SC << endl;
	cout << "SB = " << SB << endl;
	cout << "SPER = " << SPER << endl;
	cout << "AMO = " << AMO << endl;*/
}

void MESH::step_and_delta()
{
	double sqrt_AMO = sqrt((double)AMO);

	step_on_side1 = (int)sqrt_AMO;
	step_on_side2 = step_on_side1;

	delta = AMO - step_on_side1*step_on_side2;

	int i = 0;
	while ( delta > 0)
	{
		if (i%2 == 0) step_on_side1++;
		else step_on_side2++;
		delta = AMO - step_on_side1*step_on_side2;
	}
	
	delta = abs(delta);

	
	cout << "AMO = " << AMO << endl;
	cout << "step_on_side1 = " << step_on_side1 << endl;
	cout << "step_on_side2 = " << step_on_side2 << endl;
	cout << "delta = " << delta << endl;
}


bool FBR::start_placing(BOX B, MESH M)
{
	// Параметры для стороны i
	int N_i = M.step_on_side1;
	double step_i = abs(B.END[0] - B.ST[0]) / N_i;
	if (step_i <= 3 * RC) return false;
	double A_i, B_i;

	// Параметры для стороны j
	int N_j = M.step_on_side2;
	double step_j = abs(B.END[1] - B.ST[1]) / N_j;
	if (step_i <= 3 * RC) return false;
	double A_j, B_j;

	double x, y;

	srand(time(NULL));

	for (int i = 0; i < N_i; i++)
	{
		// Диапозон ячейки по стороне i
		A_i = B.ST[0] + i * step_i + 1.001 * RC;
		B_i = step_i - 2 * 1.001 * RC;
		cout << "i = " << i << " A_i = " << A_i << " B_i = " << B_i << endl;

		// Расширение диапозона из-за незаполненности
		if (i == (M.step_on_side1 - M.delta) && M.delta > 0)
		{
			N_j = M.step_on_side2 - 1;
			step_j = abs(B.END[1] - B.ST[1]) / N_j;
		}

		for (int j = 0; j < N_j; j++)
		{
			// Диапозон ячейки по стороне j
			A_j = B.ST[1] + j * step_j + 1.001 * RC;
			B_j = step_j - 2 * 1.001 * RC;
			cout << "j = " << j << " A_j = " << A_j << " B_j = " << B_j << endl;

			x = A_i + (double)(rand() % ((int)((B_i)* EPS))) / EPS;
			y = A_j + (double)(rand() % ((int)((B_j)* EPS))) / EPS;

			C.push_back(CYL({ x,y,0 }, { x,y,B.END[2] }, 1));

			//cout << " x = " << x << " y = " << y << endl;
		}
		cout << endl;
		//system("PAUSE");
	}

	return true;
}
