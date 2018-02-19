#ifndef MATRIX_H
#define MATRIX_H


class matrix
{
    public:
        void create_matrix(int n);
        void get_matrix();
        void set_matrix();
        void del_matrix();
    private:
        double **A;
        double **B;
        int n;
        int i;
        int j;
};

#endif // MATRIX_H
