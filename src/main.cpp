#include <winbgim.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <windows.h>
#include<math.h>
#include <dos.h>
#include <conio.h>
#include <time.h>
using namespace std; 
#define PI 3.14159265358979323846 
double angulo,coseno,seno;
void presionado(int op);
void boton(int x,int y,int x2,int y2,int c1,int c2);
void clean();
void pantalla1();
void pantalla2();
void log();
void programa();
void carga();
void nocarga();
void nuevousuario();
void vuelve();
void pantalla(int op2);
void caritas(int op);
void archivo();
void archivo2(int op);
int cordx,cordy,ce=0;
int c, cc,r,r2,x,y,x2,y2,l,q,tip=1,tam=2,ent=1,t1=37,t2=109,t3=123,bla=0,fro=0,fron=0,hor=0,xx,i,m=0,v=0,cu,c1,p=0,xxx1,t11=200,t22=200,t33=200,co=0,s,t=0,j=0,g;
int yy=125,a=0;
float lim=0,xr=0,yr=0,xxx;
char op,op2,recibido[150],enviado[150],u,U[150],z,Z[140],u2,U2[150],R[150],RU[1000],RM[1000],R1[150],LA[150],linea[150],dateStr [9],timeStr [9],tecla;
HANDLE h;
DWORD n;
DCB dcb;
DWORD dwEventMask; 
FILE *doc;

int HoraFecha2(int x, int y) //subprograma, establece hora del sistema 
{
		
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%H:%M:%S",tlocal);
        setcolor(0); 
	    setcolor(15);
	    settextstyle(8,0,1);
	    setusercharsize(1,3,1,3);
        outtextxy(x,y,output);
        hor=textwidth(output);        

        
		return 0;      
}
int HoraFecha(int x, int y) //subprograma, establece hora del sistema 
{
		
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%H:%M:%S",tlocal);
        setcolor(0); 
	    setcolor(15);
	    settextstyle(8,0,1);
	    setusercharsize(1,2,1,2);
	    setbkcolor(COLOR(2,86,105));
        outtextxy(x,y,output);
        hor=textwidth(output); 
		setbkcolor(15);
		setcolor(bla);
										settextstyle(tip,0,1);
                        				setusercharsize(ent,tam,ent,tam);
		

		return 0;      
}

int HoraFecha3(int x, int y) //subprograma, establece hora del sistema 
{
		
        time_t tiempo = time(0);
        struct tm *tlocal = localtime(&tiempo);
        char output[128];
        strftime(output,128,"%H:%M:%S",tlocal);
        setcolor(0); 
	    setcolor(15);
	    settextstyle(8,0,1);
	    setusercharsize(2,5,2,5);	   
        outtextxy(x,y,output);
        hor=textwidth(output); 
		setbkcolor(15);
		setcolor(bla);
										settextstyle(tip,0,1);
                        				setusercharsize(ent,tam,ent,tam);     
}

int main()
{
    initwindow(1024,680); 
  	pantalla1();
	  using namespace std; //Tratamiento de puertos 

	h=CreateFile("COM1",GENERIC_READ|GENERIC_WRITE,0,NULL,OPEN_EXISTING,0,NULL);
 
	if(h == INVALID_HANDLE_VALUE) {
		/* ocurrio un error al intentar abrir el puerto */
	}
 
	
	if(!GetCommState(h, &dcb)) {
		/* error: no se puede obtener la configuracion */
	}
 

	dcb.BaudRate = 9600;
	dcb.ByteSize = 8;
	dcb.Parity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;
	dcb.fBinary = TRUE;
	dcb.fParity = TRUE;
 
	
	if(!SetCommState(h, &dcb)) {
		
	}
	SetCommMask(h, EV_RXCHAR);
	
	COMMTIMEOUTS timeouts;
	timeouts.ReadIntervalTimeout = 50;
	timeouts.ReadTotalTimeoutMultiplier = 1;
	timeouts.ReadTotalTimeoutConstant = 1;
	timeouts.WriteTotalTimeoutMultiplier = 1;
	timeouts.WriteTotalTimeoutConstant = 1;
	if(!SetCommTimeouts(h,&timeouts))
    printf("Error al intentar abrir el puerto"); 	
    	doc = fopen("CHAT.txt","w");				 
										     				 _strdate( dateStr);
															 _strtime( timeStr );
															 fprintf(doc,"****************************-\n");
															fprintf(doc,"BIENVENIDO: %s-\n",U);
															fprintf(doc,"****************************-\n");
															fprintf(doc,"\tActivado:-\nDía: %s, Hora: %s-\n****************************-\n",dateStr,timeStr);
															fclose(doc);
	pantalla2(); 		

	 
}

