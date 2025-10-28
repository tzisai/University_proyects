positivo_o_negativo(X):-
(
X>0 ->
	writeln('Es positivo')
	;
X<0 ->
	writeln('Es negativo')
	;
	writeln('Es cero')
).
