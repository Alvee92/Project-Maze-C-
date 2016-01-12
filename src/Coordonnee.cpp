#include "Coordonnee.h"
#include <iostream>
using namespace std;
#include <string>
Coordonnee::Coordonnee()
:x(0), y(0)
{
    //ctor
}


Coordonnee::~Coordonnee()
{
    //dtor
}

Coordonnee::Coordonnee(double _x, double _y) : x(_x), y(_y)
{}
void Coordonnee::Afficher()
{
    cout << "("<< this->x << ", " << this->y << ")"<< endl  ;

}

void Coordonnee::Deplacer(double _x, double _y)
{
    this -> x += _x;
    this -> y += _y;

}

void Coordonnee::Positionner(double _x, double _y)
{
    this -> x = _x;
    this -> y = _y;

}

void Coordonnee::Positionner(const Coordonnee & _coord)
{
    this -> x = _coord.x;
    this -> y = _coord.y;

}

char Coordonnee::Zone()
{
    char result ='E';
    if (this->x >0)
    {
        if(this->y > 0)
        {
            result = 'B';
        }
        else { result ='C';}
    }

    if (this->x < 0)
    {
        if(this->y > 0)
        {
            result ='A';
        }
        else { result = 'D';}
    }


return result;}
