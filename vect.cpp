#include "vect.h"
#include <fstream>
#include <iostream>

using namespace std;
/*
matrix::matrix()
{
    //ctor
}
*/
void vect::create_vect(int N){
    vect::n=N;
    A = new double[n];
}
void vect::set_vect(){
    for(i=0;i<n;i++){
            cin>>A[i];
    }
}

void vect::get_vect(){
    for(i=0;i<n;i++){
            cout<<A[i]<<" ";
    }
        cout<<endl;
}
void vect::del_vect(){
    //for(i=0;i<n;i++){
        delete []A;
    //}
}
/*
matrix::~matrix()
{
    //dtor
}
*/

