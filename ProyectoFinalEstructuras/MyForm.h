#pragma once
#include "Controlador.h"
namespace ProyectoFinalEstructuras {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		long n;
		Controlador* juego;
		Bitmap^ mapa;
		Bitmap^ luffy;
		Bitmap^ sanji;
		Bitmap^ hitler;
		Bitmap^ superman;
		Bitmap^ rider;
		Bitmap^ batman;
		Bitmap^ juggernaut;
		Bitmap^ wall;
		Bitmap^ creep;
		Bitmap^ torre;
	private: System::Windows::Forms::PictureBox^  mapaIMG;
	private: System::Windows::Forms::PictureBox^  riderIMG;
	private: System::Windows::Forms::PictureBox^  batmanIMG;
	private: System::Windows::Forms::PictureBox^  sanjiIMG;
	private: System::Windows::Forms::PictureBox^  supermanIMG;
	private: System::Windows::Forms::PictureBox^  hitlerIMG;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  wallIMG;
	private: System::Windows::Forms::PictureBox^  creepIMG;
	private: System::Windows::Forms::PictureBox^  juggernautIMG;
	private: System::Windows::Forms::PictureBox^  torreIMG;


	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			//hero = new Heroe(0, 0, luffy->Width, luffy->Height);
			luffy = gcnew Bitmap(luffyIMG->Image);
			luffy->MakeTransparent(luffy->GetPixel(0, 0));

			sanji = gcnew Bitmap(sanjiIMG->Image);
			sanji->MakeTransparent(sanji->GetPixel(0, 0));

			hitler = gcnew Bitmap(hitlerIMG->Image);
			hitler->MakeTransparent(hitler->GetPixel(0, 0));

			superman = gcnew Bitmap(supermanIMG->Image);
			superman->MakeTransparent(superman->GetPixel(0, 0));

			rider = gcnew Bitmap(riderIMG->Image);
			rider->MakeTransparent(rider->GetPixel(0, 0));

			batman = gcnew Bitmap(batmanIMG->Image);
			batman->MakeTransparent(batman->GetPixel(0, 0));

			juggernaut = gcnew Bitmap(juggernautIMG->Image);
			juggernaut->MakeTransparent(juggernaut->GetPixel(0, 0));

			wall = gcnew Bitmap(wallIMG->Image);
			wall->MakeTransparent(wall->GetPixel(0, 0));

			creep = gcnew Bitmap(creepIMG->Image);
			creep->MakeTransparent(creep->GetPixel(0, 0));

			torre = gcnew Bitmap(torreIMG->Image);
			torre->MakeTransparent(torre->GetPixel(0, 0));		

			mapa = gcnew Bitmap(mapaIMG->Image);

			juego = new Controlador();

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  luffyIMG;
	protected:

	private: System::Windows::Forms::Timer^  timer1;
	private: System::ComponentModel::IContainer^  components;
	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->luffyIMG = (gcnew System::Windows::Forms::PictureBox());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->mapaIMG = (gcnew System::Windows::Forms::PictureBox());
			this->riderIMG = (gcnew System::Windows::Forms::PictureBox());
			this->batmanIMG = (gcnew System::Windows::Forms::PictureBox());
			this->sanjiIMG = (gcnew System::Windows::Forms::PictureBox());
			this->supermanIMG = (gcnew System::Windows::Forms::PictureBox());
			this->hitlerIMG = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->wallIMG = (gcnew System::Windows::Forms::PictureBox());
			this->creepIMG = (gcnew System::Windows::Forms::PictureBox());
			this->juggernautIMG = (gcnew System::Windows::Forms::PictureBox());
			this->torreIMG = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->luffyIMG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mapaIMG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->riderIMG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->batmanIMG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sanjiIMG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->supermanIMG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hitlerIMG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wallIMG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->creepIMG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->juggernautIMG))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->torreIMG))->BeginInit();
			this->SuspendLayout();
			// 
			// luffyIMG
			// 
			this->luffyIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"luffyIMG.Image")));
			this->luffyIMG->Location = System::Drawing::Point(12, 12);
			this->luffyIMG->Name = L"luffyIMG";
			this->luffyIMG->Size = System::Drawing::Size(97, 134);
			this->luffyIMG->TabIndex = 0;
			this->luffyIMG->TabStop = false;
			this->luffyIMG->Visible = false;
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// mapaIMG
			// 
			this->mapaIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"mapaIMG.Image")));
			this->mapaIMG->Location = System::Drawing::Point(272, 152);
			this->mapaIMG->Name = L"mapaIMG";
			this->mapaIMG->Size = System::Drawing::Size(443, 289);
			this->mapaIMG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->mapaIMG->TabIndex = 1;
			this->mapaIMG->TabStop = false;
			this->mapaIMG->Visible = false;
			// 
			// riderIMG
			// 
			this->riderIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"riderIMG.Image")));
			this->riderIMG->Location = System::Drawing::Point(115, 12);
			this->riderIMG->Name = L"riderIMG";
			this->riderIMG->Size = System::Drawing::Size(95, 134);
			this->riderIMG->TabIndex = 2;
			this->riderIMG->TabStop = false;
			this->riderIMG->Visible = false;
			// 
			// batmanIMG
			// 
			this->batmanIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"batmanIMG.Image")));
			this->batmanIMG->Location = System::Drawing::Point(216, 12);
			this->batmanIMG->Name = L"batmanIMG";
			this->batmanIMG->Size = System::Drawing::Size(95, 134);
			this->batmanIMG->TabIndex = 3;
			this->batmanIMG->TabStop = false;
			this->batmanIMG->Visible = false;
			// 
			// sanjiIMG
			// 
			this->sanjiIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"sanjiIMG.Image")));
			this->sanjiIMG->Location = System::Drawing::Point(317, 12);
			this->sanjiIMG->Name = L"sanjiIMG";
			this->sanjiIMG->Size = System::Drawing::Size(95, 134);
			this->sanjiIMG->TabIndex = 4;
			this->sanjiIMG->TabStop = false;
			this->sanjiIMG->Visible = false;
			// 
			// supermanIMG
			// 
			this->supermanIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"supermanIMG.Image")));
			this->supermanIMG->Location = System::Drawing::Point(418, 12);
			this->supermanIMG->Name = L"supermanIMG";
			this->supermanIMG->Size = System::Drawing::Size(95, 134);
			this->supermanIMG->TabIndex = 5;
			this->supermanIMG->TabStop = false;
			this->supermanIMG->Visible = false;
			// 
			// hitlerIMG
			// 
			this->hitlerIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"hitlerIMG.Image")));
			this->hitlerIMG->Location = System::Drawing::Point(519, 12);
			this->hitlerIMG->Name = L"hitlerIMG";
			this->hitlerIMG->Size = System::Drawing::Size(95, 134);
			this->hitlerIMG->TabIndex = 6;
			this->hitlerIMG->TabStop = false;
			this->hitlerIMG->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(721, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(974, 348);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Visible = false;
			// 
			// wallIMG
			// 
			this->wallIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"wallIMG.Image")));
			this->wallIMG->Location = System::Drawing::Point(12, 152);
			this->wallIMG->Name = L"wallIMG";
			this->wallIMG->Size = System::Drawing::Size(115, 289);
			this->wallIMG->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->wallIMG->TabIndex = 8;
			this->wallIMG->TabStop = false;
			this->wallIMG->Visible = false;
			// 
			// creepIMG
			// 
			this->creepIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"creepIMG.Image")));
			this->creepIMG->Location = System::Drawing::Point(620, 12);
			this->creepIMG->Name = L"creepIMG";
			this->creepIMG->Size = System::Drawing::Size(95, 134);
			this->creepIMG->TabIndex = 9;
			this->creepIMG->TabStop = false;
			this->creepIMG->Visible = false;
			// 
			// juggernautIMG
			// 
			this->juggernautIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"juggernautIMG.Image")));
			this->juggernautIMG->Location = System::Drawing::Point(721, 366);
			this->juggernautIMG->Name = L"juggernautIMG";
			this->juggernautIMG->Size = System::Drawing::Size(95, 134);
			this->juggernautIMG->TabIndex = 10;
			this->juggernautIMG->TabStop = false;
			this->juggernautIMG->Visible = false;
			// 
			// torreIMG
			// 
			this->torreIMG->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"torreIMG.Image")));
			this->torreIMG->Location = System::Drawing::Point(133, 152);
			this->torreIMG->Name = L"torreIMG";
			this->torreIMG->Size = System::Drawing::Size(133, 289);
			this->torreIMG->TabIndex = 11;
			this->torreIMG->TabStop = false;
			this->torreIMG->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1706, 677);
			this->Controls->Add(this->torreIMG);
			this->Controls->Add(this->juggernautIMG);
			this->Controls->Add(this->creepIMG);
			this->Controls->Add(this->wallIMG);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->hitlerIMG);
			this->Controls->Add(this->supermanIMG);
			this->Controls->Add(this->sanjiIMG);
			this->Controls->Add(this->batmanIMG);
			this->Controls->Add(this->riderIMG);
			this->Controls->Add(this->mapaIMG);
			this->Controls->Add(this->luffyIMG);
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"MyForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->luffyIMG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->mapaIMG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->riderIMG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->batmanIMG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->sanjiIMG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->supermanIMG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hitlerIMG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->wallIMG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->creepIMG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->juggernautIMG))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->torreIMG))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
		Graphics^g = this->CreateGraphics();
		BufferedGraphicsContext^bc = BufferedGraphicsManager::Current;
		BufferedGraphics^buffer = bc->Allocate(g, this->ClientRectangle);
		buffer->Graphics->Clear(Color::Black);	

		n+= 100;
		juego->dibujarJuego(n,buffer->Graphics, mapa, luffy,sanji,wall,batman,hitler,torre);
		if (n == 10000)n = 0;
		buffer->Render(g);

		delete buffer; delete bc; delete g;
	}
	private: System::Void MyForm_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		bool player;
		if (e->KeyData == Keys::D1) {
			juego->seleccion = Radiant;
			juego->mouse_x = juego->PJ1->x;
			juego->mouse_y = juego->PJ1->y;
		}
		if (e->KeyData == Keys::D2) { 
			juego->seleccion = Dire;
			juego->mouse_x = juego->PJ2->x;
			juego->mouse_y = juego->PJ2->y;
		}
	}
	private: System::Void MyForm_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->Text = e->Location.ToString()+ClientSize;
	}
	private: System::Void MyForm_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		juego->mouse_x = e->X-24;
		juego->mouse_y = e->Y-24;
	}


};
}
