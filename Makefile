OJBS = main.o RPSGame.o tool.o rock.o paper.o scissors.o
CC = g++
FLAGS = -std=c++0x -Wall

game: $(OJBS)
	@echo '[BUILDING] game...
	$(CC) $(FLAGS) $(OJBS) -o game
	@echo '[DONE] - Project output has file name: game'

main.o: main.cpp
	$(CC) $(FLAGS) main.cpp

RPSGame.o: RPSGame.cpp
	$(CC) $(FLAGS) RPSGame.cpp

tool.o: tool.cpp
	$(CC) $(FLAGS) tool.cpp

rock.o: rock.cpp
	$(CC) $(FLAGS) rock.cpp

paper.o: paper.cpp
	$(CC) $(FLAGS) paper.cpp

scissors.o: scissors.cpp
	$(CC) $(FLAGS) scissors.cpp

clean:
	rm *.o

.PHONY: valgrind

valgrind:
	valgrind --tool=memcheck ant

