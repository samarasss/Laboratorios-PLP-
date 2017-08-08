:- initialization(main).

somaNaoDuplicada(X,Y) :- tiraRepetidas(X,Z), soma(Z,Y).  

soma([],0).
soma([A|B],Y) :- soma(B,Y1), Y is A+Y1.

tiraRepetidas([],[]).
tiraRepetidas([X|Y],[X|Z]) :- retirarTodas(X,Y,L), tiraRepetidas(L,Z).

retirarTodas(_,[],[]).
retirarTodas(X,[X|Y],L) :- retirarTodas(X,Y,L).
retirarTodas(X,[Z|Y],[Z|W]) :- X =\= Z, retirarTodas(X,Y,W).

main:-
read(X),
somaNaoDuplicada(X,Y),
write(Y),nl,
halt(0).
