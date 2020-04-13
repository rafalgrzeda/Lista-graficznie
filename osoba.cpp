#include "osoba.h"

Osoba::Osoba()
{
    nastepny_ = 0;
}

Osoba::Osoba(string imie, Osoba *nastepny)
{
    nastepny_ = nastepny;
    imie_ = imie;
}

void Osoba::ustawImie(string imie)
{
    imie_ = imie;
}

void Osoba::ustawNastepny(Osoba *nastepny)
{
    nastepny_ = nastepny;
}

string Osoba::zwrocImie()
{
    return imie_;
}

Osoba *Osoba::zwrocNastepny()
{
    return nastepny_;
}
