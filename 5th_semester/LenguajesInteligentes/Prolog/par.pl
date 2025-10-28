par_o_impar(N) :-
    N mod 2 =:= 0,
    writeln('el puto numero es par alv.').

par_o_impar(N) :-
    N mod 2 =:= 1,
    writeln('el puto numero es impar alv.').