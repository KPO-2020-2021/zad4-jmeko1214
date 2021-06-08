#ifndef WEKTOR_HH
#define WEKTOR_HH

#define MIN_DIFF 0.0000000001

#include "size.hh"
#include <iostream>
#include <iomanip>
#include <cmath>



/*!
 * \file
 * \brief Ten plik zawiera definicję szablonu klasy Wektor<>
 *
 * Ten plik powinien zawiera definicję szablonu Wektor<>.
 * W tym celu przerobio definicję klasy Wektor2D.
 */


/*!
 * \brief Klasa Wektor modeluje wektor o rozmiarze SIZE oraz zadanym typie wartosci.
 * 
 *  Szablon klasy reprezentujacej wektor o zadanym rozmiarze SIZE (w naszym przypadku 2).
 *  Szablon tworzy wektory o zadanych rozmiarach. Wykonuje podstawowe operacje 
 *  matematyczne na wektorze.
 */
template <int SIZE>
class Wektor 
{
private:
  double size[SIZE];

public:
  Wektor();
  Wektor(double [SIZE]);

  double modul() const;       //metoda liczy dlugosc wektora

  //przeciazenia operatorow
  Wektor<SIZE> operator + (const Wektor<SIZE> &v) const;
  Wektor<SIZE> operator - (const Wektor<SIZE> &v) const;
  Wektor<SIZE> operator * (const double &tmp);
  Wektor<SIZE> operator / (const double &tmp);

  const double &operator [] (int index) const;
  double &operator [] (int index);

  bool operator == (const Wektor<SIZE> &wek) const;
  bool operator != (const Wektor<SIZE> &wek) const;
};

/*!
 * \brief Przeciążenie dla wyjścia musi także być szablonem
 *
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 */
template <int SIZE>
inline
std::istream& operator >> (std::istream &Strm, Wektor<SIZE> &Wek);

/*!
 * \brief Przeciążenie dla wejścia musi także być szablonem
 * 
 * To przeciazenie trzeba opisac. Co ono robi. Jaki format
 * danych akceptuje. Jakie jest znaczenie parametrow itd.
 */
template <int SIZE>
inline
std::ostream& operator << (std::ostream &Strm, const Wektor<SIZE> &Wek);

#include "Wektor.cpp"

#endif
