#ifndef __PERSONAJES_H__
#define __PERSONAJES_H__
#include "Cosas.h"
class Personaje :public Cosa
{
public:
	Tipo tipo;
	Team team;
	int expGiveAway;
	int delta;
	int ataque;
	int defensa;	
	int vida;
	int vida_actual;
	
	int obj_x;
	int obj_y;

	bool canMove;
	bool alive;
	Personaje(Tipo _tipo,int _x, int _y, int _vida, int _ataque, int _defensa, Team _team)
		:tipo(_tipo),Cosa(_x, _y), vida(_vida), ataque(_ataque), defensa(_defensa), team(_team) {
		vida_actual = vida;
		canMove = true;
	}

	virtual void set(int _x,int _y) {
		obj_x=_x;
		obj_y=_y;
		if (canMove == true) {

			if (this->obj_y >= y) {
				this->y += delta;
			}				
			if (this->obj_y < y) {
				this->y -= delta;
			}
			if (this->obj_x >= x) {
				this->x += delta;
			}
			if (this->obj_x < x) {
				this->x -= delta;
			}
		}
	}

	virtual void ataqueBase(Personaje*enemigo) {
		obj_x = enemigo->x;
		obj_y = enemigo->y;
		if (enemigo->vida_actual - ataque <= 0)
			enemigo->vida_actual = 0;
		else
			enemigo->vida_actual -= ataque;
	}
	
	virtual void dibujar(Graphics^g, Bitmap^img,Color c)
	{
		int vida_actualPrint = vida_actual * (width-1) / vida;
		dibujarBase(g,img);
		g->DrawRectangle(gcnew Pen(Color::White), x, y - 6, width, 6);
		g->FillRectangle(gcnew SolidBrush(c), x+1, y - 5, vida_actualPrint, 5);	
	}
	~Personaje() {}
};
#endif // !__PERSONAJES_H__

