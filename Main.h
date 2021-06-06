#pragma once
#include "About.h"
#include <String>
#include <list>
#include<iostream>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <fstream>
#include <list> 
#include "core.h"

using namespace std;

namespace textEditor
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for Main
	/// </summary>
	/// 
	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		//Logical fields
		bool updating = false;
		String^ fileName;

	private: System::Windows::Forms::ToolStripMenuItem^ findAllToolStripMenuItem1;
	private: System::Windows::Forms::ListBox^ textBox;
	private: System::Windows::Forms::TextBox^ readonlyBox;
	private: System::Windows::Forms::Button^ btnUpdate;
	private: System::Windows::Forms::Button^ btnDelete;


	public:
		bool PreviouslyOpened = false;

		Main(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			fileName = Application::StartupPath + "\\file.txt";
			
		}

	private: void  fromList(ListBox^ box,list<string> linkedList) {
	
		box->Items->Clear();
		list<string>::iterator it;

		for (auto it : linkedList) {
			String^ it_ptr = gcnew String(it.c_str());
			box->Items->Add(it_ptr);
		}

	}
	
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ boxFind;
	private: System::Windows::Forms::Button^ btnFindAll;
	private: System::Windows::Forms::Button^ btnReplace;
	protected:

	protected:


#pragma region controls decleration



	private: System::Windows::Forms::TextBox^ boxReplace;


	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton1;
	private: System::Windows::Forms::Button^ btnInsertUpdate;

	private: System::Windows::Forms::TextBox^ boxInsertUpdate;




	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ saveToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ saveAsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ closeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exitToolStripMenuItem;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton2;
	private: System::Windows::Forms::ToolStripMenuItem^ undoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ redoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ findAllToolStripMenuItem;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton3;
	private: System::Windows::Forms::ToolStripMenuItem^ statusBarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripDropDownButton^ toolStripDropDownButton4;
	private: System::Windows::Forms::ToolStripMenuItem^ viewHelpToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ aboutToolStripMenuItem;