void pantalla1()
{
												 //Ventana Grafica
   	setfillstyle(1,COLOR(31,52,56));
    bar(0,0,1024,776); 
    setbkcolor(COLOR(31,52,56));
    settextstyle(10,0,5);
   	outtextxy(250,80,"¡Bienvenido a Hi-Chat!");
                                        //Logo
    for(x=0;x<=70;x++)
	{
		setcolor(1); 
		setlinestyle( 3,0,1);
    	circle(512,250,70-x);
	}
    setcolor(15);
    setlinestyle ( 0,2,15);
    circle(512,250,70);
    line(505,205,515,265);
	circle(520,290,3);
	setcolor(1);
	circle(460,315,3);
	setcolor(15);
	line(450,330,455,290);
	line(450,330,480,318);   
    settextstyle(8,0,2);
    setlinestyle( 0,0,0);
	
	 setfillstyle(1,COLOR(71,74,81));
	 bar(0,548,1024,680);
	 setfillstyle(1,COLOR(47,53,59));
	 bar(100,575,924,648);
	 setbkcolor(COLOR(47,53,59));
	 settextstyle(10,0,3);
	 outtextxy(395,552,"Ingrese su Usuario");	 
	 		setfillstyle(1,15);
	 		bar(400,595,650,630);
	 		setcolor(0);
			rectangle(399,594,651,631);
			setbkcolor(COLOR(47,53,59));
			settextstyle(1,0,1);
			outtextxy(110,600,"Maximo 10 caracteres");           
            setbkcolor(15);
            bar(601,600,646,625);
            outtextxy(607,603,"ok");
             rectangle(600,599,647,626);
log();
}
void pantalla2()
{	
	yy=125;																 													
	setfillstyle(10,COLOR(30,45,110));
    bar(0,0,1024,680); 
    setfillstyle(1,COLOR(2,86,105));
    bar(0,0,1024,30);
    HoraFecha(940,5);
    setfillstyle(1,COLOR(37,109,123));
    bar(0,30,1024,100);   
	setfillstyle(1,1);
    bar(325,105,375,125);     
    setbkcolor(COLOR(2,86,105));
    settextstyle(9,0,1);     
      
   	setcolor(7);					///logo de usuario
	circle(50,65,30);
	setfillstyle(SOLID_FILL  ,7);
	floodfill(50,65,7); 
	setcolor(15);					
	circle(50,58,12);
	setfillstyle(SOLID_FILL  ,15);
	floodfill(50,65,15); 
	setcolor(15);	
	setfillstyle(SOLID_FILL , 15);
	fillellipse(50,83,21,11); 
	setbkcolor(COLOR(37,109,123));
    settextstyle(9,0,3);
    setusercharsize(1,2,1,2);
    setbkcolor(COLOR(2,86,105));
    v=920-(textwidth(U));    
   	outtextxy(v,5,U);
   		setcolor(15);
                        
   	boton(v-5,4,925,25,15,15);
    setfillstyle(1,0);
    bar(15,700,700,750);    ////Barra mensaje
    settextstyle(9,0,1);
    setcolor(0);    
    setfillstyle(1,15);     
    fillellipse(20,625,13,25);
    int point[8]={735,600,770,600,745,615};						
	fillpoly(3,point);		      
    fillellipse(735,625,13,25);    
    rectangle(20,600,735,650);  
    bar(20,601,736,650);
	setcolor(15);  
	fillellipse(740,608,11,7.9);
	setcolor(0);     
    setlinestyle( 0,2,2);
    setcolor(7);
    circle(35,625,15);
    setfillstyle(SOLID_FILL , 7);
    fillellipse(30,620,2,3);
    fillellipse(40,620,2,3);
    fillellipse(35,630,9,6);
    setfillstyle(1,15);	
    bar(24,623,45,627);
    setcolor(15);
    ellipse(35,629,180,360,7,2);
    setbkcolor(COLOR(255,255,255));
    setcolor(7);
	outtextxy(70,615,"Escribir mensaje");
				/////logo enviar	
				 setlinestyle( 0,0,1);
				for(x=0;x<=28;x++)
				{			
	     				setcolor(1);
						 setlinestyle( 3,0,1);	     							
                        circle(800,625,28-x);					
					
				}
						setlinestyle( 0,0,3);
						setcolor(15);
						circle(800,625,3);
						circle(790,625,3);
						circle(810,625,3);
						
	setfillstyle(1,1);					
	setbkcolor(1);					
	bar(880,605,980,645);
	outtextxy(885,615,"Archivo");
	boton(880,605,980,645,0,0);
	setbkcolor(15);			
	
    //Seleccionar color de Letra.
    q=5;  
	setfillstyle(1,COLOR(2,86,105));
    bar(720,120,1004,580); 
    setfillstyle(10,COLOR(30,45,110));
    bar(720+q,120+q,1004-q,580-q); 
   setfillstyle(1,COLOR(37,109,123));
    bar(720+2*q,120+2*q,1004-2*q,580-2*q); 
    setlinestyle( 10,0,1);
    setcolor(15);
     setbkcolor(COLOR(37,109,123));
    outtextxy(766,150,"Color");
     outtextxy(766,280,"Tipo de fuente");
     outtextxy(766,410,"Tamaño");
     outtextxy(766,490,"Fondo");
    setbkcolor(COLOR(215,215,215));
    setfillstyle(1,COLOR(215,215,215));
    bar(760,180,800,210);
    boton(760,180,800,210,0,0);
    setcolor(0);
    outtextxy(770,186,"A");
    bar(840,180,880,210);
    boton(840,180,880,210,0,0);
    setcolor(2);
    outtextxy(850,186,"A");
    bar(920,180,960,210);
    boton(920,180,960,210,0,0);
    setcolor(4);
    outtextxy(930,186,"A");
    bar(760,230,800,260);
    boton(760,230,800,260,0,0);
    setcolor(15);
    outtextxy(770,236,"A");
    bar(840,230,880,260);
    boton(840,230,880,260,0,0);
    setcolor(1);
    outtextxy(850,236,"A");
    bar(920,230,960,260);
    boton(920,230,960,260,0,0);
    setcolor(14);
    outtextxy(930,236,"A");
    ///tipo de letra
   
    bar(760,310,800,340);
    boton(760,310,800,340,0,0);
    setcolor(0);
    settextstyle(1,0,1);
    outtextxy(770,316,"A");
    bar(840,310,880,340);
    boton(840,310,880,340,0,0);
    settextstyle(3,0,1);
    outtextxy(854,315,"A");
    bar(920,310,960,340);
    boton(920,310,960,340,0,0);
    settextstyle(11,0,1);
    outtextxy(934,316,"A");
    bar(760,360,800,390);
    boton(760,360,800,390,0,0);
    settextstyle(5,0,1);
    outtextxy(774,366,"A");
    bar(840,360,880,390);
    boton(840,360,880,390,0,0);
    settextstyle(8,0,1);
    outtextxy(855,366,"A");
    bar(920,360,960,390);
    boton(920,360,960,390,0,0);
    settextstyle(10,0,1);
    outtextxy(930,366,"A");
    ////tamaño de letra
   
    bar(760,440,800,470);
    boton(760,440,800,470,0,0);
    setusercharsize(1,3,1,3);
    outtextxy(768,446,"A");
    bar(840,440,880,470);
    boton(840,440,880,470,0,0);
	setusercharsize(1,2,1,2);
    outtextxy(846,446,"A");
	setusercharsize(2,3,2,3);
	bar(920,440,960,470);
	boton(920,440,960,470,0,0);
    outtextxy(926,446,"A");
    
    ///COLOR DE FONDO, LETRA   
    settextstyle(1,0,1);
    bar(760,520,800,550);
    boton(760,520,800,550,0,0);
    setbkcolor(COLOR(37,109,123));
    outtextxy(770,526,"A");
    bar(840,520,880,550);
    boton(840,520,880,550,0,0);
    setbkcolor(COLOR(43,113,179));
    outtextxy(850,526,"A");
	bar(920,520,960,550);
	boton(920,520,960,550,0,0);
	setbkcolor(COLOR(110,28,52));
    outtextxy(930,526,"A");
    
    ////color de fondo, recibibo
    settextstyle(1,0,1);
    bar(760,50,800,80);
    boton(760,50,800,80,0,0);
    setbkcolor(COLOR(37,109,123));
    outtextxy(770,56,"A");
    bar(840,50,880,80);
    boton(840,50,880,80,0,0);
    setbkcolor(COLOR(43,113,179));
    outtextxy(850,56,"A");
	bar(920,50,960,80);
	boton(920,50,960,80,0,0);
	setbkcolor(COLOR(110,28,52));
    outtextxy(930,56,"A");
    
    
    settextstyle(1,0,1);
 	setusercharsize(1,2,1,2);
 	
 	 programa();
}
void presionado(int op)
{
 
    switch(op)
    {
              case 1:
                    {  
						strcpy(LA,Z);					               		
						setlinestyle( 0,0,1);
						for(x=0;x<=28;x++)
							{			
	     						setcolor(1);
								 setlinestyle( 3,0,1);	     							
                       			circle(800,625,28-x);								
							}
						setlinestyle( 0,0,3);
						setcolor(15);
						circle(800,625,3);
						circle(790,625,3);
						circle(810,625,3);   
						setlinestyle( 0,0,1);               	
						setfillstyle(1,15);
    					bar(20,601,735,650);
    					////LOGO
					    setcolor(7);
					    setlinestyle( 0,2,2);
					    circle(35,625,15);
					    setfillstyle(SOLID_FILL , 7);
					    fillellipse(30,620,2,3);
					    fillellipse(40,620,2,3);
					    fillellipse(35,630,9,6);
					    setfillstyle(1,15);	
					    bar(24,623,45,627);
					    setcolor(15);
					    ellipse(35,629,180,360,7,2);
					    setlinestyle( 0,0,1);                      
                     	setcolor(7);
                     	setbkcolor(COLOR(255,255,255));
						outtextxy(70,615,"Escribir mensaje");					
                     	pantalla(1);
                     	for(y=0;y<=150;y++)
                    	Z[y]=0;   
                    boton(770,596,828,653,15,15);                    
                    programa();
					}
                    
              case 2:
                    {                         
                          int c=0; 						  
                          	setbkcolor(COLOR(t1,t2,t3));
							for(x=0;x<=28;x++)
							{			
	     					setcolor(1);	  
							setlinestyle( 3,0,1);   							
                        	circle(800,625,28-x);				
							}
 							setcolor(15);
							setlinestyle( 0,0,8);
							line(793,610,813,625);
							line(793,640,813,625);
							line(793,610,796,625);
							line(793,640,796,625);
							setlinestyle( 0,0,1);
							setfillstyle(1,1);
						    bar(790,625,805,627);                      
                           setfillstyle(1,15);
                           bar(50,603,735,650);
                           setbkcolor(15);                      
                           do{	
						   HoraFecha(940,5);						   		
		                           getmouseclick(WM_LBUTTONDOWN,cordx,cordy);		                           
		                           	if(cordx>770&&cordy>596&&cordx<828&&cordy<653)
			                           	{presionado(1);
			                                  c=0;
										}	
										if(cordx>v-5&&cordy>4&&cordx<925&&cordy<25)
										{
										nuevousuario();	
										}											   
                            if(kbhit())
                                {
										if(fro<700)
										{										
												int r;  									   
												 	letra:                        
				                                	z=getch();	                               
				                                if(z== 8)
						                                { 
						                                if(Z[0]!=0)
															{																
															c--;
						                                  char P[140];
						                                  strncpy(P,Z,c);
						                                  setfillstyle(1,15);
						                           		  bar(50,605,735,645);
						                                  for(r=c;r<=140;r++)
						                                  {P[c]=0;
						                                  Z[c]=0;}
						                                  outtextxy(70,615,P);        
						                                  goto letra; 
															}
															else
															{
																presionado(2);
																
															}
														}
				                                  if(z== 13)
						                                  {
						                                  	c=0;		                                
														  presionado(1);		                                  	
						                            		}
				                                Z[c]=z;
				                                c++;                               
						                                for(r=c;r<=140;r++)
						                                { Z[r]=0;
															Z[c]=0;
														}				                                
		                            	}
		                                if(fro>=700)
		                                {
					                                	vuelve:
					                                	do{
					                                			
					                                		getmouseclick(WM_LBUTTONDOWN,cordx,cordy);
			                           						if(cordx>770&&cordy>596&&cordx<828&&cordy<653)
			                           						{  presionado(1);
															   fro=0;
															   z=0;
															   }     
															  if(kbhit())
															  {            															
					                           					z=getch();
					                           					if(z== 27)
																	{	
																		Z[0]='§';
																		pantalla(1);
																		closegraph();										 	
																	}
			
				                                					if(z== 13)
					                                 		 	{
																presionado(1);
																c=0;                                			                                    		
					                                    		}
					                                    		if(z==8)
					                                    		goto letra;
					                                         	
															}		   
															else
															{
																goto vuelve;
															}	                              		
		                                	
											
											}while(z=!13);
											
										
										}
											if(z== 27)
											{	
												Z[0]='§';
												pantalla(1);
												caritas(17);											
												closegraph();										 	
											}
										setcolor(bla);
										settextstyle(tip,0,1);
                        				setusercharsize(ent,tam,ent,tam);
		                                outtextxy(70,615,Z);
										fro=70+(textwidth(Z));	                                
		                                pantalla(2);									
							   }
                                  
                           }while(c<=140);
                           
                    }
                    
              case 3: 
                   exit(0);    
            HMODULE Lib = LoadLibrary("winmm.dll");
            }}
                                            
  void programa()
{
       int recibi=0,envio=0;                                             
		                                    		       		                                    		
      
	
    do               //Programa
    {                                       
				do
				{
				HoraFecha(940,5);
				getmouseclick(WM_LBUTTONDOWN,cordx,cordy);
			 
			 	if(cordx>770&&cordy>596&&cordx<828&&cordy<653)
				presionado(1);
				pantalla(2);
				
				///ARCHIVO
					if(cordx>880&&cordy>605&&cordx<980&&cordy<645)
					{
						archivo();	
					}
				 ///nuevo usuario
				 	v=s;
				 	if(cordx>s-5&&cordy>4&&cordx<925&&cordy<25)
					{printf(" \n v= %i",v);
					nuevousuario();						
					}			
				//color Letras
				if(cordx>760&&cordy>180&&cordx<800&&cordy<210)
				{
					for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(760,180,800,210,15,15);
					Sleep(100);
					boton(760,180,800,210,0,0);
										}
										ce=bla=0; 
				}                                        
			    if(cordx>840&&cordy>180&&cordx<880&&cordy<210)
			    {
			    		for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(840,180,880,210,15,15);
					Sleep(100);
					boton(840,180,880,210,0,0);
										}
										 ce=bla=2; 
				}                                   		
			    if(cordx>920&&cordy>180&&cordx<960&&cordy<210)
			    {
			    	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(920,180,960,210,15,15);
					Sleep(100);
					boton(920,180,960,210,0,0);
										}
										 ce=bla=4;
				}
			   
			    if(cordx>760&&cordy>230&&cordx<800&&cordy<260)
			      {
			      	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(760,230,800,260,15,15);
					Sleep(100);
					boton(760,230,800,260,0,0);
										}
			    	   ce=15;
					   bla=0;
				}
			    if(cordx>840&&cordy>230&&cordx<880&&cordy<260)
			    {
			    	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(840,230,880,260,15,15);
					Sleep(100);
					boton(840,230,880,260,0,0);
										}
										 ce=bla=1;
				}   
			    if(cordx>920&&cordy>230&&cordx<960&&cordy<260)
			    {
			    	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(920,230,960,260,15,15);
					Sleep(100);
					boton(920,230,960,260,0,0);
										}
										 ce=14;
										 bla=0;
				}
			       //tipo de letra
			    if(cordx>760&&cordy>310&&cordx<800&&cordy<340)
			    {
			    	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(760,310,800,340,15,15);
					Sleep(100);
					boton(760,310,800,340,0,0);
										}
										 tip=1;
				}    
			    if(cordx>840&&cordy>310&&cordx<880&&cordy<340)
			    {
			    	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(840,310,880,340,15,15);
					Sleep(100);
					boton(840,310,880,340,0,0);
										}
										tip=3;
				}    	  
			    if(cordx>920&&cordy>310&&cordx<960&&cordy<340)
			    {
			    	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(920,310,960,340,15,15);
					Sleep(100);
					boton(920,310,960,340,0,0);
										}
										tip=11;
				}    	
			    if(cordx>760&&cordy>360&&cordx<800&&cordy<390)
			    {
			    		for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(760,360,800,390,15,15);
					Sleep(100);
					boton(760,360,800,390,0,0);
										}
										tip=5;
				}    
			    if(cordx>840&&cordy>360&&cordx<880&&cordy<390)
			    {
			    		for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(840,360,880,390,15,15);
					Sleep(100);
					boton(840,360,880,390,0,0);
										}
										tip=8;
				}    	
			    if(cordx>920&&cordy>360&&cordx<960&&cordy<390)
			    {
			    	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(920,360,960,390,15,15);
					Sleep(100);
					boton(920,360,960,390,0,0);
										}
										tip=10;
				}
			    	    ///tamaño de letra
			    if(cordx>760&&cordy>440&&cordx<800&&cordy<470)
			    {
			    	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(760,440,800,470,15,15);
					Sleep(100);
					boton(760,440,800,470,0,0);
										}
			    		 ent=1;
			    		 tam=3;
				}
			    if(cordx>840&&cordy>440&&cordx<880&&cordy<470)
			    {
			    		for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(840,440,880,470,15,15);
					Sleep(100);
					boton(840,440,880,470,0,0);
										}
			    	  	 ent=1;
			    	  	 tam=2;
			    	  	 
				}  
			    if(cordx>920&&cordy>440&&cordx<960&&cordy<470)
			    {
			    	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(920,440,960,470,15,15);
					Sleep(100);
					boton(920,440,960,470,0,0);
										}
			    	ent=2;
			    	tam=3;
				}  
				///relleno letra	 
				 if(cordx>760&&cordy>520&&cordx<800&&cordy<550)
				 {
				 	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(760,520,800,550,15,15);
					Sleep(100);
					boton(760,520,800,550,0,0);
										}
				 	t1=37;
				 	t2=109;
				 	t3=123;	 	
				 }
				 if(cordx>840&&cordy>520&&cordx<880&&cordy<550)
				 {
				 	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(840,520,880,550,15,15);
					Sleep(100);
					boton(840,520,880,550,0,0);
										}
				 	t1=43;
				 	t2=113;
				 	t3=179;	 
				 }
				 if(cordx>920&&cordy>520&&cordx<960&&cordy<550)
				 {
				 	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(920,520,960,550,15,15);
					Sleep(100);
					boton(920,520,960,550,0,0);
										}
				 	t1=110;
				 	t2=28;
				 	t3=52;	 
				 }
				 
				 ////relleno letra recibe
				  if(cordx>760&&cordy>50&&cordx<800&&cordy<80)
				 {
				 	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(760,50,800,80,15,15);
					Sleep(100);
					boton(760,50,800,80,0,0);
										}
				 	t11=37;
				 	t22=109;
				 	t33=123;
					 co=0;	 	
				 }
				 if(cordx>840&&cordy>50&&cordx<880&&cordy<80)
				 {
				 		for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(840,50,880,80,15,15);
					Sleep(100);
					boton(840,50,880,80,0,0);
										}
					t11=43;
				 	t22=113;
				 	t33=179;
					 co=0;	 
				 }
				 if(cordx>920&&cordy>50&&cordx<960&&cordy<80)
				 {
				 	for(int i=0;i<1;i++){
					v=1000-(textwidth(U)); 
					boton(920,50,960,80,15,15);
					Sleep(100);
					boton(920,50,960,80,0,0);
										}
					t11=110;
				 	t22=28;
				 	t33=52;	 
				 	co=15;
				 }
				
				if(cordx>18&&cordy>608&&cordx<52&&cordy<642)
							{
								caritas(2);				
							}	
					if(cordx>325&&cordy>105&&cordx<375&&cordy<125)
							{
								
								archivo2(1);				
							}										
			    }while(!kbhit());
	presionado(2);
	}while(1);
 
    closegraph(); 
	}


