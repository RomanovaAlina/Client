#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]

void main (array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Project::MyForm form;
	Application::Run(%form);

	if (IsDebuggerPresent()) ExitProcess(0);
	BOOL f=false;
	CheckRemoteDebuggerPresent(GetCurrentProcess(), &f);
	if (f==true) ExitProcess(0);

}