#pragma endregion

	
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->boxFind = (gcnew System::Windows::Forms::TextBox());
			this->btnFindAll = (gcnew System::Windows::Forms::Button());
			this->btnReplace = (gcnew System::Windows::Forms::Button());
			this->boxReplace = (gcnew System::Windows::Forms::TextBox());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripDropDownButton1 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->saveAsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->closeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exitToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripDropDownButton2 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->undoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->redoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findAllToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->findAllToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripDropDownButton3 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->statusBarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripDropDownButton4 = (gcnew System::Windows::Forms::ToolStripDropDownButton());
			this->viewHelpToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aboutToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->btnInsertUpdate = (gcnew System::Windows::Forms::Button());
			this->boxInsertUpdate = (gcnew System::Windows::Forms::TextBox());
			this->textBox = (gcnew System::Windows::Forms::ListBox());
			this->readonlyBox = (gcnew System::Windows::Forms::TextBox());
			this->btnUpdate = (gcnew System::Windows::Forms::Button());
			this->btnDelete = (gcnew System::Windows::Forms::Button());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// boxFind
			// 
			this->boxFind->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->boxFind->Location = System::Drawing::Point(11, 48);
			this->boxFind->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->boxFind->Name = L"boxFind";
			this->boxFind->Size = System::Drawing::Size(172, 30);
			this->boxFind->TabIndex = 3;
			this->boxFind->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Main::boxFind_KeyDown);
			// 
			// btnFindAll
			// 
			this->btnFindAll->BackColor = System::Drawing::SystemColors::Control;
			this->btnFindAll->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->btnFindAll->Location = System::Drawing::Point(188, 47);
			this->btnFindAll->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnFindAll->Name = L"btnFindAll";
			this->btnFindAll->Size = System::Drawing::Size(75, 32);
			this->btnFindAll->TabIndex = 4;
			this->btnFindAll->Text = L"Find all";
			this->btnFindAll->UseVisualStyleBackColor = false;
			this->btnFindAll->Click += gcnew System::EventHandler(this, &Main::btnFindAll_Click);
			// 
			// btnReplace
			// 
			this->btnReplace->BackColor = System::Drawing::SystemColors::Control;
			this->btnReplace->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->btnReplace->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->btnReplace->Location = System::Drawing::Point(448, 47);
			this->btnReplace->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnReplace->Name = L"btnReplace";
			this->btnReplace->Size = System::Drawing::Size(99, 31);
			this->btnReplace->TabIndex = 6;
			this->btnReplace->Text = L"Replace all";
			this->btnReplace->UseVisualStyleBackColor = false;
			this->btnReplace->Click += gcnew System::EventHandler(this, &Main::btnReplace_Click);
			// 
			// boxReplace
			// 
			this->boxReplace->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::Suggest;
			this->boxReplace->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::RecentlyUsedList;
			this->boxReplace->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->boxReplace->Location = System::Drawing::Point(269, 48);
			this->boxReplace->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->boxReplace->Name = L"boxReplace";
			this->boxReplace->Size = System::Drawing::Size(172, 30);
			this->boxReplace->TabIndex = 5;
			// 
			// toolStrip1
			// 
			this->toolStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->toolStripDropDownButton1,
					this->toolStripDropDownButton2, this->toolStripDropDownButton3, this->toolStripDropDownButton4
			});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(977, 27);
			this->toolStrip1->TabIndex = 7;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripDropDownButton1
			// 
			this->toolStripDropDownButton1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->openToolStripMenuItem,
					this->saveToolStripMenuItem, this->saveAsToolStripMenuItem, this->closeToolStripMenuItem, this->exitToolStripMenuItem
			});
			this->toolStripDropDownButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton1.Image")));
			this->toolStripDropDownButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton1->Name = L"toolStripDropDownButton1";
			this->toolStripDropDownButton1->Size = System::Drawing::Size(66, 24);
			this->toolStripDropDownButton1->Text = L"File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"openToolStripMenuItem.Image")));
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::O));
			this->openToolStripMenuItem->Size = System::Drawing::Size(231, 26);
			this->openToolStripMenuItem->Text = L"Open";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::openToolStripMenuItem_Click);
			// 
			// saveToolStripMenuItem
			// 
			this->saveToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveToolStripMenuItem.Image")));
			this->saveToolStripMenuItem->Name = L"saveToolStripMenuItem";
			this->saveToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::S));
			this->saveToolStripMenuItem->Size = System::Drawing::Size(231, 26);
			this->saveToolStripMenuItem->Text = L"Save";
			this->saveToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::saveToolStripMenuItem_Click);
			// 
			// saveAsToolStripMenuItem
			// 
			this->saveAsToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"saveAsToolStripMenuItem.Image")));
			this->saveAsToolStripMenuItem->Name = L"saveAsToolStripMenuItem";
			this->saveAsToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::S));
			this->saveAsToolStripMenuItem->Size = System::Drawing::Size(231, 26);
			this->saveAsToolStripMenuItem->Text = L"Save as";
			this->saveAsToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::saveAsToolStripMenuItem_Click);
			// 
			// closeToolStripMenuItem
			// 
			this->closeToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"closeToolStripMenuItem.Image")));
			this->closeToolStripMenuItem->Name = L"closeToolStripMenuItem";
			this->closeToolStripMenuItem->Size = System::Drawing::Size(231, 26);
			this->closeToolStripMenuItem->Text = L"Close";
			// 
			// exitToolStripMenuItem
			// 
			this->exitToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"exitToolStripMenuItem.Image")));
			this->exitToolStripMenuItem->Name = L"exitToolStripMenuItem";
			this->exitToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::W));
			this->exitToolStripMenuItem->Size = System::Drawing::Size(231, 26);
			this->exitToolStripMenuItem->Text = L"Exit";
			this->exitToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::exitToolStripMenuItem_Click);
			// 
			// toolStripDropDownButton2
			// 
			this->toolStripDropDownButton2->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->undoToolStripMenuItem,
					this->redoToolStripMenuItem, this->findAllToolStripMenuItem, this->findAllToolStripMenuItem1
			});
			this->toolStripDropDownButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton2.Image")));
			this->toolStripDropDownButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton2->Name = L"toolStripDropDownButton2";
			this->toolStripDropDownButton2->Size = System::Drawing::Size(69, 24);
			this->toolStripDropDownButton2->Text = L"Edit";
			// 
			// undoToolStripMenuItem
			// 
			this->undoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"undoToolStripMenuItem.Image")));
			this->undoToolStripMenuItem->Name = L"undoToolStripMenuItem";
			this->undoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z));
			this->undoToolStripMenuItem->Size = System::Drawing::Size(229, 26);
			this->undoToolStripMenuItem->Text = L"Undo";
			// 
			// redoToolStripMenuItem
			// 
			this->redoToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"redoToolStripMenuItem.Image")));
			this->redoToolStripMenuItem->Name = L"redoToolStripMenuItem";
			this->redoToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->redoToolStripMenuItem->Size = System::Drawing::Size(229, 26);
			this->redoToolStripMenuItem->Text = L"Redo";
			// 
			// findAllToolStripMenuItem
			// 
			this->findAllToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"findAllToolStripMenuItem.Image")));
			this->findAllToolStripMenuItem->Name = L"findAllToolStripMenuItem";
			this->findAllToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F));
			this->findAllToolStripMenuItem->Size = System::Drawing::Size(229, 26);
			this->findAllToolStripMenuItem->Text = L"Find";
			this->findAllToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::findAllToolStripMenuItem_Click);
			// 
			// findAllToolStripMenuItem1
			// 
			this->findAllToolStripMenuItem1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"findAllToolStripMenuItem1.Image")));
			this->findAllToolStripMenuItem1->Name = L"findAllToolStripMenuItem1";
			this->findAllToolStripMenuItem1->ShortcutKeys = static_cast<System::Windows::Forms::Keys>(((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Shift)
				| System::Windows::Forms::Keys::F));
			this->findAllToolStripMenuItem1->Size = System::Drawing::Size(229, 26);
			this->findAllToolStripMenuItem1->Text = L"Find all";
			this->findAllToolStripMenuItem1->Click += gcnew System::EventHandler(this, &Main::findAllToolStripMenuItem1_Click);
			// 
			// toolStripDropDownButton3
			// 
			this->toolStripDropDownButton3->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->statusBarToolStripMenuItem });
			this->toolStripDropDownButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton3.Image")));
			this->toolStripDropDownButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton3->Name = L"toolStripDropDownButton3";
			this->toolStripDropDownButton3->Size = System::Drawing::Size(75, 24);
			this->toolStripDropDownButton3->Text = L"View";
			// 
			// statusBarToolStripMenuItem
			// 
			this->statusBarToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"statusBarToolStripMenuItem.Image")));
			this->statusBarToolStripMenuItem->Name = L"statusBarToolStripMenuItem";
			this->statusBarToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V));
			this->statusBarToolStripMenuItem->Size = System::Drawing::Size(209, 26);
			this->statusBarToolStripMenuItem->Text = L"Status bar";
			// 
			// toolStripDropDownButton4
			// 
			this->toolStripDropDownButton4->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->viewHelpToolStripMenuItem,
					this->aboutToolStripMenuItem
			});
			this->toolStripDropDownButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripDropDownButton4.Image")));
			this->toolStripDropDownButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripDropDownButton4->Name = L"toolStripDropDownButton4";
			this->toolStripDropDownButton4->Size = System::Drawing::Size(89, 24);
			this->toolStripDropDownButton4->Text = L"Credits";
			// 
			// viewHelpToolStripMenuItem
			// 
			this->viewHelpToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"viewHelpToolStripMenuItem.Image")));
			this->viewHelpToolStripMenuItem->Name = L"viewHelpToolStripMenuItem";
			this->viewHelpToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::H));
			this->viewHelpToolStripMenuItem->Size = System::Drawing::Size(210, 26);
			this->viewHelpToolStripMenuItem->Text = L"View help";
			// 
			// aboutToolStripMenuItem
			// 
			this->aboutToolStripMenuItem->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"aboutToolStripMenuItem.Image")));
			this->aboutToolStripMenuItem->Name = L"aboutToolStripMenuItem";
			this->aboutToolStripMenuItem->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::U));
			this->aboutToolStripMenuItem->Size = System::Drawing::Size(210, 26);
			this->aboutToolStripMenuItem->Text = L"About";
			this->aboutToolStripMenuItem->Click += gcnew System::EventHandler(this, &Main::aboutToolStripMenuItem_Click);
			// 
			// btnInsertUpdate
			// 
			this->btnInsertUpdate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnInsertUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->btnInsertUpdate->Location = System::Drawing::Point(876, 599);
			this->btnInsertUpdate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnInsertUpdate->Name = L"btnInsertUpdate";
			this->btnInsertUpdate->Size = System::Drawing::Size(89, 32);
			this->btnInsertUpdate->TabIndex = 13;
			this->btnInsertUpdate->Text = L"Append";
			this->btnInsertUpdate->UseVisualStyleBackColor = true;
			this->btnInsertUpdate->Click += gcnew System::EventHandler(this, &Main::insertUpdate_Click);
			// 
			// boxInsertUpdate
			// 
			this->boxInsertUpdate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->boxInsertUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->boxInsertUpdate->Location = System::Drawing::Point(11, 601);
			this->boxInsertUpdate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->boxInsertUpdate->Name = L"boxInsertUpdate";
			this->boxInsertUpdate->Size = System::Drawing::Size(860, 30);
			this->boxInsertUpdate->TabIndex = 12;
			this->boxInsertUpdate->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Main::boxInsertUpdate_KeyDown);
			// 
			// textBox
			// 
			this->textBox->FormattingEnabled = true;
			this->textBox->ItemHeight = 16;
			this->textBox->Location = System::Drawing::Point(11, 89);
			this->textBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBox->Name = L"textBox";
			this->textBox->Size = System::Drawing::Size(955, 500);
			this->textBox->TabIndex = 14;
			this->textBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Main::listBox1_SelectedIndexChanged);
			// 
			// readonlyBox
			// 
			this->readonlyBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->readonlyBox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->readonlyBox->Location = System::Drawing::Point(11, 89);
			this->readonlyBox->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->readonlyBox->Multiline = true;
			this->readonlyBox->Name = L"readonlyBox";
			this->readonlyBox->ReadOnly = true;
			this->readonlyBox->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->readonlyBox->Size = System::Drawing::Size(955, 504);
			this->readonlyBox->TabIndex = 11;
			// 
			// btnUpdate
			// 
			this->btnUpdate->BackColor = System::Drawing::SystemColors::Control;
			this->btnUpdate->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->btnUpdate->Location = System::Drawing::Point(873, 48);
			this->btnUpdate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnUpdate->Name = L"btnUpdate";
			this->btnUpdate->Size = System::Drawing::Size(89, 31);
			this->btnUpdate->TabIndex = 15;
			this->btnUpdate->Text = L"Update";
			this->btnUpdate->UseVisualStyleBackColor = false;
			this->btnUpdate->Click += gcnew System::EventHandler(this, &Main::btnUpdate_Click);
			// 
			// btnDelete
			// 
			this->btnDelete->BackColor = System::Drawing::SystemColors::Control;
			this->btnDelete->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
			this->btnDelete->Location = System::Drawing::Point(781, 48);
			this->btnDelete->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnDelete->Name = L"btnDelete";
			this->btnDelete->Size = System::Drawing::Size(75, 31);
			this->btnDelete->TabIndex = 16;
			this->btnDelete->Text = L"Delete";
			this->btnDelete->UseVisualStyleBackColor = false;
			this->btnDelete->Click += gcnew System::EventHandler(this, &Main::btnDelete_Click);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(977, 642);
			this->Controls->Add(this->btnDelete);
			this->Controls->Add(this->btnUpdate);
			this->Controls->Add(this->textBox);
			this->Controls->Add(this->btnInsertUpdate);
			this->Controls->Add(this->boxInsertUpdate);
			this->Controls->Add(this->readonlyBox);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->btnReplace);
			this->Controls->Add(this->boxReplace);
			this->Controls->Add(this->btnFindAll);
			this->Controls->Add(this->boxFind);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"Main";
			this->Text = L"Text Editor";
			this->Activated += gcnew System::EventHandler(this, &Main::Main_Load);
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		
private: string showSaveDialog() {
	SaveFileDialog dialog;
	dialog.InitialDirectory = Application::StartupPath;
	dialog.Title = "Save Text File";
	dialog.DefaultExt = "txt";
	dialog.Filter =
		"Text files (*.txt)|*.txt|All files (*.*)|*.*";
	dialog.ShowDialog();

	MessageBox::Show(dialog.FileName);
	return core::convertToString(dialog.FileName);
}

