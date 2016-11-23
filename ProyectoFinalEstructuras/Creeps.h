#ifndef __CREEPS_H__
#define __CREEPS_H__
#include "Personajes.h"
#include "Estructuras.h"
class Creep:public Personaje
{
public:
	int base_x;
	int base_y;
	Creep( int _x, int _y, int _vida, int _ataque, int _defensa,Player _team,Estructura* _obj) :
		Personaje(_x, _y, _vida, _ataque, _defensa,_team){
		width = 32; height = 32;
		delta = 5;
		canMove = true;
		base_x = _obj->x;
		base_y = _obj->y;
	}
	virtual void dibujarBase(Graphics^g, Bitmap^img)override {
		Rectangle Origen = Rectangle(0,0, 32, 32);
		Rectangle Destino = Rectangle(x, y, width, height);
		g->DrawImage(img, Destino, Origen, GraphicsUnit::Pixel);
	}
	~Creep(){}
	virtual void ataqueBase(bool colision, Personaje*enemigo) override{
		if (enemigo->vida_actual>0)
		{
			obj_x = enemigo->x;
			obj_y = enemigo->y;
			if (colision == true) {
				if (enemigo->vida_actual - ataque <= 0)
					enemigo->vida_actual = 0;
				else
					enemigo->vida_actual -= ataque;
				canMove = false;
			}
		}
		else
		{
			canMove = true;
			obj_x = base_x;
			obj_y = base_y;
		}


	}


};

#endif // !__CREEPS_H__