void boton(int x,int y,int x2,int y2,int c1,int c2)
{
   setcolor(c1);
   line(x,y,x2,y);
   line(x,y,x,y2);
   setcolor(c2);
   line(x2,y2,x,y2);
   line(x2,y2,x2,y);
}

void nocarga()
{
	int radius=20;
 const float conv=PI/180;
	  for(angulo=0;angulo<=(360*2);angulo++)
      {
      	x=740+radius*cos(angulo*conv);
      	y=610+radius*sin(angulo*conv);
        setlinestyle( 1,0,5);
      setcolor(15);
      circle(int(x),int(y),4.5);  
      Sleep(30);  
      setcolor(1);
      circle(int(x),int(y),5); 
	 Sleep(40);
	       setcolor(COLOR(47,53,59));
      circle(int(x),int(y),5);   
    angulo=angulo+50;
  		}
  	setfillstyle(1,COLOR(47,53,59));
	 bar(700,575,924,648);
	 setlinestyle(2,0,4);
	 for(x=0;x<=23;x++)
	 {
	 	setcolor(4);	 	
	 circle(740,610,23-x);
	 }
	 setcolor(15);
	 circle(740,610,23);
	 setlinestyle(2,0,5);
	 line(732,603,747,618);
	 line(732,618,747,603);   
   	Sleep(600); 
	setfillstyle(1,COLOR(47,53,59));
	 bar(700,575,924,648);
	 setcolor(0);
	 setlinestyle(0,0,1);
	
}

