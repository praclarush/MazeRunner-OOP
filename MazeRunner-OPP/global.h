/* ---------------------------------------------------------------------------
**
** File: Engine.h
** Description:  Contains Global constants and variables
**
** Author: Nathan Bremmer
** -------------------------------------------------------------------------*/
#ifndef GLOBAL_H
#define GLOBAL_H

const int MAX_HEIGHT = 20; //Max hight of the maze
const int MAX_WIDTH = 75; //max width of the maze
const char END_OF_LINE_CHAR = '\n'; //the end of line character
const int ESC = 27; //key code for the esc key

//tracks if the enemy's have been enabled or disabled
extern bool _EnableEnemy;
#endif