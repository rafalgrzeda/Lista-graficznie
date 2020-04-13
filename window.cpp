#include "window.h"
#include "ui_window.h"
#include <QDebug>
#include <QPushButton>
#include <QGridLayout>
#include "lista.h"
#include "osoba.h"
#include <QWidget>
#include <QMessageBox>
Window::Window(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);

    lista = new Lista;

    lista->dodajNaKoncu("Rafał");
    lista->dodajNaKoncu("Zosia");
    lista->dodajNaKoncu("Krystian");
    lista->dodajNaKoncu("Ola");
    lista->dodajNaKoncu("Michał");


    maingrid = new QGridLayout;
    maingrid->setRowStretch(0,18);
    maingrid->setRowStretch(1,1);
    //maingrid->addWidget(renderarea,0,0,1,7);
    maingrid->addWidget(stworzBoxDane(),1,0);
    maingrid->addWidget(stworzBoxSterowanie(),1,1);
    maingrid->addWidget(stworzBoxDodawanie(),1,2);
    maingrid->addWidget(stworzBoxUsuwanie(),1,3);

    connect(koniec,SIGNAL(clicked(bool)),this,SLOT(dodajNaKoncu()));
    connect(poczatek,SIGNAL(clicked(bool)),this,SLOT(dodajNaPoczatku()));
    connect(usun,SIGNAL(clicked(bool)),this,SLOT(usunElement()));
    connect(lewo,SIGNAL(clicked(bool)),this,SLOT(przesunWLewo()));
    connect(prawo,SIGNAL(clicked(bool)),this,SLOT(przesunWPrawo()));
    connect(sterowanie_usun,SIGNAL(clicked(bool)),this,SLOT(usunAktualny()));
    connect(modyfikuj,SIGNAL(clicked(bool)),this,SLOT(modyfikujAktualny()));

    setLayout(maingrid);
    setWindowTitle(tr("Lista Graficznie - Rafał Grzęda"));

}

Window::~Window()
{
    delete lista;
    delete ui;
}

QGroupBox *Window::stworzBoxSterowanie()
{
    QGroupBox *box = new QGroupBox("Sterowanie");

    lewo = new QPushButton;
    lewo->setText("Lewo");

    prawo = new QPushButton;
    prawo->setText("Prawo");

    sterowanie_usun = new QPushButton;
    sterowanie_usun->setText("Usuń");

    modyfikuj = new QPushButton;
    modyfikuj->setText("Modyfikuj");

    imie_modyfikuj = new QLineEdit;
    imie_modyfikuj->setText("Tu wpisz imię");

    QHBoxLayout *lay_poziom = new QHBoxLayout;
    lay_poziom->addWidget(lewo);
    lay_poziom->addWidget(prawo);

    QHBoxLayout *lay_poziom2 = new QHBoxLayout;
    lay_poziom2->addWidget(imie_modyfikuj);
    lay_poziom2->addWidget(modyfikuj);

    QGridLayout *grid = new QGridLayout;
    grid->addLayout(lay_poziom,0,0);
    grid->addLayout(lay_poziom2,1,0);

    box->setLayout(grid);

    return box;


}

QGroupBox *Window::stworzBoxDodawanie()
{
    QGroupBox *box = new QGroupBox("Dodawanie");
    imie = new QLabel;
    imie->setText("Imie: ");
    imie->setFixedWidth(50);
    imie_wpisz = new QLineEdit;
    poczatek = new QPushButton;
    poczatek->setText("Dodaj na początku");
    koniec = new QPushButton;
    koniec->setText("Dodaj na końcu");

    QHBoxLayout *lay_poziom = new QHBoxLayout;
    lay_poziom->addWidget(imie);
    lay_poziom->addWidget(imie_wpisz);

    QHBoxLayout *lay_poziom2 = new QHBoxLayout;
    lay_poziom2->addWidget(poczatek);
    lay_poziom2->addWidget(koniec);

    QGridLayout *grid = new QGridLayout;
    grid->addLayout(lay_poziom,0,0);
    grid->addLayout(lay_poziom2,1,0);

    box->setLayout(grid);

    return box;

}

QGroupBox *Window::stworzBoxUsuwanie()
{
    QGroupBox *box = new QGroupBox("Usuwanie");

    usun = new QPushButton;
    usun->setText("Usuń");
    imie_usun = new QLabel;
    imie_usun->setText("Imie: ");
    imie->setFixedWidth(50);
    imie_wpisz_usun = new QLineEdit;

    QHBoxLayout *lay_poziom = new QHBoxLayout;
    lay_poziom->addWidget(imie_usun);
    lay_poziom->addWidget(imie_wpisz_usun);

    QHBoxLayout *lay_poziom2 = new QHBoxLayout;
    lay_poziom2->addWidget(usun);

    QGridLayout *grid = new QGridLayout;
    grid->addLayout(lay_poziom,0,0);
    grid->addLayout(lay_poziom2,1,0);

    box->setLayout(grid);

    return box;
}

