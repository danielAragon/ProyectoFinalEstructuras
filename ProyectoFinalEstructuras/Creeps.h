#ifndef __CREEPS_H__
#define __CREEPS_H__
#include "Personajes.h"
#include "Estructuras.h"
class Creep:public Personaje
{
public:

	Creep(Tipo _tipo, int _x, int _y, int _vida, int _ataque, int _defensa,Team _team) :
		Personaje(_tipo,_x, _y, _vida, _ataque, _defensa,_team){
		width = 32; height = 32;
		delta = 5;
		canMove = true;
		set(_team == Radiant ? 950 : 50, 324);
	}
	~Creep() {}

	virtual void dibujarBase(Graphics^g, Bitmap^img)override {
		Rectangle Origen = Rectangle(0,0, 32, 32);
		Rectangle Destino = Rectangle(x, y, width, height);
		g->DrawImage(img, Destino, Origen, GraphicsUnit::Pixel);
	}
	virtual void ataqueBase(Personaje*enemigo) override{
		if (enemigo->vida_actual>0)
		{
			obj_x = enemigo->x;
			obj_y = enemigo->y;
			if (enemigo->vida_actual - ataque <= 0){
				canMove = true;
				set(team == Radiant ? 950 : 50, 324);
				enemigo->vida_actual = 0;
			}
			else
				enemigo->vida_actual -= ataque;
		}
	}


};

#endif // !__CREEPS_H__
