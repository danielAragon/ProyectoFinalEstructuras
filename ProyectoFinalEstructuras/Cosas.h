#ifndef __COSAS_H__
#define __COSAS_H__
#include <vector>
#include <time.h>
#include <list>
using namespace std;
using namespace System;
using namespace System::Drawing;
enum Building {Ancient,Tower};
enum TypeMove {Estatico, Derecha, Izquierda, Arriba, Abajo };
enum Player {Radiant, Dire };
class Cosa
{
public:
	int x;
	int y;
	int width;
	int height;

	Cosa(int _x, int _y, int _width, int _height) :
		x(_x), y(_y), width(_width), height(_height){}
	Cosa(int _x, int _y) :
		x(_x), y(_y) {}

	~Cosa(){}
	virtual void dibujarBase(Graphics^g, Bitmap^img) {
		Rectangle Origen = Rectangle(0, 0, img->Width, img->Height);
		Rectangle Destino = Rectangle(x, y, width, height);
		g->DrawImage(img, Destino, Origen, GraphicsUnit::Pixel);
	}

	void dibujarBaseEstatico(Graphics^g, Bitmap^img,int img_width,int img_height,int fixed_x, int fixed_y,int fixed_w, int fixed_h) {
		Rectangle Origen = Rectangle(0, 0, img_width, img_height);
		Rectangle Destino = Rectangle(fixed_x, fixed_y, fixed_w,fixed_h);
		g->DrawImage(img, Destino, Origen, GraphicsUnit::Pixel);

	}
};

#endif // !__COSAS_H__
