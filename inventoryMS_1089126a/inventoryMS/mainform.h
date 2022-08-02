#pragma once

#include "Staff.h"
#include "MOwner.h"
namespace inventoryMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	/// <summary>
	/// Summary for mainform
	/// </summary>
	/// 
    
	public ref class mainform : public System::Windows::Forms::Form
	{
	public:
		mainform(void)
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
		~mainform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ buttonowner;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Button^ buttonstaff;

	private: System::Windows::Forms::TextBox^ staffpassword;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ ouname;


	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ staffuname;
	private: System::Windows::Forms::TextBox^ opassword;


	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->opassword = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->ouname = (gcnew System::Windows::Forms::TextBox());
			this->buttonowner = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->staffuname = (gcnew System::Windows::Forms::TextBox());
			this->buttonstaff = (gcnew System::Windows::Forms::Button());
			this->staffpassword = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Mongolian Baiti", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label1->Location = System::Drawing::Point(36, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(361, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Inventory Management System";
			this->label1->Click += gcnew System::EventHandler(this, &mainform::label1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->panel1->Controls->Add(this->opassword);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->ouname);
			this->panel1->Controls->Add(this->buttonowner);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Location = System::Drawing::Point(40, 72);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(217, 205);
			this->panel1->TabIndex = 1;
			// 
			// opassword
			// 
			this->opassword->BackColor = System::Drawing::SystemColors::Window;
			this->opassword->Location = System::Drawing::Point(19, 128);
			this->opassword->Name = L"opassword";
			this->opassword->PasswordChar = '*';
			this->opassword->Size = System::Drawing::Size(176, 20);
			this->opassword->TabIndex = 6;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label5->Location = System::Drawing::Point(17, 101);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(83, 18);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Password";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label4->Location = System::Drawing::Point(16, 44);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 18);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Username";
			// 
			// ouname
			// 
			this->ouname->BackColor = System::Drawing::SystemColors::Window;
			this->ouname->Location = System::Drawing::Point(20, 76);
			this->ouname->Name = L"ouname";
			this->ouname->Size = System::Drawing::Size(176, 20);
			this->ouname->TabIndex = 3;
			this->ouname->Text = L" ";
			this->ouname->TextChanged += gcnew System::EventHandler(this, &mainform::ouname_TextChanged);
			// 
			// buttonowner
			// 
			this->buttonowner->BackColor = System::Drawing::SystemColors::HotTrack;
			this->buttonowner->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonowner->Location = System::Drawing::Point(118, 165);
			this->buttonowner->Name = L"buttonowner";
			this->buttonowner->Size = System::Drawing::Size(78, 28);
			this->buttonowner->TabIndex = 2;
			this->buttonowner->Text = L"Login";
			this->buttonowner->UseVisualStyleBackColor = false;
			this->buttonowner->Click += gcnew System::EventHandler(this, &mainform::buttonowner_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->Location = System::Drawing::Point(16, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(130, 24);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Owner Login";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->panel2->Controls->Add(this->label7);
			this->panel2->Controls->Add(this->label6);
			this->panel2->Controls->Add(this->staffuname);
			this->panel2->Controls->Add(this->buttonstaff);
			this->panel2->Controls->Add(this->staffpassword);
			this->panel2->Controls->Add(this->label3);
			this->panel2->Location = System::Drawing::Point(305, 72);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(217, 205);
			this->panel2->TabIndex = 2;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label7->Location = System::Drawing::Point(17, 99);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(83, 18);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Password";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label6->Location = System::Drawing::Point(17, 44);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(85, 18);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Username";
			// 
			// staffuname
			// 
			this->staffuname->BackColor = System::Drawing::SystemColors::Window;
			this->staffuname->Location = System::Drawing::Point(21, 76);
			this->staffuname->Name = L"staffuname";
			this->staffuname->Size = System::Drawing::Size(176, 20);
			this->staffuname->TabIndex = 4;
			// 
			// buttonstaff
			// 
			this->buttonstaff->BackColor = System::Drawing::SystemColors::HotTrack;
			this->buttonstaff->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->buttonstaff->Location = System::Drawing::Point(119, 165);
			this->buttonstaff->Name = L"buttonstaff";
			this->buttonstaff->Size = System::Drawing::Size(78, 28);
			this->buttonstaff->TabIndex = 3;
			this->buttonstaff->Text = L"Login";
			this->buttonstaff->UseVisualStyleBackColor = false;
			this->buttonstaff->Click += gcnew System::EventHandler(this, &mainform::buttonstaff_Click);
			// 
			// staffpassword
			// 
			this->staffpassword->BackColor = System::Drawing::SystemColors::Window;
			this->staffpassword->Location = System::Drawing::Point(21, 128);
			this->staffpassword->Name = L"staffpassword";
			this->staffpassword->PasswordChar = '*';
			this->staffpassword->Size = System::Drawing::Size(176, 20);
			this->staffpassword->TabIndex = 2;
			this->staffpassword->TextChanged += gcnew System::EventHandler(this, &mainform::textBox2_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label3->Location = System::Drawing::Point(17, 9);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(107, 24);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Staff Login";
			// 
			// mainform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(586, 360);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label1);
			this->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->Name = L"mainform";
			this->Text = L"mainform";
			this->Load += gcnew System::EventHandler(this, &mainform::mainform_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
public: MOwner^ owner = nullptr; //Object Of MOwner header file 
	  //Excracting username and password for login from textbox
	private: System::Void buttonowner_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ uname = "rahul";
		//String^ pass = "dravid";
		String^ pass = this->opassword->Text;


		//Checking if length of username or passwprd is less than 0
		if (uname->Length == 0 || pass->Length == 0) {

			MessageBox::Show("Enter the username and password", "Username or Password Empty", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

			return;
		}

		//Exception Handling For checking Validity of Username & Password
		try
		{
			String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
			SqlConnection sqlConn(conn);
			sqlConn.Open();

			String^ sqlQuery = "Select * from mowner where uname=@uname and password=@pass;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@uname", uname);
			command.Parameters->AddWithValue("@pass", pass);

			SqlDataReader^ reader = command.ExecuteReader();

			//Redirects if true to ownerdashboard form

			if (reader->Read())
			{
				owner = gcnew MOwner; 
				owner->uname = reader->GetString(1);
				owner->password = reader->GetString(2);

				this->Close();

			}
			else
			{
				MessageBox::Show("Incorrect username and password", "Username or Password Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

			}

		}
		catch (Exception^ e) {

			MessageBox::Show("Connection Failed", "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

		}
	}

	public: Staff^ staff = nullptr; //Staff headerfile Object declarator
		  
	private: System::Void buttonstaff_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ uname = this->staffuname->Text;
		String^ pass = this->staffpassword->Text;

		//Checking if length of username or passwprd is less than 0

		if (uname->Length == 0 || pass->Length == 0) {
			
			MessageBox::Show("Enter the username and password", "Username or Password Empty", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

			return;
		}
		//Exception Handling For checking Validity of Username & Password
		try
		{
			String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
			SqlConnection sqlConn(conn);
			sqlConn.Open();

			String^ sqlQuery = "Select * from staff where uname=@uname and password=@pass;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@uname", uname);
			command.Parameters->AddWithValue("@pass", pass);

			SqlDataReader^ reader = command.ExecuteReader();

			if (reader->Read())
			{
			    staff = gcnew Staff;
				staff->uname = reader->GetString(1);
				staff->password = reader->GetString(2);

				this->Close();

			}
			else
			{
				MessageBox::Show("Incorrect username and password", "Username or Password Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

			}

		}
		catch (Exception^ e) {
			
			MessageBox::Show("Connection Failed", "Database Error", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

		}
	}
	private: System::Void mainform_Load(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void ouname_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
