#ifndef __ESTRUCTURAS_H__
#define __ESTRUCTURAS_H__
#include "Personajes.h"
class Estructura :public Personaje
{
	Tipo tipo;
public:
	Estructura(Tipo _tipo, int _x, int _y, int _vida, int _ataque, int _defensa,Team _team)  :
		Personaje(_tipo,_x, _y, _vida, _ataque, _defensa,_team),tipo(_tipo){
		width = 96; height = 192;
		canMove = true;
	}
	virtual void dibujarBase(Graphics^g, Bitmap^img)override {
		Rectangle Origen = Rectangle(4+(tipo == Tower ? 260 : (vida_actual < 200 ? 130 : 0)) , 0, 124, 289);
		Rectangle Destino = Rectangle(x, y, width, height);
		g->DrawImage(img, Destino, Origen, GraphicsUnit::Pixel);
	}


	~Estructura() {}
};
#endif // __ESTRUCTURAS_H__