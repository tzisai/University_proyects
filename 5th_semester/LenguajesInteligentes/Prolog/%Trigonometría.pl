%Trigonometría(grados,[Seno,Coseno,Tangente]):-

trigonometría(grados,[Seno,Coseno,Tangente]):-
Radianes is Grados * pi /180,
Seno is sin(Radianes),
Coseno is cos(Radianes),
Tangente is tan(Radianes).


?-trigonometría(0,R).
R=[0.0,1.0,0.0).