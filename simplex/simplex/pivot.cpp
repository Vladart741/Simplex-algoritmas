#include "stdafx.h"
#include "Pivot.h"


std::vector<int> Pivot(std::vector<std::vector<double>>matrica, int n, int m)
{
	double min_piv1 = 0;
	int nr1=0, nr2=0;
	int kiek=0;
	std::vector<int> pivot;
	for (int i = 0; i < n; i++)
	{
		if (matrica[m - 1][i] < 0)
			kiek++;
	}
	if (kiek == 0)
	{
		goto end;
	}
	else
	{
		for (auto i = 1; i < n - 1; i++)
		{
			if (min_piv1 > matrica[m - 1][i] && matrica[m - 1][i]<0)
			{
				min_piv1 = matrica[m - 1][i];
				nr1 = i;
			}
		}
		double min_piv2;
		std::vector<std::vector<double>>piv2;

		for (auto i = 0; i < m - 1; i++)
		{
			if (matrica[i][nr1] > 0)
			{
				std::vector<double>x;
				x.push_back(matrica[i][nr1]);
				x.push_back(matrica[i][n - 1]);
				x.push_back(i);
				piv2.push_back(x);
			}
		}
		min_piv2 = piv2[0][1] / piv2[0][0];
		for (auto i = 0; i < piv2.size(); i++)
		{
			if (min_piv2 > piv2[i][1] / piv2[i][0])
			{
				nr2 = piv2[i][2];
			}
			else
			{
				nr2 = piv2[0][2];
			}
		}
	}


	end:
	pivot.push_back(nr1);
	pivot.push_back(nr2);
	return pivot;
}