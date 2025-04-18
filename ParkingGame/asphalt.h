#pragma once  
#include "actor.h"  
#ifndef ASPHALT_H  
#define ASPHALT_H  

class Asphalt : public Actor {  
private:  
	std::vector<Actor>m_tiles;
};  

#endif // ASPHALT_H