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
	private: System::Windows::Forms::Button^  opnSsnBtn;
	protected: 

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Button^  opnIFCbtn;

	private: System::Windows::Forms::Button^  strBtn;


	public: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button4;
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
			this->opnSsnBtn = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->opnIFCbtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			strBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// opnSsnBtn
			// 
			this->opnSsnBtn->BackColor = System::Drawing::Color::Transparent;
			this->opnSsnBtn->Font = (gcnew System::Drawing::Font(L"HelveticaNeueCyr", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->opnSsnBtn->Location = System::Drawing::Point(31, 294);
			this->opnSsnBtn->Name = L"opnSsnBtn";
			this->opnSsnBtn->Size = System::Drawing::Size(137, 42);
			this->opnSsnBtn->TabIndex = 0;
			this->opnSsnBtn->Text = L"Open Session";
			this->opnSsnBtn->UseVisualStyleBackColor = false;
			this->opnSsnBtn->Click += gcnew System::EventHandler(this, &Form1::opnSsnBtn_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// opnIFCbtn
			// 
			this->opnIFCbtn->BackColor = System::Drawing::Color::Transparent;
			this->opnIFCbtn->Enabled = false;
			this->opnIFCbtn->Font = (gcnew System::Drawing::Font(L"HelveticaNeueCyr", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->opnIFCbtn->Location = System::Drawing::Point(219, 294);
			this->opnIFCbtn->Name = L"opnIFCbtn";
			this->opnIFCbtn->Size = System::Drawing::Size(137, 42);
			this->opnIFCbtn->TabIndex = 1;
			this->opnIFCbtn->Text = L"Open Ifc File";
			this->opnIFCbtn->UseVisualStyleBackColor = false;
			this->opnIFCbtn->Click += gcnew System::EventHandler(this, &Form1::opnIFCbtn_Click);
			// 
			// strBtn
			// 
			this->strBtn->Enabled = false;
			this->strBtn->Font = (gcnew System::Drawing::Font(L"HelveticaNeueCyr", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->strBtn->ForeColor = System::Drawing::SystemColors::ControlText;
			this->strBtn->Location = System::Drawing::Point(398, 294);
			this->strBtn->Name = L"strBtn";
			this->strBtn->Size = System::Drawing::Size(137, 42);
			this->strBtn->TabIndex = 2;
			this->strBtn->Text = L"Start";
			this->strBtn->UseVisualStyleBackColor = true;
			this->strBtn->Click += gcnew System::EventHandler(this, &Form1::strBtn_Click);
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
			// button4
			// 
			this->button4->Location = System::Drawing::Point(219, 17);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(110, 23);
			this->button4->TabIndex = 5;
			this->button4->Text = L"EASY DEBUG";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Teal;
			this->ClientSize = System::Drawing::Size(571, 359);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(strBtn);
			this->Controls->Add(this->opnIFCbtn);
			this->Controls->Add(this->opnSsnBtn);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form1";
			this->Text = L"Дипломный проект Гусева Д.В. РК9-82";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void opnSsnBtn_Click(System::Object^  sender, System::EventArgs^  e) {
				 char NAMERPD [128];
				 memset(NAMERPD, 0, 128);
				 OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

				 openFileDialog1->InitialDirectory = "c:\\";
				 openFileDialog1->Filter = "RPD files (*.rpd)|*.rpd|All files (*.*)|*.*";
				 openFileDialog1->FilterIndex = 2;
				 openFileDialog1->RestoreDirectory = true;

				 if ( openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK )
				 {
					 for( int i = 0; i < openFileDialog1->FileName->Length; i++)
					 {

						 NAMERPD[i] = openFileDialog1->FileName[i];
					 }
				 }

				
				 if(OpenRepository(NAMERPD)) 
				 {
					 opnIFCbtn->Enabled = true;
					 strBtn->Enabled = true;
					 char *currentTime = getCurrentTime();
					 this->richTextBox1->Text =and_CharToSysString(currentTime) + "    Session is succesfully opened";
				 }
				 //передача строки через файл
			 }


	private: System::Void opnIFCbtn_Click(System::Object^  sender, System::EventArgs^  e) {

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
					 for(int i = 0; i < openFileDialog1->FileName->Length; i++)
					 {

						 NAMEIFC[i] = openFileDialog1->FileName[i];
					 }

				 }

				 int i =  ReadSTEPFile(NAMEIFC);
				 this->richTextBox1->Text += "\n" + and_CharToSysString(getCurrentTime()) + "    IFC File is opened";
			 }
			 //	 }

	private: System::Void strBtn_Click(System::Object^  sender, System::EventArgs^  e) {
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
				

			 }


			 System::String^  and_CharToSysString(char* ch)  //функция переводящая чар в системный стринг
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
	private: System::Void button4_Click_1(System::Object^  sender, System::EventArgs^  e) {
				  //
				 char NAMERPD [128];
				 memset(NAMERPD, 0, 128);
				  char NAMEIFC [128];//22 41
				 memset(NAMEIFC, 0, 128);

				 String^ NRPDstr = "C:\\constrData\\START.RPD";
				 String^ NIFCstr = "C:\\constrData\\constructionData\\etoSTENY.ifc";

				   for(int i = 0; i < 23; i++)
					 {
						 NAMERPD[i] = NRPDstr[i];
					 }
				   for(int i = 0; i < 43; i++)
					 {
						 NAMEIFC[i] = NIFCstr[i];
					 }

				   if(OpenRepository(NAMERPD))
				   {
					   int i =  ReadSTEPFile(NAMEIFC);
					    Creceiver Receiver;
						Receiver.m_Function = setProjectTitle;
						Intermediate = new Cintermediate;
						int t = getProjects(&Receiver);
				   }
			 }
};	



}

// функциям посылать СДАИинстанс, что можно было получить все что угодно
