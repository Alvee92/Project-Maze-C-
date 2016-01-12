#ifndef COORDONNEE_H
#define COORDONNEE_H


class Coordonnee
{
    public:
        Coordonnee();
        Coordonnee (double _x, double _y);
        void Afficher();
        void Deplacer(double _x , double _y);
        void Positionner(double _x, double _y);
        void Positionner(const Coordonnee & _coord);
        char Zone();

        virtual ~Coordonnee();
    protected:
    private:
        double x,y;

};

#endif // COORDONNEE_H
