#include "matrix.h"
#include <fstream>
#include <iostream>
//#include <vector>

using namespace std;
/*
matrix::matrix()
{
    //ctor
}
*/
void matrix::create_matrix(int N){
    matrix::n=N;
    //B = new double[n];
    A = new double *[n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new double[n];
	}
}
void matrix::set_matrix(){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
}
void matrix::get_matrix(){
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
void matrix::del_matrix(){
    for(i=0;i<n;i++)
        delete []A[i];
    delete []A;
}

void matrix::factoriz() {
	for (int k = 0; k < n; k++)
	{
		for (i = k + 1; i < n; i++)
			A[k][i] /= A[k][k];
		for (i = k + 1; i < n; i++)
			for (j = k + 1; j < n; j++)
				A[i][j] -= A[i][k] * A[k][j];
	}
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*
matrix::~matrix()
{
    //dtor
}
*/
