#ifndef __Creature__
#define __Creature__

#include <string>
#include "entity.h"

class Room;

using namespace std;

class Creature : public Entity
{
public:
	Creature(const char* name, const char* description, Room* room);
	~Creature();

	virtual bool Go(const string& direction);
	virtual void Look(const string& arguments) const;

	Room* GetRoom() const
	{
		return (Room*) parent;
	}

public :

};

#endif //__Creature__