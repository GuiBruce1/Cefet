inserirfim(Elemento,[],[Elemento]).
inserirfim(Elemento,[Head|Tail_original],[Head|Tail_modificado]) :- inserirfim(Elemento,Tail_original,Tail_modificado).
reverter([],[]).
reverter([Head|Tail],Lista_invertida) :- reverter(Tail,Lista_temp),inserirfim(Head,Lista_temp,Lista_invertida).
