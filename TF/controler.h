#pragma once
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <iostream>

#include"entidad.h"
#include"Prota.h"
#include"cactus.h"
#include"fondo.h"

using namespace std;

class Controler {
private:
	Fondo* background;
	Prota* red;
	vector<char*> cactus_img;
	vector<Cactus*> cactus;


public:
	Controler() {

		background = new Fondo();
		background->cambiarImagen("img/fondo.jpg", 1);
		
		red = new Prota();
		red->cambiarImagen("img/rojo.png", 4);
		red->setDx(10);
		cactus_img.push_back("img/tuboS.png");
		cactus_img.push_back("img/tuboM.png");
		cactus_img.push_back("img/tuboL.png");
		cactus_img.push_back("img/tuboXL.png");
	}

	~Controler() {

	}


	void mostrar(Graphics^ canvas) {
	
		background->actualizar(canvas);
		red->actualizar(canvas);



		for (size_t i = 0; i < cactus.size(); i++){
			cactus[i]->actualizar(canvas);
			if (cactus[i]->getRectangle().IntersectsWith(red->getRectangle())) {
				delete cactus[i];
				cactus[i] = cactus.back();
				cactus.pop_back();
				red->setVidas(red->getVidas() - 1);
			}
		}



	}
	

	void AddCactus() {
		srand(time(NULL));
		int max = cactus_img.size() - 1;
		int min = 0;
		int index = rand() % (max - min + 1) + min;
		
		Cactus* nuevo_cactus = new Cactus(cactus_img[index],1);
		if (index == 0) {
			nuevo_cactus->setX(500);
			nuevo_cactus->setY(410);
		}
		else if (index == 1) {
			nuevo_cactus->setX(500);
			nuevo_cactus->setY(395);
		}

		else if (index == 2) {
			nuevo_cactus->setX(500);
			nuevo_cactus->setY(380);
		}
		else if (index == 3) {
			nuevo_cactus->setX(500);
			nuevo_cactus->setY(371);
		}

		
		cactus.push_back(nuevo_cactus);

	}	

	Prota* getprota() {
		return this->red;
	}

	bool getEstaSaltando() {
		return red->getEstaSaltando();
	}

	void setSaltarProta(bool saltando) {
		red->setEstaSaltando(saltando);
	}

};