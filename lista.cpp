#include "lista.h"
#include <iostream>
#include "element.h"
#include <sstream>
#include <string>
#include <QDebug>
using namespace std;
Lista::Lista()
{
    glowa_= 0;
    ogon_ = 0;
    aktualny_ = 0;
}

Lista::~Lista()
{
    wyczyscListe();
}

void Lista::dodajNaPoczatku(string imie)
{
    dodajPrzed(glowa_,imie);

    if(ogon_==0)
        ogon_ = glowa_;

    aktualny_ = glowa_;
}

void Lista::dodajNaKoncu(string imie)
{
    if(ogon_!=0)
    {
        ogon_ = dodajPo(ogon_, imie);
    } else
    {
        glowa_ = dodajPo(glowa_, imie);
        ogon_ = glowa_;
    }
    aktualny_ = glowa_;
}

void Lista::usunImie(string imie)
{
    if(glowa_!=0)
    {
        /* Jeżeli jest to pierwszy element, to należy go usunąć najpierw.
        Pętla while na wypadek, gdyby lista zaczynała się od
        kilku elementów, które są do usunięcia */
        while(glowa_!=0 && glowa_->zwrocImie()==imie)
        {
            glowa_ = usunElement(glowa_);
        }

        Osoba *poprzedni=glowa_;

        if(poprzedni!=0)
        {
            Osoba *akt=poprzedni->zwrocNastepny();

            while(akt!=0)
            {
                if(akt->zwrocImie()==imie)
                {
                    akt = usunElement(akt);
                    poprzedni->ustawNastepny(akt);
                }
                else
                {
                    poprzedni = akt;
                    akt = akt->zwrocNastepny();
                }
            }
        }

        ogon_ = poprzedni;
    }
    aktualny_ = glowa_;
}

void Lista::wyczyscListe()
{
    wyczyscListe(glowa_);

    glowa_ = 0;
    ogon_ = 0;
}

Osoba *Lista::zwrocGlowe()
{
    return glowa_;
}

Osoba *Lista::zwrocOgon()
{
    return ogon_;
}

Osoba *Lista::zwrocAktualny()
{
    return aktualny_;
}

void Lista::ustawAktualny(Osoba *adr)
{
    aktualny_ = adr;

}

void Lista::rysujListe(QPainter *painter)
{
    rysujListe(painter,glowa_);
}

int Lista::dlugoscListy()
{
    return dlugoscListy(glowa_);
}

void Lista::przesunDoPrzoduAktualny()
{
    aktualny_ = przesunDoPrzodu(aktualny_);
}

void Lista::przesunDoTyluAktualny()
{
    aktualny_ = przesunDoTylu(aktualny_);
}

void Lista::usunElementAktualny()
{
    if(aktualny_ == glowa_){
        glowa_ = usunElement(glowa_);
        aktualny_ = glowa_;
    }

    Osoba *poprzedni=glowa_;

    if(poprzedni!=0)
    {
        Osoba *akt=poprzedni->zwrocNastepny();

        while(akt!=0)
        {
            if(akt == aktualny_)
            {
                akt = usunElement(akt);
                poprzedni->ustawNastepny(akt);
            }
            else
            {
                poprzedni = akt;
                akt = akt->zwrocNastepny();
            }
        }
    }

    ogon_ = poprzedni;
    aktualny_ = glowa_;

}

void Lista::modyfikujAktualny(string imie)
{
    aktualny_->ustawImie(imie);
}


Osoba* Lista::przesunDoPrzodu(Osoba *adr)
{

    if(adr->zwrocNastepny() == 0 ){
        return ogon_;
    }
    else{
        adr = adr->zwrocNastepny();
        return adr;
    }
}

Osoba* Lista::przesunDoTylu(Osoba *adr)
{

    Osoba * iter = glowa_;
    Osoba * poprzedni = glowa_;

    if(adr == glowa_ || iter->zwrocNastepny() == 0)
        return glowa_;

    iter = iter->zwrocNastepny();
    while(iter !=0){
        if(adr == iter){
            adr = poprzedni;
            return  adr;
        }
        poprzedni = poprzedni->zwrocNastepny();
        iter = iter->zwrocNastepny();
    }
    return glowa_;
}

void Lista::dodajPrzed(Osoba *&adr, string imie)
{
    Osoba *tmp;
    tmp = new Osoba(imie, adr);
    adr = tmp;
}

Osoba *Lista::dodajPo(Osoba *adr, string imie)
{
    Osoba *tmp;
    tmp = new Osoba(imie, 0);

    if(adr!=0)
    {
        tmp->ustawNastepny(adr->zwrocNastepny());
        adr->ustawNastepny(tmp);
    }

    return tmp;
}

void Lista::wyczyscListe(Osoba *adr)
{
    if(adr!=0)
    {
        wyczyscListe(adr->zwrocNastepny());
        delete adr;
    }
}

Osoba *Lista::usunElement(Osoba *adr)
{
    if(adr!=0)
    {
        Osoba *tmp = adr;
        adr = adr->zwrocNastepny();
        delete tmp;
    }

    return adr;
}

void Lista::rysujListe(QPainter *painter, Osoba *adr)
{
    Element el;
    int x = el.getX();
    int y = el.getY();
    int szerokosc = el.getSzerokosc();
    int dlugosc = el.getDlugosc();
    int licznik = 1;

    QPen pen;
    pen.setWidth(2);
    painter->setPen(pen);

    while(adr != 0){
        //
        if(adr == glowa_ && adr != aktualny_){
            el.setPodpisDolny("GŁOWA");
        }
        else if(adr == ogon_ && adr != aktualny_){
            el.setPodpisDolny("OGON");
        }
        else if( adr == glowa_ &&  adr == aktualny_){
            el.setPodpisDolny("GŁOWA I AKTUALNY");
        }
        else if( adr == ogon_ && adr == aktualny_){
            el.setPodpisDolny("OGON I AKTUALNY");
        }
        else if( adr == aktualny_){
            el.setPodpisDolny("AKTUALNY");
        }
        else{
            el.setPodpisDolny("");
        }

        stringstream ss;
        ss << adr;
        string podpis_g = ss.str();
        podpis_g = "ADRES: " + podpis_g;

        stringstream sz;
        sz << adr->zwrocNastepny();
        string wsk = sz.str();

        //
        licznik++;
        el.setWskaznik(wsk);
        el.setPodpisGorny(podpis_g);
        el.setDane(adr->zwrocImie());

        if(licznik != dlugoscListy()+1)
        painter->drawLine(x+dlugosc,y + 3*szerokosc/4, x+dlugosc+40, y + szerokosc/4);
        
        el.rysujElement(painter);
        x = x + 180;
        el.setX(x);
        adr = adr->zwrocNastepny();


    }
}

int Lista::dlugoscListy(Osoba *adr){
    int licznik = 0;
    while(adr != 0){
        adr = adr->zwrocNastepny();
        licznik ++;
    }
    return licznik;
}
