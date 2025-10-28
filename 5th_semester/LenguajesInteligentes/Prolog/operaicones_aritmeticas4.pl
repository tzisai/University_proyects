operaciones(X,Y,[Potencia,Exponencial,Raiz,ValorAbs]) :-
	Potencia is X**Y,
	Exponencial is exp(X),
	Raiz is sqrt(X),
	ValorAbs is abs(X).