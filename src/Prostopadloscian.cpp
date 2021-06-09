#include "Prostopadloscian.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostopadloscian, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */

 /******************************************************************************
 |  Konstruktor bezparametryczny klasy Prostopadloscian.                      |
 |  Argumenty:                                                                |
 |     brak                                                                   |
 */
Prostopadloscian::Prostopadloscian()
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            wierzcholek[i][j] = 0;
        }
    }
}

/*****************************************************************************
 |  Konstruktor parametryczny klasy Prostopadloscian.                         |
 |  Argumenty:                                                                |
 |     wektor - zmienna przechowuje dlugosc wektora przesuniecia              |
 |     wysokosc - przechowuje polozenie wierzcholka na osi Oz                 |
 |     szerokosc - przechowuje polozenie wierzcholka na osi Oy                |
 |     dlugosc - przechowuje polozenie wierzcholka na osi Ox                  |
 |  Zwraca:                                                                   |
 |     Wierzcholki prostopadloscianu przesuniete o zadany wektor              | 
 */
Prostopadloscian::Prostopadloscian(const Wektor3D &wektor, double wysokosc, double szerokosc, double dlugosc)
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        wierzcholek[i] = wektor;
    }
    wierzcholek[1][0] += szerokosc;

    wierzcholek[2][1] += wysokosc;

    wierzcholek[3][0] += szerokosc;
    wierzcholek[3][1] += wysokosc;

    wierzcholek[4][1] += wysokosc;
    wierzcholek[4][2] += dlugosc;

    wierzcholek[5][0] += szerokosc;
    wierzcholek[5][1] += wysokosc;
    wierzcholek[5][2] += dlugosc;

    wierzcholek[6][2] += dlugosc;

    wierzcholek[7][0] += szerokosc;
    wierzcholek[7][2] += dlugosc;
}

/******************************************************************************
 |  Metoda klasy Prostopadloscian.                                            |
 |  Argumenty:                                                                |
 |     kat - zmienna przechowujaca wartosc kata w stopniach                   |
 |     krotnosc - zmienna przechowujaca liczbe obrotow o zadany kat           |
 |  Zwraca:                                                                   |
 |     Wartosc True                                                           |
 */
Prostopadloscian Prostopadloscian::Obrot(Macierz3x3 macierz)  
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
    	//(*this)[i] = MacierzObrotu(kat,Os) * (*this)[i];
    	(*this)[i] = macierz* (*this)[i];
    }
    return *this;
}

/******************************************************************************
 |  Realizuje przesuniecie wierzcholkow prostopadlosciana o zadany wektor     |                                               
 |  Argumenty:                                                                |
 |     wektor - przechowuje wspolrzedne wektora przesuniecia                  |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
Prostopadloscian& Prostopadloscian::Przesuniecie(const Wektor3D &wektor)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        (*this)[i] = (*this)[i] + wektor;
    }
    return (*this);
}


/******************************************************************************
 |  Realizuje porownanie dlugosci rownoleglych bokow prostopadlosciana        |                                               
 |  Argumenty:                                                                |
 |     brak                                                                   |
 |  Zwraca:                                                                   |
 |     Informacje o dlugosci bokow oraz czy sa rowne                          |
 */