private: string showOpenDialog() {
	OpenFileDialog dialog;
	dialog.InitialDirectory = "C:\\";
	dialog.Filter =
		"Text files (*.txt)|*.txt|All files (*.*)|*.*";
	dialog.ShowDialog();
	dialog.Title = "Open Text File";
	
	return core::convertToString(dialog.FileName);
}

private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	//taking filepath 
	std::string filename_st = core::convertToString(fileName);
	filename_st = showOpenDialog();

	list<string>temp = core::fromListBox(textBox);
	/*mark file as previously opened 
	  if dialog return actual filename*/
	if (filename_st != "") {

		PreviouslyOpened = true;
		//adding loaded data to a list 
		temp = core::read(filename_st, temp);
		//add list(linked list) to listbox in gui
		fromList(textBox,temp);
	}

}

private: System::Void saveToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

	std::string filename_st = core::convertToString(fileName);
	string savePath = "";
	list<string>temp = core::fromListBox(textBox);

	if (PreviouslyOpened)					//no dialog
		savePath = filename_st;
	else                                   //show dialog
		savePath = showSaveDialog();

	core::write( savePath,temp);
	MessageBox::Show("file saved", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
}


private: System::Void saveAsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {	
	list<string>temp = core::fromListBox(textBox);
	core::write(showSaveDialog(),temp);
}

