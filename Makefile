GCCFALGS=-Wall -Werror

main: main.c
	gcc $(GCCFALGS) -o ./fft ./main.c
clean:
	rm ./main