void Prostopadloscian::Boki() const           //sprawdzenie dlugosci bokow
{
    //Obliczenie dlugosci dluzszych przeciwleglych bokow
    double bok1 = (wierzcholek[1]-wierzcholek[3]).modul();
    double bok2 = (wierzcholek[5]-wierzcholek[7]).modul();
    double bok3 = (wierzcholek[4]-wierzcholek[6]).modul();
    double bok4 = (wierzcholek[0]-wierzcholek[2]).modul();

    //Obliczenie dlugosci krotszych przeciwleglych bokow
    double bok5 = (wierzcholek[0]-wierzcholek[1]).modul();
    double bok6 = (wierzcholek[2]-wierzcholek[3]).modul();
    double bok7 = (wierzcholek[4]-wierzcholek[5]).modul();
    double bok8 = (wierzcholek[6]-wierzcholek[7]).modul();
    
    //Obliczenie dlugosci poprzecznych przeciwleglych bokow
    double bok9 = (wierzcholek[0]-wierzcholek[6]).modul();
    double bok10 = (wierzcholek[1]-wierzcholek[7]).modul();
    double bok11 = (wierzcholek[3]-wierzcholek[5]).modul();
    double bok12 = (wierzcholek[2]-wierzcholek[4]).modul();

    //wyswietlanie informacji czy odpowiadajace sobie boki sa sobie rowne
    if((abs(bok1-bok2)<=MIN_DIFF)&&(abs(bok1-bok3)<=MIN_DIFF)&&(abs(bok1-bok4)<=MIN_DIFF))
    {
        std::cout<<":)  Dluzsze przeciwlegle boki sa sobie rowne."<<std::endl;
        std::cout<<" Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<bok1<<std::endl;
        std::cout<<"   Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<bok2<<std::endl;
        std::cout<<"  Dlugosc trzeciego boku: "<<std::fixed<<std::setprecision(10)<<bok3<<std::endl;
        std::cout<<"  Dlugosc czwartego boku: "<<std::fixed<<std::setprecision(10)<<bok4<<std::endl;
        std::cout<<std::endl;
    }
    else
    {
        std::cout<<":o  Dluzsze przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        std::cout<<" Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<bok1<<std::endl;
        std::cout<<"   Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<bok2<<std::endl;
        std::cout<<"  Dlugosc trzeciego boku: "<<std::fixed<<std::setprecision(10)<<bok3<<std::endl;
        std::cout<<"  Dlugosc czwartego boku: "<<std::fixed<<std::setprecision(10)<<bok4<<std::endl;
        std::cout<<std::endl;
    }
    if((abs(bok5-bok6)<=MIN_DIFF)&&(abs(bok5-bok7)<=MIN_DIFF)&&(abs(bok5-bok8)<=MIN_DIFF))
    {
        std::cout<<":)  Krotsze przeciwlegle boki sa sobie rowne."<<std::endl;
        std::cout<<" Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<bok5<<std::endl;
        std::cout<<"   Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<bok6<<std::endl;
        std::cout<<"  Dlugosc trzeciego boku: "<<std::fixed<<std::setprecision(10)<<bok7<<std::endl;
        std::cout<<"  Dlugosc czwartego boku: "<<std::fixed<<std::setprecision(10)<<bok8<<std::endl;
        std::cout<<std::endl;
    }
    else
    {
        std::cout<<":o  Krotsze przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        std::cout<<" Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<bok5<<std::endl;
        std::cout<<"   Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<bok6<<std::endl;
        std::cout<<"  Dlugosc trzeciego boku: "<<std::fixed<<std::setprecision(10)<<bok7<<std::endl;
        std::cout<<"  Dlugosc czwartego boku: "<<std::fixed<<std::setprecision(10)<<bok8<<std::endl;
        std::cout<<std::endl;
    }
    if((abs(bok9-bok10)<=MIN_DIFF)&&(abs(bok9-bok11)<=MIN_DIFF)&&(abs(bok9-bok12)<=MIN_DIFF))
    {
        std::cout<<":)  Poprzeczne przeciwlegle boki sa sobie rowne."<<std::endl;
        std::cout<<" Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<bok9<<std::endl;
        std::cout<<"   Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<bok10<<std::endl;
        std::cout<<"  Dlugosc trzeciego boku: "<<std::fixed<<std::setprecision(10)<<bok11<<std::endl;
        std::cout<<"  Dlugosc czwartego boku: "<<std::fixed<<std::setprecision(10)<<bok12<<std::endl;
        std::cout<<std::endl;
    }
    else
    {
        std::cout<<":o  Poprzeczne przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        std::cout<<" Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<bok9<<std::endl;
        std::cout<<"   Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<bok10<<std::endl;
        std::cout<<"  Dlugosc trzeciego boku: "<<std::fixed<<std::setprecision(10)<<bok11<<std::endl;
        std::cout<<"  Dlugosc czwartego boku: "<<std::fixed<<std::setprecision(10)<<bok12<<std::endl;
        std::cout<<std::endl;
    }
}

