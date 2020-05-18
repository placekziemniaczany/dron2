#ifndef BRYLA_HH
#define BRYLA_HH
#include "ZbiorWierzcholkow.hh"
#include "SMacierz.hh"
#define M_PI 3.14159265358979323846

/*!
 * \file
 * \brief Definicja klasy Bryla
 *
 * Plik zawiera definicje klasy Bryla
 */

/*!
 * \brief Enum pozwalajacy wybrac oœ obrotu
 *
 * \param os_ox - obrót wokol osi ox
 * \param os_oy - obrót wokol osi oy
 * \param os_oz - obrót wokol osi oz
 */

enum obroc_wokol {os_ox, os_oy, os_oz};
/*!
 * \brief Modeluje bryly, z których zbudowany jest dron
 *
 * Posiada metody virtualne z ktorych korzystaja powstale bryly
 * (prostopadloscian i graniastoslup)
 *
 */
class Bryla{
protected:
/*!
 * \brief Tablica wierzchołków
 *
 * Zawiera współrzędne wierzchołków obiektów graficznych.
 */
ZbiorWierzcholkow Tablica_wierzcholkow;
/*!
 * \brief id
 *
 * Jest to id obiektu potrzebne do jego usuniecia z programu gnuplot
 */
Wektor3D srodek;
MacierzOb <double, 3> orientacja;
int id;
public:
/*!
 * \brief Wirtualna metoda zmieniająca aktualne położenie obiektu
 */
virtual void PrzesunOWektor (Wektor3D W) = 0;
/*!
 * \brief Metoda obracajaca obiekt konkretnej osi
 */
/*!
 * \brief Metoda wczytujaca wierzcholki z pliku
 */
virtual void loadfromfile(string plik) = 0;
virtual void wyznacz_srodek();

};
#endif

