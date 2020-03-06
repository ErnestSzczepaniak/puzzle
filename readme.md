# Cel projektu

Celem zadania jest stworzenie aplikacji będącej autorską implementacją popularnej gry logicznej. Do jego realizacji zostaną wykorzystane następujące komponenty

## System operacyjny
Całość oprogramowania zostanie wykonana na systemie operacyjnym klasy Linux (dystrybucja Ubuntu) ze względu na dostępność oraz łatwość wykorzystania bibliotek oraz pakietów programistycznych.

## Środowisko
Oprogramowanie zostanie napisane w darmowym oraz bardzo popularnym wśród programistów IDE - VSCode. 

## Kompilator
Ze względu na wybrany system operacyjny, w projekcie zostanie wykorzystany darmowy oraz łatwo dostępny kompilator GCC.

## Oprogramowanie dodatkowe
W celu zautomatyzowoania procesu kompilacji, w projekcie zostanie wykorzystane oprogramowanie make w postaci prostego pliku Makefile.

## Architektura oprogramowania

Ze względu na charakter tworzonej aplikacji, oprogramowanie zostanie rozdzielone na 3 systematyczne grupy:
* Grupa interfejsu - odpowiedzialna za inicjalizację oraz sterowanie wewnętrznymi procesami gry;
* Grupa funkcjonalna - zespół oprogramowania odpowiedzialny za logiczne funkcjonowanie gry;
* Grupa zobrazowania - część oprogramowania odpowiedzialna za prezentację graficzną działania gry na ekranie użytkownika;

### Klasy

Klasa | Grupa | Zakres odpowiedzialności
--- | --- | ---
Item | funkcjonalna | klasa reprezentująca abstakcyjny obiekt który można wyświetlić na ekranie. W prywatnych polach, klasa będzie przechowywała aktualną pozycję obiektu, rozmiary w płąszczyznach X oraz Y a także kolor obiektu w formacie RGB. Ze względu na brak konieczności posiadania informacji o sposobie rysowania oraz czyszczenia konkretnego kształtu  klasa będzie posiadała metody wirtualne (co  uczyni ją klasą abstakcyjną), które będą mogły zostać zaimplementowane przez konkretne klasy potomne. Dodatkowo, klasa będzie posiadała metody pozwalające na przesuwanie obiektu, co wynika bezpośrednio z zasad projektowanej gry.
Square | funkcjonalna | klasa reprezentująca konkretny obiekt (w przypadku projektowanej aplikacji jest to kwadrat). W prywatnym obszarze, klasa będzie przechowywała informacje o numerze nadawanym w procesie inicjalizacji. Jedynymi metodami tej klasy będą metody dziedziczone po klasie Item, które na tym etapie dziedziczenia mogą zostać zaimplementowane.
Game | interfejsu | Klasa symbolizująca całość gry z punktu widzenia użytkownika. Będzie posiadała metody do inicjalizacji gry, reagowania na polecenia gracza (w tym wypadku będą to sygnały przekazywane do części logicznej poprzez strzałki na klawiaturze) oraz sprawdzania czy gra nie dobiegła już końca. Dodatkowo, klasa będzie posiadała moduł losowości (odpowiedzialny za losowe umiejscowienie pól podczas rozpoczynania gry) oraz moduł monitorujący (w celu zliczania ilości ruchów gracza oraz pomiaru czasu gry)
Display | zobrazowania | klasa odpowiedzialna za zobrazowanie działania gry na ekranie komputera. Do jej implementacji zostanie wykorzystana biblioteka X11/Xlib, która jest wbudowana w system operacyjny Linux. Klasa będzie wrapperem stanowiącym zbiór metod wykorzystujących funkcję z biblioteki do zobrazowania w celu uproszczenia składni oraz zapewnienia funkcji niezbędnych do wykorzystania (np. rysuj tekts, rysuj linie, ustaw kolor itp...)

# Instalacja i kompilowanie

1. `git clone https://github.com/ErnestSzczepaniak/puzzle.git`
2. `cd puzzle/`
3. `make`
4. `./puzzle.elf`


# Generowanie i otworzenie dokumentacji
1. `make doxy`
1. `cd doxygen/html/`
1. `firefox index.html`





