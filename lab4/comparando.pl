populacao(brasil, 200).
populacao(eua, 320).
populacao(canada, 35).
populacao(india, 1200).
populacao(china, 1300).
populacao(japao, 127).
populacao(russia, 142).

territorio(brasil, 8).
territorio(eua, 9).
territorio(canada, 9).
territorio(india, 3).
territorio(china, 9).
territorio(japao, 1).
territorio(russia, 17).

densidade(PAIS, DENSIDADE) :- territorio(PAIS, TER), 
    populacao(PAIS, POP), DENSIDADE is POP / TER.

maior_densidade(PAIS1, PAIS2, MAIOR) :- densidade(PAIS1, DENSIDADE1), densidade(PAIS2, DENSIDADE2), DENSIDADE1 >= DENSIDADE2, MAIOR = PAIS1.
maior_densidade(PAIS1, PAIS2, MAIOR) :- densidade(PAIS1, DENSIDADE1), densidade(PAIS2, DENSIDADE2), DENSIDADE1 < DENSIDADE2, MAIOR = PAIS2.

:- initialization main.
main :-
    read(PAIS1),
    read(PAIS2),
    maior_densidade(PAIS1, PAIS2, MAIOR),
    write(MAIOR),nl,
    halt(0).





