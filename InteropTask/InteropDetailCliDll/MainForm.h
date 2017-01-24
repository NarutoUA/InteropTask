#pragma once

namespace InteropDetailCliDll {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::GroupBox^  grpDetails;
	public: System::Windows::Forms::PictureBox^  picSkin;
	private:

	public: System::Windows::Forms::Label^  lblGenderA;
	private:

	private: System::Windows::Forms::Label^  lblGenderQ;
	public: System::Windows::Forms::Label^  lblLocationA;
	private:

	private: System::Windows::Forms::Label^  lblLocationQ;
	public: System::Windows::Forms::Label^  lblSkinTypeA;
	private:

	private: System::Windows::Forms::Label^  lblSkinTypeQ;
	public: System::Windows::Forms::Label^  lblSkinModelA;
	private:

	private: System::Windows::Forms::Label^  lblSkinNameQ;
	public: System::Windows::Forms::Label^  lblSkinIdA;
	private:

	private: System::Windows::Forms::Label^  lblSkinIdQ;
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
			this->grpDetails = (gcnew System::Windows::Forms::GroupBox());
			this->lblGenderA = (gcnew System::Windows::Forms::Label());
			this->lblGenderQ = (gcnew System::Windows::Forms::Label());
			this->lblLocationA = (gcnew System::Windows::Forms::Label());
			this->lblLocationQ = (gcnew System::Windows::Forms::Label());
			this->lblSkinTypeA = (gcnew System::Windows::Forms::Label());
			this->lblSkinTypeQ = (gcnew System::Windows::Forms::Label());
			this->lblSkinModelA = (gcnew System::Windows::Forms::Label());
			this->lblSkinNameQ = (gcnew System::Windows::Forms::Label());
			this->lblSkinIdA = (gcnew System::Windows::Forms::Label());
			this->lblSkinIdQ = (gcnew System::Windows::Forms::Label());
			this->picSkin = (gcnew System::Windows::Forms::PictureBox());
			this->grpDetails->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSkin))->BeginInit();
			this->SuspendLayout();
			// 
			// grpDetails
			// 
			this->grpDetails->Controls->Add(this->lblGenderA);
			this->grpDetails->Controls->Add(this->lblGenderQ);
			this->grpDetails->Controls->Add(this->lblLocationA);
			this->grpDetails->Controls->Add(this->lblLocationQ);
			this->grpDetails->Controls->Add(this->lblSkinTypeA);
			this->grpDetails->Controls->Add(this->lblSkinTypeQ);
			this->grpDetails->Controls->Add(this->lblSkinModelA);
			this->grpDetails->Controls->Add(this->lblSkinNameQ);
			this->grpDetails->Controls->Add(this->lblSkinIdA);
			this->grpDetails->Controls->Add(this->lblSkinIdQ);
			this->grpDetails->Location = System::Drawing::Point(167, 13);
			this->grpDetails->Name = L"grpDetails";
			this->grpDetails->Size = System::Drawing::Size(473, 407);
			this->grpDetails->TabIndex = 1;
			this->grpDetails->TabStop = false;
			// 
			// lblGenderA
			// 
			this->lblGenderA->AutoSize = true;
			this->lblGenderA->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblGenderA->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->lblGenderA->Location = System::Drawing::Point(7, 295);
			this->lblGenderA->Name = L"lblGenderA";
			this->lblGenderA->Size = System::Drawing::Size(106, 22);
			this->lblGenderA->TabIndex = 9;
			this->lblGenderA->Text = L"lblGenderA";
			// 
			// lblGenderQ
			// 
			this->lblGenderQ->AutoSize = true;
			this->lblGenderQ->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblGenderQ->Location = System::Drawing::Point(7, 271);
			this->lblGenderQ->Name = L"lblGenderQ";
			this->lblGenderQ->Size = System::Drawing::Size(91, 24);
			this->lblGenderQ->TabIndex = 8;
			this->lblGenderQ->Text = L"Gender:";
			// 
			// lblLocationA
			// 
			this->lblLocationA->AutoSize = true;
			this->lblLocationA->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblLocationA->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->lblLocationA->Location = System::Drawing::Point(7, 230);
			this->lblLocationA->Name = L"lblLocationA";
			this->lblLocationA->Size = System::Drawing::Size(114, 22);
			this->lblLocationA->TabIndex = 7;
			this->lblLocationA->Text = L"lblLocationA";
			// 
			// lblLocationQ
			// 
			this->lblLocationQ->AutoSize = true;
			this->lblLocationQ->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblLocationQ->Location = System::Drawing::Point(7, 206);
			this->lblLocationQ->Name = L"lblLocationQ";
			this->lblLocationQ->Size = System::Drawing::Size(234, 24);
			this->lblLocationQ->TabIndex = 6;
			this->lblLocationQ->Text = L"Singleplayer Location:";
			// 
			// lblSkinTypeA
			// 
			this->lblSkinTypeA->AutoSize = true;
			this->lblSkinTypeA->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblSkinTypeA->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->lblSkinTypeA->Location = System::Drawing::Point(7, 168);
			this->lblSkinTypeA->Name = L"lblSkinTypeA";
			this->lblSkinTypeA->Size = System::Drawing::Size(120, 22);
			this->lblSkinTypeA->TabIndex = 5;
			this->lblSkinTypeA->Text = L"lblSkinTypeA";
			// 
			// lblSkinTypeQ
			// 
			this->lblSkinTypeQ->AutoSize = true;
			this->lblSkinTypeQ->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblSkinTypeQ->Location = System::Drawing::Point(7, 144);
			this->lblSkinTypeQ->Name = L"lblSkinTypeQ";
			this->lblSkinTypeQ->Size = System::Drawing::Size(177, 24);
			this->lblSkinTypeQ->TabIndex = 4;
			this->lblSkinTypeQ->Text = L"Skin Name/Type:";
			// 
			// lblSkinModelA
			// 
			this->lblSkinModelA->AutoSize = true;
			this->lblSkinModelA->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblSkinModelA->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->lblSkinModelA->Location = System::Drawing::Point(7, 105);
			this->lblSkinModelA->Name = L"lblSkinModelA";
			this->lblSkinModelA->Size = System::Drawing::Size(130, 22);
			this->lblSkinModelA->TabIndex = 3;
			this->lblSkinModelA->Text = L"lblSkinModelA";
			// 
			// lblSkinNameQ
			// 
			this->lblSkinNameQ->AutoSize = true;
			this->lblSkinNameQ->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblSkinNameQ->Location = System::Drawing::Point(7, 81);
			this->lblSkinNameQ->Name = L"lblSkinNameQ";
			this->lblSkinNameQ->Size = System::Drawing::Size(190, 24);
			this->lblSkinNameQ->TabIndex = 2;
			this->lblSkinNameQ->Text = L"Skin Model Name:";
			// 
			// lblSkinIdA
			// 
			this->lblSkinIdA->AutoSize = true;
			this->lblSkinIdA->Font = (gcnew System::Drawing::Font(L"Arial", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblSkinIdA->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->lblSkinIdA->Location = System::Drawing::Point(7, 44);
			this->lblSkinIdA->Name = L"lblSkinIdA";
			this->lblSkinIdA->Size = System::Drawing::Size(95, 22);
			this->lblSkinIdA->TabIndex = 1;
			this->lblSkinIdA->Text = L"lblSkinIdA";
			// 
			// lblSkinIdQ
			// 
			this->lblSkinIdQ->AutoSize = true;
			this->lblSkinIdQ->Font = (gcnew System::Drawing::Font(L"Arial", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->lblSkinIdQ->Location = System::Drawing::Point(7, 20);
			this->lblSkinIdQ->Name = L"lblSkinIdQ";
			this->lblSkinIdQ->Size = System::Drawing::Size(87, 24);
			this->lblSkinIdQ->TabIndex = 0;
			this->lblSkinIdQ->Text = L"Skin ID:";
			// 
			// picSkin
			// 
			this->picSkin->Location = System::Drawing::Point(13, 13);
			this->picSkin->Name = L"picSkin";
			this->picSkin->Size = System::Drawing::Size(148, 408);
			this->picSkin->TabIndex = 2;
			this->picSkin->TabStop = false;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(649, 427);
			this->Controls->Add(this->picSkin);
			this->Controls->Add(this->grpDetails);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Managed Interop Details";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->grpDetails->ResumeLayout(false);
			this->grpDetails->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picSkin))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void MainForm_Load(System::Object^  sender, System::EventArgs^  e)
	{
				 
	}
};
}
