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
    private:
        double **A;
        double **F;
        int d=1;
        int n;
        int i;
        int j;
};

#endif // MATRIX_H
