#include "matrix.h"
#include <fstream>
#include <iostream>

using namespace std;
/*
matrix::matrix()
{
    //ctor
}
*/
void matrix::create_matrix(int N){
    matrix::n=N;
    B = new double*[n];
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
/*
matrix::~matrix()
{
    //dtor
}
*/
