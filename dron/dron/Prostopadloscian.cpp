#include "Prostopadloscian.hh"
using namespace std;
/*!
 * Funkcja rysujaca prostopadloscian
 * Funkcja w petlach wrzuca do lokalnych szablonow \e W1 i \e W2 za pomoca
 * metody push_back dane wierzcholkow odczytanych z tablic wierzcholkow danych
 * prostopadloscianu. Pozniej szablony te sa wrzucane do szablonu \e w, z ktorego
 * korzysta funkcja draw_polyhedron. Kazda petla odpowiada za narysowanie podstawy
 * prostopadloscianu. Id tego prostopadloscianu przypisywane jest funkcji draw_polyhedron,
 * zeby z kazdym kolejnym rysowaniem poprzedni obiekt byl wymazywany z gnuplota
 * \param kpi - wskaznik na modul do rysowania w gnuplocie
 */
void Prostopadloscian::rysuj(std::shared_ptr<drawNS::Draw3DAPI> kpi){
vector<vector<drawNS::Point3D>> w;
vector<drawNS::Point3D> W1, W2;
kpi->erase_shape(this->id);
for (int i = 0; i<4; i++){
W1.push_back(drawNS::Point3D((srodek+(orientacja*Tablica_wierzcholkow[i]))[0],(srodek+(orientacja*Tablica_wierzcholkow[i]))[1],(srodek+(orientacja*Tablica_wierzcholkow[i]))[2]));
}
w.push_back(W1);
for (int i = 4; i<8; i++){
W2.push_back(drawNS::Point3D((srodek+(orientacja*Tablica_wierzcholkow[i]))[0],(srodek+(orientacja*Tablica_wierzcholkow[i]))[1],(srodek+(orientacja*Tablica_wierzcholkow[i]))[2]));
}
w.push_back(W2);
this->id = kpi->draw_polyhedron(vector<vector<drawNS::Point3D>> {w
},"black");
}
/*!
 * Funkcja wczytujaca dane wierzcholkow drona z pliku
 * funkcja ktora obsluguje wczytywanie danych za pomoca fstream. W petli
 * wczytywane sa poszczegole wierzcholki, ktore potem metoda DodajWierzholek
 * trafiaja do Tablicy wierzcholkow
 * \param plik - nazwa pliku
 */
void Prostopadloscian::loadfromfile(string plik){
fstream input(plik.c_str(), std::ios::in);
double x, y, z;
for (int i = 0; i < 8; i++){
input>>x;
input>>y;
input>>z;
Prostopadloscian::Tablica_wierzcholkow.DodajWierzcholek(x, y, z);
}
input.close();
}
/*!
 * Funkcja przesuwajaca prostopadloscian o wektor
 * W petli konczacej sie gdy i osiagnie 8 (wierzcholki). Do kazdych 3 wierzcholkow
 * dodawany jest nowy wektor przesuniecia
 */

void Prostopadloscian::PrzesunOWektor(Wektor3D W){
  this->srodek = this->srodek + (orientacja*W);
}
void Prostopadloscian::Obrot(double kat, obroc_wokol os){
kat = kat * (M_PI/180);
 MacierzOb <double, 3> M,N,O;
switch (os){
case os_ox:
M = M.obrot_ox(kat);
this->orientacja =this->orientacja* M;
break;
case os_oy:
 N = N.obrot_oy(kat);
 this->orientacja =this->orientacja* N;
break;
case os_oz:
    O = O.obrot_oz(kat);
    this->orientacja =this->orientacja* O;
    break;
} 
}
