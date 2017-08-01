reinado(rhodi, 884, 878).
reinado(anarawd, 878, 916).
reinado(hywel_dda, 916, 950).
reinado(lago_ap_idwal, 950, 979).
reinado(hywal_ap_Ieuaf, 979, 985).
reinado(cadwallon, 985, 986).
reinado(maredudd, 986, 999).

quem_reina(R, X) :- reinado(R, A, B), X >= A, X =< B. 

:- initialization(main).

main:-
    repeat,
    read(X),
    quem_reina(R, X),
    write(R),nl,
    halt(0).
