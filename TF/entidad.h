#pragma once

#include<string>


using namespace System::Drawing;
using System::Drawing::Color;
using System::Drawing::Pen;



class Entidad {
protected:
	int x, y;
	int dx, dy;
	int w, h;
	char* imagen;
	int i_w;
	int i_h;
	int vel;
	int direc;
	bool estasaltando;
	int piso;
	int div_X;
	int div_Y;


public:
	Entidad() {
		x = y = 0;
		imagen = new char[40];
		i_w = i_h = 0;
		dx = 0;
		dy = 0;
		estasaltando = false;
		piso = y;
		direc = 1;
		vel = 0;
		div_X = 0;
		div_Y = 0;
	}
	~Entidad() {

	}
	void cambiarImagen(char* nombreArchivo, int fotogramas) {
		strcpy(imagen, nombreArchivo);
		this->div_X = fotogramas;

		Bitmap^ sprite = gcnew Bitmap(gcnew System::String(imagen));
		w = sprite->Width / fotogramas;
		h = sprite->Height / 1;
		delete sprite;
	}





	void mostrar(Graphics^ canvas, int direc) {
		Bitmap^ sprite = gcnew Bitmap(gcnew System::String(imagen));
		Rectangle Corte = Rectangle(i_w * w, i_h * h, w, h);
		Rectangle Zoom = Rectangle(x, y, w, h);
		if (direc == -1) {
			sprite->RotateFlip(RotateFlipType::RotateNoneFlipX);
		}
		canvas->DrawImage(sprite, Zoom, Corte, GraphicsUnit::Pixel);



	}

	void animar(Graphics^ canvas, int direccion) {

		i_w++;
		if (i_w > div_X - 1) {
			i_w = 0;
		}
		mostrar(canvas, direccion);
	}


	virtual void actualizar(Graphics^ canvas) {

	}


	int getX() {
		return x;
	}
	int getY() {
		return y;
	}
	int getAncho() {
		return w;
	}
	int getLargo() {
		return h;
	}
	void setDx(int dx) {
		this->dx = dx;
	}
	void setDy(int dy) {
		this->dy = dy;
	}
	void setX(int x) {
		this->x = x;
	}
	void setY(int y) {
		this->y = y;
	}

	Rectangle getRectangle() {
		return Rectangle(x, y, w, h);
	}


};