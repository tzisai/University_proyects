% operadores lógicos 2

puede_votar(Edad,Nacionalidad) :-
Edad >=18,
Nacionalidad = mexicano,
writeln('Puede Votar').

puede_votar(Edad,Nacionalidad) :-
	(Edad < 18 ; Nacionalidad\=mexicano),
	writeln('No puede votar el w').