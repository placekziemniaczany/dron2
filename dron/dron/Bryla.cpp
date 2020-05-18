#include "Bryla.hh"

/** \brief  Obraca ka�dy wierzcho�ek dowolnej bry�y w oparciu o wz�r:
            Wektor nowych warto�ci *= Macierz Obrotu
            Za pomoca switch case funkcja wybiera wokol jakiej osi sie obrocic
 *
 * \param kat - k�t o kt�ry chcemy obr�ci� bry��
 * \param os - os wok� kt�rej chcemy obr�ci� bry��
 *
 */

void Bryla::wyznacz_srodek(){
    double x, y, z;
    for(unsigned int i = 0; i < Tablica_wierzcholkow.size(); ++i) {
        x += Tablica_wierzcholkow[i][0];
        y += Tablica_wierzcholkow[i][1];
        z += Tablica_wierzcholkow[i][2];
    }
    this->srodek.dodaj_wartosc(x/Tablica_wierzcholkow.size(),0);
    this->srodek.dodaj_wartosc(y/Tablica_wierzcholkow.size(),1);
    this->srodek.dodaj_wartosc(z/Tablica_wierzcholkow.size(),2);
}

