// Executables must have the following defined if the library contains
// doctest definitions. For builds with this disabled, e.g. code shipped to
// users, this can be left out.
#ifdef ENABLE_DOCTEST_IN_LIBRARY
#define DOCTEST_CONFIG_IMPLEMENT
#include "../tests/doctest/doctest.h"
#endif

#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <string>

#include "Wektor.hh"
#include "Wektor3D.hh"
#include "Macierz.hh"
#include "Macierz3x3.hh"
#include "Prostopadloscian.hh"
#include "exampleConfig.h"
#include "example.h"
#include "lacze_do_gnuplota.hh"

using namespace std;

void Menu_wyswietl()
{
  cout<<endl;
  cout<<" Menu programu:"<<endl<<endl;
  cout<<" o - obrot prostopadloscianu o zadany kat"<<endl;
  cout<<" t - powtorzenie poprzedniego obrotu"<<endl;
  cout<<" r - wyswietlenie macierzy rotacji"<<endl;
  cout<<" p - przesuniecie prostopadloscianu o zadany wektor"<<endl;
  cout<<" w - wyswietlanie wspolrzednych wierzcholkow"<<endl;
  cout<<" s - sprawdzenie dlugosci przeciwleglych bokow"<<endl;
  cout<<" m - wyswietl menu"<<endl;
  cout<<" k - koniec dzialania programu"<<endl;
  cout<<endl;
}

/*
 * Simple main program that demontrates how access
 * CMake definitions (here the version number) from source code.
 */
int main() {
  cout << "Project Rotation 3D based on C++ Boiler Plate v"
            << PROJECT_VERSION_MAJOR /*duże zmiany, najczęściej brak kompatybilności wstecz */
            << "."
            << PROJECT_VERSION_MINOR /* istotne zmiany */
            << "."
            << PROJECT_VERSION_PATCH /* naprawianie bugów */
            << "."
            << PROJECT_VERSION_TWEAK /* zmiany estetyczne itd. */
            << endl;
  PzG::LaczeDoGNUPlota  Lacze;  // Zmienna odpowiada za wizualizacje rysunku prostopadloscianu
  Lacze.DodajNazwePliku("../datasets/Prostopadloscian.dat",PzG::RR_Ciagly,2);
  Lacze.ZmienTrybRys(PzG::TR_3D);
  // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-200,200);
  Lacze.UstawZakresX(-200,200);
  Lacze.UstawZakresZ(-200,200);

  double kat;
  double wek[] = {15.0, 25.0, 40.0};
  Wektor3D wektor(wek);
  Prostopadloscian Pr(wektor, 100, 80, 60);
  Prostopadloscian prosty;
  Macierz3x3 obrot;   //macierz obrotu
  Macierz3x3 obrot2;  //zmienna pomocnicza do powtorzenia obrotu
  char opcja;         //zmienna dla obslugi prostego menu
  char os;            //zmienna dla wyboru osi obrotu
  

  cout<<"\n Program rysuje w gnuplocie Prostopadloscian z pliku,"<<endl;
  cout<<" obraca go o zadany kat i przesuwa o zadany wektor."<<endl;
  cout<<" Wynik jest wyswietlany w gnuplocie oraz zapisywany do pliku."<<endl;
  
  Menu_wyswietl();   //wyswietlenie prostego menu
  Pr.Boki();    // wyswietla dlugosci bokow z dokladnoscia do 10 miejsc po przecinku

  while(opcja!='k')
  {
    if(!prosty.Zapis_do_pliku("../datasets/Prostopadloscian.dat",Pr))
    {
      cerr<<"Blad! Nie udalo sie wczytac pliku ze wspolrzednymi prostokota!"<<endl;
      return 1;
    }
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    cout<<endl;
    cout<<" Twoj wybor? (m - menu) > ";
    cin>>opcja;
    cout<<endl;

    switch(opcja)   //obsluga prostego menu
    {
      case 'o':
      {
        cout<<" Podaj os, wedlug ktorej chcesz dokonac obrotu, oraz kat w stopniach: "<<endl;
        cin >> os >> kat;
        if(os=='x'||os=='y'||os=='z')
        {
          obrot=MacierzObrotu(kat,os);
          Pr=Pr.Obrot(obrot);
        }
        else
        {
          cerr<< " Nieznana opcja. Dopuszczalne opcje: x,y,z lub X,Y,Z"<<endl;
        }
        break;
      }
      case 't':
      {
        obrot2=obrot;
        Pr=Pr.Obrot(obrot2);
        break;
      }
      case 'r':
      {
        cout<<" Wybierz os, dla ktorej wyswietlic macierz rotacji. "<<endl;
        cin >> os >> kat;
        if(os=='x'||os=='y'||os=='z')
        {
          obrot=MacierzObrotu(kat,os);
          cout<<obrot<<endl;
        }
        else
        {
          cerr<< " Nieznana opcja. Dopuszczalne opcje: x,y,z lub X,Y,Z"<<endl;
        }
        break;
      }
      case 'p':
      {
        cout<<" Wprowadz wspolrzedne wektora translacji w postaci trzech liczb"<<endl;
        cout<<" tzn. wspolrzednych: x, y oraz z."<<endl;
        cin>>wektor;
        Pr.Przesuniecie(wektor);
        break;
      }
      case 'w':
      {
        cout<<endl;
        cout<<Pr<<endl;     //wyswietla nam wspolrzedne wierzcholkow
        break;
      }
      case 's':
      {
        Pr.Boki();
        break;
      }
      case 'm':
      {
        Menu_wyswietl(); 
        break;
      }
      case 'k':
      {
        cout<<"\n Koniec dzialania programu.\n"<<endl;
        break;
      }
      default:
      {
        cerr<<"\n Blad! Nie rozpoznano opcji menu. Sprobuj jeszcze raz."<<endl;
        break;
      }
    }
  }   


  // Bring in the dummy class from the example source,
  // just to show that it is accessible from main.cpp.
  Dummy d = Dummy();
  return d.doSomething() ? 0 : -1;
}
