adjacente(Elemento1,Elemento2,[Elemento1,Elemento2|_]).
adjacente(Elemento1,Elemento2,[Elemento2,Elemento1|_]).
adjacente(Elemento1,Elemento2,[_|Tail]) :- adjacente(Elemento1,Elemento2,Tail).
