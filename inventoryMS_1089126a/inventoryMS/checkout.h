#pragma once
#include "invoice.h"
namespace inventoryMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;
	using namespace System::Text::RegularExpressions;

	/// <summary>
	/// Summary for checkout
	/// </summary>
	public ref class checkout : public System::Windows::Forms::Form
	{
	public:
		checkout(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		checkout(String^ data,String^ data2)
		{
			InitializeComponent();
			//
			label10->Text = data;
			label11->Text = data2;
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~checkout()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ custname;
	private: System::Windows::Forms::TextBox^ phone;
	private: System::Windows::Forms::DateTimePicker^ datetime;
	private: System::Windows::Forms::ComboBox^ dropdown;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ price;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Button^ total;
	private: System::Windows::Forms::Button^ sale;
	private: System::Windows::Forms::DateTimePicker^ datetimet;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->custname = (gcnew System::Windows::Forms::TextBox());
			this->phone = (gcnew System::Windows::Forms::TextBox());
			this->datetime = (gcnew System::Windows::Forms::DateTimePicker());
			this->dropdown = (gcnew System::Windows::Forms::ComboBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->price = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->total = (gcnew System::Windows::Forms::Button());
			this->sale = (gcnew System::Windows::Forms::Button());
			this->datetimet = (gcnew System::Windows::Forms::DateTimePicker());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Sitka Heading", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(283, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 28);
			this->label1->TabIndex = 0;
			this->label1->Text = L"CHECKOUT";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(72, 89);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(214, 88);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Phone Number";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(357, 87);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(87, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Payment Method";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(493, 89);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(77, 13);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Date and Time";
			// 
			// custname
			// 
			this->custname->Location = System::Drawing::Point(49, 116);
			this->custname->Name = L"custname";
			this->custname->Size = System::Drawing::Size(116, 20);
			this->custname->TabIndex = 5;
			// 
			// phone
			// 
			this->phone->Location = System::Drawing::Point(197, 117);
			this->phone->Name = L"phone";
			this->phone->Size = System::Drawing::Size(109, 20);
			this->phone->TabIndex = 6;
			// 
			// datetime
			// 
			this->datetime->CustomFormat = L"dd-MM-yyyy";
			this->datetime->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->datetime->Location = System::Drawing::Point(478, 117);
			this->datetime->Name = L"datetime";
			this->datetime->Size = System::Drawing::Size(118, 20);
			this->datetime->TabIndex = 7;
			this->datetime->Value = System::DateTime(2022, 7, 30, 0, 0, 0, 0);
			// 
			// dropdown
			// 
			this->dropdown->FormattingEnabled = true;
			this->dropdown->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Cash" });
			this->dropdown->Location = System::Drawing::Point(349, 116);
			this->dropdown->Name = L"dropdown";
			this->dropdown->Size = System::Drawing::Size(95, 21);
			this->dropdown->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(72, 193);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(44, 13);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Product";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(226, 193);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 13);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Quantity";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(357, 193);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(89, 13);
			this->label8->TabIndex = 11;
			this->label8->Text = L"Price per Product";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(72, 310);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(31, 13);
			this->label9->TabIndex = 12;
			this->label9->Text = L"Total";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(61, 225);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 13);
			this->label10->TabIndex = 13;
			this->label10->Text = L"label10";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(220, 224);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(41, 13);
			this->label11->TabIndex = 14;
			this->label11->Text = L"label11";
			// 
			// price
			// 
			this->price->Location = System::Drawing::Point(351, 219);
			this->price->Name = L"price";
			this->price->Size = System::Drawing::Size(92, 20);
			this->price->TabIndex = 15;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(66, 352);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(41, 13);
			this->label12->TabIndex = 16;
			this->label12->Text = L"label12";
			// 
			// total
			// 
			this->total->Location = System::Drawing::Point(478, 215);
			this->total->Name = L"total";
			this->total->Size = System::Drawing::Size(112, 23);
			this->total->TabIndex = 17;
			this->total->Text = L"Calculate Total";
			this->total->UseVisualStyleBackColor = true;
			this->total->Click += gcnew System::EventHandler(this, &checkout::total_Click);
			// 
			// sale
			// 
			this->sale->Location = System::Drawing::Point(274, 310);
			this->sale->Name = L"sale";
			this->sale->Size = System::Drawing::Size(137, 66);
			this->sale->TabIndex = 18;
			this->sale->Text = L"Confirm Sale";
			this->sale->UseVisualStyleBackColor = true;
			this->sale->Click += gcnew System::EventHandler(this, &checkout::sale_Click);
			// 
			// datetimet
			// 
			this->datetimet->CustomFormat = L"HH:mm:ss";
			this->datetimet->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->datetimet->Location = System::Drawing::Point(478, 143);
			this->datetimet->Name = L"datetimet";
			this->datetimet->Size = System::Drawing::Size(118, 20);
			this->datetimet->TabIndex = 19;
			this->datetimet->Value = System::DateTime(2022, 7, 30, 9, 4, 50, 0);
			// 
			// checkout
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(677, 397);
			this->Controls->Add(this->datetimet);
			this->Controls->Add(this->sale);
			this->Controls->Add(this->total);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->price);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->dropdown);
			this->Controls->Add(this->datetime);
			this->Controls->Add(this->phone);
			this->Controls->Add(this->custname);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"checkout";
			this->Text = L"checkout";
			this->Load += gcnew System::EventHandler(this, &checkout::checkout_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void checkout_Load(System::Object^ sender, System::EventArgs^ e) {
	}
 public:int tot=0,num,num2;

	   //Calculating Final Checkout Value
private: System::Void total_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ price = this->price->Text; //taking price input
	String^ quan = this->label11->Text;
	num = System::Convert::ToInt32(price);//type casting string to integer
	num2 = System::Convert::ToInt32(quan);
	tot = num * num2;
	label12->Text = System::Convert::ToString(tot);//type casting int to string
}
	private: System::Void sale_Click(System::Object^ sender, System::EventArgs^ e) {


		String^ conn = "Data Source=MEDGE144;Initial Catalog=inventory;Persist Security Info=True;User ID=sa;Password=pass@word1";
		SqlConnection sqlConn(conn);
		sqlConn.Open();
		
		//Using Exception handling to Validate Name Phone Number and Total

		try
		{

		String^ cname = this->custname->Text;
		String^ pno = this->phone->Text;
		String^ prod = this->label10->Text;
		String^ quan = this->label11->Text;
		String^ payment = this->dropdown->SelectedItem->ToString();
		String^ datetime2 = this->datetime->Text;
		String^ datetime3 = this->datetimet->Text;

		Regex^ reg = gcnew Regex("^[A-Z][a-zA-Z ]*$"); //Validate Name using Regex
		
			if (reg->IsMatch(cname))
			{

				Regex^ r = gcnew Regex("^[0-9]{10}$"); //Validate Number using
				if (r->IsMatch(pno))
				{
					if (tot != 0) //Checking if total is calculated
					{

						String^ sqlQuery = "Insert into sales (custname,phone,payment,date,time,product,quantity,total) values(@cname,@pno,@payment,@datetime2,@datetime3,@prod,@num,@tot);";
						SqlCommand command(sqlQuery, % sqlConn);
						command.Parameters->AddWithValue("@cname", cname);
						command.Parameters->AddWithValue("@pno", pno);
						command.Parameters->AddWithValue("@prod", prod);
						command.Parameters->AddWithValue("@payment", payment);
						command.Parameters->AddWithValue("@datetime2", datetime2);
						command.Parameters->AddWithValue("@datetime3", datetime3);
						command.Parameters->AddWithValue("@num", num2);
						command.Parameters->AddWithValue("@tot", tot);
						SqlDataReader^ reader4 = command.ExecuteReader();
						reader4->Read();

						reader4->Close();

						String^ sqlQuery2 = "update products set quantity=quantity-@num where pname=@prod;"; //Updating quantity of Product once sale is made
						SqlCommand command2(sqlQuery2, % sqlConn);
						command2.Parameters->AddWithValue("@num", num2);
						command2.Parameters->AddWithValue("@prod", prod);
						SqlDataReader^ reader5 = command2.ExecuteReader();
						reader5->Read();

						reader5->Close();

						//Printing the invoice data 

						invoice^ inv = gcnew invoice(cname, pno, prod, payment, datetime2, datetime3, label11->Text, label12->Text); 
						inv->ShowDialog();
					}
					else
					{
						MessageBox::Show("Invalid Total", "Invalid", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
						return;

					}


				}
				else
				{
					MessageBox::Show("Invalid Contact Number", "Invalid", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
					return;
				}
			}
			else
			{
				MessageBox::Show("Invalid Name", "Invalid", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
				return;
			}






		}
		catch (Exception^ ep)
		{
			MessageBox::Show("Invalid  Entry Of Data", "Invalid", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);

		}

	}
};
}
