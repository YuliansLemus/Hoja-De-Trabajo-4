/* Ejercicio#2
Una persona desea realizar un muestreo con un numero de personas para determinar el porcentaje de
niños, jóvenes, adultos y adultos mayores que existen en la zona en donde vive.
La categoría se determina en base a la siguiente tabla:
Categorias 			Edad
Niños				0-12
Jovenes				13-29
Adultos				30-59
Adultos Mayores		60 en adelante
Teniendo en cuenta que para el muestreo de personas no será mayor a 50, realice un programa que en
primer lugar reciba como dato el numero de personas del muestreo y luego por cada persona permita el
ingreso de su edad y grabar todo a un archivo. El programa deberá leer los datos del archivo y mostrar
como resultado el porcentaje de personas que hay por cada una de las categorías.*/

#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct datos{
	char edad[5];
}est;
int main(){
	int Num, i, Sal=0,menu, Aux;
	int Con=0, Con1=0,  Con2=0, Con3=0, total;
	float Porc;
	
	do{
		cout<<"Muestreo"<<endl;
		cout<<"1. Ingresar Datos"<<endl;
		cout<<"2. Leer Datos"<<endl;
		cout<<"3. Salir "<<endl;
		cout<<"Ingrese La Opcion: ";
		cin>>menu;
		
		switch(menu){
			case 1:
			do{
			cout<<"Muestreo"<<endl;
			cout<<"Numero de personas? ";
			cin>>Num;
    		}while(Num>50); 
	
			for(i=0;i<Num;i++){
				fflush(stdin);
				cout<<"Ingrese La Edad "<<i+1<<": ";
				gets(est.edad);
				fflush(stdin);
				Aux = atoi(est.edad);
				if(Aux>=0 && Aux<13){
		        	   	Con++;
				}else if(Aux>12 && Aux<30){
					Con1++;
				}else if(Aux>29 && Aux<=59){
				Con2++;
				}else if(Aux>60){
					Con3++;
				}
			}
			FILE *archivo;
			archivo = fopen("Promedio De Edades.txt","a+b");
			
			if(archivo ==NULL){
				cout<<"no se pudo abrir el archivo "<<endl;
				exit(1);
			}
			fwrite(&est,sizeof(est),1,archivo);
			fclose(archivo);
			system("pause");
				break;
			case 2:
				FILE *leer;
				leer = fopen("Promedio De Edades.txt","r");
				if(leer==NULL){
					cout<<"no se pudo leer el archivo"<<endl;
					exit(1);
				}
					total= Con+Con1+Con2+Con3;
					cout<<"El Total de datos :                 "<<total<<endl;
					cout<<"El Porcentaje de Niños :            "<<(Con*100)/total<<"%"<<endl;
					cout<<"El Porcentaje de Jovenes  :         "<<(Con1*100)/total<<"%"<<endl;
					cout<<"El Porcentaje de Adultos :          "<<(Con2*100)/total<<"%"<<endl;
					cout<<"El Porcentaje de Adultos Mayores :  "<<(Con3*100)/total<<"%"<<endl;
					fclose(leer);
					system("pause");
				break;
			case 3:
				Sal = 1;
				break;
		}
	}while(Sal!=1);
	system("pause");
}

