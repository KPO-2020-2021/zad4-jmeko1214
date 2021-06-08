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
  cout<<" p - przesuniecie prostopadloscianu o zadany wektor"<<endl;
  cout<<" w - wyswietlanie wspolrzednych wierzcholkow"<<endl;
  cout<<" m - wyswietl menu"<<endl;
  cout<<" k - koniec dzialania programu"<<endl;
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
  // Zmienna odpowiada za zapis wspolrzednych do strumienia
  /*Prostopadloscian Pr{{10,  25,  10 }
                      {150, 25,  10 },
                      {10,  100, 10 },
                      {150, 100, 10 },
                      {10,  100, 110},
                      {150, 100, 110},
                      {10,  25,  110},
                      {150, 25,  110}};  */
 Prostopadloscian Pr{{10,  25,  10 },{150, 25,  10 },{10,  100, 10 },{150, 100, 10 },{10,  100, 110},{150, 100, 110},{10,  25,  110},{150, 25,  110}};  

  Lacze.DodajNazwePliku("../datasets/Prostopadloscian.dat",PzG::RR_Ciagly,2);
  Lacze.ZmienTrybRys(PzG::TR_3D);
  // Ustawienie zakresow poszczegolnych osi
  Lacze.UstawZakresY(-155,155);
  Lacze.UstawZakresX(-155,155);
  Lacze.UstawZakresZ(-155,155);

  double kat;
  int krotnosc;
  Wektor3D wektor;
  Prostopadloscian prosty;
  char opcja;  //zmienna dla obslugi prostego menu

  cout<<"\n Program rysuje w gnuplocie Prostopadloscian z pliku,"<<endl;
  cout<<" obraca go o zadany kat i przesuwa o zadany wektor."<<endl;
  cout<<" Wynik jest wyswietlany w gnuplocie oraz zapisywany do pliku."<<endl;
  
  Menu_wyswietl();   //wyswietlenie prostego menu

  while(opcja!='k')
  {
    if(!prosty.Zapis_do_pliku("../datasets/Prostopadloscian.dat",Pr))
    {
      cerr<<"Blad! Nie udalo sie wczytac pliku ze wspolrzednymi prostokota!"<<endl;
      return 1;
    }
    prosty.Boki(); // wyswietla dlugosci bokow z dokladnoscia do 10 miejsc po przecinku
    Lacze.Rysuj(); // <- Tutaj gnuplot rysuje, to co zapisaliśmy do pliku
    cout<<endl;
    cout<<" Twoj wybor? (m - menu) > ";
    cin>>opcja;
    cout<<endl;

    switch(opcja)   //obsluga prostego menu
    {
      case 'o':
      {
        cout<<" Podaj wartosc kata obrotu w stopniach"<<endl;
        cin>>kat;
        cout<<" Ile razy operacja obrotu ma byc powtorzona?"<<endl;
        cin>>krotnosc;
        prosty.Obrot(kat,krotnosc);
        prosty.Zapis_do_pliku("../datasets/Prostopadloscian.dat",Pr);
        Lacze.Rysuj();
        prosty.Boki();
        break;
      }
      case 'p':
      {
        cout<<" Wprowadz wspolrzedne wektora translacji w postaci dwoch liczb"<<endl;
        cout<<" tzn. wspolrzednej x oraz wsporzednej y."<<endl;
        cin>>wektor;
        prosty.Przesuniecie(wektor);
        prosty.Zapis_do_pliku("../datasets/Prostopadloscian.dat",Pr);
        Lacze.Rysuj();
        break;
      }
      case 'w':
      {
        cout<<endl;
        cout<<prosty<<endl;     //wyswietla nam wspolrzedne wierzcholkow
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
