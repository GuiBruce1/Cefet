somaElementos([],0).
somaElementos([Head|Tail],Soma) :- somaElementos(Tail,Soma_temp),Soma is Head+Soma_temp.

nelementos([],0).
nelementos([_|Tail],Tamanho) :- nelementos(Tail,Tamanho_temp),Tamanho is Tamanho_temp+1.

medio([],0) :- !.
medio(Lista,Media) :- somaElementos(Lista,Soma),nelementos(Lista,Tamanho),(Tamanho=\=0->Media is Soma/Tamanho;Media is 0).
