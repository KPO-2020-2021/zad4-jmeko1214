Zadanie 4 czyli rotacja 3D prostopadloscianu. 

Program posiada proste menu, ktore staralem sie odwzorowac te w opisie zadania. Program umozliwia obrot prostopadloscianu o zadany kat wokol zadanej osi (punktem odniesienia jest poczatek ukladu wspolrzednych), powtorzenie poprzedniego obrotu, przesuniece Prostopadloscianu o zadany wektor, wyswietlenie wspolrzednych wierzcholkow, sprawdzenie czy boki sa rownej dlugosci oraz ponowne wyswietlenie menu.

Podczas tego zadania miałem problem z poczatkowa kompilacja po dodaniu modulu prostopadloscianu (wtedy mialem szablony klasy macierz i wektor rozdzielone na plik naglowkoy oraz plik .cpp), okazalo sie, ze trzeba bylo dodac plik (np. #include "Wektor.cpp") na samym koncu pliku naglowkowego (czyli pliku "Wektor.hh" ). Ten problem zajal mi sporo czasu bo poczatkowo myslalem ze zle zrobilem szablony. Z tym problemem pomogl mi kolega.

Podczas pisania pierwszej fazy drona zauważyłem, że widocznie przez przypadek usunałem jeden z plików w tym zadaniu (Wektor3D.cpp).
