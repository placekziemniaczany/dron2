#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH
/*!
 * \file
 * \brief Definicja klasy graniastoslup
 *
 * Plik zawiera definicjê klasy graniastoslup
 */
#include "Bryla.hh"
#include "InterfejsRysowania.hh"
#include "ZbiorWierzcholkow.hh"
/*!
 * \brief Modeluje graniastoslup, sruby drona
 *
 * Modeluje graniastoslup dziedzczacy z klas bryla i interfejsrysowania
 * Posiada metody rysowania, wczytywania i przesuwania
 *
 */
class graniastoslup6 : public Bryla, public InterfejsRysowania {
    public:
/*!
 * \brief funkcja rysujaca graniastoslup
 */
void rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi);
/*!
 * \brief funkcja wczytujaca z pliku wierzcholki
 */
void loadfromfile(string plik);
/*!
 * \brief Przesuwajaca graniastoslup o wektor
 */
void PrzesunOWektor(Wektor3D W);
void Obrot(double, obroc_wokol);
};



#endif

