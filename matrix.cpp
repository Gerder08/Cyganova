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
    //F = new double *[n];
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

	F = new double *[n];
	for (int i = 0; i < n; i++)
	{
		F[i] = new double[n];
	}
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            F[i][j] = A[i][j];
        }
    }
	for (int k = 0; k < n; k++)
	{
		for (i = k + 1; i < n; i++)
			F[k][i] /= F[k][k];
		for (i = k + 1; i < n; i++)
			for (j = k + 1; j < n; j++)
				F[i][j] -= F[i][k] * F[k][j];
	}
	/*
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
    */
    cout<<endl;
	for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<F[i][j]<<" ";
        }
        cout<<endl;
    }
}
void matrix::det(){
    matrix::factoriz();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i=j)
                d*=F[i][j];
        }
    }
    cout<<d;
}
/*
void matrix::Det() {
    double mas=**A;
    int m=n;
int i, j, d, k, o;
int ki, kj, di, dj;
int **p;
p = new int*[m];
for (i = 0; i<m; i++)
p[i] = new int[m];
j = 0; d = 0;
k = 1; //(-1) в степени i
n = m - 1;
if (m<1) cout << "Opr vycheslit' nevozmojno!";
if (m == 1) {
d = mas[0][0];
return(d);
}
if (m == 2) {
d = mas[0][0] * mas[1][1] - (mas[1][0] * mas[0][1]);
return(d);
}
if (m>2) {
for (i = 0; i<m; i++) {
di = 0;
for (ki = 0; ki<m - 1; ki++) { // проверка индекса строки
if (ki == i) di = 1;
dj = 0;
for (kj = 0; kj<m - 1; kj++) { // проверка индекса столбца
if (kj == j) dj = 1;
p[ki][kj] = mas[ki + di][kj + dj];
}
}
d = d + k * mas[i][0] * Det(p, o);
k = -k;
}
}
cout<<d;
} */
/*
void matrix::det(){
int l;
double d;
double sum11=1,sum12=0, sum21=1, sum22=0;
// находим детерминант
        for(int i=0;i<n;i++){
            sum11=1; l=2*n-1-i;sum21=1;
            for(int j=0;j<n;j++){
                sum21*=A[j][l%n];
            l--;
            sum11*=A[j][(j+i)%(n)];
        }
        sum22+=sum21;
        sum12+=sum11;
    }
    d=sum12-sum22;
    cout<<d;
}
*/
/*
matrix::~matrix()
{
    //dtor
}
*/
