#ifndef VCS_CPP
#define VCS_CPP
#include "VCS.h"

//base constructor, init
VCS::VCS(string filename)
{
	curr_size=0;
}

//destructor
VCS::~VCS()
{

}


//time to commit
void VCS::commit(string msg)
{
	
}

//print status of every version
void VCS::status()
{

}

//goes one step back
string VCS::undo()
{
	
}

//one step ahead
string VCS::redo()
{
	
}

//goes t_stamp step back or ahead
string VCS::revert(int t_stamp)
{
	
}

#endif