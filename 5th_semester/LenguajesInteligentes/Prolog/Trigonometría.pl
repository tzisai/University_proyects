% Calcula seno, coseno y tangente de un angulo en grados
trigonometria(Grados, [Seno, Coseno, Tangente]) :-
    Pi is 3.141592653589793,
    Radianes is Grados * Pi / 180,
    Seno is sin(Radianes),
    Coseno is cos(Radianes),
    Tangente is tan(Radianes).