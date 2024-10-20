build:
	gcc -Wall -Werror -O0 code/*.c -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2 -o sort
run:
	./sort
clean:
	rm sort
