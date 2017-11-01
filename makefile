testFile: validChar.cpp main.cpp RPSGame.cpp
	g++ -std=c++0x validChar.cpp main.cpp RPSGame.cpp -o testFile


clean:
	rm testFile