#pragma once
#include <string>  

namespace ifc_walker05 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;


	/// <summary>
	/// Summary for Form1
	/// </summary>	

	 class Cintermediate
	{
	public:
		Cintermediate(void){
			Title = nullptr;};
		char* Title;
	};


	Cintermediate* Intermediate = nullptr;

	char* setProjectTitle(SdaiString Str)
		{
			
			char* r = "t";
	
			if(Intermediate)
			{
             Intermediate->Title = new char [25];
			for (unsigned i=0; i<24; ++i)
			 {
				 Intermediate->Title [i]  = Str[i];
			}
			
			 Intermediate->Title [24] =  0;
			 
			}
			return r;
			
		}

	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		
		Form1(void)
		{
			InitializeComponent();
		//	GlobalForm = this;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	public: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	public: 
	private: System::Windows::Forms::PictureBox^  pictureBox2;


	protected: 

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"HelveticaNeueCyr", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(281, 345);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(137, 42);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Open Session";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::Transparent;
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"HelveticaNeueCyr", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->Location = System::Drawing::Point(424, 345);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(137, 42);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Open Ifc File";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Font = (gcnew System::Drawing::Font(L"HelveticaNeueCyr", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(567, 345);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(137, 42);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Start";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"HelveticaNeueCyr", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(27, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 19);
			this->label1->TabIndex = 3;
			this->label1->Text = L"File Name";
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::White;
			this->pictureBox1->Location = System::Drawing::Point(31, 52);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(330, 272);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::White;
			this->pictureBox2->Location = System::Drawing::Point(377, 52);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(327, 272);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)), 
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(732, 408);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Дипломный проект Гусева Д.В. РК9-82";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				char NAMERPD [128];
				memset(NAMERPD, 0, 128);
				OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

				openFileDialog1->InitialDirectory = "c:\\";
				 openFileDialog1->Filter = "RPD files (*.rpd)|*.rpd|All files (*.*)|*.*";
				openFileDialog1->FilterIndex = 2;
				openFileDialog1->RestoreDirectory = true;

      if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
      {
		  
//		   string FlNm = openFileDialog1->FileName;
		   //memcpy ((const char*)&NAMEIFC[0], FlNm, strlen(FlNm)); 
		   int size = 10;
		 //  String s = openFileDialog1->FileName.get();
		   for(size = 0; size < 128;size++)
		   {
			   char WhatIs = openFileDialog1->FileName[size];
			   if(openFileDialog1->FileName[size] == 'r' || openFileDialog1->FileName[size] == 'R')
			   {
				   size++;
				   if(openFileDialog1->FileName[size] == 'p' || openFileDialog1->FileName[size] == 'P')
				   {size++;
				   if(openFileDialog1->FileName[size] == 'd' || openFileDialog1->FileName[size] == 'D')
					   {
						   size++;
							break;
				   }
				   }
				   
			   }
		   }
		   for(int i = 0; i < size; i++)
		   {

			   NAMERPD[i] = openFileDialog1->FileName[i];
		   }
		   
         
//            myStream->Close();
		   }
	
			//
	  if(OpenRepository(NAMERPD)) 
		{
			  button2->Enabled = true;
			   button3->Enabled = true;
		}
				 //передача строки через файл
			 }


	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
				
				 char NAMEIFC [128];
				memset(NAMEIFC, 0, 128);
				//сделать зависимости промежуточной длл и верхнего файла
//				 Stream^ myStream;
				OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

				openFileDialog1->InitialDirectory = "c:\\";
				 openFileDialog1->Filter = "IFC files (*.ifc)|*.ifc|All files (*.*)|*.*";
				openFileDialog1->FilterIndex = 2;
				openFileDialog1->RestoreDirectory = true;

      if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
      {
		   int size = 10;
		   for(size = 0; size < 128;size++)
		   {
			   char WhatIs = openFileDialog1->FileName[size];
			   if(openFileDialog1->FileName[size] == 'i' || openFileDialog1->FileName[size] == 'I')
			   {
				   size++;
				   if(openFileDialog1->FileName[size] == 'f' || openFileDialog1->FileName[size] == 'F')
				   {
					   size++;
					   if(openFileDialog1->FileName[size] == 'c' || openFileDialog1->FileName[size] == 'C')
						   {
							   size++;
								break;
						   }
				   }
			   }
		   }
			
		   for(int i = 0; i < size; i++)
			{

				NAMEIFC[i] = openFileDialog1->FileName[i];
			}
		   
	}
	
				int i =  ReadSTEPFile(NAMEIFC);
			
}
		//	 }
			 
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
			  Creceiver Receiver;
			  Receiver.m_Function = setProjectTitle;
			 Intermediate = new Cintermediate;
			 int t = getProjects(&Receiver);
			 if (Intermediate)
			 {
				 this->label1->Text = and_CharToSysString(Intermediate->Title);
			 }
		
		
		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
			 //
		 }

		 System::String^  and_CharToSysString(char* ch)  //функция переводящая чар в системный стринг
		{
		char * chr=new char[]=ch;
		System::String^ str = gcnew String(ch);

		return str;
		}

};	


}

// функциям посылать СДАИинстанс, что можно было получить все что угодно
