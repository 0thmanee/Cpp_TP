#include <iostream>
using namespace std;

class vecteur3d{
    int x;
    int y;
    int z;
    friend bool coincide(vecteur3d, vecteur3d);
    
    public:
    vecteur3d(int, int, int);
};
vecteur3d::vecteur3d(int x, int y, int z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}
bool coincide(vecteur3d v1, vecteur3d v2)
{
    return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
}
int main() {
    vecteur3d v1(1, 2, 3);
    vecteur3d v2(1, 2, 3);
    vecteur3d v3(4, 5, 6);

    cout << coincide(v1, v2) << endl;
    cout << coincide(v1, v3) << endl;
    return 0;
}