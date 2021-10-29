# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <iostream>
# include <sstream>
# include <fstream>
# include <string>
# define NOMBRE_ARCHIVO "Data.csv"
using namespace std;

float data[12][3];
float kilometros;
float proment[2];
int cambio;


float inicializacion();
void explicacion();
int motor_de_inferencia(int a, float b, float c);
void motor_de_explicacion(int a);
float kmt;

main()
{
	int i;
	int r=1;
	int des;
	int nser;
	int dias;
	float kmr;
	float promkm;
	promkm=inicializacion();
	explicacion();
	do{
	    do{
	    	system("color 30");
			system("cls");
		    printf("\n ¿Le has hecho algun servicio?"); 
	        printf("\n SI = 1"); 
	        printf("\n NO = 0"); 
	        printf("\n R: "); 
	        scanf("%i",&des);
	        if((des!=1)&&(des!=0))
	            {
	            	system("cls");
					des=100;
	            	printf("\n OPCION INCORRECTA"); 
	            	printf("\n\n\n\n");
	            	system("pause");
			    }
		  }while(des==100);
	    if(des==1)
	        {
	        	printf("\n ¿Cuantos?");
	        	printf("\n R: "); 
	        	scanf("%i",&nser);
	        	printf("\n ¿Cuantos Kilometros has recorrido desde el ultimo servicio?"); 
		        printf("\n aprox"); 
		        printf("\n R: "); 
	            scanf("%f",&kmr);	            
		    }
		else
		    { 
			    nser=0; 
			    printf("\n ¿Cuantos Kilometros has recorrido?"); 
		        printf("\n aprox"); 
		        printf("\n R: "); 
	            scanf("%f",&kmr);
			}
		dias=motor_de_inferencia(nser, kmr, promkm);
		motor_de_explicacion(dias);
		do{
			//r=1;
			system("color 30");
			system("cls");
		    printf("\n ¿Quieres hacer otra consulta?"); 
		    printf("\n SI = 1"); 
	        printf("\n NO = 0"); 
	        printf("\n R: "); 
	        scanf("%i",&r);
	        if((r!=1)&&(r!=0))
	            {
	            	system("cls");
					r=100;
	            	printf("\n OPCION INCORRECTA"); 
	            	printf("\n\n\n\n");
	            	system("pause");
			    }
		  } while(r==100);
		
      } while(r==1);
}

//############################################################################################################################//

float inicializacion()
{  
    ifstream archivo(NOMBRE_ARCHIVO);    
    string linea;
    char delimitador = ',';
    string mes;
    string cantidad;
    string tipo;
    string ckm;
    string km;
    int mm;
    int x;
    int i;
    int j;
    float k;
    int ii;
    float y=0;
    float z;
    
    
    getline(archivo, linea);  // Leemos la primer línea para descartarla, pues es el encabezado
    while (getline(archivo, linea))  // Leemos todas las líneas
        {
            // Extraer todos los valores de esa fila
            stringstream stream(linea); // Convertir la cadena a un stream
			getline(stream, mes, delimitador);
            getline(stream, cantidad, delimitador);
            getline(stream, tipo, delimitador);
            getline(stream, ckm, delimitador);
            
            
            mm=atoi(mes.c_str())-1;
            
            if(mm==13)
                {
                	kilometros=strtof(cantidad.c_str(),NULL);
			    }
            else{
                    data[mm][0]=strtof(cantidad.c_str(),NULL);
                    data[mm][1]=strtof(tipo.c_str(),NULL);   
                    data[mm][2]=strtof(ckm.c_str(),NULL);  
			    }
        }
	archivo.close();
	for(x=0;x<12;x++)
	    {
	    	if(data[x][2]==1)
			    y=y+data[x][0];
	    }
	z=kilometros/y;
	/*printf("\n %f",z); 
	printf("\n\n\n\n"); 
	system("pause");*/
	for(ii=0;ii<2;ii++)
	    {
	    	k=0;
	    	j=0;
			for(i=0; i<12 ; i++)
                {
    	            if(ii==data[i][1])
    	                {
				            k=k+data[i][0];
    	    	            j++;
		                }
                }
            proment[ii] = (k/j)/30;
	    }
	return z;
}

//############################################################################################################################//

void explicacion()
{
	system("color 2f");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n"); 
	printf("\n Este programa te ayudara a saber en cuanto tiempo deberas de llevar tu moto Modelo \"Hornet 250 R line\" a servicio ");  
	printf("\n Para esto se te hara una serie de preguntas. ");    
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); 
	system("pause");
	system("cls");
}

//############################################################################################################################//

int motor_de_inferencia(int a, float b, float c)
{
  int i;
  int j;
  int cont;
  float k;
  int dias;
  int mes;
  int dd;
  int tipo;
  int km;

  time_t t;
  struct tm *tm;
  t=time(NULL);
  tm=localtime(&t);
  mes = tm->tm_mon;
  dd=tm->tm_mday;
  tipo=data[mes][1];
  //tipo=1;

  if(a==0)
    km=500;
  if(a==1)
    km=1000;
  if(a==2)
    km=1500;
  if((a>=3)&&(a<6))
    km=2000;
  if(a>=6)
    km=3000; 
    
  dias=0;
  
  if(km<b)
    {
    	kmt=b-km;
    	return 0;
    }
    
  else
    {
    	for(i=mes;b<km; mes++, i++)
            {
    	        /*printf("\n %i",mes);    
                printf("\n\n"); */
		        if(tipo==data[i][1])
    	            {
				        for(cont=0;(dd!=30)&&(b<km);dd++,cont++)
				            {
				    	        b=b+(proment[tipo]*c);
				    	        /*printf("\n %f",b);    
                                printf("\n\n"); 
                                system("pause");*/
				            }
		            }
		        else
		            {
		    	        if (tipo == 0)
		    	            {
		    	    	        for(cont=0;(dd!=30)&&(b<km);dd++,cont++)
				                    {
				    	                b=b+(proment[1]*c);
				                    }
			  	            }
			  	        if (tipo == 1)
		    	            {
		    	    	        for(cont=0;(dd!=30)&&(b<km);dd++,cont++)
				                    {
				    	                b=b+(proment[0]*c);
				                    }
			  	            }
		            }
		        dias=dias+cont;
		        dd=0;
		        if(mes==11)
		        mes=-1;
            }
        return dias;
    }
}

//############################################################################################################################//

void motor_de_explicacion(int a)
{
	system("cls");
	if(a==0)
	    {
	    	system("color 4f");
	    	printf("\n  **************************************************************************************** \n");   
			printf("\n  ¡¡¡¡¡¡Ya deberias haber llevado a mantenimiento tu moto hace %0.02f kilomestros!!!!!!",kmt);    
			printf("\n\n  **************************************************************************************** \n");  
	        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); 
	        system("pause");
	    }
	else{
		    system("color 1f");
			printf("\n  Necesitara llevar Su Motocicleta a mantenimiento en %i dias.",a);    
	        printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"); 
	        system("pause");
	    }
}

//############################################################################################################################//