void carga()
{
   int radius=20;
 const float conv=PI/180;

       for(angulo=0;angulo<=(360*7);angulo++)
      {
      	x=740+radius*cos(angulo*conv);
      	y=610+radius*sin(angulo*conv);
        setlinestyle( 1,0,5);
      setcolor(15);
      circle(int(x),int(y),4.5);  
      Sleep(30);  
      setcolor(1);
      circle(int(x),int(y),5); 
	 Sleep(40);
	       setcolor(COLOR(47,53,59));
      circle(int(x),int(y),5);   
    angulo=angulo+50;
  		}
  	setfillstyle(1,COLOR(47,53,59));
	 bar(700,575,924,648);
	 setlinestyle(2,0,7);
	 setcolor(2);
	 setfillstyle(SOLID_FILL  ,2);	
	 circle(740,610,23);
	 floodfill(743,613,2); 
	 setcolor(15);
	 circle(740,610,23);
	 setlinestyle(2,0,5);
	 line(731,610,735,618);
	 line(735,618,750,603);
	 Sleep(600);	
   setlinestyle(0,0,1);
   
}
void log()
	{ cu=0;
           	do
			{ 	
				if(!kbhit())   
                     getmouseclick(WM_LBUTTONDOWN,cordx,cordy);
                if(cordx>600&&cordy>599&&cordx<647&&cordy<626)
            	  	{ cu=11;
                   for(int i=0;i<1;i++)
				   				{
					boton(600,599,647,626,15,15);
					Sleep(100);
					boton(600,599,647,626,0,0);
								}
					if(U[0]==0)
						{
							
							nocarga();
							log();
							break;
						}	
						carga();		
									break;  
					}	                         	                 
                        if(kbhit())
                        {       
								if(fron<570)
								{
								letraU:
                                u=getch();
                                if(u== 8)
                                {
                                	if(U[0]!=0)
                                	{
                                		 cu--;
                                char Uu[11];
                                  strncpy(Uu,U,cu);
                                  setfillstyle(1,15);
	 							  bar(400,595,650,630);	 							 
                                  setbkcolor(15);
                                  outtextxy(607,603,"ok");
                                  boton(600,599,647,626,0,0);
                                  for(r=cu;r<=10;r++)
                                { Uu[r]=0;
                                  U[r]=0;}
                                  outtextxy(430,600,Uu);    
                                  goto letraU;
									}
									else
									{
										goto letraU;
									}
								}
                                  if(u== 13)
                                  {
                                  		 cu=11;
					                   for(int i=0;i<1;i++){
										boton(600,599,647,626,15,15);
										Sleep(100);
										boton(600,599,647,626,0,0);
													}
													if(U[0]==0)
														{
															nocarga();
															log();
															break;
														}
									carga();   
								  }
								  U[cu]=u;
                                 for(r=cu;r<=10;r++)
                                { U[r+1]=0;}
                                 cu++;                                 
								}
                                 if(fron>=570)
                                 {
                                 	do
									{     
  	                 					vuelv:
                        				if(kbhit())
                       				 	{	
                       				 		u=0;
                       				 		u=getch();
											if(u== 13)
												{
                                  				cu=11;                       			
                                  				fron=0;
                                  				if(U[0]==0)
														{
															nocarga();
															log();
															break;
														}
												carga();   		
                                  				}
                                  			if(u== 8)
											goto letraU;
										 }										
										else
										{
											goto vuelv;
										}
									}while(u=!27);
                             	}
                             	if(u==27)
                             	{
                             		 closegraph(); 	
								}
							if(U[0]==0)
								{
									nocarga();
									log();
									break;
								}
                        }
						outtextxy(430,600,U);
						fron=430+(textwidth(U)); 											
    		}while(cu<11); 	     	                    
    }
                                     
void pantalla(int op2)
{ switch (op2)
     {
                case 1: 
                	 fro=0;                  
                     {  
                    	 rectangulito: 
							if(yy>560)     
					   			{
                                 setfillstyle(10,COLOR(10,45,110));
   								 bar(0,100,710,600); 
                                 yy=125;
                                 goto rectangulito; 
			           			}
						if(strlen(Z)!=0)	    
						    { 
							xxx=0; 							
	                        cc=strlen(U); 
							strcat(U,"²");							
							strcat(U,Z);																											
							m=strlen(U);															
							xxx=textwidth(LA);
							WriteFile(h, &m, 1, &n, NULL);	                    
	                        WriteFile(h, &U, m, &n, NULL);	
							if(Z[0]=='æ')
								{
									for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}								
							if(Z[0]=='Æ')
								{
										for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='º')
								{
									for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='ª')
								{
										for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='ø')
								{
									for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='ß')
								{
										for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='Ø')
								{
										for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='©')
								{
										for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='¢')
								{
										for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='¥')
								{
										for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='ð')
								{
										for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='Ð')
								{
										for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='¶')
								{
										for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}			
							if(Z[0]=='§')
								{
									for(x=0;x<=m;x++)
                    				Z[x]=0;
                    				for(c=cc;c<=m;c++)
		                    		U[c]=0;	
									break; 	
								}							
																
							setfillstyle(1,COLOR(t1,t2,t3));
							bar(670-xxx,yy-6,700,yy+30);  
							setcolor(COLOR(t1,t2,t3));
							fillellipse(670-xxx,yy+12,10,18);
							fillellipse(700,yy+12,10,18);							
							int point[8]={690,yy+30,700,yy+30,700,yy+40};						
							fillpoly(3,point);														
		                    setbkcolor(COLOR(t1,t2,t3));
							setcolor(ce);
							settextstyle(tip,0,1);							
                        	setusercharsize(ent,tam,ent,tam); 							                     		                                  
		                    outtextxy(680-xxx,yy,LA);																								                    
		    				HoraFecha2(655,yy+17);
		                    yy=yy+35;
		                    for(c=cc;c<=m;c++)
		                    	U[c]=0;					  
	                		doc = fopen("CHAT.txt","a");     				 			 
													_strtime( timeStr );
													fprintf(doc,"\r%s: %s\t%s-\n",U,Z,timeStr);
												   fclose(doc);					
		                    						                             
                            }              
						 for(c=cc;c<=m;c++)
		                    	U[c]=0;	
						for(x=0;x<=m;x++)
                    				Z[x]=0;      
                   				           
                       break;        
		            }
					  						
                     
             case 2:
					{c=strlen(U); 
					m=0;
					t=0;
					j=0;				
					ReadFile(h, &m, 1, &n, NULL);							
                			   					               	                                        
                                         
                        do
                        {ReadFile(h, &R, m, &n, NULL);
                               if(!n)
                                {break;}
                                 c++;
                                 delay(5);                                 
						}while(1);
                                 
                        if(strlen(R)==0)
                              break;  
                    		delay(5); 		        
					     do{
                        	RU[t]=R[t];
                        	t++;							                       
						}while(R[t]!='²');      
                            t++;  
						strcat(R,"Æ");    
                         do{
                         	RM[j]=R[t];
                         	t++;
                         	j++;
						   }while(R[t]!='Æ');
							   			
							if(yy>540)
                        {
                        	setfillstyle(10,COLOR(10,45,110));
                        	setbkcolor(15);
   							bar(0,100,710,600); 
                            yy=125;
                        }         
					  	
                        xxx1=textwidth(RM);				           	                      
						if(RM[0]=='æ')								
									{
										caritas(3);
										break;
									}
						if(RM[0]=='Æ')
							{
										caritas(4);
										break;							
									}
						if(RM[0]=='º')
							{
										caritas(5);
										break;
									}						
						if(RM[0]=='ª')
							{
										caritas(6);
										break;
									}	
						if(RM[0]=='ø')
							{
										caritas(7);
										break;
									}		
						if(RM[0]=='ß')
							{
										caritas(8);
										break;
									}		
						if(RM[0]=='Ø')
							{
										caritas(9);
										break;
									}		
						if(RM[0]=='©')
							{
										caritas(10);
										break;
									}	
						if(RM[0]=='¢')
							{
										caritas(11);
										break;
									}		
						if(RM[0]=='¥')
							{
										caritas(12);
										break;
									}		
						if(RM[0]=='ð')
							{
										caritas(13);
										break;
									}		
						if(RM[0]=='Ð')
							{
										caritas(14);
										break;
									}		
						if(RM[0]=='¶')
							{
										caritas(15);
										break;
							}																																
						
						if(RM[0]=='§')
					     			{
					     				caritas(16);
					     				break;
									}					 			
                        setbkcolor(COLOR(t11,t22,t33));
                        setfillstyle(1,COLOR(t11,t22,t33));
                        bar(20,yy-6,xxx1+40,yy+30);  
						setcolor(COLOR(t11,t22,t33));
						fillellipse(xxx1+40,yy+12,10,18);
						fillellipse(20,yy+12,10,18);							
						int point[8]={30,yy+30,20,yy+30,30,yy+40};						
						fillpoly(3,point);		
						setcolor(co);						
						settextstyle(tip,0,1);
                        setusercharsize(ent,tam,ent,tam);  	
                        outtextxy(40,yy,RM);
                        HoraFecha2(20,yy+17);
                        setfillstyle(1,COLOR(37,109,123));
    					bar(85,30,700,100);  
                        setbkcolor(COLOR(37,109,123));                    
					    settextstyle(8,0,1);
					    setusercharsize(2,5,2,5);
					    outtextxy(100,80,"en linea");
					    setcolor(15);
                        setbkcolor(COLOR(37,109,123));
    					settextstyle(6,0,4);
    					outtextxy(100,45,RU); 
						puts(RU); 
					    setbkcolor(15);
                        yy=yy+35;   
						doc = fopen("CHAT.txt","a");     				 			 
													_strtime( timeStr );
													fprintf(doc,"%s: %s\t%s-\n",RM,RU,timeStr);
												   fclose(doc);			                    
                        for(i=0;i<=150;i++)
                        {
                        	R[i]= 0;
                        	RM[i]= 0;
						}
                        for(x=0;x<=j;x++)
                        RU[x]= 0;
                        
                    break;
					} 
					
	 }             
}
                 
