#include "MyForm.h"
#include "MyForm2.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ args){
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	test::MyForm form;
	Application::Run(%form);
}

