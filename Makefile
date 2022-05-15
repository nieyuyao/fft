GCCFALGS=-Wall -Werror

main: main.c fft.c
	gcc $(GCCFALGS) -o main ./main.c ./fft.c
clean:
	rm ./fft ./main