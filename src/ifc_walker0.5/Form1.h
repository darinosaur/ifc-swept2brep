#pragma once
#include <string>  
#include <ctime>

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
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	public: 

	public: 



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
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"HelveticaNeueCyr", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(31, 294);
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
			this->button2->Location = System::Drawing::Point(219, 294);
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
			this->button3->Location = System::Drawing::Point(398, 294);
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
			// richTextBox1
			// 
			this->richTextBox1->BackColor = System::Drawing::SystemColors::InfoText;
			this->richTextBox1->Font = (gcnew System::Drawing::Font(L"Courier New", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->richTextBox1->ForeColor = System::Drawing::SystemColors::Info;
			this->richTextBox1->Location = System::Drawing::Point(31, 52);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(504, 226);
			this->richTextBox1->TabIndex = 4;
			this->richTextBox1->Text = L"All rights reserved by me (C)";
			this->richTextBox1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::richTextBox1_MouseClick);
			this->richTextBox1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::richTextBox1_MouseDoubleClick);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Teal;
			this->ClientSize = System::Drawing::Size(571, 359);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"��������� ������ ������ �.�. ��9-82";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
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
					 char *currentTime = getCurrentTime();
					 this->richTextBox1->Text =and_CharToSysString(currentTime) + "    Session is succesfully opened";
				 }
				 //�������� ������ ����� ����
			 }


	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {

				 char NAMEIFC [128];
				 memset(NAMEIFC, 0, 128);
				 //������� ����������� ������������� ��� � �������� �����
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
				 this->richTextBox1->Text += "\n" + and_CharToSysString(getCurrentTime()) + "    IFC File is opened";
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
					 this->richTextBox1->Text += "\n" + and_CharToSysString(getCurrentTime()) + "    Project name is " + and_CharToSysString(Intermediate->Title);
				 }


			 }
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
				 //
			 }


			 System::String^  and_CharToSysString(char* ch)  //������� ����������� ��� � ��������� ������
			 {
				 char * chr=new char[]=ch;
				 System::String^ str = gcnew String(ch);

				 return str;
			 }


	private: System::Void richTextBox1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 this->richTextBox1->Text += "\n Do not click";
			 }
	private: System::Void richTextBox1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
				 this->richTextBox1->Text += "\n Do not double click";
			 }

			 char* getCurrentTime()
			 {
				 char * buffer = new char[80];
				 time_t seconds = time(NULL);
				 tm* timeinfo = localtime(&seconds);
				 char* format = "%H:%M:%S";
				 strftime(buffer, 80, format, timeinfo);

				 return buffer;
			 }
	};	



}

// �������� �������� �����������, ��� ����� ���� �������� ��� ��� ������
