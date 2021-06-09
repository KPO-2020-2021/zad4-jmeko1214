#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#define WIERZCHOLKI 8

#include "Macierz.hh"
#include "Macierz3x3.hh"
#include "Wektor.hh"
#include "Wektor3D.hh"
#include <iostream>                                                                                                                                                                                                                                                                                                                                         
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <cmath>

/*!
 *  \brief Definicja klasy Prostopadloscian.
 *
 * Klasa reprezentuje prostopadloscian, obiekt skladajacy 
 * sie z 8 wierzcholkow. Prostopadloscian mozna przesuwac,
 * obracac, wyswietlac jego wierzcholki oraz sprawdzac, czy
 * po tych operacjach boki sa rowne.
 */
class Prostopadloscian {
    Wektor3D wierzcholek[WIERZCHOLKI];
    //zaprzyjaznienie funkcji by moc wyswietlac wspolrzedne wierzcholkow prostopadloscianu
    friend std::ostream & operator << (std::ostream &Strm, const Prostopadloscian &Pr);

  public:
    Prostopadloscian();
    Prostopadloscian(const Wektor3D &wektor, double wysokosc, double szerokosc, double dlugosc);                                                                                                                                                                                                                                                                      
    //Prostopadloscian Obrot(double kat, char Os);           //metoda odpowiada o obrot okresliona os o dany kat
    Prostopadloscian Obrot(Macierz3x3 macierz);
    Prostopadloscian& Przesuniecie(const Wektor3D &wektor);
    void Boki() const;                          //sprawdza dlugosci poszczegolnych bokow

    void Zapis_do_strumienia(std::ostream& StrmWy, Prostopadloscian Pr);
    bool Zapis_do_pliku(const std::string &NazwaPliku, const Prostopadloscian Pr);

    Wektor3D & operator[] (unsigned int index);         //przeciazenie operatora indeksowania, sluzy do odczytu i zapisu wierzcholkow
    bool operator == (const Prostopadloscian &prosty) const;
    bool operator != (const Prostopadloscian &prosty) const;
};
  
/*!
 * \brief Przeciazenie operatora wyswietlania.
 *
 * Przeciazenie sluzy do przekazywania do strumienia wspolrzednych
 * wierzcholkow prostopadloscianu.
 */
//wyswietla wspolrzedne wierzcholkow prostopadlosciana 
std::ostream& operator << ( std::ostream &Strm, const Prostopadloscian &Pr); 


#endif


