#ifndef SCENA_HH
#define SCENA_HH
#include <iostream>
#include "dron.hh"
class Zbiornik{
    Dron D;
public:
    void WyswietlMenu();
    void Menu(std::shared_ptr<drawNS::Draw3DAPI> kpi);
  void Scena();
};
#endif // SCENA_HH
