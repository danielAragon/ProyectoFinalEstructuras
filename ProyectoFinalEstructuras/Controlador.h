#ifndef __CONTROLADOR_H__
#define __CONTROLADOR_H__
#include "Heroes.h"
#include "Tienda.h"
#include "Creeps.h"
#include "Estructuras.h"

class Controlador 
{
public:
	Heroe* PJ1;
	Heroe* PJ2;

	Player seleccion;

	Cosa* map;
	Cosa*barraLateral;
	int mouse_x;
	int mouse_y;

	int spwnR_x;
	int spwnR_y;
	int spwnD_x;
	int spwnD_y;
	
	Estructura* r_Ancient;
	Estructura* d_Ancient;

	Estructura* r_Torre;
	Estructura* d_Torre;

	vector<Creep*> r_Creeps;
	vector<Creep*> d_Creeps;

	vector<Personaje*> recRadiant;
	vector<Personaje*> recDire;

	Controlador(){
		spwnR_x = 140;
		spwnR_y = 300;
		spwnD_x = 870;
		spwnD_y = 300;

		PJ1 = new Heroe(spwnR_x, spwnR_y, 1000, 1, 20, 2, 25,Radiant);		
		PJ2 = new Heroe(spwnD_x, spwnD_y,1000, 1, 20, 3, 5,Dire);

		r_Ancient = new Estructura(10, 180, 5000, 200,100, Radiant, Ancient);
		d_Ancient = new Estructura(920, 180, 5000, 200,100, Dire, Ancient);

		r_Torre = new Estructura(285, 180, 5000, 200,100,Radiant,Tower);
		d_Torre = new Estructura(725, 180, 5000, 200,100,Dire,Tower);

		map = new Cosa(0, 0, 1040, 656);
		barraLateral = new Cosa(1040, 0, 240, 656);

		srand(time(0));

		recRadiant.push_back(PJ1);
		recRadiant.push_back(r_Ancient);
		recRadiant.push_back(r_Torre);
		recDire.push_back(PJ2);
		recDire.push_back(d_Ancient);
		recDire.push_back(d_Torre);


	}
	~Controlador(){}

	void comenzar(){}
	void dibujarJuego(long n,Graphics^g, Bitmap^mapa,Bitmap^luffy,Bitmap^sanji,Bitmap^wall,Bitmap^r_creep, Bitmap^d_creep,Bitmap^torre){
		map->dibujarBase(g, mapa);
		barraLateral->dibujarBase(g, wall);
		colisionador();
		moverTodo();
		PJ1->dibujarInfo(g, luffy,Player::Radiant,barraLateral,Color::Salmon);
		PJ2->dibujarInfo(g, sanji, Player::Dire, barraLateral, Color::BlueViolet);

		r_Torre->dibujar(g, torre, Color::Gold);
		d_Torre->dibujar(g, torre, Color::Gold);
		r_Ancient->dibujar(g, torre, Color::Gold);
		d_Ancient->dibujar(g, torre, Color::Gold);

		if (n == 1000) {	
			r_Creeps.push_back(new Creep(230 + rand() % 50, 250 + rand() % 50, 100, 4, 0, Radiant, d_Ancient));
			recRadiant.push_back(r_Creeps.back());
			r_Creeps.push_back(new Creep(185 + rand() % 50, 300 + rand() % 50, 100, 4, 0, Radiant, d_Ancient));
			recRadiant.push_back(r_Creeps.back());
			r_Creeps.push_back(new Creep(230 + rand() % 50, 340 + rand() % 50, 100, 4, 0, Radiant, d_Ancient));
			recRadiant.push_back(r_Creeps.back());

			d_Creeps.push_back(new Creep(780 + rand() % 50, 250 + rand() % 50, 100, 4, 0, Dire, r_Ancient));
			recDire.push_back(d_Creeps.back());
			d_Creeps.push_back(new Creep(825 + rand() % 50, 300 + rand() % 50, 100, 4, 0, Dire, r_Ancient));
			recDire.push_back(d_Creeps.back());
			d_Creeps.push_back(new Creep(780 + rand() % 50, 340 + rand() % 50, 100, 4, 0, Dire, r_Ancient));
			recDire.push_back(d_Creeps.back());
		}
		for each (Creep* i in r_Creeps) {
			i->dibujar(g, r_creep, Color::Lime);
		}
		for each (Creep* i in d_Creeps) {
			i->dibujar(g, d_creep, Color::Lime);
		}
	}
	void moverTodo() {
		switch (seleccion)
		{
		case Player::Radiant:
			PJ1->set(mouse_x,mouse_y);
			break;
		case Player::Dire:	
			PJ2->set(mouse_x,mouse_y);
			break;		
		}
		for each (Creep* i in r_Creeps) {
			i->set(d_Ancient->x, d_Ancient->y+98);
		}
		for each (Creep* i in d_Creeps) {
			i->set(r_Ancient->x, r_Ancient->y+98);
		}
	}
	void colisionador() {
		
		Rectangle R_M = Rectangle(mouse_x - 16, mouse_y - 16, 1, 1);
		
		for each(Personaje* R in recRadiant) {
			Rectangle A = Rectangle(R->x - 16, R->y - 16, R->width, R->height);
			for each(Personaje* D in recDire) {
				Rectangle B = Rectangle(D->x - 16, D->y - 16, D->width, D->height);
				
				R->ataqueBase(A.IntersectsWith(B),D);
				D->ataqueBase(B.IntersectsWith(A),R);

				if (!R_M.IntersectsWith(Rectangle(PJ1->x,PJ1->y,PJ1->width,PJ1->height)))
					PJ1->canMove = true;
				if (!R_M.IntersectsWith(Rectangle(PJ2->x, PJ2->y, PJ2->width, PJ2->height)))
					PJ2->canMove = true;
				
			}
		}
	}
};
#endif // !__CONTROLADOR_H__