void nuevousuario()
{		cc=cc+1;
		for(c=0;c<=cc;c++)
		U[c]= 0;                            
	cleardevice();
	setfillstyle(1,COLOR(31,52,56));
    bar(0,0,1024,776); 
	settextstyle(10,0,5);
	setbkcolor(COLOR(31,52,56));
    settextstyle(10,0,5);
	 for(x=0;x<=70;x++)
	{
		setcolor(1); 
		setlinestyle( 3,0,1);
    	circle(512,250,70-x);
	}
    setcolor(15);
    setlinestyle ( 0,2,15);
    circle(512,250,70);
    line(505,205,515,265);
	circle(520,290,3);
	setcolor(1);
	circle(460,315,3);
	setcolor(15);
	line(450,330,455,290);
	line(450,330,480,318);   
    settextstyle(8,0,2);
    setlinestyle( 0,0,0);
    bar(400,595,650,630);	 							 
  setbkcolor(15);
  bar(601,600,646,625);
outtextxy(610,600,"ok");
rectangle(600,599,647,626);
setfillstyle(1,COLOR(71,74,81));
	 bar(0,548,1024,680);
	 setfillstyle(1,COLOR(47,53,59));
	 bar(100,575,924,648);
	 setbkcolor(COLOR(47,53,59));
	 settextstyle(10,0,3);
	 outtextxy(345,552,"Ingrese su nuevo Usuario");	 
	 		setfillstyle(1,15);
	 		bar(400,595,650,630);
	 		setcolor(0);
			rectangle(399,594,651,631);
			setbkcolor(COLOR(47,53,59));
			settextstyle(1,0,1);
			outtextxy(110,600,"Maximo 10 caracteres");           
            setbkcolor(15);
            bar(601,600,646,625);
            outtextxy(607,603,"ok");
             rectangle(600,599,647,626);
log();
yy=125;
pantalla2();
}

