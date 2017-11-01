/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description:
*********************************************************************/

#include "RPSGame.hpp"
#include "validChar.hpp"

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <cstdlib>
using std::rand;

RPSGame::RPSGame()
{
	rounds = 0;
	hWins = 0;
	cWins = 0;
	ties = 0;
}

void RPSGame::playGame()
{
	cout << "**************************************************" << endl;
	cout << "Welcome to Rock, Paper, Scissors!" << endl;
	cout << "Would you like to set different strengths for the tools? (y - yes, n - no)" << endl;
	getline(cin, inputStr);
	ynInput = validChar(inputStr, yn, 2);
	//TODO *** THIS IS WHERE STRENGTH WILL NEED TO BE SET *** //
	cout << "**************************************************" << endl;

	// do while loop for the game to play as long as the user has not input 'e'
	do{
		rounds = rounds + 1;
		cout << "**************************************************" << endl;
		cout << "ROCK, PAPER, SCISSORS -- ROUND " << rounds << ":" << endl;
		cout << "Choose your tool (r - rock, p - paper, s - scissor, e - exit)" << endl;
		getline(cin, inputStr);
		rpseInput = validChar(inputStr, rpse, 4);
		if (rpseInput != 'e')
		{
			cout << "**************************************************" << endl;
			assignToolComp();
			cout << "   VS." << endl;
			userHistory.push_back(rpseInput); // must assign after comp AI done to avoid cheating
			assignToolUser();
			
			//TODO *** FIGHT FUNCTION WILL NEED TO GO HERE *** //

			//TODO *** DELETE UP TO "END DELETE HERE" LINE ONCE FIGHT FUNCTION IS USED *** //
			if (rpseInput == compChoice)
				{gameWinner = 't';}
			else if (rpseInput == 'r')
			{
				if(compChoice == 'p')
					{gameWinner = 'c';}
				else if(compChoice = 's')
					{gameWinner = 'h';}
			}
			else if (rpseInput == 'p')
			{
				if(compChoice == 'r')
					{gameWinner = 'h';}
				else if(compChoice = 's')
					{gameWinner = 'c';}
			}
			else if (rpseInput == 's')
			{
				if(compChoice == 'p')
					{gameWinner = 'h';}
				else if(compChoice = 'r')
					{gameWinner = 'c';}
			}
			//TODO *** END DELETE HERE *** //

			printResults();

		}

	} while(rpseInput != 'e');

	cout << "**************************************************" << endl;
	cout << "You have ended the game before round " << rounds << endl;
	cout << "FINAL GAME TOTALS:" << endl;
	cout << "Human: " << hWins << "\t Computer: " << cWins << "\t Ties: " << ties << endl;
	cout << "**************************************************" << endl;

}

void RPSGame::assignToolUser()
{
	//TODO *** WILL NEED TO ADD ASSIGNMENTS TO USER TOOLS WITHIN LOOPS *** //
	if (rpseInput == 'r')
	{
		cout << "Human: ROCK" << endl;
	}
	if (rpseInput == 'p')
	{
		cout << "Human: PAPER" << endl;
	}
	if (rpseInput == 's')
	{
		cout << "Human: SCISSORS" << endl;
	}
}

void RPSGame::assignToolComp() // making this void as the Tools are available throughout class
{

	rCount = pCount = sCount = 0;
	
	if (rounds > 3) // must have 3 saved rounds in order to have enough input
	{
		last = userHistory[rounds - 3]; // this is -3 because starts at zero & we look at 2 rounds back
		current = userHistory[rounds - 2]; // this is -2 because starts at zero & we look at prev round
		for (int i=1; i<rounds-1; i++)
		{
			if (userHistory[i] == current && userHistory[i-1] == last)
			{
				if (userHistory[i+1] == rock)
					{rCount++;}
				else if (userHistory[i+1] == paper)
					{pCount++;}
				else if (userHistory[i+1] == scissor)
					{sCount++;}
			}
		}
		
		// 7 possible outcomes below:
		if(rCount == pCount && rCount == sCount) // all equally likely
		{
			randVal = rand()%3;
			if (randVal == 0)
				{compChoice = 'r';}
			else if (randVal == 1)
				{compChoice = 'p';}
			else if (randVal == 2)
				{compChoice = 's';}
		}
		else if (rCount > pCount && rCount > sCount) // rock most likely
			{compChoice = 'p';} // choose paper to beat their rock
		else if (pCount > rCount && pCount > sCount) // paper most likely
			{compChoice = 's';} // choose scissors to beat their paper
		else if (sCount > pCount && sCount > rCount) // scissors most likely
			{compChoice = 'r';} // choose rock to beat their scissors
		else if (rCount == pCount && rCount > sCount) // rock & paper most likely
			{compChoice = 'p';} // p beats r & ties p but s loses to r & beats p
		else if (rCount == sCount && rCount > pCount) // rock & scissors most likely
			{compChoice = 'r';} // r beats s & ties r but p loses to s & beats r
		else if (sCount == pCount && sCount > rCount) // scissors & paper most likely
			{compChoice = 's';} // s beats p & ties s but r loses to p & beats s		
	}

	else // randomly select if not enough data for AI
	{
		randVal = rand()%3;
		if (randVal == 0)
			{compChoice = 'r';}
		else if (randVal == 1)
			{compChoice = 'p';}
		else if (randVal == 2)
			{compChoice = 's';}
	}
	
	//TODO *** WILL NEED TO ADD ASSIGNMENTS TO USER TOOLS WITHIN LOOPS *** //
	if (compChoice == 'r')
	{
		cout << "Computer: ROCK" << endl;
	}
	if (compChoice == 'p')
	{
		cout << "Computer: PAPER" << endl;
	}
	if (compChoice == 's')
	{
		cout << "Computer: SCISSORS" << endl;
	}
}

void RPSGame::printResults()
{
	cout << "**************************************************" << endl;
	if (gameWinner == 't')
	{
		cout << "It's a tie!" << endl;
		ties = ties + 1;
	}
	else if (gameWinner == 'h')
	{
		cout << "Human wins!" << endl;
		hWins = hWins + 1;
	}
	else if (gameWinner == 'c')
	{
		cout << "Computer wins!" << endl;
		cWins = cWins + 1;
	}
	cout << "RUNNING GAME TOTALS:" << endl;
	cout << "Human: " << hWins << "\t Computer: " << cWins << "\t Ties: " << ties << endl;
	cout << "**************************************************" << endl;
}
