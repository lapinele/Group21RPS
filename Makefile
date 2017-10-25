#I've added some notes using echo to the make and clean process,
#and removed compile msgs. Hopefully they are helpful - Patrick

OJBS = main.o
CC = g++ 
FLAGS = -std=c++0x -Wall

game: $(OJBS)
	@echo '[BUILDING] --- game'
	@$(CC) $(FLAGS) $(OJBS) -o game
	@echo '[DONE!] Output file: game'

main.o: main.cpp
	@echo '[BUILDING] --- main'
	@$(CC) -c $(FLAGS) main.cpp

clean:
	@echo '[CLEANING] ...'
	@rm *.o
	@echo '... [DONE!]'

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck

