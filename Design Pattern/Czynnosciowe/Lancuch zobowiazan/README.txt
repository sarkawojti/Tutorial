
NAZWA:		Lancuch zobowiazan/odpowiedzialnosci [Chain of responsibility]


ZASTOSOWANIE:	Sluzy do stworzenia lancucha obiektow, ktore przetwarzaja zadanie. 
		Przetwarzanie zadania odbywa sie w kazdym obiekcie nalezacym do 
		lancucha odpowiedzialnosci. Obiekt obsluguje zadanie albo wysyla je dalej.

ARCHITEKTURA:	
		CLIENT			tworzy zadanie i inicjuje jego przetwarzanie, 
					przekazujac je do pierwszego obiektu HANDLER;

		HANDLER			definiuje interfejs dla CONCRETE_HANDLER oraz
					dostarcza mechanizm kolejki;

		CONCRETE_HANDLER	wykonwawca zadania, sprawdza czy moze je obsluzyc
					przekazuje zadanie dalej [jesli go nie wykonal lub
					jest to zadanie skierowane do kilku obiektow] jesli 
					istnieje nastepnik;

KONSEKWENCJE:
	- brak gwarancji obslugi zadania
	- dynamiczne dodawanie i usuwanie elementow lancucha w czasie dzialania aplikacji
	- zmniejszenie zaleznosci na linii nadawca - odbiorca
	- nie zaleznosc w implementacji poszczegolnych wykonawcow