void caritas(int op)
{	switch(op)
		{
		case 1:
			{yy=yy+15;
				xx=680;
				do
					{
						do
						{caras:
						if(yy<560)	
							{
								getmouseclick(WM_LBUTTONDOWN,cordx,cordy);	
								for(x=0;x<=150;x++)
								Z[x]=0;								
							if(cordx>89&&cordy>609&&cordx<121&&cordy<641)
							{setlinestyle( 1,0,2);
							setcolor(COLOR(243,165,5));
							circle(xx,yy,17);	
								for(x=0;x<=15;x++)			///carita feliz
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}
								setcolor(6);	
								setfillstyle(SOLID_FILL , 6);							
								fillellipse(xx,yy+5,10,7);				    
								setfillstyle(1,14);	
								bar(xx-11,yy-4,690,yy+2);
								fillellipse(xx-5,yy-5,2,5);
								fillellipse(xx+5,yy-5,2,5);
								setcolor(15);
								setlinestyle( 0,0,1);								
								fillellipse(xx,yy+4,7,1);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
								Z[0]='æ';
								presionado(1);
							}
							if(cordx>139&&cordy>609&&cordx<171&&cordy<641)   
							{
									///carita guiño
									setlinestyle( 1,0,2);
									setcolor(COLOR(243,165,5));
									circle(xx,yy,17);			
									for(x=0;x<=15;x++)
										{
											setcolor(14);
											circle(xx,yy,15-x);	
										}	
									setcolor(6);
									fillellipse(xx-5,yy-1,2,2);
									line(xx,yy,xx+5,yy);
									line(xx+3,yy-3,xx+8,yy-3); 
									line(xx-10,yy-4,xx-5,yy-9); 
									line(xx,yy+8,xx-4,yy+5);
									line(xx+4,yy+5,xx,yy+8);
									setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
								Z[0]='Æ';
								presionado(1);
							}
							if(cordx>189&&cordy>609&&cordx<221&&cordy<641)
							{
								///carita saca la lengua
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(12);
								fillellipse(xx,yy+10,4,4);
								setcolor(6);		
								setfillstyle(SOLID_FILL , 6);
								fillellipse(xx,yy+6,10,5);
								setlinestyle( 1,0,4);
								setcolor(12);
								fillellipse(xx,yy+10,4,4);
								setlinestyle( 1,0,2);
								setcolor(6);				    
								setfillstyle(1,14);	
								bar(xx-11,yy-2,xx+10,yy+4);
								line(xx-8,yy-7,xx-3,yy-3);
								line(xx-3,yy-3,xx-8,yy+1);			
								line(xx+3,yy-3,xx+8,yy-7);			
								line(xx+3,yy-3,xx+8,yy+1);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
								Z[0]='º';
								presionado(1);
							}
							if(cordx>239&&cordy>609&&cordx<271&&cordy<641)
							{
								///carita canchera	
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);	
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-4,yy,2,2);
								fillellipse(xx+9,yy,2,2);			
								line(xx-10,yy-2,xx-5,yy-3);			
								line(xx+3,yy-3,xx+8,yy-2);			
								line(xx,yy+8,xx-5,yy+8);
								line(xx+4,yy+5,xx,yy+8);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
								Z[0]='ª';
								presionado(1);
							}
							if(cordx>289&&cordy>609&&cordx<321&&cordy<641) 
							{
								  ///carita preocupacion
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);	
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-5,yy-2,2,2);
								fillellipse(xx+5,yy-2,2,2); 
								line(xx-7,yy+8,xx+7,yy+5);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
								Z[0]='ø';
								presionado(1);
							}
							if(cordx>339&&cordy>609&&cordx<371&&cordy<641)
							{
								///carita bah
								 setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);	
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-5,yy-2,2,2);
								fillellipse(xx+5,yy-2,2,2); 
								line(xx-7,yy+4,xx+7,yy+4);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
									Z[0]='ß';
								presionado(1);
							}
							if(cordx>389&&cordy>609&&cordx<421&&cordy<641)
							{
								setlinestyle( 1,0,2); //carita triste
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);	
									for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(680,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-5,yy,2,2);
								fillellipse(xx+5,yy,2,2); 
								line(xx-3,yy+8,xx,yy+5);
								line(xx,yy+5,xx+3,yy+8);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
									Z[0]='Ø';
								presionado(1);
							 } 
							if(cordx>439&&cordy>609&&cordx<471&&cordy<641)
							{
								///carita indiferente	
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);	
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-4,yy,2,2);
								fillellipse(xx+8,yy,2,2);			
								line(xx-10,yy-2,xx-5,yy-3);			
								line(xx+3,yy-3,xx+8,yy-2);			
								line(xx-3,yy+8,xx,yy+5);
								line(xx,yy+5,xx+3,yy+8);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
									Z[0]='©';
								presionado(1);
							 } 
							if(cordx>489&&cordy>609&&cordx<521&&cordy<641)
							{
								///carita desconfiada
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-5,yy+1,2,2);
								fillellipse(xx+5,yy+1,2,2); 
								line(xx-10,yy-4,xx-3,yy);				
								line(xx+3,yy-3,xx+8,yy-4);
								line(xx-3,yy+8,xx,yy+5);
								line(xx,yy+5,xx+3,yy+8);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
									Z[0]='¢';
								presionado(1);	
							}
							if(cordx>539&&cordy>609&&cordx<571&&cordy<641)
							{
								 ///carita enojada
								setlinestyle( 1,0,2);
								setcolor(COLOR(255,35,1));
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(COLOR(255,117,20));
										circle(xx,yy,15-x);	
									}	
								setcolor(0);
								fillellipse(xx-5,yy+1,2,2);
								fillellipse(xx+5,yy+1,2,2); 
								line(xx-11,yy-4,xx-5,yy-1);				
								line(xx+3,yy,xx+10,yy-4);
								line(xx-3,yy+8,xx,yy+5);
								line(xx,yy+5,xx+3,yy+8);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
									Z[0]='¥';
								presionado(1);	
							 } 
							if(cordx>589&&cordy>609&&cordx<621&&cordy<641)
							{
								///carita diablito		
								setlinestyle( 1,0,2);
								setcolor(COLOR(74,25,44));
								setfillstyle(1,COLOR(74,25,44));
								pieslice(xx+10,yy-15,280,30,10);
								pieslice(xx-10,yy-15,150,-30,10);
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(COLOR(160,52,114));
										circle(xx,yy,15-x);	
									}	
								setcolor(0);
								fillellipse(xx-5,yy+1,2,2);
								fillellipse(xx+5,yy+1,2,2); 
								line(xx-11,yy-4,xx-5,yy-1);				
								line(xx+3,yy-1,xx+10,yy-4);
								line(xx,yy+8,xx-5,yy+8);
								line(xx+4,yy+5,xx,yy+8);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17);
								yy=yy+35;
									Z[0]='ð';
								presionado(1);		
							}
							if(cordx>639&&cordy>609&&cordx<671&&cordy<641)
							{
								  ///carita tira beso
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(12);
								fillellipse(xx,yy+10,4,4);
								setcolor(6);		
								fillellipse(xx-5,yy-1,2,2);
								line(xx+1,yy,xx+6,yy);
								line(xx+3,yy-3,xx+8,yy-3); 
								line(xx-10,yy-4,xx-5,yy-9);
								setbkcolor(COLOR(t1,t2,t3));
								HoraFecha2(660,yy+17); 
								yy=yy+35;
								Z[0]='Ð';
								presionado(1);	
							}
							if(cordx>685&&cordy>609&&cordx<722&&cordy<641) 
							{xx=675;
										///corazon
								 	setlinestyle( 1,0,2);
								 	setfillstyle(1,4);
										for(x=0;x<=10;x++)
									{
										setcolor(4);
										circle(xx,yy-5,10-x);
										circle(xx+18,yy-5,10-x);	
									}	
									pieslice(xx+9,yy+15,43,138,20);
										setbkcolor(COLOR(t1,t2,t3));
									HoraFecha2(660,yy+17);
									yy=yy+35;							
									Z[0]='¶';
								presionado(1);	
							} 
							  
							
							}
						else     
						   	{
						   		setbkcolor(15);
	                            setfillstyle(10,COLOR(10,45,110));
	   							bar(0,100,710,580); 
	                            yy=125;
	                            goto caras;
                            }                     
						}while(!kbhit());
					presionado(2);	
					}while(1);
			break;		
			}
		
		case 2:
			{
				
			setlinestyle( 1,0,2);	
			setfillstyle(1,15);
			bar(15,604,80,646);
			setlinestyle( 0,2,2);
			setcolor(0);
						circle(35,625,15);
					    setfillstyle(SOLID_FILL , 0);
					    fillellipse(30,620,2,3);
					    fillellipse(40,620,2,3);
					    fillellipse(35,630,9,6);
					    setfillstyle(1,15);	
					    bar(24,623,45,627);
					    setcolor(15);
					    ellipse(35,629,180,360,7,2);
					    setbkcolor(COLOR(255,255,255));
					    setcolor(7);
			setfillstyle(1,7);
			bar(80,604,735,646);
			
			boton(89,609,121,641,7,7);
			boton(139,609,171,641,7,7);	
			boton(189,609,221,641,7,7);
			boton(239,609,271,641,7,7);	
			boton(289,609,321,641,7,7);	
			boton(339,609,371,641,7,7);	
			boton(389,609,421,641,7,7);
			boton(439,609,471,641,7,7);
			boton(489,609,521,641,7,7);
			boton(539,609,571,641,7,7);	
			boton(589,609,621,641,7,7);	
			boton(639,609,671,641,7,7);
			boton(685,609,722,641,7,7);					
			
										///carita feliz
			setcolor(COLOR(243,165,5));
			circle(105,625,17);	
			for(x=0;x<=15;x++)			
				{
					setcolor(14);
					circle(105,625,15-x);	
				}
			setcolor(6);	
			setfillstyle(SOLID_FILL , 6);			
			fillellipse(105,630,10,7);				    
			setfillstyle(1,14);	
			bar(94,621,115,627);
			fillellipse(100,620,2,5);
			fillellipse(110,620,2,5);
			setcolor(15);
			setlinestyle( 0,0,1);
			fillellipse(105,629,7,1);
			
					  ///carita guiño
			setlinestyle( 1,0,2);
			setcolor(COLOR(243,165,5));
			circle(155,625,17);			
			for(x=0;x<=15;x++)
				{
					setcolor(14);
					circle(155,625,15-x);	
				}	
			setcolor(6);
			fillellipse(150,624,2,2);
			line(156,625,161,625);
			line(158,622,163,622); 
			line(145,621,150,616); 
			line(155,633,151,630);
			line(159,630,155,633);
			
			 ///carita saca la lengua
			setlinestyle( 1,0,2);
			setcolor(COLOR(243,165,5));
			circle(205,625,17);		
			for(x=0;x<=15;x++)
				{
					setcolor(14);
					circle(205,625,15-x);	
				}	
			setcolor(12);
			fillellipse(205,635,4,4);
			setcolor(6);		
			setfillstyle(SOLID_FILL , 6);
			fillellipse(205,631,10,5);
			setlinestyle( 1,0,4);
			setcolor(12);
			fillellipse(205,635,4,4);
			setlinestyle( 1,0,2);
			setcolor(6);				    
			setfillstyle(1,14);	
			bar(194,623,215,629);
			line(197,618,202,622);
			line(202,622,197,626);			
			line(208,622,213,618);			
			line(208,622,213,626);
			
			///carita canchera	
			setlinestyle( 1,0,2);
			setcolor(COLOR(243,165,5));
			circle(255,625,17);	
			for(x=0;x<=15;x++)
				{
					setcolor(14);
					circle(255,625,15-x);	
				}	
			setcolor(6);
			fillellipse(251,625,2,2);
			fillellipse(264,625,2,2);			
			line(245,623,250,622);			
			line(258,622,263,623);			
			line(255,633,250,633);
			line(259,630,255,633);
			
			  ///carita preocupacion
			setlinestyle( 1,0,2);
			setcolor(COLOR(243,165,5));
			circle(305,625,17);	
			for(x=0;x<=15;x++)
				{
					setcolor(14);
					circle(305,625,15-x);	
				}	
			setcolor(6);
			fillellipse(300,623,2,2);
			fillellipse(310,623,2,2); 
			line(298,633,312,630);
			
			 ///carita bah
			 setlinestyle( 1,0,2);
			setcolor(COLOR(243,165,5));
			circle(355,625,17);	
			for(x=0;x<=15;x++)
				{
					setcolor(14);
					circle(355,625,15-x);	
				}	
			setcolor(6);
			fillellipse(350,623,2,2);
			fillellipse(360,623,2,2); 
			line(348,629,362,629);
			
			 ///carita triste
			setlinestyle( 1,0,2);
			setcolor(COLOR(243,165,5));
			circle(405,625,17);	
			for(x=0;x<=15;x++)
				{
					setcolor(14);
					circle(405,625,15-x);	
				}	
			setcolor(6);
			fillellipse(400,625,2,2);
			fillellipse(410,625,2,2); 
			line(402,633,405,630);
			line(405,630,408,633);
			
			///carita indiferente	
			setlinestyle( 1,0,2);
			setcolor(COLOR(243,165,5));
			circle(455,625,17);	
			for(x=0;x<=15;x++)
				{
					setcolor(14);
					circle(455,625,15-x);	
				}	
			setcolor(6);
			fillellipse(451,625,2,2);
			fillellipse(464,625,2,2);			
			line(445,623,450,622);			
			line(458,622,463,623);			
			line(452,633,455,630);
			line(455,630,458,633);
			
			 ///carita desconfiada
			setlinestyle( 1,0,2);
			setcolor(COLOR(243,165,5));
			circle(505,625,17);		
			for(x=0;x<=15;x++)
				{
					setcolor(14);
					circle(505,625,15-x);	
				}	
			setcolor(6);
			fillellipse(500,626,2,2);
			fillellipse(510,626,2,2); 
			line(495,621,502,625);				
			line(508,622,513,621);
			line(502,633,505,630);
			line(505,630,508,633);	
			
			 ///carita enojada
			setlinestyle( 1,0,2);
			setcolor(COLOR(255,35,1));
			circle(555,625,17);		
			for(x=0;x<=15;x++)
				{
					setcolor(COLOR(255,117,20));
					circle(555,625,15-x);	
				}	
			setcolor(0);
			fillellipse(550,626,2,2);
			fillellipse(560,626,2,2); 
			line(544,621,550,624);				
			line(558,625,565,621);
			line(552,633,555,630);
			line(555,630,558,633);
			
			///carita diablito		
			setlinestyle( 1,0,2);
			setcolor(COLOR(74,25,44));
			setfillstyle(1,COLOR(74,25,44));
			pieslice(615,610,280,30,10);
			pieslice(595,610,150,-30,10);
			circle(605,625,17);		
			for(x=0;x<=15;x++)
				{
					setcolor(COLOR(160,52,114));
					circle(605,625,15-x);	
				}	
			setcolor(0);
			fillellipse(600,626,2,2);
			fillellipse(610,626,2,2); 
			line(594,621,600,624);				
			line(608,625,615,621);
			line(605,633,600,633);
			line(609,630,605,633);	
			
			 
						 ///carita tira beso
			setlinestyle( 1,0,2);
			setcolor(COLOR(243,165,5));
			circle(655,625,17);		
			for(x=0;x<=15;x++)
				{
					setcolor(14);
					circle(655,625,15-x);	
				}	
			setcolor(12);
			fillellipse(655,635,4,4);
			setcolor(6);		
			fillellipse(650,624,2,2);
			line(656,625,661,625);
			line(658,622,663,622); 
			line(645,621,650,616); 
			
					///corazon
			 	setlinestyle( 1,0,2);
			 	setfillstyle(1,4);
					for(x=0;x<=10;x++)
				{
					setcolor(4);
					circle(695,620,10-x);
					circle(713,620,10-x);	
				}	
				pieslice(704,640,43,138,20);
				
				
				
			setbkcolor(COLOR(255,255,255));				    
			setcolor(7);
			caritas(1);
			break;	
			}
			
		case 3:
			{yy=yy+15;
			xx=30;
			setlinestyle( 1,0,2);
				setcolor(COLOR(243,165,5));
				circle(xx,yy,17);	
				for(x=0;x<=15;x++)			///carita feliz
												{
													setcolor(14);
													circle(30,yy,15-x);	
												}
										setcolor(6);	
										setfillstyle(SOLID_FILL , 6);										
										fillellipse(xx,yy+5,10,7);				    
										setfillstyle(1,14);	
										bar(xx-11,yy-4,40,yy+2);
										fillellipse(xx-5,yy-5,2,5);
										fillellipse(xx+5,yy-5,2,5);
										setcolor(15);
										setlinestyle( 1,0,2);
										setlinestyle( 0,0,1);
										fillellipse(xx,yy+4,7,1);
										setbkcolor(COLOR(t11,t22,t33));
										HoraFecha2(20,yy+17);
										setlinestyle( 0,0,1);
										yy=yy+35;
								for(c=0;c<=150;c++)
		                    	R[c]=0;			
									
			break;	
			}	
			
		case 4:
			{yy=yy+15;
			xx=30;
				///carita guiño
									setlinestyle( 1,0,2);
									setcolor(COLOR(243,165,5));
									circle(xx,yy,17);			
									for(x=0;x<=15;x++)
										{
											setcolor(14);
											circle(xx,yy,15-x);	
										}	
									setcolor(6);
									fillellipse(xx-5,yy-1,2,2);
									line(xx,yy,xx+5,yy);
									line(xx+3,yy-3,xx+8,yy-3); 
									line(xx-10,yy-4,xx-5,yy-9); 
									line(xx,yy+8,xx-4,yy+5);
									line(xx+4,yy+5,xx,yy+8);
									setbkcolor(COLOR(t11,t22,t33));
									HoraFecha2(20,yy+17);
									setlinestyle( 0,0,1);
								yy=yy+35;
							 	for(c=0;c<=150;c++)
		                    	R[c]=0;		
							
			break;								
			}	
			
		case 5:
			{yy=yy+15;
			xx=30;
					///carita saca la lengua
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(12);
								fillellipse(xx,yy+10,4,4);
								setcolor(6);		
								setfillstyle(SOLID_FILL , 6);
								fillellipse(xx,yy+6,10,5);
								setlinestyle( 1,0,4);
								setcolor(12);
								fillellipse(xx,yy+10,4,4);
								setlinestyle( 1,0,2);
								setcolor(6);				    
								setfillstyle(1,14);	
								bar(xx-11,yy-2,xx+10,yy+4);
								line(xx-8,yy-7,xx-3,yy-3);
								line(xx-3,yy-3,xx-8,yy+1);			
								line(xx+3,yy-3,xx+8,yy-7);			
								line(xx+3,yy-3,xx+8,yy+1);
								setbkcolor(COLOR(t11,t22,t33));
									HoraFecha2(20,yy+17);
									setlinestyle( 0,0,1);
									yy=yy+35;	
							 	for(c=0;c<=150;c++)
		                    	R[c]=0;								
							
				break;
			}
		
		case 6:
			{yy=yy+15;
			xx=30;
				///carita canchera	
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);	
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-4,yy,2,2);
								fillellipse(xx+9,yy,2,2);			
								line(xx-10,yy-2,xx-5,yy-3);			
								line(xx+3,yy-3,xx+8,yy-2);			
								line(xx,yy+8,xx-5,yy+8);
								line(xx+4,yy+5,xx,yy+8);
								setbkcolor(COLOR(t11,t22,t33));
									HoraFecha2(20,yy+17);
									setlinestyle( 0,0,1);
									yy=yy+35;							
									for(c=0;c<=150;c++)
		                    	R[c]=0;		
				break;	
			}	
		
		case 7:
			{yy=yy+15;
			xx=30;
					  ///carita preocupacion
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);	
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-5,yy-2,2,2);
								fillellipse(xx+5,yy-2,2,2); 
								line(xx-7,yy+8,xx+7,yy+5);
								setbkcolor(COLOR(t11,t22,t33));
									HoraFecha2(20,yy+17);
									setlinestyle( 0,0,1);
									yy=yy+35;							
								for(c=0;c<=150;c++)
		                    	R[c]=0;		
				break;	
			}
		
		case 8:
			{yy=yy+15;
			xx=30;
						///carita bah
								 setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);	
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-5,yy-2,2,2);
								fillellipse(xx+5,yy-2,2,2); 
								line(xx-7,yy+4,xx+7,yy+4);
								setbkcolor(COLOR(t11,t22,t33));
									HoraFecha2(20,yy+17);
									setlinestyle( 0,0,1);
									yy=yy+35;							
							 	for(c=0;c<=150;c++)
		                    	R[c]=0;		
				break;	
			}
		
		case 9:
			{yy=yy+15;
			xx=30;
				setlinestyle( 1,0,2);
				setcolor(COLOR(243,165,5));
				circle(xx,yy,17);	
									for(x=0;x<=15;x++)
										{
											setcolor(14);
											circle(30,yy,15-x);	
										}	
									setcolor(6);
									fillellipse(xx-5,yy,2,2);
									fillellipse(xx+5,yy,2,2); 
									line(xx-3,yy+8,xx,yy+5);
									line(xx,yy+5,xx+3,yy+8);
									setbkcolor(COLOR(t11,t22,t33));
									HoraFecha2(20,yy+17);
									setlinestyle( 0,0,1);
									yy=yy+35;							
									for(c=0;c<=150;c++)
		                    	R[c]=0;		
			break;	
			}	
			
			case 10:
			{yy=yy+15;
			xx=30;
				///carita indiferente	
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);	
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-4,yy,2,2);
								fillellipse(xx+8,yy,2,2);			
								line(xx-10,yy-2,xx-5,yy-3);			
								line(xx+3,yy-3,xx+8,yy-2);			
								line(xx-3,yy+8,xx,yy+5);
								line(xx,yy+5,xx+3,yy+8);
								setbkcolor(COLOR(t11,t22,t33));
								HoraFecha2(20,yy+17);
								setlinestyle( 0,0,1);
									yy=yy+35;							
								for(c=0;c<=150;c++)
		                    	R[c]=0;			
				break;	
			}	
			
		case 11:
			{yy=yy+15;
			xx=30;
				///carita desconfiada
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(6);
								fillellipse(xx-5,yy+1,2,2);
								fillellipse(xx+5,yy+1,2,2); 
								line(xx-10,yy-4,xx-3,yy);				
								line(xx+3,yy-3,xx+8,yy-4);
								line(xx-3,yy+8,xx,yy+5);
								line(xx,yy+5,xx+3,yy+8);
								setbkcolor(COLOR(t11,t22,t33));
								HoraFecha2(20,yy+17);
								setlinestyle( 0,0,1);
									yy=yy+35;							
							 	for(c=0;c<=150;c++)
		                    	R[c]=0;		
				break;	
			}
			
		case 12:
			{yy=yy+15;
			xx=30;
				///carita enojada
								setlinestyle( 1,0,2);
								setcolor(COLOR(255,35,1));
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(COLOR(255,117,20));
										circle(xx,yy,15-x);	
									}	
								setcolor(0);
								fillellipse(xx-5,yy+1,2,2);
								fillellipse(xx+5,yy+1,2,2); 
								line(xx-11,yy-4,xx-5,yy-1);				
								line(xx+3,yy,xx+10,yy-4);
								line(xx-3,yy+8,xx,yy+5);
								line(xx,yy+5,xx+3,yy+8);
								setbkcolor(COLOR(t11,t22,t33));
								HoraFecha2(20,yy+17);
								setlinestyle( 0,0,1);
									yy=yy+35;							
									for(c=0;c<=150;c++)
		                    	R[c]=0;		
				break;	
			}
			
		case 13:
			{yy=yy+15;
			xx=30;
				///carita diablito		
								setlinestyle( 1,0,2);
								setcolor(COLOR(74,25,44));
								setfillstyle(1,COLOR(74,25,44));
								pieslice(xx+10,yy-15,280,30,10);
								pieslice(xx-10,yy-15,150,-30,10);
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(COLOR(160,52,114));
										circle(xx,yy,15-x);	
									}	
								setcolor(0);
								fillellipse(xx-5,yy+1,2,2);
								fillellipse(xx+5,yy+1,2,2); 
								line(xx-11,yy-4,xx-5,yy-1);				
								line(xx+3,yy-1,xx+10,yy-4);
								line(xx,yy+8,xx-5,yy+8);
								line(xx+4,yy+5,xx,yy+8);
								setbkcolor(COLOR(t11,t22,t33));
								HoraFecha2(20,yy+17);
								setlinestyle( 0,0,1);
									yy=yy+35;							
									for(c=0;c<=150;c++)
		                    	R[c]=0;		
				break;	
			}
		
		case 14:
			{yy=yy+15;
			xx=30;
				   ///carita tira beso
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(12);
								setfillstyle(SOLID_FILL , 6);
								fillellipse(xx,yy+10,4,4);
								setcolor(6);								
								fillellipse(xx-5,yy-1,2,2);															
								line(xx+1,yy,xx+6,yy);
								line(xx+3,yy-3,xx+8,yy-3); 
								line(xx-10,yy-4,xx-5,yy-9); 
								setbkcolor(COLOR(t11,t22,t33));
								HoraFecha2(20,yy+17);
								setlinestyle( 0,0,1);
									yy=yy+35;							
									for(c=0;c<=150;c++)
		                    	R[c]=0;		
				break;	 
			}
			
		case 15:
			{yy=yy+15;
			xx=25;
					///corazon
								 	setlinestyle( 1,0,2);
								 	setfillstyle(1,4);
										for(x=0;x<=10;x++)
									{
										setcolor(4);
										circle(xx,yy,10-x);
										circle(xx+18,yy,10-x);	
									}	
									pieslice(xx+9,yy+20,43,138,20);
									setbkcolor(COLOR(t11,t22,t33));
								HoraFecha2(20,yy+22);
								setlinestyle( 0,0,1);
									yy=yy+35;							
									for(c=0;c<=150;c++)
		                    	R[c]=0;			
				break;	 
			}
		case 16:
			{
										setbkcolor(COLOR(37,109,123));
					     				setfillstyle(1,COLOR(37,109,123));
					     				bar(100,75,300,90);
									    settextstyle(8,0,1);
									    setusercharsize(2,5,2,5);
									    setcolor(15);
									    outtextxy(100,80,"Últ. vez hoy a las");
									    HoraFecha3(205,80);	
							break;
			}
		case 17:
			{
					setcolor(15);				 //Ventana Grafica
				   	setfillstyle(1,COLOR(31,52,56));
				    bar(0,0,1024,776); 
				    setbkcolor(COLOR(31,52,56));
				    settextstyle(10,0,5);
				   	outtextxy(360,80,"Hasta Luego");
				                                        //Logo
				    for(x=0;x<=70;x++)
					{
						setcolor(1); 
						setlinestyle( 3,0,1);
				    	circle(512,350,70-x);
					}
					setcolor(15);				
				    setlinestyle ( 0,2,15);
				    circle(512,350,70);
				    line(505,305,515,365);
					circle(520,390,3);
					setcolor(1);
					circle(460,415,3);
					setcolor(15);
					line(450,430,455,390);
					line(450,430,480,418);   
					
					yy=650;
					xx=765;
					///carita saca la lengua
								setlinestyle( 1,0,2);
								setcolor(COLOR(243,165,5));
								circle(xx,yy,17);		
								for(x=0;x<=15;x++)
									{
										setcolor(14);
										circle(xx,yy,15-x);	
									}	
								setcolor(12);
								fillellipse(xx,yy+10,4,4);
								setcolor(6);		
								setfillstyle(SOLID_FILL , 6);
								fillellipse(xx,yy+6,10,5);
								setlinestyle( 1,0,4);
								setcolor(12);
								fillellipse(xx,yy+10,4,4);
								setlinestyle( 1,0,2);
								setcolor(6);				    
								setfillstyle(1,14);	
								bar(xx-11,yy-2,xx+10,yy+4);
								fillellipse(xx-5,yy-1,2,2);
									line(xx+1,yy,xx+6,yy);
									line(xx+3,yy-3,xx+8,yy-3); 
									line(xx-10,yy-3,xx-5,yy-8); 
								
					
					settextstyle(10,0,2);
					setcolor(0);
					outtextxy(800,640,"Maxi Guzmán");
						doc = fopen("CHAT.txt","a");				 
																_strtime( timeStr );
																fprintf(doc,"****************************-\nDesactivado a las: %s -\n****************************-\n\tHASTA LUEGO-\nQ", timeStr);
																fclose(doc);
					delay(2500);
				break;
			}
		for(i=0;i<=150;i++)
		{
			Z[i]=0;
			R[i]=0;
		}
	
		}
}

