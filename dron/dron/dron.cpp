#include "dron.hh"
/*!
 * Rysuje kazdy element drona osobno
 *
 * \param kpi - wskaznik na modul do rysowania w gnuplocie
 */
void Dron::rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi){ 
    this->P.rysuj(kpi);
    this->S1.rysuj(kpi);
    this->S2.rysuj(kpi);
}
/*!
 * Konstruktor Drona
 * Wczytuje dane wierzcholkow za pomoca metody loadfromfile z plikow o
 * podanych nazwach
 */
Dron::Dron(){
    this->P.loadfromfile("korpus.txt");
    this->S1.loadfromfile("dronSruba1.txt");
    this->S2.loadfromfile("dronSruba2.txt");
    this->P.wyznacz_srodek();
}
/*!
 * Obraca drona
 * Obraca kazdy element drona osobno, dodaje nowy kat do pola Alpha
 * \param kat - obroca kazda bryle o dany kat
 */
void Dron::Obrot(double kat, std::shared_ptr<drawNS::Draw3DAPI> & kpi){
  this->Alpha =this->Alpha + kat;
        this->P.Obrot(kat, os_oz);
        this->S1.Obrot(kat, os_oz);
        this->S2.Obrot(kat, os_oz);
	this->rysuj(kpi);
}

/*!
 * Porusza drona
 * Porusza drona na plaszczyznie xy z uwzglednieniem pod jakim katem
 * jest obecnie ustawiony
 * \param odleglosc - dlugosc na jaka ma sie przeniesc dron
 */
void Dron::Plyn(double odleglosc, double kat,std::shared_ptr<drawNS::Draw3DAPI> & kpi){
  Wektor3D przemieszczenie;
  if(kat!=90 && kat!=-90){
 przemieszczenie[0]=cos(kat)*odleglosc;
 przemieszczenie[1]=0;
 przemieszczenie[2]=sin(kat)*odleglosc;
 this->P.PrzesunOWektor(przemieszczenie);
  this->S1.PrzesunOWektor(przemieszczenie);
  this->S2.PrzesunOWektor(przemieszczenie);
  this->rysuj(kpi);
  }
  else { przemieszczenie[0]=0;
 przemieszczenie[1]=0;
 przemieszczenie[2]=sin(kat)*odleglosc;
this->P.PrzesunOWektor(przemieszczenie);
  this->S1.PrzesunOWektor(przemieszczenie);
  this->S2.PrzesunOWektor(przemieszczenie);
  this->rysuj(kpi);
  }
}


