#include "element.h"
#include "punkt.h"
#include <iostream>
#include <QtCore>
#include <QtGui>
using namespace std;



Element::Element(int x, int y, int dlugosc, int szerokosc, string dane, string wsk, string p_g, string p_d)
    :Punkt(x,y)
{
    dlugosc_ = dlugosc;
    szerokosc_ = szerokosc;
    dane_ = dane;
    wskaznik_ = wsk;
    podpis_gorny_ = p_g;
    podpis_dolny_ = p_d;
}

void Element::setDlugosc(int dlugosc)
{
    dlugosc_ = dlugosc;
}

void Element::setSzerokosc(int szerokosc)
{
    szerokosc_ = szerokosc;
}

void Element::setDane(string dane)
{
    dane_ = dane;
}

void Element::setWskaznik(string wsk){
    wskaznik_ = wsk;
}

void Element::setPodpisDolny(string podpis_d){
    podpis_dolny_ = podpis_d;
}

void Element::rysujElement(QPainter *painter)
{
    int x = this->getX();
    int y =this->getY();

    rysujElement(painter,x,y,dlugosc_,szerokosc_,dane_,wskaznik_,podpis_gorny_,podpis_dolny_);
}

int Element::getSzerokosc()
{
    return szerokosc_;
}

int Element::getDlugosc()
{
    return dlugosc_;
}

void Element::rysujElement(QPainter * painter, int x,int y, int dlugosc, int szerokosc, string dane, string wsk, string podpis_g, string podpis_d)
{
    QString daneS = dane.c_str();
    QString wskS = wsk.c_str();
    QString podpis_gS = podpis_g.c_str();
    QString podpis_dS = podpis_d.c_str();

    QPen pen;
    pen.setWidth(2);
    painter->setPen(pen);

    QRect rect_dane(x, y, dlugosc, szerokosc/2);
    QRect rect_wsk(x, y + szerokosc/2, dlugosc, szerokosc/2);
    QRect rect_podpis_gorny(x, y - szerokosc/2, dlugosc,szerokosc/2);
    QRect rect_podpis_dolny(x, y + szerokosc, dlugosc, szerokosc/2);

    QBrush brush_dane;
    brush_dane.setColor(QColor(0, 0, 255, 127));
    brush_dane.setStyle(Qt::SolidPattern);
    QBrush brush_wsk;
    brush_wsk.setColor(QColor(255, 0, 0, 127));
    brush_wsk.setStyle(Qt::SolidPattern);

    painter->drawRect(rect_dane);
    painter->fillRect(rect_dane,brush_dane);
    painter->drawRect(rect_wsk);
    painter->fillRect(rect_wsk,brush_wsk);

    painter->drawText(rect_dane,Qt::AlignCenter,daneS);
    painter->drawText(rect_wsk,Qt::AlignCenter,wskS);
    painter->drawText(rect_podpis_gorny,Qt::AlignCenter,podpis_gS);
    painter->drawText(rect_podpis_dolny,Qt::AlignCenter,podpis_dS);
}

void Element::setPodpisGorny(string podpis_g){
    podpis_gorny_ = podpis_g;
}

string Element::getDane(){
    return dane_;
}
string Element::getPodpisDolny(){
    return podpis_dolny_;
}

string Element::getPodpisGorny(){
    return podpis_gorny_;
}

string Element::getWskaznik(){
    return wskaznik_;
}
