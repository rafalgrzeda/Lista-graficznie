#ifndef ELEMENT_H
#define ELEMENT_H

#include "punkt.h"
#include <iostream>
#include <QPainter>
#include <osoba.h>
using namespace std;

class Element: public Punkt
{
    int dlugosc_;
    int szerokosc_;
    string dane_;
    string wskaznik_;
    string podpis_gorny_;
    string podpis_dolny_;


public:
    Element(int x = 100, int y = 100 ,int dlugosc = 140, int szerokosc= 60, string dane = "DANE", string wsk = "WSKAŹNIK", string p_g ="PODPIS", string p_d = "PODPIS");

    void setDlugosc(int dlugosc);
    void setSzerokosc(int szerokosc);
    void setDane(string dane);
    void setWskaznik(string wsk);
    void setPodpisGorny(string podpis_g);
    void setPodpisDolny(string podpis_d);
    void rysujElement(QPainter *painter);

    int getSzerokosc();
    int getDlugosc();
    string getDane();
    string getWskaznik();
    string getPodpisGorny();
    string getPodpisDolny();
private:
    void rysujElement(QPainter * painter ,int x, int y, int dlugosc, int szerokosc, string dane, string wsk, string podpis_g, string podpis_d);
};

#endif // ELEMENT_H
