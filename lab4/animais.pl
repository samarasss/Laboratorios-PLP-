gato(kawai).
pessoa(alma).
passaro(joao).
peixe(pedro).
minhoca(maria).
     
gosta_comer(X,Y) :- passaro(X),
minhoca(Y).
gosta_comer(X,Y) :- gato(X),
peixe(Y).
gosta_comer(X,Y) :- gato(X),
passaro(Y).
gosta_amizade(X,Y) :- gato(X),
pessoa(Y).
amigo(X,Y) :- gato(X),
pessoa(Y).
come(X,Y) :- gosta_comer(X,Y).

