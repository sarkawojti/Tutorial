
Zasada pojedynczej odpowiedzialnosci [Single Responsibility Principle]

Autor:
    Toma DeMarco/ Meilir Page-Jones


Definicja:
    
    "Klasa powinna posiadac tylko jeden powod do zmiany."
    ["A class should have only one reason to change"]

Objasnienie:

    Zasada ta polega na umieszczeniu w interfejsie/klasie/funkcji tylko takich 
    funkcjonalnosci, ktore maja scisle polaczenie z nimi, wpisuja sie w ich przeznaczenie.

Konsekwencje:

    - wzrost liczby malych konkretnych klas [pozbycie sie klas "spaghetti" - 
       skomplikowanych, wieloekranowych, wielozadaniowych, robiacych wszystko, trudnych w zarzadzaniu];

    - duza przejrzystosc i czytelnosc kodu;

    - latowosc utrzymania i rozwoju oprogramowania [brak konfliktow przy realizacji zadan];

    - spadek wskaznika duplikacji kodu [wykorzytanie nowych klas w innych czesciach kodu];

    - uproszczenie testowania kodu;

    
	
	
	