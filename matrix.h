#ifndef MATRIX_H
#define MATRIX_H


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
		void slae();
		void obr();
		void get_slae();
		void get_obr();
		void create_vect(int n);
        void get_vect();
        void set_vect();
        void del_vect();
        void get_p_q();
    private:
        double **A;
        double **F;
        double **X;
        double *V;
        double *x;
        int d=1;
        int n;
        int i;
        int j;
        int *p, *q;
};

#endif // MATRIX_H
