#pragma once

namespace EjemplodeBusquedas {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Generar_btn;
	protected:

	private: System::Windows::Forms::TextBox^ cantidad_de_numeros_txt;
	protected:

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button1;

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
			this->Generar_btn = (gcnew System::Windows::Forms::Button());
			this->cantidad_de_numeros_txt = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// Generar_btn
			// 
			this->Generar_btn->Location = System::Drawing::Point(395, 33);
			this->Generar_btn->Name = L"Generar_btn";
			this->Generar_btn->Size = System::Drawing::Size(115, 39);
			this->Generar_btn->TabIndex = 0;
			this->Generar_btn->Text = L"Generar Arreglo";
			this->Generar_btn->UseVisualStyleBackColor = true;
			this->Generar_btn->Click += gcnew System::EventHandler(this, &MyForm::Generar_btn_Click);
			// 
			// cantidad_de_numeros_txt
			// 
			this->cantidad_de_numeros_txt->Location = System::Drawing::Point(200, 52);
			this->cantidad_de_numeros_txt->Name = L"cantidad_de_numeros_txt";
			this->cantidad_de_numeros_txt->Size = System::Drawing::Size(159, 20);
			this->cantidad_de_numeros_txt->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(29, 55);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(141, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Ingrese cantidad de arreglos";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(200, 136);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(159, 20);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(32, 142);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Valor a buscar";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(395, 127);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(115, 39);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Buscar";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(570, 447);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cantidad_de_numeros_txt);
			this->Controls->Add(this->Generar_btn);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: ArrayList^ Arreglo;

	private: System::Void generarNumerosAleatorios(int size)
	{
		Arreglo = gcnew ArrayList(size);
		Random^ random = gcnew Random();
		for (int i = 0; i < size; i++)
		{
			Arreglo->Add(random->Next(0, 100));	
		}

	}
	 private: System::Void mostrarNumerosAleatorios()
	 {
		 String^ valores = "";
		 for each (int num in Arreglo)
		 {
			 valores += num + " ";
		 }
		 System::Windows::Forms::MessageBox::Show(valores);
	 }

	private: Hashtable^ TablaHash = gcnew Hashtable();
	//TablaHash.add (Key, Valor);
	//La key podría ser como una posición o índice.
	//Valor sería nuestro valor
	// h(x) = x mod cantidad de valores 
	//x = valor
	//h = 3 mod 10
	//h(3) = 3 mod 10 
	//Entonces el resultado de la función es el índice o posición. 
	//

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Generar_btn_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		int cantidad = System::Convert::ToInt32(cantidad_de_numeros_txt->Text);
		generarNumerosAleatorios(cantidad);
		mostrarNumerosAleatorios();
	}

	private: System::Void llenarTablaHash(int size)
	{
		TablaHash = gcnew Hashtable(size*2);
		int llave = 0;
		for each (int num in Arreglo)
		{
			llave = num % (size * 2);
			while (TablaHash[llave] != nullptr)
			{
				llave++;
			}
			TablaHash->Add(llave, num);
		}

	}


	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) 
	{
		int valorBuscar = System::Convert::ToInt16(textBox1->Text);
		//

	}


	private: System::Int16 PosicionEnHash(int valorBuscar, int size)
	{
		int posicion = valorBuscar % (size * 2);
		if (TablaHash[posicion] == valorBuscar)
		{
			return posicion;
		}
		while (TablaHash[posicion] != valorBuscar)
		{
			posicion++;
		}
		return posicion;
	}

};
}
