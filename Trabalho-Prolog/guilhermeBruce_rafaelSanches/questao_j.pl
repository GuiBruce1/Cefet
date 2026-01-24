remover(_,[],[]).
remover(Elemento,[Elemento|Tail],Lista_modificada):- remover(Elemento,Tail,Lista_modificada).
remover(Elemento,[Head|Tail1],[Head|Tail2]) :- Elemento \= Head,remover(Elemento,Tail1,Tail2).

