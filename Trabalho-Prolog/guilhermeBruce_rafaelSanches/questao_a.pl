nelementos([],0).
nelementos([_|Tail],Num) :- (nelementos(Tail,Num_temp),Num is Num_temp+1).
