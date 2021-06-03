#include "Prostopadloscian.hh"


/*
 *  Tutaj nalezy zdefiniowac odpowiednie metody
 *  klasy Prostopadloscian, ktore zawieraja 
 *  wiecej kodu niz dwie linijki.
 *  Mniejsze metody mozna definiwac w ciele klasy.
 */
 
 /*****************************************************************************
 |  Metoda klasy Prostopadloscian.                                            |
 |  Argumenty:                                                                |
 |     kat - zmienna przechowujaca wartosc kata w stopniach                   |
 |  Zwraca:                                                                   |
 |     obrot o zadany kat                                                     |
 */
bool Prostopadloscian::Obrot(double &kat)
{
    double obrot;
    obrot = this->Obrot(kat, 1);
    return obrot;
}

/******************************************************************************
 |  Metoda klasy Prostopadloscian.                                            |
 |  Argumenty:                                                                |
 |     kat - zmienna przechowujaca wartosc kata w stopniach                   |
 |     krotnosc - zmienna przechowujaca liczbe obrotow o zadany kat           |
 |  Zwraca:                                                                   |
 |     Wartosc True                                                           |
 */
bool Prostopadloscian::Obrot(double &kat, char Os)  //krotnosc > ile razy powtorzyc obrot o dany kat
{
    for(int i=0; i<WIERZCHOLKI; i++)
    {
    	wierzcholek[i] = MacierzObrotu(kat,Os) * wierzcholek[i];
    }
    return wierzcholek;
}

/******************************************************************************
 |  Realizuje przesuniecie wierzcholkow prostopadlosciana o zadany wektor     |                                               
 |  Argumenty:                                                                |
 |     wektor - przechowuje wspolrzedne wektora przesuniecia                  |
 |  Zwraca:                                                                   |
 |     True lub False                                                         |
 */
bool Prostopadloscian::Przesuniecie(const Wektor3D &wektor)                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
{
    if(wektor[0]==0 || wektor[1]==0)
    {
        return false;
    }
    else
    {
        for(int i=0; i<WIERZCHOLKI; i++)
        {
            wierzcholek[i] = wierzcholek[i] + wektor;
        }
    }
    return true;
}


/******************************************************************************
 |  Realizuje porownanie dlugosci przeciwleglych bokow prostopadlosciana      |                                               
 |  Argumenty:                                                                |
 |     brak                                                                   |
 |  Zwraca:                                                                   |
 |     Informacje o dlugosci bokow oraz czy sa rowne                          |
 */
void Prostopadloscian::Boki() const           //sprawdzenie dlugosci bokow
{
    double dlugosc[WIERZCHOLKI];   //przechowuje dlugosci bokow
    for(int i=0; i<WIERZCHOLKI; i++)
    {
        dlugosc[i]=(wierzcholek[i+1]-wierzcholek[i]).modul();
    }
    dlugosc[WIERZCHOLKI-1]=(wierzcholek[0]-wierzcholek[WIERZCHOLKI-1]).modul();
    //sprawdzenie rownosci dlugosci przeciwleglych bokow prostopadlosciana
    if(dlugosc[0]>dlugosc[1])
    {
        //dlugosc[0] i dlugosc[2] ->dluzsze boki
        //sprawdzenie dlugosci dluzszych bokow
        if(dlugosc[0]==dlugosc[2])
        {
            std::cout<<":)  Dluzsze przeciwlegle boki sa sobie rowne."<<std::endl;
        }
        else
        {
            std::cout<<":o  Dluzsze przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        }
        //wyswietlenie dlugosci bokow dluzszych
        std::cout<<"  Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[0]<<std::endl;
        std::cout<<"    Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[2]<<std::endl<<std::endl;
        
        //sprawdzenie dlugosci krotszych bokow
        if(dlugosc[1]==dlugosc[3])
        {
            std::cout<<":)  Krotsze przeciwlegle boki sa sobie rowne."<<std::endl;
        }
        else
        {
            std::cout<<":o  Krotsze przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        }
        //wyswietlenie dlugosci bokow krotszych
        std::cout<<"  Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[1]<<std::endl;
        std::cout<<"    Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[3]<<std::endl;
    }
    else
    {
        //dlugosc[1] i dlugosc[3] ->dluzsze boki
        //sprawdzenie dlugosci dluzszych bokow
        if(dlugosc[1]==dlugosc[3])
        {
            std::cout<<":)  Dluzsze przeciwlegle boki sa sobie rowne."<<std::endl;
        }
        else
        {
            std::cout<<":o  Dluzsze przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        }
        //wyswietlenie dlugosci bokow dluzszych
        std::cout<<"  Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[1]<<std::endl;
        std::cout<<"    Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[3]<<std::endl<<std::endl;
        
        //sprawdzenie dlugosci krotszych bokow
        if(dlugosc[0]==dlugosc[2])
        {
            std::cout<<":)  Krotsze przeciwlegle boki sa sobie rowne."<<std::endl;
        }
        else
        {
            std::cout<<":o  Krotsze przeciwlegle boki nie sa sobie rowne!!!"<<std::endl;
        }
        //wyswietlenie dlugosci bokow krotszych
        std::cout<<"  Dlugosc pierwszego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[0]<<std::endl;
        std::cout<<"    Dlugosc drugiego boku: "<<std::fixed<<std::setprecision(10)<<dlugosc[2]<<std::endl;
   }
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



