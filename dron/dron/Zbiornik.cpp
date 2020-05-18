#include "Zbiornik.hh"
using namespace std;
using drawNS::APIGnuPlot3D;
using drawNS::Point3D;

void Zbiornik::WyswietlMenu(){
cout<<"\t CENTRUM STEROWANIA DRONEM PODWODNYM! " <<endl;
    cout << "p -> Plywanie" << endl;
    cout << "o -> Obrot: "<<endl;
    cout << "w -> Ponowne wyswietlenie menu" << endl;
    cout << "k -> Zakonczenie dzialania programu" << endl;
}

void Zbiornik::Menu(std::shared_ptr<drawNS::Draw3DAPI> kpi){
    char znak;
    double kat, odleglosc;
    while(znak != 'k'){
      cin>>znak;
    switch(znak){
    case 'p':
        cout<<"Na jaką odleglosc ma plynac? "<<endl;
        cin>>odleglosc;
        cout<<"Podaj kat wznoszenia/opadania drona "<<endl;
        cin>>kat;
        for(double i = 0; i<odleglosc; i++){
            this->D.Plyn(i, kat, kpi);
        }
        break;
    case 'o':
        cout<<"Podaj kat na jaki chcesz obrocic drona "<<endl;
        cin>>kat;
        for(double i = 0; i<2*kat; i++){
        this->D.Obrot(i, kpi);
    }
    break;
    case 'w':
        this->WyswietlMenu();
        break;
    case 'k':
        cout<<"Koniec pracy z programem!"<<endl;
        exit(0);
    }

}
}
void Zbiornik::Scena(){
  std::shared_ptr<drawNS::Draw3DAPI> api (new APIGnuPlot3D(-30,30,-30,30,-30,30,0)); 
  api->draw_surface(vector<vector<Point3D>>{{
	drawNS::Point3D(-30,-30,-30), drawNS::Point3D(-30,0,-30), drawNS::Point3D(-30,30,-30)},{
	drawNS::Point3D(-20,-30,-30), drawNS::Point3D(-20,0,-30), drawNS::Point3D(-20,30,-30)},{
	drawNS::Point3D(-10,-30,-30), drawNS::Point3D(-10,0,-30), drawNS::Point3D(-10,30,-30)},{
	drawNS::Point3D(0,-30,-30), drawNS::Point3D(0,0,-30), drawNS::Point3D(0,30,-30)}, {
	drawNS::Point3D(10,-30,-30), drawNS::Point3D(10,0,-30), drawNS::Point3D(10,30,-30)},{
	drawNS::Point3D(20,-30,-30), drawNS::Point3D(20,0,-30), drawNS::Point3D(20,30,-30)},{
	drawNS::Point3D(30,-30,-30), drawNS::Point3D(30,0,-30), drawNS::Point3D(30,30,-30)}
    }, "blue");
  api->draw_surface(vector<vector<Point3D>>{{
	drawNS::Point3D(-30,-30,28), drawNS::Point3D(-30,0,30), drawNS::Point3D(-30,30,28)},{
	drawNS::Point3D(-20,-30,30), drawNS::Point3D(-20,0,28), drawNS::Point3D(-20,30,30)},{
	drawNS::Point3D(-10,-30,28), drawNS::Point3D(-10,0,30), drawNS::Point3D(-10,30,28)},{
	drawNS::Point3D(0,-30,30), drawNS::Point3D(0,0,28), drawNS::Point3D(0,30,30)}, {
	drawNS::Point3D(10,-30,28), drawNS::Point3D(10,0,30), drawNS::Point3D(10,30,28)},{
	drawNS::Point3D(20,-30,30), drawNS::Point3D(20,0,28), drawNS::Point3D(20,30,30)},{
	drawNS::Point3D(30,-30,28), drawNS::Point3D(30,0,30), drawNS::Point3D(30,30,28)}
    }, "blue");
  this->D.rysuj(api);
  this->WyswietlMenu();
  this->Menu(api);
}

