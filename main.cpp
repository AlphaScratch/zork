#include <iostream>
#include <string>
#include <conio.h>
#include "globals.h"
#include "world.h"

using namespace std;

// -------------------------------------------------
bool Same(const string& a, const string& b)
{
	return _stricmp(a.c_str(), b.c_str()) == 0;
}

bool Same(const char* a, const string& b)
{
	return _stricmp(a, b.c_str()) == 0;
}

bool Same(const string& a, const char* b)
{
	return _stricmp(a.c_str(), b) == 0;
}
// -------------------------------------------------

int main()
{
	cout << "Welcome to Zork!\n";
	cout << "----------------\n\n";
	string player_input;

	World my_world;
	my_world.Tick("look", "");

	string command;
	string arguments;

	while(1)
	{
		char key;


		if(_kbhit() != 0)
		{
			key = _getch();
			if(key != '\r')
			{
				player_input += key;
				cout << key;
			}
			else
			{	
				//getline(cin, player_input);
				size_t pos = player_input.find(' ');

				command = player_input;

				if(pos != string::npos)
				{
					command = player_input.substr(0, pos);
					arguments = player_input.substr(pos + 1);
				}

				player_input = "";
				cout << "\n> ";
			}
		}

		if(Same(command, "quit"))
			break;

		if(my_world.Tick(command, arguments) == false)
			cout << "Sorry, I do not understand your command.";

		command = "";
		arguments = "";
	}

	cout << "\nThanks for playing, Bye!\n";
	return 0;
}