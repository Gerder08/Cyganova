#include "matrix.h"
#include <fstream>
#include <iostream>
#include <math.h>
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
    int imax=0, jmax=0, buf;
   // int *p, *q;
    double mx=0;
     p =new int[n];
     q =new int[n];

	F = new double *[n];
	for (int i = 0; i < n; i++)
	{
		F[i] = new double[n];
	}
	for ( i=0; i<n; i++)
    {
        p[i]=i;
        q[i]=i;
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            F[i][j] = A[i][j];
        }
    }
	for (int k = 0; k < n; k++)
	{


    // выбока главного элемента

        mx= fabs(F[p[k]][q[k]]);
        imax=k;
        jmax=k;
        for (i = k ; i < n; i++)
            for (j = k ; j < n; j++)
        {
            if(fabs(F[p[i]][q[j]])>mx)
            {
                mx=fabs(F[p[i]][q[j]]);
                imax=i;
                jmax=j;
           }
        }

    for (i = k + 1; i < n; i++){
			F[p[k]][q[i]] /= F[p[k]][q[k]];
		for (i = k + 1; i < n; i++)
			for (j = k + 1; j < n; j++)
				F[p[i]][q[j]] -= F[p[i]][q[k]] * F[p[k]][q[j]];
    }
  }
}

void matrix::get_factoriz(){
    matrix::factoriz();
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
            if(i==j){
                d*=F[p[i]][q[j]];
            }
        }
    }
    cout<<d;
    d=1;
}

void matrix::slae(){
        double s;
        double y[n];
    for (i = 0; i<n; i++){
        s=0;
        for(j=0; j<i; j++){
            s+=F[p[i]][q[j]]*y[j];
            y[i]=(V[p[i]]-s)/F[p[i]][q[j]];
        }
    }
    for(i=n-1;i>=0;i--)
    {
        s=0;
        for(j=i+1;j<n;j++)
        s+=F[p[i]][q[j]]*x[q[j]];
        x[q[i]]=y[i]-s;
    }
}

void matrix::obr(){
    for(j=0;j<n;j++){
        for(i=0;i<n;i++)
            if(i==j)
            V[i]=1;
        else V[i]=0;
        slae();
        for(i=0;i<n;i++)
            X[i][j]=x[i];
    }
}

void matrix::get_slae(){
    slae();
    for(i=0;i<n;i++){
            cout<<x[i]<<" ";
    }
    cout<<endl;
}
void matrix::get_obr(){
    obr();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<X[i][j]<<" ";
        }
        cout<<endl;
    }
}
void matrix::create_vect(int N){
    matrix::n=N;
    V = new double[n];
}
void matrix::set_vect(){
    for(i=0;i<n;i++){
            cin>>V[i];
    }
}

void matrix::get_vect(){
    for(i=0;i<n;i++){
            cout<<V[i]<<" ";
    }
        cout<<endl;
}
void matrix::del_vect(){
    //for(i=0;i<n;i++){
        delete []V;
    //}
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
