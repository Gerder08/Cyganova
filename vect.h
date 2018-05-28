#ifndef VECT_H
#define VECT_H


class vect
{
    public:
        void create_vect(int n);
        void get_vect();
        void set_vect();
        void del_vect();
        double *A;
    private:
        double **B;
        int n;
        int i;
        int j;
};

#endif // VECT_H
