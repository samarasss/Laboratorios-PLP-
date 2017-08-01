notas(joao, 5, 7, 8).
notas(maria, 6, 6, 6).
notas(joana, 8, 5.1, 10).
notas(mariana, 9, 9, 3).
notas(cleuza, 8.5, 7, 8.6).
notas(jose, 3.5, 3.0, 2.0).
notas(mary, 10, 8, 7).
 
media(X, S) :- notas(X,Y,Z,W), S is ((Y+Z+W)/3).

status(X, R) :- X =< 10, X >= 7, R = "aprovado".
status(X, R) :- X =< 6.9, X >= 4, R = "final".
status(X, R) :- X =< 3.9, X >= 0, R = "reprovado".
 
:- initialization(main).
 
main:-
    read(X),
    media(X,S),
    status(S,Y),
    write(Y),nl,
    halt(0).
