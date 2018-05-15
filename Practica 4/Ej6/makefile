crucigrama: crucigrama.o main.o ficheros.o libMemoria.a
	gcc -o crucigrama crucigrama.o main.o ficheros.o libMemoria.a

libMemoria.a: reservaMemoria.o liberaMemoria.o
	ar -rsv libMemoria.a reservaMemoria.o liberaMemoria.o

reservaMemoria.o: reservaMemoria.c
	gcc -c reservaMemoria.c

liberaMemoria.o: liberaMemoria.c
	gcc -c liberaMemoria.c

main.o: main.c
	gcc -c main.c

ficheros.o: ficheros.c
	gcc -c ficheros.c

crucigrama.o: crucigrama.c
	gcc -c crucigrama.c

clean:
	@echo Borrando ficheros objeto...
	rm *.o
