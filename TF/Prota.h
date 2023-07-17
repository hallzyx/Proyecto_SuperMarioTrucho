#pragma once
#include"entidad.h"
class Prota : public Entidad {

private:
	bool moverDerecha;
	bool moverIzquierda;
	int vidas;
	int piso;
	int gravedad;


public:
	Prota() : Entidad() {
		vidas = 2;
		x = 100;
		//y = 190;
		y = 390;
		moverDerecha = false;
		moverIzquierda = false;
		piso = y;
		dy = 10;
		gravedad = 0;
	}

	~Prota() {

	}



	void actualizar(Graphics^ canvas) {
		direc = 1;
		animar(canvas, direc);
		salto_prron();

	}

	int getVidas() {
		return this->vidas;
	}

	void setVidas(int _vidas) {
		this->vidas = _vidas;
	}
	bool getEstaSaltando() {
		return estasaltando;
	}
	void setEstaSaltando(bool saltando) {

		estasaltando = saltando;
		gravedad = 1;
		
	}

	void salto_prron() {


		if (estasaltando == true) {

			if (y <= 280) {
				gravedad = -1;
				 
			}
			if (gravedad == -1) {
				y = y + dy;
			}
			else if (gravedad == 1) {
				y = y - dy;	
			}
			
			if (y == piso) {
				gravedad = 0;
				estasaltando = false;
			}


		}

		
	}




};