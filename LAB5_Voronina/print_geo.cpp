#include "header.h"

void BOX::print_boxes()
{
	string str1 = "solid box";
	string str2 = " = plane (";
	string str3 = ") - bc = ";

	for (int i = 0; i < P.size(); i++)
	{
		cout << str1 << i + 1 << str2;
		int N = P[i].param.size();
		for (int j = 0; j < N; j++)
		{
			cout << P[i].param[j];
			if (j != N/2 - 1 && j < N-1) cout << ", ";
			else if (j == N/2 - 1 && j < N - 1)  cout << "; ";
		}
		cout << str3 << P[i].bc << ";" << endl;
	}

	string str4 = "solid box = box";
	string str5 = " and box";
	cout << str4;
	for (int i = 0; i < P.size()-1; i++) cout << i+1 << str5;
	cout << P.size() << ";" << endl;

}