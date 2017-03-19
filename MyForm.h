#pragma once
#pragma comment(lib, "Ws2_32.lib") //библиотека сокетов
#include <WinSock2.h> // сами сокеты
#include <iostream> //для вывода информации в консоль
#include <WS2tcpip.h> //для получения информации о сервере
#include <string>
//#include <pthread.h>
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
	private: System::Windows::Forms::ToolStripMenuItem^  войтиToolStripMenuItem;
	public: 
		int^port;	
		IPAddress^ip;
		Socket^Client;
		Thread^th;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Label^  label2;
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
				char* buffer=new char[1024];
				std::strcpy(buffer,message.c_str());
				send(socket(AF_UNSPEC, SOCK_STREAM, IPPROTO_TCP),buffer,strlen(buffer),NULL);
			}
		}

		  void* RecvMessage(void *args) // функция принятия сообщений от клиента
        {
			//array<Byte>^ buffer;
			char* buffer=new char [1024];
			for (int i = 0; i < sizeof(buffer); i++)
            {
                buffer[i] = 0; //чистим буфер
            }
            for (; ; )
            {
                   //Client.receive(buffer);//прием сообщения с помощью именно сокета, в виде байтовых сиволов
				   recv(socket(AF_UNSPEC, SOCK_STREAM,IPPROTO_TCP),buffer,1024,NULL);
				   //String^ message;//перевод байтов в строку
				   //message=Encoding::UTF8->GetString(buffer);
				   string message(buffer);
				   int count = message.find("##",0);// поиск "##", это означает конец сообщения;
                   if (count == -1)
                   {
                       continue;
                   }

                   String^ Clear_Message(" "); //уже "чистое" готовое сообщение
                   for (int i = 0; i < count; i++)
                   {
                       Clear_Message+= message[i];
                   }

                   for (int i = 0; i < sizeof(buffer); i++)
                   {
                       buffer[i] = 0; //чистим буфер
                   }
				   richTextBox1->AppendText(Clear_Message); //добавляем сообщение в бокс
            }
        }
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->войтиToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
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
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label1.Image")));
			this->label1->Location = System::Drawing::Point(25, 302);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(146, 19);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Введите сообщение:";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->menuStrip1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"menuStrip1.BackgroundImage")));
			this->menuStrip1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripMenuItem1});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(526, 27);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// toolStripMenuItem1
			// 
			this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->войтиToolStripMenuItem});
			this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			this->toolStripMenuItem1->Size = System::Drawing::Size(63, 23);
			this->toolStripMenuItem1->Text = L"Меню";
			// 
			// войтиToolStripMenuItem
			// 
			this->войтиToolStripMenuItem->Name = L"войтиToolStripMenuItem";
			this->войтиToolStripMenuItem->Size = System::Drawing::Size(121, 24);
			this->войтиToolStripMenuItem->Text = L"Войти";
			this->войтиToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::войтиToolStripMenuItem_Click);
			// 
			// button2
			// 
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button2->Location = System::Drawing::Point(377, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 26);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Войти";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(375, 69);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(131, 20);
			this->textBox1->TabIndex = 6;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// button3
			// 
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->button3->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->button3->Location = System::Drawing::Point(355, 325);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(109, 26);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Отправить";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"label2.Image")));
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label2->Location = System::Drawing::Point(374, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(132, 19);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Введите ваше имя";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(526, 375);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->richTextBox2);
			this->Controls->Add(this->richTextBox1);
			this->Controls->Add(this->menuStrip1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"Чат";
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

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) //кнопка "войти"
			 {
				if (textBox1->Text != " " && textBox1->Text != "")
				{
					SOCKET ConnectSocket = INVALID_SOCKET; 
					int iResult; 

					WSADATA wsaData; 
					struct addrinfo *result = NULL, *ptr = NULL, hints;
 
					iResult = WSAStartup(MAKEWORD(2, 2), &wsaData); 

					ZeroMemory(&hints, sizeof(hints)); 
					hints.ai_family = AF_UNSPEC; 
					hints.ai_socktype = SOCK_STREAM; 
					hints.ai_protocol = IPPROTO_TCP; 

					iResult = getaddrinfo("127.0.0.1","7770", &hints, &result); 

					for (ptr = result; ptr != NULL; ptr = ptr->ai_next) 
					{ 
						ConnectSocket = socket(ptr->ai_family, ptr->ai_socktype, ptr->ai_protocol); 

						iResult = connect(ConnectSocket, ptr->ai_addr, (int)ptr->ai_addrlen); //подключение к серверу
						if (iResult == SOCKET_ERROR) 
						{ 
							closesocket(ConnectSocket); 
							ConnectSocket = INVALID_SOCKET; 
							continue; 
						} 
						break; 
					} 
					freeaddrinfo(result);

					richTextBox1->Enabled = false;
					richTextBox1->AppendText("Hello");
					//new th([&]() { this.RecvMessage(); })
					//CreateThread(NULL,NULL,&RecvMessage,NULL,NULL,NULL);
					//pthread_t t;
					//pthread_create(&t, NULL, RecvMessage, NULL);
					//pthread_join(t, NULL);
				}
			 }
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) //кнопка "отправить"
		 {
			String^ qwe="\n" + textBox1->Text + ": " + richTextBox2->Text + "##";
			std::string str = msclr::interop::marshal_as<std::string>(qwe);
			SendMessage(str);
            richTextBox2->Clear();
		 }
private: System::Void войтиToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
			 MyForm1 ^f2=gcnew MyForm1();
			 f2->ShowDialog();
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
