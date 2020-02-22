
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

Klasa | Zakres odpowiedzialności
--- | ---
Generic_item | klasa reprezentująca abstakcyjny obiekt który można wyświetlić na ekranie. W prywatnych polach, klasa będzie przechowywała aktualną pozycję obiektu, rozmiary w płąszczyznach X oraz Y a także kolor obiektu w formacie RGB. Ze względu na brak konieczności posiadania informacji o sposobie rysowania oraz czyszczenia konkretnego kształtu  klasa będzie posiadała metody wirtualne (co  uczyni ją klasą abstakcyjną), które będą mogły zostać zaimplementowane przez konkretne klasy potomne.

### Biblioteki








