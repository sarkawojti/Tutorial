
Nazwa:	      Fasada - strukturalny wzorzec projektowy (obiektowy)

Problem:      ujednolicenie dostepu do zlozonego systemu poprzez 
	      wystawienie uproszczonego, ujednoliconego interfejsu.

Rozwiazanie:  

    Klient - dowolny kod zainteresowany wykorzystaniem zlozonego systemu.

    Fasada - klasa posiadajaca referencje do elementow sytemu 
	     i interfejs najczesciej wykonywanych zadan

    Zlozony System - to szereg obiektow i metod do ktorych dostep chcemy uproscic.


Konsekwencje:
    - zmniejszenie zaleznosci miedzy klientem a zlozonym systemem
    - wprowadzenie podzialu aplikacji na warstwy - latwy niezalezny 
      rozwoj klienta i zlozonego systemu
    - wieksza czytelnosc i zrozumienie kodu klienta