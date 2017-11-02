
/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: This is the implemenation file for the Scissors class
*********************************************************************/

#ifndef SCISSORS_HPP
#define SCISSORS_HPP
#include "tool.hpp"

class Scissors: public Tool{

protected:

	int strength;
	char type;

public:
	Scissors();
	Scissors(int);
	virtual void setStrength(int);
	virtual int getStrength();
	//virtual as it will be overriden by each different type
	virtual char fight(char type);// will return fight results


};
#endif
