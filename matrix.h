#ifndef MATRIX_H
#define MATRIX_H
//#include "stdafx"

class matrix
{
    public:
        void create_matrix(int n);
        void get_matrix();
        void set_matrix();
        void del_matrix();
		void factoriz();
		void get_factoriz();
		void det();
		void slae(double *b);
		void obr();
		void get_slae();
		void get_obr();
		void create_vect(int n);
        void get_vect();
        void set_vect();
        void del_vect();
        void get_p_q();
        void get_obras();
        void obras();
        double use_slae();
        void ex1();
        void ex2();
        void ex3();
        void ex2_1(double **A, int n);
        void ex2_2(double **A, int n);
        void ex2_3(double **A, int n);
        void ex2_4(double **A, int n);
        void ex2_5(double **A, int n);
        void ex2_6(double **A, int n);
        void ex2_7(double **A, int n);
        void ex2_8(double **A, int n);
        void ex2_9(double **A, int n);
        void ex2_10(double **A, int n);
        double pogreshnost_task_9(double *B, double **A, int n, int *q, double **kopyA);
    private:
        double **A;
        double **F;
        double **X;
        double **E;
        double *V;
        double *x;
        int d=1;
        int n;
        int i;
        int j;
        int *p, *q;
        //double *b;
        double *buf;
        int number;
        int number_1;
        int number_2;
};

#endif // MATRIX_H
