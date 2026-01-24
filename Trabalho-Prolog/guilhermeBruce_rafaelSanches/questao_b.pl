maior([X],X).
maior([Head|Tail],Maior) :- maior(Tail,Maior_temp),((Head>Maior_temp,Maior is Head);(Maior_temp>=Head,Maior is Maior_temp)).
