gerar(Inicio,Fim,[]) :- Inicio>Fim.
gerar(Inicio,Fim,[Inicio|Tail]) :- Inicio =< Fim, Proximo is Inicio + 1, gerar(Proximo, Fim, Tail).
