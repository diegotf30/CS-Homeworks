IN 20; Leer y
LDA 20; AC <- y
BRAZ 12; Ciclo while; if y==0, salta al final del ciclo
IN 21; Leer z
SUB 21; AC <- AC – z
BRAN 08; Si y<z, entonces PC<-8
OUT 20; y es mayor, entonces output y
JUMP 09; PC<-9
OUT 21; Z es mayor, entonces output z
IN 20; Leer y de nuevo
LDA 20; AC<- y
JUMP 02; Ir al inicio del while
HALT; Fin