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
    E = new double *[n];
    for (int i = 0; i < n; i++){
        E[i] = new double[n];
    }
    A = new double *[n];
    for (int i = 0; i < n; i++){
        A[i] = new double[n];
    }
    X = new double *[n];
    for (int i = 0; i < n; i++){
        X[i] = new double[n];
    }

	//b = new double[n];
    for(i=0;i<n;i++){
    for(j=0;j<n;j++){
            E[i][j] = 1;
            if(i!=j){E[i][j] = 0;}
    }
    }
	buf = new double[n];
    x = new double[n];
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
    //delete []b;
    delete []buf;
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


    // ������ �������� ��������

        mx= fabs(F[p[k]][q[k]]);
        imax=k;
        jmax=k;
        for (i = k; i < n; i++)
            for (j = k; j < n; j++)
        {
            if(fabs(F[p[i]][q[j]])>mx)
            {
                mx=fabs(F[p[i]][q[j]]);
                imax=i;
                jmax=j;
           }
        }


    for (i = k + 1; i < n; i++)
			F[p[k]][q[i]] /= F[p[k]][q[k]];
		for (i = k + 1; i < n; i++)
			for (j = k + 1; j < n; j++)
				F[p[i]][q[j]] -= F[p[i]][q[k]] * F[p[k]][q[j]];
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

void matrix::slae(double *b){
        double s;
        double y[n];
        //x = new double[n];
        for(i=0;i<n;i++){
            y[i]=0;
            x[i]=0;
        }

    for (i = 0;i<n;i++){
        s=0;
        for(j=0; j<=i; j++){
            s+=F[p[i]][q[j]]*y[j];
        }
            y[i]=(b[p[i]]-s)/F[p[i]][q[i]];
    }
    for(i=n-1;i>=0;i--){
        s=0;
        for(j=i+1;j<n;j++){
        s+=F[p[i]][q[j]]*x[q[j]];
        }
        x[q[i]]=y[i]-s;
    }
}

void matrix::obr(){
    int l,m;
    double *I;
    I = new double[n];
        for(m=0;m<n;m++){
            for(l=0;l<n;l++){
        I[l] = 0;
        if(l==m){
                I[l]=1;
        }
    }
        slae(I);
        for(l=0;l<n;l++){
                cout<<x[l]<<" ";
            X[l][m]=x[l];

        }
        cout<<endl;
    }
}


	void matrix::obras() {
    double s;
    const double one = 1.0;
	//1 ���� ----------------------------
	for (int i =0; i<n; i++){
        for (int j =i+1; j<n; j++){
        F[p[i]][q[j]]=-F[p[i]][q[j]];
        }
	}
    for (int j =0; j<n; j++){
     F[p[j]][q[j]]=one/F[p[j]][q[j]];
       for (int i =j+1; i<n; i++){
            F[p[i]][q[j]]=-F[p[i]][q[j]]*F[p[i]][q[j]];
       }
     }
       //2 ����----------------------
       // U
      for(int k=n-1; k>0; k--){
        for (int i =0; i<=k-2; i++){
            for (int j =k; j<n; j++){
               F[p[i]][q[j]]+=F[p[i]][q[k-1]]*F[p[k-1]][q[j]];
            }
        }
      }
      // L
      for(int k=0; k<n-1; k++){
         for (int i =k+2; i<n; i++){
            for (int j =0; j<=k; j++){
                 F[p[i]][q[j]]+=F[p[i]][q[k+1]]*F[p[k+1]][q[j]];
            }
         }
            for (int j =0; j<=k; j++){
                F[p[k+1]][q[j]]*=F[p[k+1]][q[k+1]];
            }
      }
     // 3 ����-----------------------------------
     for (int i =0; i<n; i++){
        for (int j =0; j<n; j++){
            if(i<j){
                s=0;
                for(int k=j; k<n; k++){
                  s+=F[p[i]][q[k]]*F[p[k]][q[j]];
                }
            }
            if(i>=j){
                s=F[p[i]][q[j]];
                for(int k=i+1; k<n; k++){
                    s+=F[p[i]][q[k]]*F[p[k]][q[j]];
                }
            }
            F[p[i]][q[j]]=s;
        }
	}
}
void matrix::get_slae(){
    slae(V);
    for(i=0;i<n;i++){
            cout<<x[i]<<" ";
    }
    cout<<endl;
}

void matrix::get_obras(){
    obras();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<F[i][j]<<" ";
        }
        cout<<endl;
    }
}
/*
double matrix::use_slae(){
    for(int j =0; j<n; j++){
            //b[i]=1;
            slae(&E[0][j]);
            //b[i] = 0;
    }
}
*/
void matrix::get_obr(){
    obr();
     for(i=0;i<n;i++){
    for(j=0;j<n;j++){
        cout<<E[i][j];
    }
    cout<<endl;
    }
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
void matrix::get_p_q(){
    for(i=0;i<n;i++)
        cout<<p[i]<<"   "<<q[i]<<endl;
}
void matrix::ex1{
    cout<<"===============================================================================";
    cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|";
    cout<<"|--------+------+-----------+-------------------------+-----------------------|";
    for(int N = 5; N<=100; N+5;){
        matrix::create_matrix(N);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                A[i][j] = rand() %50 -50;
            }
        }
    }
}
