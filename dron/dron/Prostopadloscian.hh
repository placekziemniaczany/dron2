#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH
/*!
 * \file
 * \brief Definicja klasy Prostopadloscian
 *
 * Plik zawiera definicjê klasy Prostopadloscian
 */
#include "Bryla.hh"
#include "InterfejsRysowania.hh"
#include "ZbiorWierzcholkow.hh"
/*!
 * \brief Modeluje Prostopadloscian, korpus Drona
 *
 * Modeluje prostoadloscian dziedzczacy z klas bryla i interfejsrysowania
 * Posiada metody rysowania, wczytywania i przesuwania
 *
 */
class Prostopadloscian : public Bryla, public InterfejsRysowania {
public:
  /*!
 * \brief funkcja rysujaca prostopadloscian
 */
void rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi);
/*!
 * \brief funkcja wczytujaca z pliku wierzcholki
 */
void loadfromfile(string plik);
/*!
 * \brief Przesuwajaca prostopadloscian o wektor
 */
void PrzesunOWektor(Wektor3D W);
void Obrot(double, obroc_wokol);
};



#endif
