#pragma once
#include<iostream>
#include<string>
#include "MyForm2.h"
//#include "AnalizatorLeksykalny.h"
namespace test {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;


	private: System::Windows::Forms::TextBox^  textBox2;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  generuj;


	private: System::Windows::Forms::Button^  button4;

	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  Sciezka;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->generuj = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->Sciezka = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(16, 24);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(94, 34);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Przegl¹daj ";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(15, 107);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(576, 335);
			this->textBox2->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 77);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Podgl¹d pliku";
			// 
			// generuj
			// 
			this->generuj->Location = System::Drawing::Point(635, 400);
			this->generuj->Name = L"generuj";
			this->generuj->Size = System::Drawing::Size(96, 42);
			this->generuj->TabIndex = 6;
			this->generuj->Text = L"Generuj ";
			this->generuj->UseVisualStyleBackColor = true;
			this->generuj->Click += gcnew System::EventHandler(this, &MyForm::generuj_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(15, 783);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(92, 39);
			this->button4->TabIndex = 8;
			this->button4->Text = L"Wyjdz";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(631, 356);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(100, 23);
			this->progressBar1->TabIndex = 10;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(133, 76);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 13);
			this->label1->TabIndex = 11;
			this->label1->Text = L"Podaj œcie¿kê";
			// 
			// Sciezka
			// 
			this->Sciezka->Location = System::Drawing::Point(236, 69);
			this->Sciezka->Name = L"Sciezka";
			this->Sciezka->Size = System::Drawing::Size(355, 20);
			this->Sciezka->TabIndex = 12;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(752, 525);
			this->Controls->Add(this->Sciezka);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->generuj);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		    {
				if(openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
                { 
					System::IO::StreamReader ^ sr = gcnew
					System::IO::StreamReader(openFileDialog1->FileName);
					textBox2->Text=sr->ReadToEnd();
					//MessageBox::Show(sr->ReadToEnd());
					sr->Close();
				}

				 /*OpenFileDialog^ odczyt = gcnew OpenFileDialog();
				 odczyt->Filter="Text Files|*.txt";
				 if(odczyt->ShowDialog()==Windows::Forms::DialogResult::OK)
				 {
					 MessageBox::Show(zapis->ReadToEnd());//"Plik zosta³ wczytany.");
				 }*/

				
			 }


		private: System::Void generuj_Click(System::Object^  sender, System::EventArgs^  e) 
		    {
		        AnalizatorLeksykalny nowy,*wsk;
				String^ sciezkowy = gcnew String(Sciezka->Text);
				string os="123";
				using namespace Runtime::InteropServices;
                const char* chars =  (const char*)(Marshal::StringToHGlobalAnsi(sciezkowy)).ToPointer();
                os = chars;
				String^ str3 = gcnew String(os.c_str());
				textBox2->Text+=str3;
                Marshal::FreeHGlobal(IntPtr((void*)chars));
				nowy.tabWzo=nowy.zapisz1(os);
			    nowy.tabSym=nowy.zapisz2(os);
				
				for(int i=0;i<nowy.tabSym.size();i++){
					string pomoc=nowy.tabSym[i].zwracany;
				    String^ str2 = gcnew String(pomoc.c_str());
					textBox2->Text+=" "+str2;
				}
				wsk= &nowy;
				//textBox2->Text+=" ROZMIAR: "+nowy.tabSym.size();
				MyForm2^ noweOkno = gcnew MyForm2(wsk);
                noweOkno->ShowDialog();
				this->Hide();
		    } 	
};
}
