#pragma once

class Fondo : public Entidad {

public:
	Fondo() : Entidad() {
		direc = 1;
	}
	
	~Fondo() {

	}
	
	void actualizar(Graphics^ canvas) {
		animar(canvas, direc);
	}

	 


};