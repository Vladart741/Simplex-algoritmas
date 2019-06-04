#include "stdafx.h"
#include "Reform.h"
std::vector<std::vector<double>> Reform(std::vector<std::vector<double>>matrica, std::vector<int>duomenys)
{
	int pivot[2];
	int n, m;
	n = duomenys[0];
	m = duomenys[1];
	pivot[0] = duomenys[3];
	pivot[1] = duomenys[2];
	double x = matrica[pivot[0]][pivot[1]];
	for (int i = 0; i < n; i++)
		{
			matrica[pivot[0]][i] = matrica[pivot[0]][i] * std::fabs(1 / x);
		}
	

	for (int i = 0; i < m; i++)
	{
		if (i != pivot[0])
		{
			double daugiklis = 0;
			if (matrica[i][pivot[1]] != 0)
			{
				daugiklis = matrica[i][pivot[1]] / matrica[pivot[0]][pivot[1]];
			}
			
				for (int j = 0; j < n; j++)
					{
						matrica[i][j] = matrica[i][j] - (matrica[pivot[0]][j] * daugiklis);
					}

		}
				
	}
	return matrica;
}