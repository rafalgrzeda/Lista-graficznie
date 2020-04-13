#include "punkt.h"

Punkt::Punkt(int x, int y)
{
    X = x; Y = y;
}

void Punkt::setX(int x)
{
    X = x;
}

void Punkt::setY(int y){
    Y = y;
}

int Punkt::getX(){
    return X;
}

int Punkt::getY(){
    return Y;
}
