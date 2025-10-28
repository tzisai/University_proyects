%Arbol genealógico
%Hechos

hombre(juan).
hombre(pedro).
mujer(maria).
mujer(ana).


%Reglas
%X es padre de Y si X es hombre y Y es mujer 
padre(X,Y) :-
	hombre(X),
	mujer(Y).

%X es pariente de Y si es hombre O es mujer 
pariente(X,Y) :-
	hombre(X);
	mujer(Y).
	