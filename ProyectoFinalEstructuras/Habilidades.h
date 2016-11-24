#ifndef __HABILIDADES_H__
#define __HABILIDADES_H__
#include "Cosas.h"
enum Skill{Fire,Stun,Poison,Heal,AreaDamage,AtqUp,DltUp,DefUp};
class Habilidad
{
	int cooldown;
	Skill skill;
public:
	Habilidad(Skill _skill):skill(_skill){
		switch (skill)
		{
		case Fire:case Stun:case Poison:
			cooldown = 500;
			break;
		case Heal:
			break;
		case AreaDamage:
			break;
		case AtqUp: case DefUp:
			break;
		case DltUp:
			break;

		}
	}

};

#endif // !__HABILIDAD_H___
