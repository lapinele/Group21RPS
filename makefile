testFile: validInput.cpp inputTest.cpp
	g++ -std=c++0x validInput.cpp inputTest.cpp -o testFile


clean:
	rm testFile