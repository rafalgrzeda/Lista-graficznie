#ifndef OSOBA_H
#define OSOBA_H

#include <string>

using namespace std;

class Osoba
{
private:
    string imie_;
    Osoba *nastepny_;

public:
    Osoba();
    Osoba(string imie, Osoba *nastepny);
    void ustawImie(string imie);
    void ustawNastepny(Osoba *nastepny);
    string zwrocImie();
    Osoba *zwrocNastepny();

};



#endif // OSOBA_H
