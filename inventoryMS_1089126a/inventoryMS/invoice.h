#pragma once

namespace inventoryMS {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	/// <summary>
	/// Summary for invoice
	/// </summary>
	public ref class invoice : public System::Windows::Forms::Form
	{
	public:
		invoice(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		//Parameterized Constructor for initializing the values of Invoice form data members

		invoice(String^ cname, String^ phno, String^ prod, String^ pay, String^ datetime2,String^ datetime3,String^ quan,String^ ttl)
		{
			InitializeComponent();
			//
			label6->Text = cname;
			label7->Text = phno;
			label8->Text = prod;
			label9->Text = quan;
			label13->Text = datetime2;
			label14->Text = pay;
			label15->Text = ttl;
			label16->Text = datetime3;
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~invoice()
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
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::Button^ print;

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
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->print = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(262, 19);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Invoice";
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(19, 90);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(164, 30);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Customer Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(219, 90);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(104, 20);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Contact No.";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(364, 90);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 20);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Product";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(521, 90);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(76, 20);
			this->label5->TabIndex = 4;
			this->label5->Text = L"Quantity";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(14, 149);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(57, 20);
			this->label6->TabIndex = 5;
			this->label6->Text = L"label6";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(219, 149);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(57, 20);
			this->label7->TabIndex = 6;
			this->label7->Text = L"label7";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(378, 149);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(57, 20);
			this->label8->TabIndex = 7;
			this->label8->Text = L"label8";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(540, 149);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(57, 20);
			this->label9->TabIndex = 8;
			this->label9->Text = L"label9";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(55, 242);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(91, 20);
			this->label10->TabIndex = 9;
			this->label10->Text = L"Date Time";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(244, 242);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(127, 20);
			this->label11->TabIndex = 10;
			this->label11->Text = L"Payment Mode";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(474, 242);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(104, 20);
			this->label12->TabIndex = 11;
			this->label12->Text = L"Grand Total";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(14, 299);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(67, 20);
			this->label13->TabIndex = 12;
			this->label13->Text = L"label13";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(272, 299);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(67, 20);
			this->label14->TabIndex = 13;
			this->label14->Text = L"label14";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(493, 299);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(67, 20);
			this->label15->TabIndex = 14;
			this->label15->Text = L"label15";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(116, 299);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(67, 20);
			this->label16->TabIndex = 15;
			this->label16->Text = L"label16";
			// 
			// print
			// 
			this->print->Location = System::Drawing::Point(455, 346);
			this->print->Name = L"print";
			this->print->Size = System::Drawing::Size(117, 36);
			this->print->TabIndex = 16;
			this->print->Text = L"Print Invoice";
			this->print->UseVisualStyleBackColor = true;
			this->print->Click += gcnew System::EventHandler(this, &invoice::print_Click);
			// 
			// invoice
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(660, 415);
			this->Controls->Add(this->print);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->label14);
			this->Controls->Add(this->label13);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->label11);
			this->Controls->Add(this->label10);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"invoice";
			this->Text = L"invoice";
			this->Load += gcnew System::EventHandler(this, &invoice::invoice_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void invoice_Load(System::Object^ sender, System::EventArgs^ e) {
	}

		   //Displaying the Final Invoice Data Before Printing
	private: System::Void print_Click(System::Object^ sender, System::EventArgs^ e) {

		StreamWriter^ pwriter = gcnew StreamWriter("Invoice.txt"); //Creating a new File Invoice.txt for respective output
		pwriter->Write("Customer Name : -" + label6->Text + " Phone Number :-" + label7->Text + " Product : -"
			+ label8->Text + " Quantity :- " + label9->Text + " Total :- " + label15->Text); //Writing the content to file using StreamWriter Object
		pwriter->Close(); //Closing the File
		MessageBox::Show("Invoice Printed as Output.txt ", "Success", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);


	}
};
}
