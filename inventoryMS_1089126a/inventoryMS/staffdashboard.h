#pragma once
#include "Staff.h"
#include "Products.h"
#include "checkout.h"
void ListBox_Event(Object sender, EventArgs m);
namespace inventoryMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;



	/// <summary>
	/// Summary for staffdashboard
	/// </summary>
    
	public ref class staffdashboard : public System::Windows::Forms::Form
	{
	public:Products^ pro = nullptr; //Products header file object
	public:
		//Calling Staff Constructor Object 
		staffdashboard(Staff^ staff)   
		{
			InitializeComponent();
		     
			String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
			SqlConnection sqlConn(conn);
			sqlConn.Open();
			static int n;
			int idd = 1;
			String^ sqlQuery = "Select count(*) from products;";
			SqlCommand command(sqlQuery, % sqlConn);

			SqlDataReader^ reader2 = command.ExecuteReader();
			while (reader2->Read()) {
				n = reader2->GetInt32(0);

			}
			reader2->Close();
			while (idd <= n)
			{

				String^ sqlQuery = "Select * from products where id=@idd;";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@idd", idd);

				SqlDataReader^ reader = command.ExecuteReader();
				if (reader->Read()) {
					pro = gcnew Products;
					pro->id = reader->GetInt32(0);
					pro->pname = reader->GetString(1);
					pro->quantity = reader->GetInt32(2);

					
					//Printing Products List 

					listbox->Items->Add(pro->pname);
					if (pro->quantity <= 5)
					{
						listbox1->Items->Add(pro->quantity+"	(few left)");
					}
					else
					{
						listbox1->Items->Add(pro->quantity);
					}
					
				}
				else
				{
					n = n + 1;
				}
				reader->Close();
				idd++;

			}
			//staffinfo->Text = "ID = " + pro->id + "Username = " + pro->pname;
			//TODO: Add the constructor code here
			
		 
			//
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~staffdashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ staffinfo;
	private: System::Windows::Forms::ListBox^ listbox;
	private: System::Windows::Forms::Button^ select;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ quant;

	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::ListBox^ listbox1;




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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->staffinfo = (gcnew System::Windows::Forms::Label());
			this->listbox = (gcnew System::Windows::Forms::ListBox());
			this->select = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->quant = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->listbox1 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(243, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(148, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Product Listing";
			// 
			// staffinfo
			// 
			this->staffinfo->AutoSize = true;
			this->staffinfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->staffinfo->Location = System::Drawing::Point(419, 89);
			this->staffinfo->Name = L"staffinfo";
			this->staffinfo->Size = System::Drawing::Size(0, 20);
			this->staffinfo->TabIndex = 1;
			this->staffinfo->Click += gcnew System::EventHandler(this, &staffdashboard::staffinfo_Click);
			// 
			// listbox
			// 
			this->listbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listbox->FormattingEnabled = true;
			this->listbox->ItemHeight = 16;
			this->listbox->Location = System::Drawing::Point(114, 75);
			this->listbox->Name = L"listbox";
			this->listbox->Size = System::Drawing::Size(117, 132);
			this->listbox->TabIndex = 2;
			// 
			// select
			// 
			this->select->Location = System::Drawing::Point(182, 219);
			this->select->Name = L"select";
			this->select->Size = System::Drawing::Size(75, 23);
			this->select->TabIndex = 3;
			this->select->Text = L"Select";
			this->select->UseVisualStyleBackColor = true;
			this->select->Click += gcnew System::EventHandler(this, &staffdashboard::select_Click);
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(500, 173);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(32, 34);
			this->button1->TabIndex = 4;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &staffdashboard::button1_Click);
			// 
			// button2
			// 
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(423, 173);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(30, 34);
			this->button2->TabIndex = 5;
			this->button2->Text = L"-";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &staffdashboard::button2_Click);
			// 
			// quant
			// 
			this->quant->Location = System::Drawing::Point(449, 173);
			this->quant->Name = L"quant";
			this->quant->Size = System::Drawing::Size(53, 34);
			this->quant->TabIndex = 6;
			this->quant->Text = L"0";
			this->quant->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(521, 250);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 37);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Proceed";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &staffdashboard::button3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(420, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 20);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Select Quantity";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(420, 54);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(147, 20);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Selected Product";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(129, 54);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(80, 20);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Products";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(243, 54);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 20);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Quantity";
			// 
			// listbox1
			// 
			this->listbox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listbox1->FormattingEnabled = true;
			this->listbox1->ItemHeight = 16;
			this->listbox1->Location = System::Drawing::Point(237, 77);
			this->listbox1->Name = L"listbox1";
			this->listbox1->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listbox1->Size = System::Drawing::Size(129, 132);
			this->listbox1->TabIndex = 13;
			// 
			// staffdashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(683, 321);
			this->Controls->Add(this->listbox1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->quant);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->select);
			this->Controls->Add(this->listbox);
			this->Controls->Add(this->staffinfo);
			this->Controls->Add(this->label1);
			this->Name = L"staffdashboard";
			this->Text = L"staffdashboard";
			this->Load += gcnew System::EventHandler(this, &staffdashboard::staffdashboard_Load_1);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void staffdashboard_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void staffinfo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	
		   //Selecting the Product item from listbox
private: System::Void select_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ curItem = listbox->SelectedItem->ToString();
	staffinfo->Text = curItem;
}
	   private:static int counter;
			  
	//VAlidating the Quantity of Product 

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
	SqlConnection sqlConn(conn);
	sqlConn.Open();
	int n;
	String^ pd = staffinfo->Text->ToString();
	String^ sqlQuery = "Select quantity from products where pname=@pd;";
	SqlCommand command(sqlQuery, % sqlConn);
	command.Parameters->AddWithValue("@pd", pd);
	SqlDataReader^ reader3 = command.ExecuteReader();
	while (reader3->Read()) {
		n = reader3->GetInt32(0);

	}
	reader3->Close();


	if (counter > n-1)
	{
	MessageBox::Show("Quantity Cannot be more than " +n, "Invalid", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

	}
	else
	{
		counter++;
		quant->Text = counter.ToString();
	}
}   
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
	

	if (counter > 0)
	{
		counter--;
		quant->Text = counter.ToString();
	}
	else
	{
		MessageBox::Show("Quantity Cannot be less than 0", "Invalid", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
	}
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
	   //Redirecting to Checkout Page with additional Data

private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	checkout^ co = gcnew checkout(staffinfo->Text,quant->Text);
	co->ShowDialog();
}
private: System::Void staffdashboard_Load_1(System::Object^ sender, System::EventArgs^ e) {
}
};
}
