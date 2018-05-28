#include "matrix.h"
#include <fstream>
#include <iostream>
#include <math.h>
#include <time.h>
#include <chrono>
#include <conio.h>
#include <stdlib.h>
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


    // выбока главного элемента

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


    for (i = k + 1; i < n; i++){
			F[p[k]][q[i]] /= F[p[k]][q[k]];
			matrix::number++;
			}
		for (i = k + 1; i < n; i++){
			for (j = k + 1; j < n; j++){
				F[p[i]][q[j]] -= F[p[i]][q[k]] * F[p[k]][q[j]];
				matrix::number++;
			}
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
            matrix::number++;
        }
            y[i]=(b[p[i]]-s)/F[p[i]][q[i]];
    }
    for(i=n-1;i>=0;i--){
        s=0;
        matrix::number++;
        for(j=i+1;j<n;j++){
        s+=F[p[i]][q[j]]*x[q[j]];
        }
        x[q[i]]=y[i]-s;
        matrix::number++;
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
	//1 этап ----------------------------
	for (int i =0; i<n; i++){
        for (int j =i+1; j<n; j++){
        F[p[i]][q[j]]=-F[p[i]][q[j]];
        }
	}
    for (int j =0; j<n; j++){
     F[p[j]][q[j]]=one/F[p[j]][q[j]];
     matrix::number++;
       for (int i =j+1; i<n; i++){
            F[p[i]][q[j]]=-F[p[i]][q[j]]*F[p[i]][q[j]];
            matrix::number++;
       }
     }
       //2 этап----------------------
       // U
      for(int k=n-1; k>0; k--){
        for (int i =0; i<=k-2; i++){
            for (int j =k; j<n; j++){
               F[p[i]][q[j]]+=F[p[i]][q[k-1]]*F[p[k-1]][q[j]];
               matrix::number++;
            }
        }
      }
      // L
      for(int k=0; k<n-1; k++){
         for (int i =k+2; i<n; i++){
            for (int j =0; j<=k; j++){
                 F[p[i]][q[j]]+=F[p[i]][q[k+1]]*F[p[k+1]][q[j]];
                 matrix::number++;
            }
         }
            for (int j =0; j<=k; j++){
                F[p[k+1]][q[j]]*=F[p[k+1]][q[k+1]];
                matrix::number++;
            }
      }
     // 3 этап-----------------------------------
     for (int i =0; i<n; i++){
        for (int j =0; j<n; j++){
            if(i<j){
                s=0;
                for(int k=j; k<n; k++){
                  s+=F[p[i]][q[k]]*F[p[k]][q[j]];
                  matrix::number++;
                }
            }
            if(i>=j){
                s=F[p[i]][q[j]];
                for(int k=i+1; k<n; k++){
                    s+=F[p[i]][q[k]]*F[p[k]][q[j]];
                    matrix::number++;
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

void multiplication(double *B, double **A, int n, double *x)
{
	for (int i = 0; i < n; i++)
	{
		B[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			B[i] += A[i][j] * x[j];
		}
	}
}

double pogreshnost(double *B, double **A, int n, double *x, double *x2, int *q)
{
	double max = fabs(x[0] - x2[0]);
	for (int i = 1; i < n; i++)
	{
		if (max < fabs(x[i] - x2[i]))
		{
			max = fabs(x[i] - x2[i]);
		}
	}
	return max;
}

void matrix::ex1()
{
	//int number = 0;
	int *znak = new int(1);
	//int n=matrix::n;
	//system("cls");
    cout<<"==============================================================================="<<endl;
    cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
    cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
	for (matrix::n = 5; matrix::n <= 100; matrix::n += 5)
	{
	    //cout<< matrix::n<<endl;
		matrix::number = 0;
		srand(time(0));
		double *x = new double[n];
		double *x2 = new double[n];
		int *q = new int[n];
		//double *B = new double[n];
		//double **F = new double*[n];
		matrix::create_matrix(n);
		matrix::create_vect(n);

		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				matrix::A[i][j] = rand() % 200 - 100;
			}
		}
		for (int i = 0; i < n; i++)
		{
			x[i] = i + 1;
		}
		multiplication(matrix::V, matrix::A, n, x);
		auto begin = chrono::high_resolution_clock::now();
		factoriz();
        slae(V);
		auto end = chrono::high_resolution_clock::now();
		printf("|%9i", n);
		cout << "|";
		printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
		cout << "|";
		printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
		cout << "|";
		printf("%21.4f", (double)(n*n*n) / 3);
		cout << "|";
		printf("%16i", matrix::number);
		cout << "|\n";
		delete[] V;
		delete[] q;
		delete[] x;
		delete[] x2;
		for (int i = 0; i<n; i++)
		{
			delete[] A[i];
		}
		delete[] A;
	}
	printf("|_________|___________|_____________|_____________________|________________|\n");
	delete znak;
	system("pause");
}

void matrix::ex2_1(double **A, int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			A[i - 1][j - 1] = 1.0 / (i + j - 1.0);
		}
	}
}
void matrix::ex2_2(double **A, int n)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			A[i][j] = 0;
		}
		A[i][i] = 1;
	}
	for (int i = 0; i < 19; i++)
	{
		A[i][i + 1] = 1;
	}
}
void matrix::ex2_3(double **A, int n)
{
	const int k = 7;
	double S[k][k] = {
		{ 5,4,7,5,6,7,5 },
		{ 4,12,8,7,8,8,6 },
		{ 7,8,10,9,8,7,7 },
		{ 5,7,9,11,9,7,5 },
		{ 6,8,8,9,10,8,9 },
		{ 7,8,7,7,8,10,10 },
		{ 5,6,7,5,9,10,10 }
	};
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			A[i][j] = S[i][j];
		}
	}
}
void matrix::ex2_4(double **A, int n)
{
	n++;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i == j)
			{
				A[i - 1][j - 1] = 0.01 / (n - i + 1) / (i + 1);
			}
			else
			{
				if (i < j)
				{
					A[i - 1][j - 1] = 0;
				}
				else
				{
					A[i - 1][j - 1] = i * (n - j);
				}
			}
		}
	}
}
void matrix::ex2_5(double **A, int n)
{
	n++;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			if (i == j)
			{
				A[i - 1][j - 1] = 0.01 / (n - i + 1) / (i + 1);
			}
			else
			{
				if (i < j)
				{
					A[i - 1][j - 1] = j * (n - i);
				}
				else
				{
					A[i - 1][j - 1] = i * (n - j);
				}
			}
		}
	}
}
void matrix::ex2_6(double **A, int n)
{
	const int k = 8;
	double S[k][k] = {
		{ 1 / tan(0.0000075)     , 1 / cos(3.142354)     , 1 - (1 / tan(0.0000075))  , 1 / cos(3.142354)     , 1                    , 1                   , 1                   , 1 },
		{ -(1 / cos(0.00004))    , 1 / tan(3.145673)     , -(1 / cos(0.00004))     , 1 + (1 / tan(3.145673)) , 1                    , 1                   , 1                   , 1 },
		{ 1 - (1 / tan(0.0000075)) , 1 / cos(3.142354)     , 1 / tan(0.0000075)      , 1 / cos(3.142354)     , 1 - (1 / tan(0.0000075)) , 1 / cos(3.142354)     , 1                   , 1 },
		{ -(1 / cos(0.00004))    , 1 + (1 / tan(3.145673)) , -(1 / cos(0.00004))     , 1 / tan(3.145673)     , -(1 / cos(0.00004))    , 1 + (1 / tan(3.145673)) , 1                   , 1 },
		{ 1                    , 1                   , 1 - (1 / tan(0.000006))   , 1 / cos(0.000045)     , 1 / tan(0.0000075)     , 1 / cos(3.142354)     , 1 - (1 / tan(0.000006)) , 1 / cos(0.000045) },
		{ 1                    , 1                   , -(1 / cos(0.00004))     , 1 + (1 / tan(3.145673)) , -(1 / cos(0.00004))    , 1 / tan(3.145673)     , -(1 / cos(0.00004))   , 1 + (1 / tan(3.145673)) },
		{ 1                    , 1                   , 1                     , 1                   , 1 - (1 / tan(0.0000075)) , 1 / cos(3.142354)     , 1 / tan(0.0000075)    , 1 / cos(3.142354) },
		{ 1                    , 1                   , 1                     , 1                   , -(1 / cos(0.00004))    , 1 + (1 / tan(3.145673)) , -(1 / cos(0.00004))   , 1 / tan(3.145673) }
	};
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			A[i][j] = S[i][j];
		}
	}
}
void matrix::ex2_7(double **A, int n)
{
	srand(time(0));
	int al = rand() % 200 - 100;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = 0;
		}
		A[i][i] = pow(al, (abs(n - 2 * i) / 2));
		A[0][i] = A[i][0] = A[0][0] / pow(al, i);
		A[0][n - 1] = A[i][n - 1] = A[n - 1][n - 1] / pow(al, i);
	}
}
void matrix::ex2_8(double **A, int n)
{
	double h = 0;
	srand(time(0));
	if (rand() % 2 == 0)
	{
		h = 1.0 / (rand() % 100 + 2);
	}
	else
	{
		if (rand() % 2 == 1)
		{
			h = 1000.0 - (1 / (rand() % 100 + 2));
		}
		else
		{
			h = 1000.0 + (1 / (rand() % 100 + 2));
		}
	}
	n++;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			A[i - 1][j - 1] = pow(2.7183, i*j*h);
		}
	}
}
void matrix::ex2_9(double **A, int n)
{
	srand(time(0));
	double c = RAND_MAX - (rand() % 100000);
	if (rand() % 2 == 0)
	{
		c = -c;
	}
	n++;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			A[i - 1][j - 1] = c + ((double)log10(i*j) / log10(2));
		}
	}
}
void matrix::ex2_10(double **A, int n)
{
	const int k = 4;
	double S[k][k] = {
		{ 0.00009143,  0,  0,  0 },
		{ 0.8762,  0.00007156,  0,  0 },
		{ 0.7943,  0.8143,  0.00009504,  0 },
		{ 0.8017,  0.6123,  0.7165,  0.00007123 }
	};
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; j++)
		{
			A[i][j] = S[i][j];
		}
	}
}

