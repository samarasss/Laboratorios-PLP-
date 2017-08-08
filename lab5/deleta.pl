:- initialization(main).

remover(X, [], []).
remover(X,[X|C],C).
remover(X,[Y|C],[Y|D]):- remover(X,C,D).

main:-
read(X),
read(Y),
remover(Y,X,Z),
write(Z),nl,
halt(0).

