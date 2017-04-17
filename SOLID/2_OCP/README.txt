
Zasada otwarte-zamkniete [Open-Closed Principle]


Autor:
    Bertrand Meyer


Definicja:

    "Klasa powinna byæ otwarta na rozszerzanie, ale zamkniêta na modyfikacje"


Objasnienie:

    Powinnismy miec mozliwosc zmienic zachowanie klasy/interfejsu [dodac nowa  funkcjonalnosc, 
    rozszerzyc klase] bez zmiany jego kodu [bez koniecznosci modyfikacji juz istniejacej struktury].


Konsekwencje:

    - dodajac nowa funkcje nie ma koniecznosci zmiany istniejacego kodu
      [brak konfliktow w prcesie tworzenia oprogramowania];
    - brak modyfikacji kodu powoduje brak nowych bledow w starym kodzie;
    - powstaja nowe podklasy z przeciazonymi metodami
