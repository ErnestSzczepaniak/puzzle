#ifndef _game_h
#define _game_h

/**
 * @file	game.h
 * @author	Radoslaw Krupka
 * @date	06-04-2020
 * @brief	
 * @details	
**/

#include "time.h"
#include "display.h"
#include "item_square.h"

enum class Key : unsigned char
{
    UP,
    DOWN,
    LEFT,
    RIGHT
}; /* enum: Key */

class Game
{
    /**
     * @class	Game
     * @brief	Klasa symbolizujaca gre i jej interfejs.
     * @details	Glowna klasa projektu odpowiedzialna za inicjalizacje okna glownego zobrazowania,
     *          utworzenie, inicjalizacje oraz nadanie losowych numerow oraz kolorow przetwarzanym w
     *          danej rozgrywce blokom, a takze zapisanie aktualnego czasu rozpoczecia gry a celu pozniejszego
     *          zobrazowania wyniku uzytkownika.
    **/
public:
    Game(int squares);
    ~Game();

    /**
     * @brief	Akcja podejmowana po wcisnieciu strzalki.
     * @param	key enum opisujacy dany klawisz
     * @return	
     * @details	Glowna metoda gry pozwalajaca na prowadzenie rozgrywki. Jej dzialanie mozna
     *          opisac jako 4 podstawowe kroki, ktore powtarzaja sie dla kazdego wywolania:
     *          1.  Znalezienie bloku ktory aktualnie jest pusty (jest to jedyny blok ktory mozemy wypelnic).
     *          2.  Na podstawie klawisza ktory zostal wcisniecy okreslenie czy dany ruch jest
     *              mozliwy do wykonania.
     *          3.  Wyswietlenie animacji poruszajacego sie bloku w strone pustego miejsca.
     *          4.  Logiczna zamiana bloku pustego (ktory istnieje jednak posiada czarny kolor wiec
     *              sprawia wrazenie, iz go tam nie ma) z blokiem wybranym na podstawie przeciwienstwa 
     *              zadanego ruchu (strzalka w "gore" to zamiana bloku pustego z blokiem "ponizej",
     *              strzalka w "lewo" to zamiana bloku pustego z blokeim po jego prawej stronie itd.).
    **/
    void react(Key key);

    /**
     * @brief	Metoda sprawdzajaca czy gra dobiegla wlasnie konca.
     * @return	true - gra dobiegla konca, false - gra trwa nadal.
     * @details	Metoda dokonuje sprawdzenia numerow przypisanych w konstruktorze klasy do poszczeglonych
     *          blokow. Jezeli wszystkie numery ulozone sa w kolejnosci, mamy koniec gry.
    **/
    bool end();

    /**
     * @brief	Wyswietlenie napisow koncowych.
     * @return	
     * @details	Metoda dokonuje koncowego pomiaru czasu rozgrywki, wyczyszczenia wyswietlacza 
     *          oraz wydrukowania informacji dotyczacych zakonczonej wlasnie rozgrywki.
    **/
    void info();

protected:
    /**
     * @brief	Animacja bloku.
     * @param	square Wskaznik na blok podlegajacy animacji przesuniecia.
     * @param	dx Wartosc przesuniecia bloku w osi X.
     * @param	dy Wartosc przesuniecia bloku w osi Y.
     * @return	
     * @details	Metoda iteracyjnei wywoluje metode bloku move(dx, dy), wprowadza opoznienie ktore
     *          wygladza animacje, oraz odswieza ekran.
    **/
    void _animate(Item_square * square, int dx, int dy);

    /**
     * @brief	Poszukiwanie pustego bloku.
     * @return	Wspolrzedne pustego bloku w formacie {x, y}.
     * @details	Iteracyjne przeszukiwanie tablicy blokow w celu znalezienia wspolrzednych bloku 
     *          w kolorze czarnym (symbolizujacym blok pusty).
    **/
    Position _find_blank();

    /**
     * @brief	Zamiana blokow na siatce [x, y]
     * @param	x1 Indeks bloku 1 w siatce (wspolrzedna x).
     * @param	y1 Indeks bloku 1 w siatce (wspolrzedna y).
     * @param	x2 Indeks bloku 2 w siatce (wspolrzedna x).
     * @param	y2 Indeks bloku 2 w siatce (wspolrzedna y).
     * @return	
     * @details	Proste przypisanie blokow w siatce stanowiace ich zamiane miejscami.
    **/
    void _swap(int x1, int y1, int x2, int y2);

private:
    Item_square ** grid;    /**< Wskasnik na wskaznik na tablice blokow gry. */
    int _squares;           /**< Zmienna przechowujaca zadany rozmiar gry (ilosc blokow). */
    int _moves;             /**< Zmienna przechowujaca ilosc wykonanych w danym podejsciu ruchow. */
    time_t _start;          /**< Czas rozpoczecia danego podejscia. */
    time_t _end;            /**< Czas zakonczenia danego podejscia. */

}; /* class: Game */

#endif /* define: game_h */