private: System::Void exitToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}

private: System::Void textBox1_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}



private: System::Void insertUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
	//
	list<string>temp = core::fromListBox(textBox);
	string line = core::convertToString(boxInsertUpdate->Text);
	int selectedLine;
	if (textBox->SelectedIndex>=0)
		selectedLine = textBox->SelectedIndex;
	else
		selectedLine = textBox->Items->Count;
	
	if (updating) {
		temp=core::insert(selectedLine, line, temp);

		fromList(textBox,temp);

		updating = false;
		btnInsertUpdate->Text = "Append";
		boxInsertUpdate->Text = "";
	}
	else
	{
		temp=core::insert(selectedLine, line, temp);
		fromList(textBox, temp);
		updating = false;
		btnInsertUpdate->Text = "Append";
		boxInsertUpdate->Text = "";

	}
}
private: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
	boxInsertUpdate->Focus();
}
private: System::Void aboutToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	About^ about = gcnew About();
	about->ShowInTaskbar = false;
	about->ShowDialog();
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	updating = true;
	btnInsertUpdate->Text = "Insert";
	if (textBox->SelectionMode==SelectionMode::One) 
		MessageBox::Show("You have selected line number "+textBox->GetItemText(textBox->SelectedIndex));
	
}

private: System::Void boxInsertUpdate_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue==(int)Keys::Return)
		 btnInsertUpdate->PerformClick();
}


