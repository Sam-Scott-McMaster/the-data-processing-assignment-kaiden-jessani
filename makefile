cleantest: clean.c functions.c functions.h
	gcc -o cleantest --coverage clean.c functions.c
clean: clean.c functions.c functions.h
	gcc -o clean clean.c functions.c