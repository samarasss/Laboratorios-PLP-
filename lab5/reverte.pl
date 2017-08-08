:- initialization(main).

reverte([],[]).
reverte([H|T],L):- reverte(T,R), concat(R,[H],L).

concat([],L,L).
concat([X|L1],L2,[X|L3]):- concat(L1,L2,L3). 

main:-
read(X),
reverte(X,Y),
write(Y),nl,
halt(0).
