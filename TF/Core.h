#pragma once
#include"entidad.h"
#include"controler.h"
#include"Prota.h"
#include"cactus.h"

#include"Lose.h"

namespace TF {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Core
	/// </summary>
	public ref class Core : public System::Windows::Forms::Form
	{
	public:
		Core(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			this->ControlBox = false;

			canvas = this->CreateGraphics();
			espacioBuffer = BufferedGraphicsManager::Current;
			buffer = espacioBuffer->Allocate(canvas, this->ClientRectangle);

			match = new Controler();

			Perdiste = gcnew Lose();

			
			

		}

		void encenderTimer() {
			timer1->Enabled = true;
		}

		void ReiniciarVida(int _index) {
			match->getprota()->setVidas(_index);
		}

		void PintarOFF() {
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Core()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		///


		Controler* match;
		Graphics^ canvas;
		BufferedGraphicsContext^ espacioBuffer;
		BufferedGraphics^ buffer;

		int tiempoActual=0;
		int tiempoTotal=3000;

		int seg=0;
		int min=0;

		int tictac=0;

		int high_seg = 0;
		int high_min = 0;


		Lose^ Perdiste;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label_min;
	private: System::Windows::Forms::Label^ label_seg;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label_hMin;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label_hSeg;
	public: System::Windows::Forms::Timer^ timer1;
	private:




		  




#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Core::typeid));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label_min = (gcnew System::Windows::Forms::Label());
			this->label_seg = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label_hMin = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label_hSeg = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Core::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label1->Location = System::Drawing::Point(504, 22);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Vidas: [ - ]";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label2->Location = System::Drawing::Point(637, 22);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 25);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Tiempo:";
			// 
			// label_min
			// 
			this->label_min->AutoSize = true;
			this->label_min->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label_min->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label_min->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label_min->Location = System::Drawing::Point(754, 22);
			this->label_min->Name = L"label_min";
			this->label_min->Size = System::Drawing::Size(19, 25);
			this->label_min->TabIndex = 0;
			this->label_min->Text = L"-";
			// 
			// label_seg
			// 
			this->label_seg->AutoSize = true;
			this->label_seg->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label_seg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label_seg->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label_seg->Location = System::Drawing::Point(823, 22);
			this->label_seg->Name = L"label_seg";
			this->label_seg->Size = System::Drawing::Size(19, 25);
			this->label_seg->TabIndex = 0;
			this->label_seg->Text = L"-";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label5->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label5->Location = System::Drawing::Point(796, 22);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(18, 25);
			this->label5->TabIndex = 0;
			this->label5->Text = L":";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label3->Location = System::Drawing::Point(637, 60);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(100, 25);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Highscore";
			// 
			// label_hMin
			// 
			this->label_hMin->AutoSize = true;
			this->label_hMin->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label_hMin->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label_hMin->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label_hMin->Location = System::Drawing::Point(754, 60);
			this->label_hMin->Name = L"label_hMin";
			this->label_hMin->Size = System::Drawing::Size(19, 25);
			this->label_hMin->TabIndex = 0;
			this->label_hMin->Text = L"-";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label6->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label6->Location = System::Drawing::Point(797, 60);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(18, 25);
			this->label6->TabIndex = 0;
			this->label6->Text = L":";
			// 
			// label_hSeg
			// 
			this->label_hSeg->AutoSize = true;
			this->label_hSeg->BackColor = System::Drawing::Color::PaleTurquoise;
			this->label_hSeg->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label_hSeg->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label_hSeg->Location = System::Drawing::Point(823, 60);
			this->label_hSeg->Name = L"label_hSeg";
			this->label_hSeg->Size = System::Drawing::Size(19, 25);
			this->label_hSeg->TabIndex = 0;
			this->label_hSeg->Text = L"-";
			// 
			// Core
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(882, 653);
			this->Controls->Add(this->label_hSeg);
			this->Controls->Add(this->label_seg);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label_hMin);
			this->Controls->Add(this->label_min);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Core";
			this->Text = L"¡A correr!";
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Core::Core_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Core::Core_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &Core::Core_KeyUp);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		


#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		label1->Text = "Vidas: " + match->getprota()->getVidas().ToString();
		

		if (seg < 10) {
			label_seg->Text = "0" + seg.ToString();
		}
		else if (seg >= 10) {
			label_seg->Text = seg.ToString();
		}
		if (min < 10) {
			label_min->Text = "0" + min.ToString();
		}
		else if (min >= 10) {
			label_min->Text = min.ToString();
		}
		

		if (high_seg < 10) {
			label_hSeg->Text = "0" + high_seg.ToString();
		}
		else if (high_seg >= 10) {
			label_hSeg->Text = high_seg.ToString();
		}
		if (high_min < 10) {
			label_hMin->Text = "0" + high_min.ToString();
		}
		else if (high_min >= 10) {
			label_hMin->Text = high_min.ToString();
		}






		

		tiempoActual += 100;
		if (tiempoActual >= tiempoTotal) {
			tiempoActual = 0;
			match->AddCactus();
		}

		if (seg >= 59) {
			seg = 0;
			min++;
		}


		if (match->getprota()->getVidas() == 2) {
			timer1->Interval = 100;

			tictac += 100;
			if (tictac >= 1000) {
				seg++;
				tictac = 0;
			}
		}




		if (match->getprota()->getVidas() == 1) {

			timer1->Interval = 50;

			tictac += 50;
			if (tictac >= 1000) {
				seg++;
				tictac = 0;
			}




		}
	
		if (match->getprota()->getVidas() == 0) {
			label1->Text = "Vidas: 0";

			if (min > high_min) {
				high_min = min;
			}
			if (seg > high_seg) {
				high_seg = seg;
			}

			seg = 0;
			min = 0;
			timer1->Enabled = false;
			Perdiste->ControlBox = false;
			Perdiste->ShowDialog();


		}


		


		if (Perdiste->getSwitcher() == true) {

			timer1->Enabled = true;
			this->ReiniciarVida(2);
			Perdiste->setSwitcher(false);
		}
		if (Perdiste->getCloseAll() == true) {
			timer1->Enabled = false;

			this->ReiniciarVida(2);
			Perdiste->setCloseAll(false);

			this->Close();
			
		}


		//if (timer1->Enabled == true) {
			buffer->Graphics->Clear(Color::White);
			match->mostrar(buffer->Graphics);
			buffer->Render();
		//}
		

		



	}
	private: System::Void Core_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		
		


	}








	private: System::Void Core_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
		if (e->KeyCode == Keys::Space && match->getEstaSaltando()==false) {
			match->setSaltarProta(true);
		}
	}


	private: System::Void Core_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		if (e->KeyCode == Keys::Space && match->getEstaSaltando() == false) {
			match->setSaltarProta(true);
		}

	}
};
}
