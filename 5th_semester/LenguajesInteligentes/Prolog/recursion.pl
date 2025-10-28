% Verifica si un elemento está en la lista
is_it_there([X|_], Encontrar) :-
    Encontrar = X,
    writeln("el numero si esta").

is_it_there([_|Y], Encontrar) :-
    is_it_there(Y, Encontrar).