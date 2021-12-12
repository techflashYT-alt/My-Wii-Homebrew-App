#pragma once

#include "flags.h"

int main(int argc, char **argv);
void StartClose();
char* checkAspect();
void getControllerInput();
void ClearConsole();
void ScrollAway();
void ChangeState(char state[25]);

//void initWiiJunk();
// void displayMenu(char* menuName[100], bool Horizontal, int optionsNum, struct MenuOptions MenuOptions);
