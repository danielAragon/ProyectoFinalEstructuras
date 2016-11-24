#ifndef __CONTROLADOR_H__
#define __CONTROLADOR_H__
#include "Heroes.h"
#include "Tienda.h"
#include "Creeps.h"
#include "Estructuras.h"

class Controlador 
{
public:
	long n;
	int creepsSpawntime;
	Team seleccion;

	Heroe* PJ1;
	Heroe* PJ2;
	Estructura* R_Ancestro;
	Estructura* D_Ancestro;

	Cosa* map;
	Cosa*barraLateral;

	int mouse_x;
	int mouse_y;
	int spwnR_x;
	int spwnR_y;
	int spwnD_x;
	int spwnD_y;

	vector<Personaje*> recRadiant;
	vector<Personaje*> recDire;

	Controlador(){
		n = 99;
		creepsSpawntime=200;
		spwnR_x = 140;
		spwnR_y = 300;
		spwnD_x = 870;
		spwnD_y = 300;

		PJ1 = new Heroe(R_Player,spwnR_x, spwnR_y, 1000, 1, 20, 2, 25,Radiant);		
		PJ2 = new Heroe(D_Player,spwnD_x, spwnD_y,1000, 1, 20, 3, 5,Dire);

		R_Ancestro = new Estructura(Ancient, 10, 180, 5000, 200, 100, Radiant);
		D_Ancestro = new Estructura(Ancient, 920, 180, 5000, 200, 100, Dire);

		recRadiant.push_back(PJ1);
		recRadiant.push_back(R_Ancestro);
		recRadiant.push_back(new Estructura(Tower,285, 180, 5000, 200, 100, Radiant));

		recDire.push_back(PJ2);
		recDire.push_back(D_Ancestro);
		recDire.push_back(new Estructura(Tower,725, 180, 5000, 200, 100, Dire));

		map = new Cosa(0, 0, 1040, 656);
		barraLateral = new Cosa(1040, 0, 240, 656);

		srand(time(0));
	}
	///---
	void comenzar(){}
	///---
	void dibujarJuego(Graphics^g, Bitmap^mapa,Bitmap^luffy,Bitmap^sanji,Bitmap^wall,Bitmap^r_creep, Bitmap^d_creep,Bitmap^torre){
		map->dibujarBase(g, mapa);
		barraLateral->dibujarBase(g, wall);

		colisionador(g);
		moverTodo();

		PJ1->dibujarInfo(g, luffy,Team::Radiant,barraLateral,Color::Salmon);
		PJ2->dibujarInfo(g, sanji, Team::Dire, barraLateral, Color::BlueViolet);

		for each(Personaje* p in recRadiant)
		{	
			switch (p->tipo)
			{
			case Ancient:case Tower:
				p->dibujar(g, torre, Color::Gold);
				break;
			case R_Creep:
				p->dibujar(g, r_creep, Color::Lime);
				break;		
			case R_Player:
				p->dibujar(g, luffy, Color::Salmon);
				break;		
			default:
				break;
			}
		}
		for each (Personaje* p in recDire)
		{
			switch (p->tipo)
			{
			case Ancient:case Tower:
				p->dibujar(g, torre, Color::Gold);
				break;		
			case D_Creep:
				p->dibujar(g, d_creep, Color::Lime);
				break;		
			case D_Player:
				p->dibujar(g, sanji, Color::BlueViolet);
				break;
			default:
				break;
			}
		}
		if (n == creepsSpawntime) {			
			for (int i = 0; i < 3; i++)
			{
				recRadiant.push_back(new Creep(R_Creep,230 + rand() % 100, 250 + rand() % 100, 400, 15, 7, Radiant));
				recDire.push_back(new Creep(D_Creep,780 + rand() %100, 340 + rand() % 100, 400, 15, 7, Dire));
			}
			creepsSpawntime+=200;
		}
	}
	///---
	vector<Personaje*>::iterator Eliminar(vector<Personaje*> &vec) {
		for (vector<Personaje*>::iterator it = vec.begin(); it != vec.end(); ++it) {
			if ((*it)->vida_actual == 0)
				return it;
		}
		return vec.end();
	}
	///---
	void moverTodo() {
		switch (seleccion)
		{
		case Team::Radiant:
			PJ1->set(mouse_x,mouse_y);
			break;
		case Team::Dire:	
			PJ2->set(mouse_x,mouse_y);
			break;		
		}
		for each(Personaje* p in recRadiant) {
			if (p->tipo == R_Creep)
			p->set(p->obj_x, p->obj_y);
		}
		for each(Personaje* p in recDire) {
			if (p->tipo == D_Creep)
			p->set(p->obj_x, p->obj_y);
		}
	}
	///---
	void colisionador(Graphics^g) {

		Rectangle M = Rectangle(mouse_x - 16, mouse_y - 16, 1, 1);
		g->DrawRectangle(gcnew Pen(Color::White, 1), M);

		for each(Personaje* R in recRadiant) {
			Rectangle A = Rectangle(R->x, R->y , R->width, R->height);
			g->DrawRectangle(gcnew Pen(Color::White,1),A);
			for each(Personaje* D in recDire) {
				Rectangle B = Rectangle(D->x , D->y , D->width, D->height);
				g->DrawRectangle(gcnew Pen(Color::White, 1), B);
				if (A.IntersectsWith(B)&&B.IntersectsWith(A)) {
					if (R->tipo == R_Creep) {
						R->canMove = false;
						R->obj_x = D->x;
						R->obj_y = D->y + D->height/2;
					}
					if (D->tipo == D_Creep) {
						D->canMove = false;
						D->obj_x = R->x;
						D->obj_y = R->y + R->height / 2;
					}
					R->ataqueBase(D);
					D->ataqueBase(R);
				}
				else
				{
					if (R->tipo == R_Creep) {
						R->canMove = true;
					}
					if (D->tipo == D_Creep) {
						D->canMove = true;
					}
				}				
			}
		}
		vector<Personaje*>::iterator R = Eliminar(recRadiant);

		if (R != recRadiant.end() && (*R)->vida_actual == 0) {
			if ((*R)->tipo == R_Player)
			{
				Heroe* aux = new Heroe(R_Player, spwnR_x, spwnR_y, 1000, 1, 20, 2, 25, Radiant);
				recRadiant.push_back(aux);
				PJ1 = aux;
			}
			recRadiant.erase(R);
		
		}
		vector<Personaje*>::iterator D = Eliminar(recDire);
		if (D != recDire.end() && (*D)->vida_actual == 0) {
			recDire.erase(D);
		}
	}
};
#endif // !__CONTROLADOR_H__
