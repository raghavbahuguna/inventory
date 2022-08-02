#pragma once
#include "MOwner.h"
#include "Products.h"
#include "editproduct.h"
#include "filtersales.h"
namespace inventoryMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for ownerdashboard
	/// </summary>
	public ref class ownerdashboard : public System::Windows::Forms::Form
	{
	public:Products^ pro = nullptr;
	public:
		ownerdashboard(MOwner^ owner)
		{
			InitializeComponent();
			//
			String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
			SqlConnection sqlConn(conn);
			sqlConn.Open();
			static int n,p;
			int size;
			int idd = 1,idd2=0,inc=0,inc1=0;
			String^ sqlQuery = "Select count(*) from products;";
			SqlCommand command(sqlQuery, % sqlConn);

			//Extracting the number of products listed in table

			SqlDataReader^ reader2 = command.ExecuteReader();
			while (reader2->Read()) {
				n = reader2->GetInt32(0);
				p = reader2->GetInt32(0);
				size = reader2->GetInt32(0);

			}
			reader2->Close();

			//Creating String Array to sort products in Ascending order
			array<String^>^ str = gcnew array<String^>(size);
			
			//Storing the product values from table to string array
			while (idd <= n)
			{

				String^ sqlQuery = "Select * from products where id=@idd;";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@idd", idd);

				SqlDataReader^ reader = command.ExecuteReader();
				if (reader->Read()) 
				{
					pro = gcnew Products;
					pro->id = reader->GetInt32(0);
					pro->pname = reader->GetString(1);

					
						str[inc1++] = pro->pname;
					


				}
				else
				{
					n = n + 1;
				}
				reader->Close();
				idd++;

			}

			array<String^>^ str2 = gcnew array<String^>(1); //Temp String

			//Applying Bubble Sort to Sort the String Array

			for (int i=0;i<size-1;i++)
			{
				str2[0] = "";
				for (int j=0;j<size-i-1;j++)
				{
					if (str[j]->CompareTo(str[j + 1])>0)
					{
						str2[0]=str[j];
						str[j] = str[j + 1];
						str[j + 1]=str2[0];
					}
				}
			}


			//Printing The ListBox Content in Sorted Format

			while (idd2<p)
			{

				String^ sqlQuery = "Select * from products where pname=@stri;";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@stri",str[idd2]);
				
				

				SqlDataReader^ reader2 = command.ExecuteReader();
				if (reader2->Read()) {
					pro = gcnew Products;
					pro->id = reader2->GetInt32(0);
					pro->pname = reader2->GetString(1);
					pro->quantity = reader2->GetInt32(2);



					listbox1->Items->Add(pro->pname);
					if (pro->quantity <= 5)  //if quantity is less than 5
					{
						listbox3->Items->Add(pro->quantity + "	(few left)");
					}
					else
					{
						listbox3->Items->Add(pro->quantity);
					}

				}

				
				
				reader2->Close();
				idd2++;

			}
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~ownerdashboard()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ ownerinfo;
	private: System::Windows::Forms::ListBox^ listbox1;

	private: System::Windows::Forms::Button^ del;
	private: System::Windows::Forms::Button^ edit;
	private: System::Windows::Forms::Button^ addc;

	private: System::Windows::Forms::Button^ sales;


	private: System::Windows::Forms::Button^ filter;
	private: System::Windows::Forms::TextBox^ quantval;

	private: System::Windows::Forms::TextBox^ prodval;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DateTimePicker^ datetime3;

	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::ListBox^ listbox3;

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
			this->ownerinfo = (gcnew System::Windows::Forms::Label());
			this->listbox1 = (gcnew System::Windows::Forms::ListBox());
			this->del = (gcnew System::Windows::Forms::Button());
			this->edit = (gcnew System::Windows::Forms::Button());
			this->addc = (gcnew System::Windows::Forms::Button());
			this->sales = (gcnew System::Windows::Forms::Button());
			this->filter = (gcnew System::Windows::Forms::Button());
			this->quantval = (gcnew System::Windows::Forms::TextBox());
			this->prodval = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->datetime3 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->listbox3 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(55, 13);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(570, 23);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Owner Inventory Dashboard";
			this->label1->Click += gcnew System::EventHandler(this, &ownerdashboard::label1_Click);
			// 
			// ownerinfo
			// 
			this->ownerinfo->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ownerinfo->Location = System::Drawing::Point(56, 152);
			this->ownerinfo->Name = L"ownerinfo";
			this->ownerinfo->Size = System::Drawing::Size(150, 23);
			this->ownerinfo->TabIndex = 1;
			this->ownerinfo->Text = L"Product List";
			this->ownerinfo->Click += gcnew System::EventHandler(this, &ownerdashboard::ownerinfo_Click);
			// 
			// listbox1
			// 
			this->listbox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listbox1->FormattingEnabled = true;
			this->listbox1->ItemHeight = 18;
			this->listbox1->Location = System::Drawing::Point(12, 194);
			this->listbox1->Name = L"listbox1";
			this->listbox1->Size = System::Drawing::Size(115, 184);
			this->listbox1->TabIndex = 2;
			this->listbox1->SelectedIndexChanged += gcnew System::EventHandler(this, &ownerdashboard::listbox1_SelectedIndexChanged);
			// 
			// del
			// 
			this->del->Location = System::Drawing::Point(297, 194);
			this->del->Name = L"del";
			this->del->Size = System::Drawing::Size(89, 39);
			this->del->TabIndex = 3;
			this->del->Text = L"Delete";
			this->del->UseVisualStyleBackColor = true;
			this->del->Click += gcnew System::EventHandler(this, &ownerdashboard::button1_Click);
			// 
			// edit
			// 
			this->edit->Location = System::Drawing::Point(297, 269);
			this->edit->Name = L"edit";
			this->edit->Size = System::Drawing::Size(89, 39);
			this->edit->TabIndex = 4;
			this->edit->Text = L"Edit";
			this->edit->UseVisualStyleBackColor = true;
			this->edit->Click += gcnew System::EventHandler(this, &ownerdashboard::edit_Click);
			// 
			// addc
			// 
			this->addc->Location = System::Drawing::Point(468, 73);
			this->addc->Name = L"addc";
			this->addc->Size = System::Drawing::Size(109, 39);
			this->addc->TabIndex = 5;
			this->addc->Text = L"Add";
			this->addc->UseVisualStyleBackColor = true;
			this->addc->Click += gcnew System::EventHandler(this, &ownerdashboard::addc_Click);
			// 
			// sales
			// 
			this->sales->Location = System::Drawing::Point(595, 13);
			this->sales->Name = L"sales";
			this->sales->Size = System::Drawing::Size(109, 39);
			this->sales->TabIndex = 6;
			this->sales->Text = L"Sales";
			this->sales->UseVisualStyleBackColor = true;
			// 
			// filter
			// 
			this->filter->Location = System::Drawing::Point(516, 269);
			this->filter->Name = L"filter";
			this->filter->Size = System::Drawing::Size(109, 39);
			this->filter->TabIndex = 7;
			this->filter->Text = L"Filter";
			this->filter->UseVisualStyleBackColor = true;
			this->filter->Click += gcnew System::EventHandler(this, &ownerdashboard::filter_Click);
			// 
			// quantval
			// 
			this->quantval->Location = System::Drawing::Point(297, 83);
			this->quantval->Name = L"quantval";
			this->quantval->Size = System::Drawing::Size(147, 20);
			this->quantval->TabIndex = 8;
			// 
			// prodval
			// 
			this->prodval->Location = System::Drawing::Point(78, 83);
			this->prodval->Name = L"prodval";
			this->prodval->Size = System::Drawing::Size(158, 20);
			this->prodval->TabIndex = 9;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(74, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(150, 23);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Product";
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(294, 57);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(150, 23);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Quantity";
			// 
			// datetime3
			// 
			this->datetime3->CustomFormat = L"dd-MM-yyyy";
			this->datetime3->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->datetime3->Location = System::Drawing::Point(504, 213);
			this->datetime3->Name = L"datetime3";
			this->datetime3->Size = System::Drawing::Size(142, 20);
			this->datetime3->TabIndex = 12;
			this->datetime3->Value = System::DateTime(2022, 7, 28, 20, 35, 54, 0);
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(512, 171);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(150, 23);
			this->label4->TabIndex = 14;
			this->label4->Text = L"Filter By Date";
			// 
			// listbox3
			// 
			this->listbox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listbox3->FormattingEnabled = true;
			this->listbox3->ItemHeight = 18;
			this->listbox3->Location = System::Drawing::Point(133, 194);
			this->listbox3->Name = L"listbox3";
			this->listbox3->SelectionMode = System::Windows::Forms::SelectionMode::None;
			this->listbox3->Size = System::Drawing::Size(149, 184);
			this->listbox3->TabIndex = 16;
			// 
			// ownerdashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(732, 407);
			this->Controls->Add(this->listbox3);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->datetime3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->prodval);
			this->Controls->Add(this->quantval);
			this->Controls->Add(this->filter);
			this->Controls->Add(this->sales);
			this->Controls->Add(this->addc);
			this->Controls->Add(this->edit);
			this->Controls->Add(this->del);
			this->Controls->Add(this->listbox1);
			this->Controls->Add(this->ownerinfo);
			this->Controls->Add(this->label1);
			this->Name = L"ownerdashboard";
			this->Text = L"ownerdashboard";
			this->Load += gcnew System::EventHandler(this, &ownerdashboard::ownerdashboard_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ownerdashboard_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void ownerinfo_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		//Deleting Product from Products table using Exception Handling

		try {
			String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
			SqlConnection sqlConn(conn);
			sqlConn.Open();


			String^ cur = listbox1->SelectedItem->ToString();

			String^ sqlQuery = "Delete from products where pname=@cur;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@cur", cur);
			SqlDataReader^ reader4 = command.ExecuteReader();
			reader4->Read();
			reader4->Close();
			MessageBox::Show("Deleted Successfully", "Invalid", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			Application::Restart();
		}
		catch (Exception^ e)
		{
			MessageBox::Show("Failed To Delete", "Invalid", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
			return;

		}

	}
private: System::Void listbox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

	
}
	   //Adding New Product and Quantity in The Table

	private: System::Void addc_Click(System::Object^ sender, System::EventArgs^ e) {
		try{
		String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
		SqlConnection sqlConn(conn);
		sqlConn.Open();



		String^ cname = this->prodval->Text;
		String^ pno = this->quantval->Text;

		String^ sqlQuery = "Insert into products (pname,quantity) values(@cname,@pno);";
		SqlCommand command(sqlQuery, % sqlConn);
		command.Parameters->AddWithValue("@cname", cname);
		command.Parameters->AddWithValue("@pno", pno);
		SqlDataReader^ reader4 = command.ExecuteReader();
		reader4->Read();
		reader4->Close();
		MessageBox::Show("Added Successfully", "Invalid", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		
		Application::Restart();
	}
	catch(Exception^ e)
	{
		MessageBox::Show("Failed To Add", "Invalid", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		return;

	}
	
}

		   //Editing the Quantity of an Existing Product
private: System::Void edit_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ cur2 = listbox1->SelectedItem->ToString();
	editproduct^ ep = gcnew editproduct(cur2); //Object of editproduct header file and calling its parameterised constructor
	ep->ShowDialog();

}

	   //Filtering The Sales Data Based On Selected dAte By The Owner

private: System::Void filter_Click(System::Object^ sender, System::EventArgs^ e) {

	String^ dateval = datetime3->Text;
	filtersales^ fs = gcnew filtersales(dateval); //Object of filtersales header file and calling its Parameterised constructor
	fs->ShowDialog();

}
};
}


