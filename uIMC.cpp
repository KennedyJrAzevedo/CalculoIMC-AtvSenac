//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "uIMC.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	double imc;
	Panel1->Visible= true;
	Panel2->Visible= true;
	Panel3->Visible= true;
	Panel4->Visible= true;

	imc = StrToFloat(Edit3->Text) / (StrToFloat(Edit2->Text) * StrToFloat(Edit2->Text));
	Label4->Caption = "IMC=" +FormatFloat("0.00",imc);
	if (imc<18.5) {
		Label4->Caption=Label4->Caption+ ". Abaixo do Peso. "+Edit1->Text+", procure um médico";
       Panel2->Visible=false;
	}else{
        if (imc>=18.5 && imc<=24.9) {
           Label4->Caption=Label4->Caption+ ". Peso Ideal. "+Edit1->Text+", parabéns";
           Panel1->Visible=false;
          }else{
                if (imc>24.9 && imc<=29.9) {
	               	Label4->Caption=Label4->Caption+ ". Levemente acima do peso. "+Edit1->Text+", atenção";
	                Panel3->Visible=false;
                   	}  else{
	                        if (imc>29.9 && imc<=34.9) {
                                Label4->Caption=Label4->Caption+ ". Obesidade grau I. "+Edit1->Text+", fique alerta";
	                            Panel4->Visible=false;
                             }else{
                                 Label4->Caption = Label4->Caption+ ". Obesidade grau maior que I. "+Edit1->Text+", procure um médico imediatemente!";
                             }
                     	}
                 }
	}

}
//---------------------------------------------------------------------------