private: System::Void btnDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	list<string>temp = core::fromListBox(textBox);
	//handling nonselection delete
	int lineSelected;
	if (!temp.empty()) {
		if (textBox->SelectedIndex >= 0)
			lineSelected = textBox->SelectedIndex;
		else
			lineSelected = textBox->Items->Count - 1;
	
		temp=core::Delete(lineSelected,temp);
	
		MessageBox::Show("You have deleted line number " + lineSelected);
		fromList(textBox,temp);
	}
	else
	{
		MessageBox::Show("the list is already empty !");
	}
	updating = false;
}

private: System::Void btnUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
	list<string>temp = core::fromListBox(textBox);
	int lineSelected;
	if (!temp.empty()) {
		string lineUpdate = core::convertToString(boxInsertUpdate->Text);
		if (textBox->SelectedIndex >= 0)
			lineSelected = textBox->SelectedIndex;
		else
			lineSelected = textBox->Items->Count - 1;

		temp = core::update(lineSelected,lineUpdate, temp);
		
		updating = false;
		fromList(textBox, temp);
		boxInsertUpdate->Text = "";
	}
	else
	{
		MessageBox::Show("the list is already empty !");
	}
}
private: System::Void btnFindAll_Click(System::Object^ sender, System::EventArgs^ e) {
	list<string>temp = core::fromListBox(textBox);
	string findst = core::convertToString(boxFind->Text);
	if (findst!="") {
		textBox->SelectionMode= SelectionMode::MultiExtended;
		list<int>foundlist=core::FindAll(findst,temp);
		for (auto it:foundlist)
		{
			textBox->SetSelected(it, true);
		}
	}
	else
	{
		MessageBox::Show("there is now word to find !");
	}
}
private: System::Void boxFind_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyValue == (int)Keys::Return)
		btnFindAll->PerformClick();
}

private: System::Void findAllToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	list<string>temp = core::fromListBox(textBox);
	string findst = core::convertToString(boxFind->Text);
	textBox->SelectionMode = SelectionMode::One;
	int foundLine;
	foundLine = core::find(findst, temp);
	textBox->SelectedIndex = foundLine;
}
private: System::Void btnReplace_Click(System::Object^ sender, System::EventArgs^ e) {
	list<string>temp = core::fromListBox(textBox);
	string findst = core::convertToString(boxFind->Text);
	string replacest = core::convertToString(boxReplace->Text);
	temp = core::ReplaceAll(temp, findst, replacest);
	fromList(textBox, temp);
}
private: System::Void findAllToolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e) {
	btnFindAll->PerformClick();
}
};


}