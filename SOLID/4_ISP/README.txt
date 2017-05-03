
Zasada segregacji interfejsow [Interface Segregation Principle]

Definicja:

    "Klienci nie powinni zalezec od interfejsow, których nie uzywaja."
    "Wiele dedykowanych interfejsow jest lepszym rozwiazaniem, niz stosowanie jednego ogolnego interfejsu.”


Objasnienie:

    Interfejsy jakie tworzymy powinny zawierac minimalna liczbe potrzebnych metod, 
    ktore powinny byc œciœle ze soba powiazane.

    "fat interface" - jeden ogromny "tlusty" interfejs, wymuszajacy niekiedy implementacje 
	niepotrzebnych w danym przypadku metod.
    
    Cechy interfejsu:
	- zawiera deklaracje metod i wlasciwosci
	- kazdy element zdefiniowany w inteferjsie musi byc zaimplementowany w docelowej klasie
	- interfejs moze rozszerzac inny interfejs
	- klasa moze implementowac kilka interfejsow
    

Konsekwencje:
	- powstanie wielu krotkich i zwiezlych interfejsow/klas abstrakcyjnych
	  [pozbycie sie "fat interface'ow", mozliwosc ich wielokrotnego uzywania]

    
