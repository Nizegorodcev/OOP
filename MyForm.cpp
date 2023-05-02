#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace prilogenie;
using namespace System::Threading;
[STAThreadAttribute]
void main(array<System::String^>^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew MyForm());
}
System::Void prilogenie::MyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
	richTextBox1->Text += L"Привет ";
}

System::Void prilogenie::MyForm::richTextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
	return System::Void();
}
System::Void prilogenie::MyForm::открытьToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
	if (openFileDialog1->ShowDialog() != System::Windows::Forms::DialogResult::OK) return;

	std::string fileName = SystemStringToStdString(openFileDialog1->FileName);// преобразование строки типа String^ в стандартную строку std::string

	if (fileName.empty()) return;

	std::ifstream in(fileName.c_str());

	String^ systemEndStr = gcnew String(endStr);//Создаем символ конца строки

	while (!in.eof()) // читаем информацию из файл стандартными средствами языка С++

	{
		
		std::string s;
		getline(in, s);
		String^ myInfoDisp = gcnew String(s.c_str());// преобразование стандартной строки std::string в строку типа String^
		richTextBox1->Text += (myInfoDisp + systemEndStr);

	}
}