QGroupBox *Window::stworzBoxDane()
{
    QGroupBox *box = new QGroupBox("Dane");
    liczba = new QLabel;
    liczba->setText("Liczba elementów: ");
    liczba_info = new QLabel;

    glowa = new QLabel;
    glowa->setText("Głowa: ");
    glowa_info= new QLabel;

    ogon = new QLabel;
    ogon->setText("Ogon: ");
    ogon_info = new QLabel;


    QHBoxLayout *lay_poziom = new QHBoxLayout;
    lay_poziom->addWidget(liczba,0,Qt::AlignLeft);
    lay_poziom->addWidget(liczba_info,0,Qt::AlignRight);

    QHBoxLayout *lay_poziom2 = new QHBoxLayout;
    lay_poziom2->addWidget(glowa,0,Qt::AlignLeft);
    lay_poziom2->addWidget(glowa_info,0,Qt::AlignRight);

    QHBoxLayout *lay_poziom3 = new QHBoxLayout;
    lay_poziom3->addWidget(ogon,0,Qt::AlignLeft);
    lay_poziom3->addWidget(ogon_info,0,Qt::AlignRight);

    QGridLayout *grid = new QGridLayout;
    grid->addLayout(lay_poziom,0,0);
    grid->addLayout(lay_poziom2,1,0);
    grid->addLayout(lay_poziom3,2,0);


    setDane();
    box->setLayout(grid);

    return box;
}

void Window::setDane()
{
    QFont myfont;
    myfont.setBold(true);

    int dlugosc = lista->dlugoscListy();
    QString dl = QString::number(dlugosc);
    liczba_info->setFont(myfont);
    if(lista->dlugoscListy() == 7)
        liczba_info->setText("<font color='red'>MAX</font>");
    else
        liczba_info->setText(dl);

    Osoba *gl;
    gl=lista->zwrocGlowe();
    string glowa_str = gl->zwrocImie();
    glowa_info->setFont(myfont);
    glowa_info->setText(glowa_str.c_str());

    Osoba * ogo;
    ogo = lista->zwrocOgon();
    string ogon_str = ogo->zwrocImie();
    ogon_info->setFont(myfont);
    ogon_info->setText(ogon_str.c_str());
}

void Window::dodajNaKoncu()
{

    if(lista->dlugoscListy() == 7){
        QMessageBox::information(this,"Błąd","Maksymalna ilośc elementów to 7");
        return;
    }

    QString imie_dodaj = imie_wpisz->text();
    if(imie_dodaj.isEmpty()){
        QMessageBox::information(this,"Nieprawidłowe dane","Pole imię jest puste");
        return;
    }
    else{
        lista->dodajNaKoncu(imie_dodaj.toStdString());
        setDane();
        Window::update();
        imie_wpisz->clear();
    }

}

void Window::dodajNaPoczatku()
{
    if(lista->dlugoscListy() == 7){
        QMessageBox::information(this,"Błąd","Maksymalna ilośc elementów to 7");
        return;
    }

    QString imie_dodaj = imie_wpisz->text();
    if(imie_dodaj.isEmpty()){
        QMessageBox::information(this,"Nieprawidłowe dane","Pole imię jest puste");
        return;
    }
    else{
        lista->dodajNaPoczatku(imie_dodaj.toStdString());
        setDane();
        Window::update();
        imie_wpisz->clear();
    }



}

void Window::usunElement()
{
    if(lista->dlugoscListy() == 1){
        QMessageBox::information(this,"Błąd","Nie można usunąć ostatniego elementu");
        return;
    }
    QString imie_usun = imie_wpisz_usun->text();
    if(imie_usun.isEmpty()){
        QMessageBox::information(this,"Nieprawidłowe dane","Pole imię jest puste");
        return;
    }
    else{
        lista->usunImie(imie_usun.toStdString());
        setDane();
        Window::update();
        imie_wpisz_usun->clear();
    }



}

void Window::przesunWLewo()
{
    lista->przesunDoTyluAktualny();
    Window::update();
}

void Window::przesunWPrawo()
{
    lista->przesunDoPrzoduAktualny();
    Window::update();
}

void Window::usunAktualny()
{
    if(lista->dlugoscListy() == 1){
        QMessageBox::information(this,"Błąd","Nie można usunąć ostatniego elementu");
        return;
    }
    lista->usunElementAktualny();
    setDane();
    Window::update();
}

void Window::modyfikujAktualny()
{
    lista->modyfikujAktualny(imie_modyfikuj->text().toStdString());
    setDane();
    imie_modyfikuj->clear();
    Window::update();
}

void Window::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    lista->rysujListe(&painter);
}


