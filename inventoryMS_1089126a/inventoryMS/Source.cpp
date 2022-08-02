#include "mainform.h"
#include "ownerdashboard.h"
#include "staffdashboard.h"


using namespace System;
using namespace System::Windows::Forms;

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	inventoryMS::mainform mainform; //invocking the object of mainform headerfile

	mainform.ShowDialog();  //opens the form for mainform
	MOwner^ owner = mainform.owner;
	Staff^ staff = mainform.staff;

	if (owner != nullptr)
	{
		inventoryMS::ownerdashboard ownerdashboard(owner);
		Application::Run(% ownerdashboard);  //Redirects Route to ownerdashboard form
	}
	else if (staff != nullptr)
	{
		inventoryMS::staffdashboard staffdashboard(staff);
		Application::Run(% staffdashboard);  //Redirects Route to staffdashboard form
	}
	else
	{
		
		MessageBox::Show("Auth Terminated", "Source.cpp", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		
	}
}