%operadores aritméticos 

calculadora(X,+,Y,Resultado) :-
	Resultado is X + Y.

calculadora(X,-,Y,Resultado) :-
	Resultado is X - Y.

calculadora(X,*,Y,Resultado) :-
	Resultado is X * Y.

calculadora(X,/,Y,Resultado) :-
	Y =\= 0,
	Resultado is X/Y.