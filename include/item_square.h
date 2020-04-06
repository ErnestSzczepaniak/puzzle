#ifndef _item_square_h
#define _item_square_h

/**
 * @file	item_square.h
 * @author	Radoslaw Krupka
 * @date	06-04-2020
 * @brief	
 * @details	
**/

#include "item_generic.h"

static constexpr auto size_square = 60;

class Item_square : public Item_generic
{
    /**
     * @class	Item_square
     * @brief	Obiekt pojedynczego bloku ukladanki
     * @details	Podstawowy typ ukladanki symbolizujacy pojedynczy blok posiadajacy wlasny unikalny numer (ktorego unikalnosc)
     *          zapewniana jest w klasie Game. Klasa jest rozszezeniem abstrakcyjnej klasy Item_generic oraz uzupelnia jej
     *          metody metody o charakterze czysto wirtualnym (co czyni ja klasa konkretna). W celu interakcji z oknem gry,
     *          klasa wykorzystuje warstwe abstrakcji wyswietlacza z pliku display.h.
    **/
public:
    Item_square(int number = 0);
    ~Item_square();

    /**
     * @brief	Rysowanie obiektu.
     * @return	
     * @details	Rysowanie bloku na podstawie polozenia oraz rozmiaru obiektu z wykorzystaniem warstwy abstrakcji wyswietlacza.
    **/
    void draw();

    /**
     * @brief	Czyszczenie obiektu.
     * @return	
     * @details	Czyszczenie fragmentu wyswietlacza na ktorym aktualnie znajduje sie dany blok z wykorzystaniem warstwy abstrakcji
     *          wyswietlacza
    **/
    void clear();

    /**
     * @brief	Przypisanie numeru bloku.
     * @param	value Numer nadawany przez uzytkownika.
     * @return	
     * @details	Ze wzgledu na wewnetrzne wyrownanie cyfr w bloku, wartosc zostala ograniczona do 2 cyfr na blok (czyli maksymalny
     *          mozliwy do nadania numer to 99).
    **/
    void number(int value);

    /**
     * @brief	Pobranie numeru bloku.
     * @return	Numer bloku.
     * @details	Zwrocenie prywatnego pola klasy przechowyjacego number bloku;
    **/
    int number();

private:
    int _number;    /**< Numer bloku */

}; /* class: Item_square */

#endif /* define: item_square_h */