#include <iostream>
#include <cmath>
using namespace std;

class complexe{
	double re;
	double img;

	public:
	complexe(double = 0, double = 0);
	void affichage();
	double module();
	complexe conjugue();
	complexe operator +(complexe);
};

complexe::complexe(double re, double img)
{
	this->re = re;
	this->img = img;
}

void complexe::affichage()
{
	cout << "La Partie Reelle est: " << this->re << " La Partie Imaginaire est: " << this->img << endl;
}

double complexe::module()
{
	return sqrt(pow(this->re, 2) + pow(this->img, 2));
}

complexe complexe::conjugue()
{
	complexe c1(this->re, -this->img);
	return c1;
}

complexe complexe::operator +(complexe c1)
{
	complexe c2;
	c2.re = this->re + c1.re;
	c2.img = this->img + c1.img;
	return c2;
}

int main()
{
	complexe c1(1, 2);
	complexe c2(3, 4);
	c1.affichage();
	complexe c3 = c1 + c2;
	c3.affichage();
	cout << c1.module() << endl;
	c3.conjugue().affichage();
}