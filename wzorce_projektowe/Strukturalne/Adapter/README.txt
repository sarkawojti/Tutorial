
Nazwa:	     Adapter - strukturalny wzorzec projektowy (obiekowy lub klasowy)


Problem:     dany obiekt lub klasa sa niezgodne z interfejsem oczekiwanym przez klienta;
  	     brak mozliwosci wspolpracy pomiedzy dwoma klasami o niekompatybilnych intefejsach.

Rozwiazanie: przeksztalcenie niekompatybilnego interfejsu na oczekiwany.


	Client  - definiuje interfejs docelowy / wspolpracuje z obiektami o oczekiwanym interfejsie.

	Target  - interfejs docelowy

	Adaptee - niekompatybilny interfejs wymagajacy dostosowania

	Adapter - adaptuje stary niekompatybilny interfejs na nowy oczekiwany przez klienta

	    wzorzec obiektowy:
		-) dziedziczy po interfejsie docelowym
		-) przechowuje odwolanie umoziliwajace dostep do metod Adaptee

	    wzorzec klasowy:
		-) dziedziczy wielokrotnie: publicznie po Target, prywatnie po Adaptee

Konsekwencje:
	-) narzut wydajnosci proporcjonalny do wielkosci niekompatyblnosci interfejsow

	wzorzec obiektowy:
	    -) mozliwosc adaptacji klasy i jej podklas
	    -) mozliwosc dodania nowej funkcjonalnosci
	    -) nie ma mozliwosci przesloniecia metod Adaptee

	wzorzec klasowy:
	    -) mozliwosc adaptacji klasy ale NIE jej podklas
	    -) mozliwosc przesloniecia metod Adaptee