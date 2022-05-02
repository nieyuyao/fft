GCCFALGS=-Wall -Werror

main: main.c
	gcc $(GCCFALGS) -o ./main ./main.c
clean:
	rm ./main