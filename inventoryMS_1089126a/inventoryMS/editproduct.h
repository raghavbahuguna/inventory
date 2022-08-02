#pragma once

namespace inventoryMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	/// <summary>
	/// Summary for editproduct
	/// </summary>
	public ref class editproduct : public System::Windows::Forms::Form
	{
	public:
		editproduct(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		editproduct(String^ data)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			String^ prod = data;
			label2->Text = prod;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~editproduct()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ editbox;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	protected:

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
			this->editbox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// editbox
			// 
			this->editbox->Location = System::Drawing::Point(54, 85);
			this->editbox->Name = L"editbox";
			this->editbox->Size = System::Drawing::Size(169, 20);
			this->editbox->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(97, 126);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(87, 44);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Edit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &editproduct::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(77, 34);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(117, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Enter the New Quantity";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(77, 63);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 3;
			// 
			// editproduct
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->editbox);
			this->Name = L"editproduct";
			this->Text = L"editproduct";
			this->Load += gcnew System::EventHandler(this, &editproduct::editproduct_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void editproduct_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		
		String^ num2 = editbox->Text;
		String^ prod2 = label2->Text;
		String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
		SqlConnection sqlConn(conn);
		sqlConn.Open();
		String^ sqlQuery2 = "update products set quantity=@num where pname=@prod;";
		SqlCommand command2(sqlQuery2, % sqlConn);
		command2.Parameters->AddWithValue("@num", num2);
		command2.Parameters->AddWithValue("@prod", prod2);
		SqlDataReader^ reader5 = command2.ExecuteReader();
		reader5->Read();

		reader5->Close();
		MessageBox::Show("Updated", "Success", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		
		Application::Restart();
	}
};
}
