//#include "stdafx.h"
#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "matrix.h"
#include "vect.h"
//#include "matrix.cpp"
//#include "vect.cpp"
//#include <vector>

using namespace std;

int main()
{
	int sw, n;

	//double *A;
	//double *B;


    matrix matr;
    cout<<"n= ";cin >> n;
    matr.create_matrix(n);
    matr.create_vect(n);


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
			<< "6. Detremenant matr" << endl
			<< "7. " << endl
			<< "8. " << endl
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
		    matr.set_vect();
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
		    matr.get_vect();
            system("pause");
			break;
		}
		case 5:
		{
			cout <<"Factoriz matr"<<endl;
			matr.get_factoriz();
			system("pause");
			break;

		}
		case 6:
		{
            cout <<"Detremenant matr"<<endl;
			matr.det();
			system("pause");
			break;
		}
		case 7:
		{
            cout<<"slae"<<endl;
            matr.get_slae();
            system("pause");

			break;

		}
		case 8:
		{
            cout<<"obr"<<endl;
            matr.get_obr();
            system("pause");
			break;

		}
		case 9:
		{

			break;

		}
		case 10:
		{
            matr.del_matrix();
            matr.del_vect();
			return 0;

		}
		}
	}
}
