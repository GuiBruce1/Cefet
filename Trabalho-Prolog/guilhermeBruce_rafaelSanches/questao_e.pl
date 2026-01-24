ultimo([Elemento],Elemento).
ultimo([_|Tail],Elemento) :- ultimo(Tail,Elemento).
