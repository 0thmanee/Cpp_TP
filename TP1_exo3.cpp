#include <iostream>
using namespace std;

class vecteur{
    int x;
    int y;
    int z;

    friend bool operator !=(vecteur, vecteur);
    friend vecteur operator ++(vecteur);

    public:
    vecteur(int, int, int);
    bool operator ==(vecteur);
    int operator *(vecteur);
    void affiche();
};
vecteur::vecteur(int x = 0, int y = 0, int z = 0)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

bool vecteur::operator ==(vecteur v1)
{
    return (this->x == v1.x && this->y == v1.y && this->z == v1.z);
}

bool operator !=(vecteur v1, vecteur v2)
{
    return (v1.x != v2.x || v1.y != v2.y || v1.z != v2.z);
}

vecteur operator ++(vecteur v)
{
    (v.x)++;
    (v.y)++;
    (v.z)++;
    return v;
}

int vecteur::operator *(vecteur v)
{
    return (this->x * v.x + this->y * v.y + this->z * v.z);
}

void vecteur::affiche()
{
    cout<<"X = "<<this->x<<" Y = "<<this->y<<" Z = "<<this->z<<endl;
}

int main()
{
    vecteur v1(1, 2, 3);
    vecteur v2(4, 5, 6);
    vecteur v3 = ++v1;
    v3.affiche();
    bool x = (v1 == v2);
    if (x)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    cout<<v1*v2<<endl;
}