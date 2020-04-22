/*Ejercicio#1
En la región de la sierra de los Cuchumatanes la compañía Xterminio s.a. , tiene las siguientes tarifas:
		Tipo         Servicio              Costo X Hectarea
		 1			Mala hierba					10.00
		 2			Langostas					20.00
		 3 			Gusanos						30.00
		 4 		  Todo Lo anterior				50.00
Además del área a fumigar es mayor a 500.00 hectáreas se tiene un descuento del 5%. Adicionalmente,
si el total a pagar por el servicio es mayor a Q1500.00 se tiene un descuento adicional del 10% sobre el
excedente.
La compañía necesita las estadísticas de los servicios que ha ofrecido a un grupo de agricultores durante
un periodo de tiempo. 
Por cada servicio debe ingresar los datos siguientes: Tipo de Fumigación (1 a 4) y
el número de hectáreas, 
toda esta información deberá almacenarse en una base de datos (archivo plano).
Se le pide que realice un programa en C++ que solicite el ingreso de la información de cada servicio
realizado a un grupo de agricultores. 
El programa deberá de leer los datos del archivo que tiene la
información antes almacenada y mostrar la cantidad de servicios de cada tipo de fumigación, determinar
el tipo servicio con mayor demanda y el monto total pagado por los clientes.
*/

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>


using namespace std;
 
	int op=0;
	float tamhec=0,mh=10.00,lan=20.00,gus=30.00,tlh=50.00,pa=0,pag=0,des5=0,des10=0,pago=0,pag15;
	
	int main ()
	{
	cout<<"1. Hierba Mala "<<endl;
	cout<<"2. Langostas "<<endl;
	cout<<"3. Gusanos "<<endl;
	cout<<"4. Todo lo anterior "<<endl;
	cout<<"Ingrese Que tipo de fumigacion Quiere  "<<endl;
	cin >>op;
	cout<<"De cuantas Hectarias es el area a fumigar "<<endl;
	cin>>tamhec;
	
	if(tamhec>=500)
	{
		if(op==1)
		{
			pa=(tamhec*mh);
			des5=pa*0.05;
			pag=pa-des5;
		}
		else if(op==2)
		{
			pa=(tamhec*lan);
			des5=pa*0.05;
			pag=pa-des5;
		}
		else if(op==3)
		{
			pa=(tamhec*gus);
			des5=pa*0.05;
			pag=pa-des5;
		}
		else if(op==4)
		{
			pa=(tamhec*tlh);
			des5=pa*0.05;
			pag=pa-des5;
		}
	}  
	 else if(tamhec<500)
	{
		if(op==1)
		{
			pag=(tamhec*mh);
		}
		else if(op==2)
		{
			pag=(tamhec*lan);
		}
		else if(op==3)
		{
			pag=(tamhec*gus);
		}
		else if(op==4)
		{
			pag=(tamhec*tlh);
		}
	}  

	if(pag>=1500)
		{
			pag15=pag-1500;
			des10=pag15*0.10;
			pago=pag-des10; 
		}
	else if(pag<1500)
	{
	pago=pag-0;
	}
			
	cout<<"El total a pagar es de "<<pago<< " Quetzales. Por Fumigacion de "<<tamhec<<"  Hectarias"<<endl;
	
	ofstream archivo;
	try {
		archivo.open("La Compañía Xterminio,S.A..txt",ios::app);
		archivo<<op<<"\t"<<tamhec<<"\t"<<pago<<endl;
		archivo.close();
	}
	catch(exception X){
		cout<<"Error en la manipulacion del archivo"<<endl;
	}
system("cls");
	
	ifstream db;
	float tf,d,tv=0,sumatotal=0,tf1=0,tf2=0,tf3=0,tf4;	
	try{	
		db.open("La Compañía Xterminio,S.A..txt",ios::in);
		
		while (db >>tf >> d >>tv){
			sumatotal = tv + sumatotal;	
			if (tf==1)
				tf1+=tv;
			else if (tf==2)
				tf2+=tv;
			else if (tf==3)
				tf3+=tv;
			else if (tf==4)
				tf4+=tv;				
		}	
		db.close();
		
		cout<<setprecision(5)<<"Total "<<sumatotal<<endl;
		cout<<"Tipo de Fumigacion "<<endl;
		cout<<setprecision(5)<<"      Hierba Mala    "<<tf1<<endl;
		cout<<setprecision(5)<<"      Langostas      "<<tf2<<endl;
		cout<<setprecision(5)<<"      Gusanos        "<<tf3<<endl;
		cout<<setprecision(5)<<"  Todo lo anterior   "<<tf4<<endl;
	}
	catch (exception X){		
			cout<<"Error para abrir archivo"<<endl;
			}
	return(0);
	}

	