void matrix::ex2()
{
	//matrix::number = 0;
	int *znak = new int(1);
	system("cls");
	for (int f = 1; f < 11; f++)
	{
		if (f == 2)
		{
			printf("\n\n\n       № Matrix %5i\n", f);
			cout<<"==============================================================================="<<endl;
            cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
            cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
			int n = 20;
			matrix::number = 0;
			srand(time(0));
			double *x = new double[n];
			double *x2 = new double[n];
			int *q = new int[n];
			matrix::create_matrix(n);
		matrix::create_vect(n);

			ex2_2(matrix::A, n);
			for (int i = 0; i < n; i++)
			{
				x[i] = i + 1;
			}
			multiplication(matrix::V, matrix::A, n, x);
            auto begin = chrono::high_resolution_clock::now();
            factoriz();
            slae(V);
            auto end = chrono::high_resolution_clock::now();
			printf("|%9i", n);
			cout << "|";
			printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
			cout << "|";
			printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
			cout << "|";
			printf("%21.4f", (double)(n*n*n) / 3);
			cout << "|";
			printf("%16i", matrix::number);
			cout << "|\n";
			printf("|_________|___________|_____________|_____________________|________________|\n");
			delete[] V;
			delete[] q;
			delete[] x;
			delete[] x2;
			for (int i = 0; i<n; i++)
			{
				delete[] A[i];
			}
			delete[] A;
		}
		else if (f == 3)
		{
			printf("\n\n\n       № Matrix %5i\n", f);
			cout<<"==============================================================================="<<endl;
            cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
            cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
			int n = 7;
			matrix::number = 0;
			srand(time(0));
			double *x = new double[n];
			double *x2 = new double[n];
			int *q = new int[n];
			matrix::create_matrix(n);
		matrix::create_vect(n);

			ex2_3(A, n);
			for (int i = 0; i < n; i++)
			{
				x[i] = i + 1;
			}
			multiplication(matrix::V, matrix::A, n, x);
            auto begin = chrono::high_resolution_clock::now();
            factoriz();
            slae(V);
            auto end = chrono::high_resolution_clock::now();
			printf("|%9i", n);
			cout << "|";
			printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
			cout << "|";
			printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
			cout << "|";
			printf("%21.4f", (double)(n*n*n) / 3);
			cout << "|";
			printf("%16i", matrix::number);
			cout << "|\n";
			printf("|_________|___________|_____________|_____________________|________________|\n");
			delete[] V;
			delete[] q;
			delete[] x;
			delete[] x2;
			for (int i = 0; i<n; i++)
			{
				delete[] A[i];
			}
			delete[] A;
		}
		else if (f == 6)
		{
			printf("\n\n\n       № Matrix %5i\n", f);
			cout<<"==============================================================================="<<endl;
            cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
            cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
			int n = 8;
			matrix::number = 0;
			srand(time(0));
			double *x = new double[n];
			double *x2 = new double[n];
			int *q = new int[n];
			matrix::create_matrix(n);
		matrix::create_vect(n);

			ex2_6(A, n);
			for (int i = 0; i < n; i++)
			{
				x[i] = i + 1;
			}
			multiplication(matrix::V, matrix::A, n, x);
            auto begin = chrono::high_resolution_clock::now();
            factoriz();
            slae(V);
            auto end = chrono::high_resolution_clock::now();
			printf("|%9i", n);
			cout << "|";
			printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
			cout << "|";
			printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
			cout << "|";
			printf("%21.4f", (double)(n*n*n) / 3);
			cout << "|";
			printf("%16i", matrix::number);
			cout << "|\n";
			printf("|_________|___________|_____________|_____________________|________________|\n");
			delete[] V;
			delete[] q;
			delete[] x;
			delete[] x2;
			for (int i = 0; i<n; i++)
			{
				delete[] A[i];
			}
			delete[] A;
		}
		else if (f == 10)
		{
			printf("\n\n\n       № Matrix %5i\n", f);
			cout<<"==============================================================================="<<endl;
            cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
            cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
			int n = 4;
			matrix::number = 0;
			srand(time(0));
			double *x = new double[n];
			double *x2 = new double[n];
			int *q = new int[n];
			matrix::create_matrix(n);
		matrix::create_vect(n);

			ex2_10(A, n);
			for (int i = 0; i < n; i++)
			{
				x[i] = i + 1;
			}
			multiplication(matrix::V, matrix::A, n, x);
            auto begin = chrono::high_resolution_clock::now();
            factoriz();
            slae(V);
            auto end = chrono::high_resolution_clock::now();
			printf("|%9i", n);
			cout << "|";
			printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
			cout << "|";
			printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
			cout << "|";
			printf("%21.4f", (double)(n*n*n) / 3);
			cout << "|";
			printf("%16i", matrix::number);
			cout << "|\n";
			printf("|_________|___________|_____________|_____________________|________________|\n");
			delete[] V;
			delete[] q;
			delete[] x;
			delete[] x2;
			for (int i = 0; i<n; i++)
			{
				delete[] A[i];
			}
			delete[] A;
		}
		else if (f == 1)
		{
			printf("\n\n\n       № Matrix %5i\n", f);
			cout<<"==============================================================================="<<endl;
            cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
            cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
			for (int n = 4; n <= 40; n += 4)
			{
				matrix::number = 0;
				srand(time(0));
				double *x = new double[n];
				double *x2 = new double[n];
				int *q = new int[n];
				matrix::create_matrix(n);
		matrix::create_vect(n);

				ex2_1(A, n);
                for (int i = 0; i < n; i++)
                {
                    x[i] = i + 1;
                }
                multiplication(matrix::V, matrix::A, n, x);
                auto begin = chrono::high_resolution_clock::now();
                factoriz();
                slae(V);
                auto end = chrono::high_resolution_clock::now();
                printf("|%9i", n);
                cout << "|";
                printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
                cout << "|";
                printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
                cout << "|";
                printf("%21.4f", (double)(n*n*n) / 3);
                cout << "|";
                printf("%16i", matrix::number);
                cout << "|\n";

                delete[] V;
				delete[] q;
				delete[] x;
				delete[] x2;
				for (int i = 0; i<n; i++)
				{
					delete[] A[i];
				}
				delete[] A;
			}
			printf("|_________|___________|_____________|_____________________|________________|\n");
		}
		else if (f == 4)
		{
			printf("\n\n\n       № Matrix %5i\n", f);
			cout<<"==============================================================================="<<endl;
            cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
            cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
			for (int n = 4; n <= 40; n += 4)
			{
				matrix::number = 0;
				srand(time(0));
				double *x = new double[n];
				double *x2 = new double[n];
				int *q = new int[n];
				matrix::create_matrix(n);
		matrix::create_vect(n);

				ex2_4(A, n);
                for (int i = 0; i < n; i++)
                {
                    x[i] = i + 1;
                }
                multiplication(matrix::V, matrix::A, n, x);
                auto begin = chrono::high_resolution_clock::now();
                factoriz();
                slae(V);
                auto end = chrono::high_resolution_clock::now();
                printf("|%9i", n);
                cout << "|";
                printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
                cout << "|";
                printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
                cout << "|";
                printf("%21.4f", (double)(n*n*n) / 3);
                cout << "|";
                printf("%16i", matrix::number);
                cout << "|\n";

                delete[] V;
				delete[] q;
				delete[] x;
				delete[] x2;
				for (int i = 0; i<n; i++)
				{
					delete[] A[i];
				}
				delete[] A;
			}
			printf("|_________|___________|_____________|_____________________|________________|\n");
		}
		else if (f == 5)
		{
			printf("\n\n\n       № Matrix %5i\n", f);
			cout<<"==============================================================================="<<endl;
            cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
            cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
			for (int n = 4; n <= 40; n += 4)
			{
				matrix::number = 0;
				srand(time(0));
				double *x = new double[n];
				double *x2 = new double[n];
				int *q = new int[n];
				matrix::create_matrix(n);
		matrix::create_vect(n);

				ex2_5(A, n);
			for (int i = 0; i < n; i++)
			{
				x[i] = i + 1;
			}
			multiplication(matrix::V, matrix::A, n, x);
            auto begin = chrono::high_resolution_clock::now();
            factoriz();
            slae(V);
            auto end = chrono::high_resolution_clock::now();
			printf("|%9i", n);
			cout << "|";
			printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
			cout << "|";
			printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
			cout << "|";
			printf("%21.4f", (double)(n*n*n) / 3);
			cout << "|";
			printf("%16i", matrix::number);
			cout << "|\n";
				delete[] V;
				delete[] q;
				delete[] x;
				delete[] x2;
				for (int i = 0; i<n; i++)
				{
					delete[] A[i];
				}
				delete[] A;
			}
			printf("|_________|___________|_____________|_____________________|________________|\n");
		}
		else if (f == 7)
		{
			printf("\n\n\n       № Matrix %5i\n", f);
			cout<<"==============================================================================="<<endl;
            cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
            cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
			for (int n = 4; n <= 40; n += 4)
			{
				matrix::number = 0;
				srand(time(0));
				double *x = new double[n];
				double *x2 = new double[n];
				int *q = new int[n];
				matrix::create_matrix(n);
		matrix::create_vect(n);

				ex2_7(A, n);
			for (int i = 0; i < n; i++)
			{
				x[i] = i + 1;
			}
			multiplication(matrix::V, matrix::A, n, x);
            auto begin = chrono::high_resolution_clock::now();
            factoriz();
            slae(V);
            auto end = chrono::high_resolution_clock::now();
			printf("|%9i", n);
			cout << "|";
			printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
			cout << "|";
			printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
			cout << "|";
			printf("%21.4f", (double)(n*n*n) / 3);
			cout << "|";
			printf("%16i", matrix::number);
			cout << "|\n";

			delete[] V;
				delete[] q;
				delete[] x;
				delete[] x2;
				for (int i = 0; i<n; i++)
				{
					delete[] A[i];
				}
				delete[] A;
			}
			printf("|_________|___________|_____________|_____________________|________________|\n");
		}
		else if (f == 8)
		{
			printf("\n\n\n       № Matrix %5i\n", f);
			cout<<"==============================================================================="<<endl;
            cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
            cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
			for (int n = 4; n <= 40; n += 4)
			{
				matrix::number = 0;
				srand(time(0));
				double *x = new double[n];
				double *x2 = new double[n];
				int *q = new int[n];
				matrix::create_matrix(n);
		matrix::create_vect(n);

				ex2_8(A, n);
			for (int i = 0; i < n; i++)
			{
				x[i] = i + 1;
			}
			multiplication(matrix::V, matrix::A, n, x);
            auto begin = chrono::high_resolution_clock::now();
            factoriz();
            slae(V);
            auto end = chrono::high_resolution_clock::now();
			printf("|%9i", n);
			cout << "|";
			printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
			cout << "|";
			printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
			cout << "|";
			printf("%21.4f", (double)(n*n*n) / 3);
			cout << "|";
			printf("%16i", matrix::number);
			cout << "|\n";

			delete[] V;
				delete[] q;
				delete[] x;
				delete[] x2;
				for (int i = 0; i<n; i++)
				{
					delete[] A[i];
				}
				delete[] A;
			}
			printf("|_________|___________|_____________|_____________________|________________|\n");
		}
		else if (f == 9)
		{
			printf("\n\n\n       № Matrix %5i\n", f);
			cout<<"==============================================================================="<<endl;
            cout<<"|Poryadok|Vremya|Pogreshnost|Teoretich chislo operaciy|Realnoe chislo operaciy|"<<endl;
            cout<<"|--------+------+-----------+-------------------------+-----------------------|"<<endl;
			for (int n = 4; n <= 40; n += 4)
			{
				matrix::number = 0;
				srand(time(0));
				double *x = new double[n];
				double *x2 = new double[n];
				int *q = new int[n];
				matrix::create_matrix(n);
		matrix::create_vect(n);

				ex2_9(A, n);
			for (int i = 0; i < n; i++)
			{
				x[i] = i + 1;
			}
			multiplication(matrix::V, matrix::A, n, x);
            auto begin = chrono::high_resolution_clock::now();
            factoriz();
            slae(V);
            auto end = chrono::high_resolution_clock::now();
			printf("|%9i", n);
			cout << "|";
			printf("%11i", chrono::duration_cast<chrono::nanoseconds>(end - begin).count());
			cout << "|";
			printf("%13.4e", pogreshnost(V, A, n, x, x2, q));
			cout << "|";
			printf("%21.4f", (double)(n*n*n) / 3);
			cout << "|";
			printf("%16i", matrix::number);
			cout << "|\n";

			delete[] V;
				delete[] q;
				delete[] x;
				delete[] x2;
				for (int i = 0; i<n; i++)
				{
					delete[] A[i];
				}
				delete[] A;
			}
			printf("|_________|___________|_____________|_____________________|________________|\n");
		}
	}
	delete znak;
	system("pause");
}
