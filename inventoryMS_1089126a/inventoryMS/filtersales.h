#pragma once
#include "Sales.h"
#include "invoices.h"
namespace inventoryMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for filtersales
	/// </summary>
	public ref class filtersales : public System::Windows::Forms::Form
	{
	public:Sales^ pro = nullptr;
	private: System::Windows::Forms::ListBox^ listbox1;
	private: System::Windows::Forms::ListBox^ listbox2;
	private: System::Windows::Forms::ListBox^ listbox3;
	private: System::Windows::Forms::ListBox^ listbox4;
	public:

	public:



	public:invoices^ invo = nullptr;
	public:
		filtersales(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		filtersales(String^ data)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			label2->Text = data;

			String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
			SqlConnection sqlConn(conn);
			sqlConn.Open();
			static int n;
			int idd = 1;
			String^ sqlQuery = "select count(*) from sales where date=@dateval;";
			SqlCommand command(sqlQuery, % sqlConn);
			command.Parameters->AddWithValue("@dateval", data);
			SqlDataReader^ reader4 = command.ExecuteReader();
			
			while (reader4->Read()) {
				n = reader4->GetInt32(0);

			}

			reader4->Close();

			while (idd <= n)
			{

				String^ sqlQuery = "Select * from sales where date=@dateval and id=@idd;";
				SqlCommand command(sqlQuery, % sqlConn);
				command.Parameters->AddWithValue("@dateval", data);
				command.Parameters->AddWithValue("@idd", idd);

				SqlDataReader^ reader = command.ExecuteReader();
				if (reader->Read()) {
					pro = gcnew Sales;
					pro->id = reader->GetInt32(0);
					pro->custname = reader->GetString(1);
					pro->phone = reader->GetString(2);
						pro->payment = reader->GetString(3);
						pro->date = reader->GetString(4);
						pro->time = reader->GetString(5);
						pro->product = reader->GetString(6);
						pro->quantity = reader->GetInt32(7);
						pro->total = reader->GetInt32(8);



					listbox->Items->Add(pro->custname);
					listbox1->Items->Add(pro->phone);
					listbox2->Items->Add(pro->product);
					listbox3->Items->Add(pro->quantity);
					listbox4->Items->Add(pro->total);
					

				}
				else
				{
					n = n + 1;
				}
				reader->Close();
				idd++;

			}
		}
		
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~filtersales()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listbox;
	protected:
	private: System::Windows::Forms::Button^ invoice;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;

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
			this->listbox = (gcnew System::Windows::Forms::ListBox());
			this->invoice = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->listbox1 = (gcnew System::Windows::Forms::ListBox());
			this->listbox2 = (gcnew System::Windows::Forms::ListBox());
			this->listbox3 = (gcnew System::Windows::Forms::ListBox());
			this->listbox4 = (gcnew System::Windows::Forms::ListBox());
			this->SuspendLayout();
			// 
			// listbox
			// 
			this->listbox->FormattingEnabled = true;
			this->listbox->Location = System::Drawing::Point(66, 68);
			this->listbox->Name = L"listbox";
			this->listbox->Size = System::Drawing::Size(108, 251);
			this->listbox->TabIndex = 0;
			// 
			// invoice
			// 
			this->invoice->Location = System::Drawing::Point(408, 331);
			this->invoice->Name = L"invoice";
			this->invoice->Size = System::Drawing::Size(128, 23);
			this->invoice->TabIndex = 1;
			this->invoice->Text = L"See Invoice";
			this->invoice->UseVisualStyleBackColor = true;
			this->invoice->Click += gcnew System::EventHandler(this, &filtersales::invoice_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(89, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Sales  On Date :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(213, 30);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 3;
			// 
			// listbox1
			// 
			this->listbox1->FormattingEnabled = true;
			this->listbox1->Location = System::Drawing::Point(180, 68);
			this->listbox1->Name = L"listbox1";
			this->listbox1->Size = System::Drawing::Size(108, 251);
			this->listbox1->TabIndex = 4;
			// 
			// listbox2
			// 
			this->listbox2->FormattingEnabled = true;
			this->listbox2->Location = System::Drawing::Point(294, 68);
			this->listbox2->Name = L"listbox2";
			this->listbox2->Size = System::Drawing::Size(108, 251);
			this->listbox2->TabIndex = 5;
			// 
			// listbox3
			// 
			this->listbox3->FormattingEnabled = true;
			this->listbox3->Location = System::Drawing::Point(408, 68);
			this->listbox3->Name = L"listbox3";
			this->listbox3->Size = System::Drawing::Size(108, 251);
			this->listbox3->TabIndex = 6;
			// 
			// listbox4
			// 
			this->listbox4->FormattingEnabled = true;
			this->listbox4->Location = System::Drawing::Point(524, 68);
			this->listbox4->Name = L"listbox4";
			this->listbox4->Size = System::Drawing::Size(108, 251);
			this->listbox4->TabIndex = 7;
			// 
			// filtersales
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(644, 363);
			this->Controls->Add(this->listbox4);
			this->Controls->Add(this->listbox3);
			this->Controls->Add(this->listbox2);
			this->Controls->Add(this->listbox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->invoice);
			this->Controls->Add(this->listbox);
			this->Name = L"filtersales";
			this->Text = L"filtersales";
			this->Load += gcnew System::EventHandler(this, &filtersales::filtersales_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void filtersales_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void invoice_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
		SqlConnection sqlConn(conn);
		sqlConn.Open();

		String^ curItem = listbox->SelectedItem->ToString();

		String^ sqlQuery2 = "select * from sales where custname=@curItem;";
		SqlCommand command2(sqlQuery2, % sqlConn);
		command2.Parameters->AddWithValue("@curItem", curItem);
		SqlDataReader^ reader5 = command2.ExecuteReader();
		if (reader5->Read())
		{
			pro->id = reader5->GetInt32(0);
			pro->custname = reader5->GetString(1);
			pro->phone = reader5->GetString(2);
			pro->payment = reader5->GetString(3);
			pro->date = reader5->GetString(4);
			pro->time = reader5->GetString(5);
			pro->product = reader5->GetString(6);
			pro->quantity = reader5->GetInt32(7);
			pro->total = reader5->GetInt32(8);
		}

		

		invo= gcnew invoices(pro->custname,pro->phone, pro->product, pro->payment, pro->date, pro->time, pro->quantity, pro->total);
		invo->ShowDialog();
		reader5->Close();
	}
};
}