void archivo()
{
														
													int z=0,j=0,CC=0;
													char pal[10000],letras[2];	
												    doc=fopen("ARCHIVO.txt","r");	
													rewind(doc);	
													fread(pal,sizeof(pal),1,doc);
													j=strlen(pal);
													printf("\nj=%i",j);
													strcpy(Z,pal);
													if(j<=80)
													{																							
														presionado(1);								  
													}
						    else
						    {						    
						    setcolor(4);
						    outtextxy(290,yy,"No soportado");
							yy=yy+35;	
							}

}

void archivo2(int op)
{
	tecla=0;
	setfillstyle(10,COLOR(30,45,110));	
  	bar(0,30,1024,680);    					
	int z,xx=15,yy=40,j=0,CC=0;
	char pal[10000],letras[2];	
    doc=fopen("CHAT.txt","r");	
	rewind(doc);	
	fread(pal,sizeof(pal),1,doc);										  

	printf("%s\n",pal);
	settextstyle(0,0,2);
	setcolor(0);
	for(x=0;x<=1;x++)
			{
				letras[x]=0;
			}
switch(op)
{
	case 1:
			{	tecla=0;
					for(x=0;x<=10;x++)
							{setcolor(2);
							circle(462,580,10-x);						
							}	
							setfillstyle(1,0);
							bar(390,565,440,595);
							setcolor(15);
							line(411,580,421,580);
							line(415,575,415,585);
							rectangle(390,565,440,595);	
							setcolor(0);		
				do{
					while(tecla!=27)
									{	tecla = getch();
					       				if(tecla == 0)
					           			tecla = getch();
					       				else
					          			 switch(tecla)
					          			 {		
												case 43:
														{
																	if(doc==NULL)
																{
																	printf("Error al abrir el archivo CHAT.TXT");
																	outtextxy(220,130,"Error al abrir el archivo CHAT.txt");																	
																	while(tecla!=27)
																		{	tecla = getch();
														       				if(tecla == 0)
														           			tecla = getch();
														       				else
														          			 switch(tecla)
														          			 {
																			   	case 43:
																			   		{
																			   			setfillstyle(1,COLOR(234,230,202));
																						bar(200,100,824,500);
																			   			archivo2(1);
																			   		break;	
																					}
																				case 27:
																					{																						
																					pantalla2();																							
																					break;
																					}
																		     }
																	   }
																}	
																if(letras[0==' '])
																{																
																	getch();																							
																	archivo2(2);																					
																	break;	
																}
																z=0;
																	for(z=0;z<=2000;z++)
																	{
																		letras[0]=pal[j];																	
																		outtextxy(xx,yy,letras);																		
																				xx=xx+16;
																				j++;
																			  	z++;																			  		
																			  		if(yy>=550)	
																				    {
																				    	line(512,490,512,470);
																				    	line(502,480,512,490);
																						line(512,490,522,480);	
																						getch();															    	
																				    	setfillstyle(10,COLOR(30,45,110));	
  																						bar(0,30,1024,680);    		
																						xx=15;
																						yy=40;	
																					}
																				if(letras[0]=='-')
																					{			
																						yy=yy+25;
																						xx=15;													
																					}												
																			
																	for(x=0;x<=2;x++)
																		letras[x]=0;
																	}									
														
																break;
														}
															
													case 27:
														{			
														setbkcolor(15);																																							
																	pantalla2();
																		break;
														}
											}
									}						
				
				}while(letras[0!='Q']); 
			break;
			}
			
	case 2:
		{
				tecla=0;
					while(tecla!=27)
									{	tecla = getch();
					       				if(tecla == 0)
					           			tecla = getch();
					       				else
					          			 switch(tecla)
					          			 {		
												case 45:
													{
														setfillstyle(1,COLOR(234,230,202));
														bar(0,35,600,700);		
														archivo2(1);
														break;
													}
													
													case 27:
														{				
															pantalla2();		
																		break;
														}
										 }		
									}
		break;
     	}
}
}

