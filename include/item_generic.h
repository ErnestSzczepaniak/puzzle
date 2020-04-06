#ifndef _item_generic_h
#define _item_generic_h

/**
 * @file	item_generic.h
 * @author	Radoslaw Krupka
 * @date	06-04-2020
 * @brief	
 * @details	
**/

struct Color
{
public:
    int r;
    int g;
    int b;
};

struct Position
{
    int x;
    int y;
};

struct Size
{
    int x;
    int y;
};

class Item_generic
{
    /**
     * @class	Item_generic
     * @brief	Generyczny interfejs rysowanych obiektow.
     * @details	Klasa abstrakcyjna, ktora jest reprezentacja dowolnego obiektu wykorzystywanego w systemie
     *          podlegajacego rysowaniu. Przechowuje pozycje lewego gornego wierzcholka obiektu
     *          (w formacie {x, y}), rozmiar obiektu na plaszczyznie rysowania (w formacie {x, y}), oraz
     *          kolor obiektu (w formacie {r, g, b}). Ze zgledu na fakt, iz jest to jedynie interfejs,
     *          implementacja metod draw() oraz clear() zostaje pozostawiona klasom pochodym ktore 
     *          moga miec informacje np. o ksztalcie obiektu i sposobie jego rysowania.
    **/
public:
    Item_generic();
    ~Item_generic();

    /**
     * @brief	Metoda odpowiedzialna za rysowanie obiektu.
     * @return	
     * @details	Metoda czysto wirtualna.
    **/
    virtual void draw() = 0;

    /**
     * @brief	Metoda odpowiedzialna za czyszczenie obszaru obiektu.
     * @return	
     * @details	Metoda czysto wirtualna.
    **/
    virtual void clear() = 0;

    /**
     * @brief	Przesuwanie obiektu.
     * @param	diff_x Wartosc przesuniecia w plaszczyznie x.
     * @param	diff_y Wartosc przesuniecia w plaszczyznie y.
     * @return	
     * @details	Metoda wykorzystuje metody czysto wirtualne. Przesuniecie obiektu polega na
     *          wyczyszczeniu obszaru w ktorym aktualnie znajduje sie obiekt, zmiane jego polozenia
     *          oraz ponownym narysowaniu obiektu.
    **/
    void move(int diff_x, int diff_y);

    /**
     * @brief	Ustawianie pozycji obiektu.
     * @param	x Nowa pozycja obiektu w plaszczyznie x.
     * @param	y Nowa pozycja obiektu w plaszczyznie y.
     * @return	
     * @details	Metoda przechwytuje podane przez uzytkownika nowe polozenie obiektu, oraz dokonuje
     *          zapisania ich w prywatnym polu klasy.
    **/
    void pos(int x, int y);

    /**
     * @brief	Zwracanie wartosci aktualnego polozenia.
     * @return	Aktualne polozenie.
     * @details	Metoda zwraca aktualne polozenie obiektu.
    **/
    Position pos();

    /**
     * @brief	Zmiana rozmiaru obiektu.
     * @param	x Rozmiar obiektu w plaszczyznie x.
     * @param	y Rozmiar obiektu w plaszczyznie y.
     * @return	
     * @details	Metoda przechwytuje wskazane przez uzytkownika nowe wartosci rozmiaru, oraz zapisuje
     *          je jako prywatne pole klasy.
    **/
    void size(int x, int y);

    /**
     * @brief	Zwracanie wartosci aktualnego rozmiaru.
     * @return	Aktualny rozmiar obiektu.
     * @details	Metoda zwraca prywatna strukture przechowyjaca informacje o aktualnym rozmiarze obiektu.
    **/
    Size size();

    /**
     * @brief	Ustawianie koloru obiektu.
     * @param	r Wartosc skladowej R w palecie RGB.
     * @param	g Wartosc skladowej G w palecie RGB.
     * @param	b Wartosc skladowej B w palecie RGB.
     * @return	
     * @details	Metoda odpowiada za nadanie koloru obiektu (w formacie RGB).
    **/
    void color(int r, int g, int b);

    /**
     * @brief	Zwracanie wartosci koloru.
     * @return	Kolor jako struktura w formacie RGB.
     * @details	Metoda zwraca prywatne pole klasy przechowujace kolor.
    **/
    Color color();

protected:
    Position _position;     /**< Pozycja obiektu w formacie {x, y} */
    Size _size;             /**< Rozmiar obiektu w formacie {x, y} */
    Color _color;           /**< Kolor obiektu w formacie {r, g, b} */

}; /* class: Item_generic */

#endif /* define: item_generic_h */