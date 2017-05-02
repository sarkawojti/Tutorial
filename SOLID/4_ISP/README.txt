
Zasada odwrocenia zaleznosci [Dependency Inversion Principle]

Author:	Robert C. Martin

Definicja:

    "Wysokopoziomowe moduly nie powinny zalezec od modulow niskopoziomowych – 
     zaleznosci miedzy nimi powinny wynikac z abstrakcji."

    "High-level modules should not depend on low-level modules. 
     Both should depend on abstractions. Abstractions should 
     not depend on details. Details should depend on abstractions."


Objasnienie:

    [podejscie tradycyjne]
    Moduly [klasy, logika] wyzszego poziomu bezposrednio korzystaja z modulow
    [klas, logiki] nizszego poziomu. Ogranicza sie w ten sposob wykorzytsanie modulow
    wyzszego poziomu, gdyz sa scisle zwiazane z implementacja nizszego poziomu.
    

    [podejscie zgodne z DIP]
    Moduly wyzszego poziomu nie powinny zalezec od modulow nizszego poziomu. 
    W tym celu wprowadza sie elementy abstrakcji (interfejsy/ klasy abstrakcyjne) 
    tak by klasy wyzszego poziomu korzystaly z abstrakcji, a klasy nizszego 
    poziomu implementowaly abstrakcje.

Konsekwencje:

    - modyfikacje modulow niskiego poziomu nie wymuszaja modyfikacji modulow wyskopoziomowych
	[brak konfliktow w procesie tworzenia oprogramowania]

    - wykorzystanie gotowych i przetestowanych modulow wysokopoziomowych 
      do implementacji identycznych funkcjonalnosci
	[ograniczenie duplikacji w kodzie - uzycie interfejsu/klasy abstrakcyjnej;
         brak nowych bledow w kodzie; latwosc realizacji nowych zadan; 
         unikanie tworzenia nadmiarowych klas]

    - dodanie abstrakcji na kazdym poziomie kodu - uzycie interfejsu/klasy abstrakcyjnej
	[dodanie nowych komponentow lub ich podniama nie powoduje modyfikacji w modulach wyskiego poziomu;
         mozliwosc uzycia w przyszlosci modulu wyskopoziomowego jako niskopoziomowego]
