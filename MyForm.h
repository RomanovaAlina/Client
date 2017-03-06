#pragma once
#pragma comment(lib, "Ws2_32.lib") //���������� �������
#include <WinSock2.h> // ���� ������
#include <iostream> //��� ������ ���������� � �������
#include <WS2tcpip.h> //��� ��������� ���������� � �������
#include <string>
#include "MyForm1.h"
#include <msclr\marshal_cppstd.h>
using namespace System;
using namespace std;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Text;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Threading::Tasks;
using namespace System::Windows::Forms;
using namespace System::Net;
using namespace System::Net::Sockets;
using namespace System::Threading;

namespace Project {




	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::RichTextBox^  richTextBox2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  �����ToolStripMenuItem;
	public: 
		int^port;	
		IPAddress^ip;
		Socket^Client;
		Thread^th;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button3;
	public: 
	private: System::Windows::Forms::Button^  button2;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//ip=IPAddress::Parse("127.0.0.1");
			port=7770;
		}

		void SendMessage (string message)
		{
			if (message[0]!=0)
			{
				//array <Byte>^buffer;
				//buffer=Encoding::UTF8->GetBytes(message);
				char* buffer=new char[1024];
				std::strcpy(buffer,message.c_str());
				//Client.Send(buffer);
				send(socket(AF_INET, SOCK_STREAM, IPPROTO_TCP),buffer,strlen(buffer),NULL);
			}
		}

		  void RecvMessage() // ������� �������� ��������� �� �������
        {
			//array<Byte>^ buffer;
			char* buffer=new char [1024];
			for (int i = 0; i < sizeof(buffer); i++)
            {
                buffer[i] = 0; //������ �����
            }
            for (; ; )
            {
                   //Client.receive(buffer);//����� ��������� � ������� ������ ������, � ���� �������� �������
				   recv(socket(AF_INET, SOCK_STREAM,IPPROTO_TCP),buffer,1024,NULL);
				   //String^ message;//������� ������ � ������
				   //message=Encoding::UTF8->GetString(buffer);
				   string message(buffer);
				   int count = message.find("##",0);// ����� "##", ��� �������� ����� ���������;
                   if (count == -1)
                   {
                       continue;
                   }

                   String^ Clear_Message(" "); //��� "������" ������� ���������
                   for (int i = 0; i < count; i++)
                   {
                       Clear_Message+= message[i];
                   }

                   for (int i = 0; i < sizeof(buffer); i++)
                   {
                       buffer[i] = 0; //������ �����
                   }
				   richTextBox1->AppendText(Clear_Message); //��������� ��������� � ����
            }
        }
	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->�����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(377, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(122, 59);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(21, 44);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(329, 242);
			this->richTextBox1->TabIndex = 1;
			this->richTextBox1->Text = L"";
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(24, 325);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(325, 26);
			this->richTextBox2->TabIndex = 2;
			this->richTextBox2->Text = L"";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(25, 302);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(112, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"������� ���������:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripMenuItem1});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(526, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->�����ToolStripMenuItem});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(53, 20);
			this->toolStripMenuItem1->Text = L"����";
			// 
			// �����ToolStripMenuItem
			// 
			this->�����ToolStripMenuItem->Name = L"�����ToolStripMenuItem";
			this->�����ToolStripMenuItem->Size = System::Drawing::Size(152, 22);
			this->�����ToolStripMenuItem->Text = L"�����";
			this->�����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::�����ToolStripMenuItem_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(383, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(115, 56);
			this->button2->TabIndex = 5;
			this->button2->Text = L"�����";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(383, 186);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(131, 20);
			this->textBox1->TabIndex = 6;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(388, 316);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(109, 34);
			this->button3->TabIndex = 7;
			this->button3->Text = L"���������";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(526, 375);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"���";
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
			 {
				 Application::Exit();
			 }

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) //������ "�����"
			 {
				if (textBox1->Text != " " && textBox1->Text != "")
            {
				SOCKET ConnectSocket = INVALID_SOCKET; 
				int iResult; 
				struct addrinfo *result = NULL, *ptr = NULL, hints;
				SOCKADDR_IN anAddr;
				anAddr.sin_family = AF_UNSPEC;
				anAddr.sin_port = htons(30);
				//anAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
 
				ZeroMemory(&hints, sizeof(hints)); 
				hints.ai_family = AF_UNSPEC; 
				hints.ai_socktype = SOCK_STREAM; 
				hints.ai_protocol = IPPROTO_TCP; 
				hints.ai_addr="127.0.0.1";

				iResult = getaddrinfo("127.0.0.1",DEFAULT_PORT, &hints, &result); 
				ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol); 
				iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen); 

                richTextBox1->Enabled = false;
               //if (ip!=NULL)
               // {
				//connect(socket(AF_UNSPEC, SOCK_STREAM,IPPROTO_TCP),(struct sockaddr *)&anAddr, sizeof(struct sockaddr));//����������� � �������
				//CreateThread(NULL,NULL,&RecvMessage,NULL,NULL,NULL);

               // }
            }
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) //������ "���������"
		 {
			String^ qwe="\n" + textBox1->Text + ": " + richTextBox2->Text + "##";
			std::string str = msclr::interop::marshal_as<std::string>(qwe);
			SendMessage(str);
            richTextBox2->Clear();
		 }
private: System::Void �����ToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 MyForm1 ^f2=gcnew MyForm1();
			 f2->ShowDialog();
		 }
};
}
