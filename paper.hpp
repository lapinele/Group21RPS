/*********************************************************************
 * Author: Noah Buchen, Alexandra Henley, Elliott Lapinel, Patrick
 * Rice, and Samantha Tone
 * Date: 10/25/2017
 * Description: This is the implemenation file for the Paper class
*********************************************************************/

#ifndef PAPER_HPP
#define PAPER_HPP

class Paper{

protected:

	int strength;
	char type;

public:
	Paper();
	Paper(int);
	void setStrength(int);
	//virtual as it will be overriden by each different type
	virtual char fight(char type);// will return fight results


};
#endif