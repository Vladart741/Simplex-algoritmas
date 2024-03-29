﻿#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <vector>
#include "Pivot.h"
#include "Reform.h"

int main() {
	std::ifstream fd("Duomenys.txt");
	int n, m;
	
	fd >> n >> m;	
	std::vector<std::vector<double>>matrica;
	std::vector<int>doumenys;

	for (auto i = 0; i<m; i++)
	{
		std::vector<double>m1;
		for (auto j = 0; j<n; j++)
		{
			double x;
			fd >> x;
			m1.push_back(x);
		}
		matrica.push_back(m1);
	} //nuskaitymas
		start:
		std::vector<int> pivot;
		pivot = Pivot(matrica, n, m);
		
		if (pivot[0] ==0 && pivot[1] ==0)
		{
			std::cout<<"C: " << matrica[m - 1][n - 1]*-1 << std::endl;
		}
		else
		{
			std::cout << pivot[0] << " " << pivot[1] << " Pivot point" << std::endl;
			std::vector<int>duomenys;
			duomenys.push_back(n);
			duomenys.push_back(m);
			duomenys.push_back(pivot[0]);
			duomenys.push_back(pivot[1]);
			matrica = Reform(matrica, duomenys);
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					std::cout << matrica[i][j] << "\t";
				}
				std::cout << std::endl;
			}

			goto start;
		}
	system("pause");
	return 0;
}


