
Nazwa: 	   Kompozyt - strukturalny wzorzec projektowy (obiektowy)

Problem:   skladanie obiektow w taki sposob, by klient widzial wiele z nich jako pojedynczy obiekt.

Rozwiazanie:    

    Component - klasa abstrakcyjna reprezentujaca pojednycze obiekty Leaf,
		jak i kontenery tych obiektow Composite.

    Leaf      - typ prosty nie posiadajacy potomkow.

    Composite - kontener na obiekty proste Leaf,
                implementuje zachowanie eleemntow ktore zawiera.

Konsekwencje:
    - umozliwia definiowanie hierarchi z obiektow prostych i zlozonych,
    - upraszacza kod klientow,
    - ulatwia dodawanie komponentow nowego rodzaju,
    - moze sprawic, ze projekt stanie sie zanadto ogolny.