/******************************************************************************
 |  Realizuje zapis wspolrzednych Prostopadloscian do strumienia              |                                               
 |  Argumenty:                                                                |
 |     StrmWy - strumien do ktorego sa zapisywane wspolrzedne wierrzcholkow   |
 |     Pr - przechowuje wspolrzedne wierzcholkow prostopadloscianu            |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */

void Prostopadloscian::Zapis_do_strumienia(std::ostream& StrmWy,  Prostopadloscian Pr)
{
    //zapis wspolrzednych wierzcholkow do strumienia
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[1] << std::endl;
    StrmWy << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[2] << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[3] << std::endl;
    StrmWy << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[4] << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[5] << std::endl;
    StrmWy << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[6] << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[7] << std::endl;
    StrmWy << std::endl;
    //powtorzenie pierwszych wierzcholkow by zamknoc bryle
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[0] << std::endl;
    StrmWy << std::setw(16) << std::fixed << std::setprecision(10) << Pr[1] << std::endl;
    StrmWy << std::endl;
}

/******************************************************************************
 |  Realizuje zapis wspolrzednych Prostopadloscian do pliku                   |                                               
 |  Argumenty:                                                                |
 |     sNazwaPliku - nazwa pliku, do ktorego sa zapisywane wspolrzedne wierzch|
 |     Pr - przechowuje wspolrzedne wierzcholkow, ktore maja byc zapisane     |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostopadloscian::Zapis_do_pliku(const std::string &sNazwaPliku, const Prostopadloscian Pr)
{
    std::ofstream StrmPlikowy;

    StrmPlikowy.open(sNazwaPliku);
    if(!StrmPlikowy.is_open())
    {
        std::cerr << ":( Operacja otwarcia do zapisu \"" << sNazwaPliku << "\"" << std::endl
                  << ":( nie powiodla sie." << std::endl;
        return false;
    }
    Zapis_do_strumienia(StrmPlikowy,Pr);

    StrmPlikowy.close();
    return !StrmPlikowy.fail();
}

/******************************************************************************
 |  Przeciazenie operatora porownania ==                                      |                                               
 |  Argumenty:                                                                |
 |     prosty - zmienna pomocnicza do operacji na prostopadloscianie          |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostopadloscian::operator == (const Prostopadloscian &prosty) const
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        if(this->wierzcholek[i] != prosty.wierzcholek[i])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return true;
}

/******************************************************************************
 |  Przeciazenie operatora porownania =!                                      |                                               
 |  Argumenty:                                                                |
 |     prosty - zmienna pomocnicza do operacji na prostopadlosciana           |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostopadloscian::operator != (const Prostopadloscian &prosty) const
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        if(this->wierzcholek[i] == prosty.wierzcholek[i])
        {
            return false;
        }
        else
        {
            return true;
        }
    }
    return true;
}

/******************************************************************************
 |  Przeciazenie operatora <<                                                 |                                               
 |  Argumenty:                                                                |
 |     strm - strumien wyjsciowy                                              |
 |     prosty - zmienna pomocnicza do operacji na prostopadloscianie          |
 |  Zwraca:                                                                   |
 |     Strumien wyjsciowy                                                     |
 */
std::ostream & operator << (std::ostream &strm, const Prostopadloscian &prosty)
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        strm << prosty.wierzcholek[i] << std::endl;
    }
    return strm;
}

/******************************************************************************
 |  Przeciazenie operatora indeksowania, do odczytu i zapisu wsp. wierzch.    |                  
 |  Argumenty:                                                                |
 |     index - zmienna przechowuje indeks wierzcholka                         |
 |  Zwraca:                                                                   |
 |     Indeks wierzcholka prostopadlosciana                                   |
 */
Wektor3D & Prostopadloscian::operator [] (unsigned int index)
{
    return wierzcholek[index];
}



