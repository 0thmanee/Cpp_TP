#include <iostream>
using namespace std;

// definition de la Class vect
class vect{
    double x;
    double y;
    double z;

    public:
    vect(double, double, double);
    void affiche();
};

// definition de la Class vect
class matrice{
    double **matr;

    public:
    matrice(double**);
    ~matrice();
};

// fonctions de la Class vect
vect::vect(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

void vect::affiche()
{
    cout<< "Les coordonnee du vecteur, X = " << this->x << " Y = " << this->y << " Z = " << this->z;
}

// fonctions de la Class matrice
matrice::matrice(double **matr)
{
    matr = new double*[3];
    for (int i = 0; i < 3; i++)
    {
        this->matr[i] = new double[3];
        for (int j = 0; j < 3; j++)
            this->matr[i][j] = matr[i][j];
    }
}

matrice::~matrice() {
    for (int i = 0; i < 3; i++) {
        delete[] this->matr[i];
    }
    delete[] this->matr;
}

// Fonction prod qui calcul le produit
double *prod(double *vect, double **matr)
{
    double *vectResult = new double[3];
    for (int i = 0; i < 3; i++)
    {
        vectResult[i] = 0;
        for (int j = 0; j < 3; j++)
        {
            vectResult[i] += vect[j] * matr[i][j];
        }
    }
    return vectResult;
}

// test
#include <stdio.h>
int main()
{
    double k = 1.2;
    double *vect = new double[3];
    double *vectResult = new double[3];
    double **matr = new double*[3];

    vect[0] = 0.25;
    vect[1] = 0.5;
    vect[2] = 0.75;
    for (int i = 0; i < 3; i++)
    {
        matr[i] = new double[3];
        for (int j = 0; j < 3; j++)
        {
            matr[i][j] = k;
            k++;
        }
    }
    vectResult = prod(vect, matr);
    cout << "vectResult[0] = " << vectResult[0] << " vectResult[1] = " << vectResult[1] << " vectResult[2] = " << vectResult[2] << endl;
}