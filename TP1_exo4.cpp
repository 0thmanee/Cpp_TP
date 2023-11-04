#include <iostream>
using namespace std;

class form{
    protected:
    double surface = 0;
    double perimetre = 0;

    public:
    double getSurface()
    {
        return this->surface;
    }
    double getPerimetre()
    {
        return this->perimetre;
    }
};

class carre:public form{   
    double cote;
    
    public:
    carre(double cote)
    {
        this->cote = cote;
    }
    void setSurface()
    {
        this->surface = cote * cote;
    }
    void setPerimetre()
    {
        this->perimetre = cote * 4;
    }
};

class rectangle:public form{
    double longe;
    double large;

    public:
    rectangle(double longe, double large)
    {
        this->longe = longe;
        this->large = large;
    }
    void setSurface()
    {
        this->surface = longe * large;
    }
    void setperimetre()
    {
        this->perimetre = 2 * (longe + large);
    }
};

class cercle:public form{
    const double Pi = 3.14;
    double diam;
    double ray;
    
    public:
    cercle(double diam)
    {
        this->diam = diam;
        this->ray = diam / 2;
    }
    void setSurface()
    {
        this->surface = ray * ray * Pi;
    }
    void setperimetre()
    {
        this->perimetre = diam * Pi;
    }
};