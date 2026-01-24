incrementar([],[]).
incrementar([Head|Tail],[Head_incrementado|Tail_incrementado]) :- Head_incrementado is Head+1,incrementar(Tail,Tail_incrementado).

