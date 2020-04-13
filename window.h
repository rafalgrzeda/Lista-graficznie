#ifndef WINDOW_H
#define WINDOW_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include "lista.h"
namespace Ui {
class Window;
}

class Window : public QDialog
{
    Q_OBJECT

public:
    explicit Window(QWidget *parent = 0);
    ~Window();

private:
    Ui::Window *ui;
    Lista *lista;
    QGridLayout * maingrid; //główny layout

    QGroupBox *stworzBoxSterowanie();
    QGroupBox *stworzBoxDodawanie();
    QGroupBox *stworzBoxUsuwanie();
    QGroupBox *stworzBoxDane();

    QPushButton *lewo;
    QPushButton *prawo;
    QPushButton *sterowanie_usun;
    QPushButton *modyfikuj;
    QLineEdit *imie_modyfikuj;

    QPushButton *poczatek;
    QPushButton * koniec;
    QLabel *imie;
    QLineEdit *imie_wpisz;

    QLabel *imie_usun;
    QLineEdit *imie_wpisz_usun;
    QPushButton * usun;

    QLabel *liczba;
    QLabel *liczba_info;
    QLabel *glowa;
    QLabel *glowa_info;
    QLabel *ogon;
    QLabel *ogon_info;

    void setDane();
private slots:
    void dodajNaKoncu();
    void dodajNaPoczatku();
    void usunElement();
    void przesunWLewo();
    void przesunWPrawo();
    void usunAktualny();
    void modyfikujAktualny();

protected:
    void paintEvent(QPaintEvent *event);

};

#endif // WINDOW_H
