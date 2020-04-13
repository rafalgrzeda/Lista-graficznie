#ifndef PUNKT_H
#define PUNKT_H


class Punkt
{
protected:
    int X;
    int Y;
public:
    Punkt(int x = 100, int y = 100);
    void setX(int x);
    void setY(int y);
    int getX();
    int getY();
};


#endif // PUNKT_H
