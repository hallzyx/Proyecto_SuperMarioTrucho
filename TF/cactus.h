#pragma once
#include"entidad.h"

class Cactus :public Entidad {
public:
	Cactus(char* archivo, int direccion):Entidad() {
		
		dx = 10;
		this->direc = direccion;
		cambiarImagen(archivo,1);
	}
	~Cactus() {

	}
	void actualizar(Graphics^ canvas) {
		this->x = x - dx;
		animar(canvas, direc);
	}


};