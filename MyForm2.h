
#pragma once
#include "AnalizatorLeksykalny.h";
namespace test {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
     AnalizatorLeksykalny *wsk;
	 string *tabParser;
	public:
		MyForm2(void)
		{
			InitializeComponent();
			
		}
		MyForm2(AnalizatorLeksykalny *obiekt1)
		{
			InitializeComponent();
		    wsk =obiekt1;
		}

	protected:

		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Button^  button2;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(189, 452);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(109, 33);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Wykonaj";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 33);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(514, 404);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(189, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Poni¿ej napisz tekst swojego programu";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(581, 33);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(392, 404);
			this->textBox2->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(730, 452);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(103, 33);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Poka¿ tablicê";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm2::button2_Click);
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(985, 497);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm2";
			this->Text = L"MyForm2";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
		{
			//AnalizatorLeksykalny okno2 =newAnalizatorLeksykalny();
		}
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		    {
			string pomoc1="",pomo2="";
			String^ str1="";
			String^ str2="pp";
			AnalizatorLeksykalny okno2;
			TablicaSymboli pomoc;
			
			string instr="";
			array<String^>^ tempArray = gcnew array<String^>( textBox1->Lines->Length );
            tempArray = textBox1->Lines;

            // Loop through the array and send the contents of the array to debug window.
            for ( int counter = 0; counter < tempArray->Length; counter++ )
            {
				String^ pomoc=tempArray[counter];
				using namespace Runtime::InteropServices;
                const char* chars =  (const char*)(Marshal::StringToHGlobalAnsi(pomoc)).ToPointer();
                instr += chars;
				//instr+='\0';
                Marshal::FreeHGlobal(IntPtr((void*)chars));
                System::Diagnostics::Debug::WriteLine( pomoc);//tempArray[ counter ] );
            }
		    instr+='\0';

				String^ test22 = gcnew String(instr.c_str());
				//textBox2->Text+="||"+test22+"||";
				int *tablica =new int[wsk->tabWzo.size()];
				int miejsce=0;
				Symbole wynik;
				for(int k=0;;k++)
				{
					wynik=wsk->daj_leksem(instr,wsk->tabSym,wsk->tabWzo,&miejsce,tablica);
					//*tabParser="";
					if(wynik.leksem != "")
						{
						okno2.dlaParsera=okno2.dodajDoTablicy(okno2.dlaParsera,wynik ,pomoc);
					    str1 = gcnew String(wynik.rodzaj.c_str());
						str2 = gcnew String(wynik.zwracany.c_str());
						textBox2->Text+=str1+", "+str2+"\r\n";

						}
					else
					{
						break;
					}
				}
			}
	};
}
