#ifndef __HEROES_H__
#define __HEROES_H__
#include "Personajes.h"
#include "Habilidades.h"
class Heroe :public Personaje
{
public:
	int exp_actual;
	int exp_ToLVLUp;
	int exp_giveaway;
	int nivel;

	int mana;
	int mana_actual;

	int oro;
	int oro_giveaway;
	int agilidad;
	int fuerza;

	Heroe(Tipo _tipo,int _x, int _y, int _vida,int _ataque, int _defensa, int _fuerza,int _agilidad,Team _team ) :
		Personaje(_tipo,_x, _y, _vida,_ataque,_defensa,_team), fuerza(_fuerza),agilidad(_agilidad)
	{
		width = 48;
		height = 48;
		exp_actual = 0;
		nivel = 0;
		exp_ToLVLUp = 400+50*nivel;

		oro = 900;
		oro_giveaway = 200 + 10 * nivel;

		vida_actual = vida;
		ataque += fuerza * 1.2;

	


		mana = 900;
		mana_actual = mana;

		delta = agilidad;
	}
	~Heroe(){}
	virtual void dibujarBase(Graphics^g, Bitmap^img)override {
		Rectangle Origen = Rectangle(0, 0, 32, 32);
		Rectangle Destino = Rectangle(x, y, width, height);
		g->DrawImage(img, Destino, Origen, GraphicsUnit::Pixel);
	}
	void dibujarInfo(Graphics^g,Bitmap^img,Team seleccion,Cosa*area,Color c){
		int fixed_x = area->x + 15;
		int fixed_y = Team::Radiant == seleccion ? area->y + 15 : area->y + (area->height) / 2 + 15;
		Font^font = gcnew Font("Arial", 8);
		Pen^pen = gcnew Pen(Color::White);

		int vida_actualPrint = vida_actual * 211 / vida;
		int mana_actualPrint = mana_actual * 211 / mana;
		int exp_actualPrint = exp_actual * 101 / exp_ToLVLUp;

		g->DrawRectangle(pen,fixed_x-1,fixed_y-1,100,100);//marco de la imagen
		dibujarBaseEstatico(g, img, 32, 32,fixed_x,fixed_y,99,99);//g->DrawImage(img,);//la imagen

		g->DrawRectangle(pen, fixed_x + 110, fixed_y + 72 + 12, 101, 16);//marco de exp actual
		g->FillRectangle(gcnew SolidBrush(Color::Lime), fixed_x+111, fixed_y + 73 +12, exp_actualPrint, 15);
		g->DrawString(exp_actual.ToString() + "/" + exp_ToLVLUp.ToString(), font, Brushes::White, fixed_x + 5+111, fixed_y + 74 + 12);//la exp actual

		g->DrawRectangle(pen, fixed_x - 1, fixed_y + 72 + 32, 212, 16);//marco de la vida
		g->FillRectangle(gcnew SolidBrush(c), fixed_x, fixed_y +73+32, vida_actualPrint, 15);
		g->DrawString(vida_actual.ToString() + "/" + vida.ToString(), font, Brushes::White, fixed_x + 5, fixed_y + 74 + 32);//la vida

		g->DrawRectangle(pen,fixed_x-1,fixed_y+72+52,212,16);//marco del mana
		g->FillRectangle(gcnew SolidBrush(Color::MediumSlateBlue), fixed_x, fixed_y + 73 + 32+20, mana_actualPrint, 15);
		g->DrawString(mana_actual.ToString() + "/" + mana.ToString(), font, Brushes::White, fixed_x + 5, fixed_y + 74 + 32+20);//el mana

		g->DrawString("ORO: " + oro.ToString(),font,Brushes::White,fixed_x+111,fixed_y);//oro
		g->DrawString("ATQ:  " + ataque.ToString(), font, Brushes::White, fixed_x + 111, fixed_y+16);//ataque
		g->DrawString("STR:  " + fuerza.ToString(), font, Brushes::White, fixed_x + 111, fixed_y + 32);//fuerza
		g->DrawString("AGI:   " + agilidad.ToString(), font, Brushes::White, fixed_x + 111, fixed_y+48);//agilidad
		g->DrawString("LVL:   " + nivel.ToString(), font, Brushes::White, fixed_x + 111, fixed_y+64);//nivel

	//	dibujar(g, img, c);
	}

};
#endif // __HEROES_H__






