

#include"MenuPrincipal.h"

using namespace System;
using namespace Windows::Forms;
using namespace Windows::Input;
using namespace System::Drawing;




void main() {

	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Application::Run(gcnew TF::MenuPrincipal);



}