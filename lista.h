#ifndef LISTA_H
#define LISTA_H

#include <string>

#include "osoba.h"
#include <QPainter>
using namespace std;

class Lista
{
private:
    Osoba *glowa_;
    Osoba *ogon_;
    Osoba *aktualny_;
public:
    Lista();
    ~Lista();

    void dodajNaPoczatku(string imie);
    void dodajNaKoncu(string imie);
    void usunImie(string imie);
    void wyczyscListe();
    Osoba *zwrocGlowe();
    Osoba *zwrocOgon();
    Osoba *zwrocAktualny();
    void ustawAktualny(Osoba *adr);
    void rysujListe(QPainter *painter);
    int dlugoscListy();
    void przesunDoPrzoduAktualny();
    void przesunDoTyluAktualny();
    void usunElementAktualny();
    void modyfikujAktualny(string imie);
private:
    void dodajPrzed(Osoba *&adr, string imie);
    Osoba *dodajPo(Osoba *adr, string imie);
    void wyczyscListe(Osoba *adr);
    Osoba *usunElement(Osoba *adr);
    void rysujListe(QPainter * painter, Osoba *adr);
    int dlugoscListy(Osoba *adr);
    Osoba* przesunDoPrzodu(Osoba *adr);
    Osoba* przesunDoTylu(Osoba *adr);

};

#endif // LISTA_H
