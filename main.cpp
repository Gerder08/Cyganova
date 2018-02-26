//#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "matrix.h"
#include "vect.h"
#include "matrix.cpp"
#include "vect.cpp"
#include <vector>

using namespace std;

int main()
{
	int sw, n;

	//double *A;
	//double *B;

	//cin >> n;
/*
	B = new double[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}

	delete[] B;
	for(i=0; i<n; i++)
	delete[] A[i];
	delete[] A;
	 */
    matrix matr;
    vect v;
    cout<<"n= ";cin >> n;
    matr.create_matrix(n);
    v.create_vect(n);


	while (1)
	{
		system("CLS");
		cout << "Vybirite punkt" << endl;
		cout
			<< "1. Vvod dannyh v matr" << endl
			<< "2. Vvod dannyh v v" << endl
			<< "3. Vyvod dannyh iz matr" << endl
			<< "4. Vyvod dannyh iz v" << endl
			<< "5. Factorizaciya matr " << endl
			<< "6. " << endl
			<< "7. " << endl
			<< "8." << endl
			<< "9. " << endl
			<< "10.Vyhod" << endl;

		cin >> sw;
		switch (sw)
		{

		case 1:
		{
		    cout<<"Vvod matr"<<endl;
		    matr.set_matrix();
            break;
		}
		case 2:
		{
		    cout<<"Vvod v";
		    v.set_vect();
			break;

		}
		case 3:
		{
		    cout<<"Vyvod matr"<<endl;
            matr.get_matrix();
            system("pause");
			break;
		}
		case 4:
		{
		    cout<<"Vyvod v"<<endl;
		    v.get_vect();
            system("pause");
			break;
		}
		case 5:
		{
			cout <<"Factoriz matr"<<endl;
			matr.factoriz();
			system("pause");
			break;

		}
		case 6:
		{

			break;
		}
		case 7:
		{


			break;

		}
		case 8:
		{

			break;

		}
		case 9:
		{

			break;

		}
		case 10:
		{
            matr.del_matrix();
            v.del_vect();
			return 0;

		}
		}
	}
}
