
all:

	gcc calculation.c calculation.h parser.c parser.h stack.c stack.h -lm
	./a.out

clean:
	rm *.out
	rm *.gc


style:
	clang-format -i --style=google *.c *.h