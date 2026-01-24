inserirfim(Elemento,[],[Elemento]).
inserirfim(Elemento,[Head|Tail_original],[Head|Tail_modificado]) :- inserirfim(Elemento,Tail_original,Tail_modificado).
