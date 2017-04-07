
NAZWA			Polecenie [Command]

ZASTOSOWANIE		Enkapsulacja polecenie (metoda z parametrami) jako obiektu. 
			Pozwala na korzystanie z tzw. polecen odwracalnych

ARCHITEKTURA		
			CLIENT		    odpowiedzialny za stworzenie CONCRET_COMMAND and RECIVER
			RECIVER		    odbiorca polecenia COMMAND
			CONCRET_COMMAND	    definicja polaczenia pomiedzy odbiaraca a poleceniem
			COMMAND		    interfejs dla polecen
			INVOKER		    przechowuje polecenie oraz ustala odbiorce polecenia

KONSEKWENCJE:
	- oddzielenie operacji od obiekotw, na ktorych jest ona wykonywana
	- polecenia sa reprezentowane jako standardowe obiekt
	- mozliwosc laczenia elementarnych polecen w polecenia zlozone
	- latwosc dodawania nowych rodzajow polecen

	- polecenie wymaga dodatkowej pamieci na zapamietanie swojego stanu