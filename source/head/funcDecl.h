#pragma once

#include "flags.h"

int main(int argc, char **argv);
char* checkAspect();
void getControllerInput();
void ClearConsole();
void ScrollAway();
void ChangeState(const char *state);
int CheckForNewAction();
void HelpScreen();

//void initWiiJunk();
// void displayMenu(char* menuName[100], bool Horizontal, int optionsNum, struct MenuOptions MenuOptions);
