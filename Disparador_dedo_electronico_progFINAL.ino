#include <Servo.h>

Servo motor;


 
int valor, valor1, estado;


//PULSADORES
const int pulsador_asc = 8;
const int pulsador_des = 12;
const int botonselect = 10;

//LEDS
int led1 = 2;
int led2 = 3;
int estado_led_1 = 0;
int estado_led_2 = 0;

//CONTADORES
int contador = 0;
int contador_sumaseg = 0;
int contador_sumamin = 0;

//VARIABLES PROGRAMA PERSONALIZADO
int tiemposeg = 1000;
float tiempomin = 60000;

int programa_personalizado = 0;
int estado_pulsador_sumaseg = 0;
int lastbuttonstate_sumaseg = 1;
int estado_pulsador_sumamin = 0;
int lastbuttonstate_sumamin = 1;

//ESTADO DE LOS PULSADORES

int selectpulsado = 0;

int lastbuttonstate_select = 1;


int estado_pulsador_asc = 0;
int lastbuttonstate_asc = 1;

int estado_pulsador_des = 0;
int lastbuttonstate_des = 1;




void setup() {

    
  motor.attach(6);
  Serial.begin(9600);
  Serial.println("BIENVENIDA/O AL DISPARADOR AUTOMATICO");
  motor.write(0);
  pinMode(pulsador_asc,INPUT);
  pinMode(pulsador_des, INPUT);
  pinMode(botonselect, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
}

void loop() {
  
  

   
  selectpulsado = digitalRead(botonselect);
  estado_pulsador_asc = digitalRead(pulsador_asc);  
  estado_pulsador_des = digitalRead(pulsador_des);
  estado_pulsador_sumaseg = digitalRead(pulsador_asc);
  estado_pulsador_sumamin = digitalRead(pulsador_des);
  estado_led_1 = digitalRead(led1);
  estado_led_2 =  digitalRead(led2); 

  
  //Serial.println(selectpulsado);
  //Serial.println(estado_pulsador_des);
  //delay(1000);
  

 if ((estado_pulsador_sumaseg == HIGH )&&(estado_pulsador_sumamin== HIGH )&&(selectpulsado == HIGH))

                   {
                     digitalWrite(led1, HIGH);
                     digitalWrite(led2, HIGH);
                     delay(100);
                     digitalWrite(led1, LOW);
                     digitalWrite(led2, LOW);
                     delay(100);                   
                     digitalWrite(led1, HIGH);
                     digitalWrite(led2, HIGH);
                     delay(100);
                     digitalWrite(led1, LOW);
                     digitalWrite(led2, LOW);
                     delay(100);                   
                     digitalWrite(led1, HIGH);
                     digitalWrite(led2, HIGH);
                     delay(100);
                     digitalWrite(led1, LOW);
                     digitalWrite(led2, LOW);
                     delay(100);                   
                     digitalWrite(led1, HIGH);
                     digitalWrite(led2, HIGH);
                     delay(100);
                     digitalWrite(led1, LOW);
                     digitalWrite(led2, LOW);
                     delay(100);                   
                     digitalWrite(led1, HIGH);
                     digitalWrite(led2, HIGH);
                     delay(100);
                     digitalWrite(led1, LOW);
                     digitalWrite(led2, LOW);     
                     
                     
                     
                    Serial.print("BORRADO");
                    contador = 0;
                    programa_personalizado = 0;
                    contador_sumaseg = 0;
                    contador_sumamin = 0 ;
                    delay(5000);
                    
                    }

  
  if((estado_pulsador_asc != lastbuttonstate_asc)&&(programa_personalizado == 0))
  {  
     if(estado_pulsador_asc == HIGH)
     { 
        contador++;
        if ( contador >= 4)
    {
      contador = 4;}
        Serial.println("+");
        Serial.print("programa numero: ");
        Serial.println(contador);
        delay(100);
     }
  }
  lastbuttonstate_asc = estado_pulsador_asc;

  if ((estado_pulsador_des != lastbuttonstate_des)&&(programa_personalizado == 0))
  {
    if(estado_pulsador_des == HIGH)
    {
      
    contador --;
    if  
       (contador < 1 )
    {
      contador = 0;
    }
      
    Serial.println("-");
    Serial.print("programa numero: ");
    Serial.println(contador);
    delay(100);
    }
  } 

  lastbuttonstate_des = estado_pulsador_des;

if((estado_pulsador_asc == HIGH)&&(estado_pulsador_des == HIGH))
      {
      
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        delay(100);
      }
      
  
  
if((estado_pulsador_asc == HIGH)&&(estado_pulsador_des == LOW)){
        digitalWrite(led1, HIGH);
        delay(100);
        digitalWrite(led1, LOW);
      }
 if ((estado_pulsador_des == HIGH)&&(estado_pulsador_asc == LOW)){
         digitalWrite(led2, HIGH);
         delay(100);
         digitalWrite(led2, LOW);
      }

    


  
switch(contador)
{
  case 4:
      
    
         // 
     if((contador == 4)&&(selectpulsado == HIGH))//(selectpulsado != lastbuttonstate_select)
     {  
        //case true:  
        //if(selectpulsado == HIGH);
        
        //Serial.print ("programa personalizado 1");
        programa_personalizado = 1;

        
          
         switch(estado_pulsador_sumaseg != lastbuttonstate_sumaseg)
            
            {
            case true :




            
            Serial.println("FUNCIONAAAA");
            
            Serial.println(selectpulsado);
            
               
               if(estado_pulsador_sumaseg == HIGH)//&&(selectpulsado==LOW))
                   { 
                  //case HIGH:
                       
                      contador_sumaseg++;
                      Serial.println("+");
                      Serial.print("suma 1 segundo: ");
                      Serial.println(contador_sumaseg);
                      delay(100);
                      //selectpulsado = LOW;
                      delay(100);

                       //if (contador_sumaseg ++ ) {
                         //tiempo = +6000;
                           // }


                    
                   }

                  lastbuttonstate_sumaseg = estado_pulsador_sumaseg;
            break; 
            }
            
                      
                   switch(estado_pulsador_sumamin != lastbuttonstate_sumamin)
            
            {
            case true :
            
            Serial.println("FUNCIONAAAA???");
            
            Serial.println(selectpulsado);
            
               
               if(estado_pulsador_sumamin == HIGH)//&&(selectpulsado==HIGH))
                   { 
                    
                  //case HIGH:
                       
                      contador_sumamin++;
                      Serial.println("+");
                      Serial.print("suma 1 minuto: ");
                      Serial.println(contador_sumamin);
                      delay(100);
                      //selectpulsado = LOW;
                      delay(100);

                       //if (contador_sumaseg ++ ) {
                         //tiempo = +6000;
                           // }
                   

                    
                   }
                  

                    lastbuttonstate_sumamin = estado_pulsador_sumamin ;
                      break; 
                     
                    }
       
              if ((estado_pulsador_sumaseg == HIGH )&&(estado_pulsador_sumamin== HIGH )&&(selectpulsado == HIGH))

                   {
                    Serial.print("BORRADO");
                    contador = 0;
                    programa_personalizado = 0;
                    contador_sumaseg = 0;
                    contador_sumamin = 0 ;
                    delay(5000);
                    
                    }
              
             //Serial.println(estado_pulsador_sumaseg);
            //Serial.println(lastbuttonstate_sumaseg);
            selectpulsado = lastbuttonstate_select ;
          
      }
      
      //Serial.println(selectpulsado);
     //if (selectpulsado == HIGH)
          //{ 
          
           //programa_personalizado = 0;
         // }
        // break;   

   
     
     
  case 1:
     if((contador == 1)&&(selectpulsado ==HIGH))
     { 

        delay(5000);
        motor.write(90);
        delay(5000);
        motor.write(0);
        selectpulsado = LOW;
        contador = 0;

     }  
     break;
   case 2:
         if((contador == 2)&&(selectpulsado ==HIGH))
     { 

        delay(1000);
        motor.write(120);
        delay(1000);
        motor.write(0);
        selectpulsado = LOW;  
        contador = 0;
      }
      break;
    case 3:
        if ((contador == 3)&&(selectpulsado==HIGH))
      {
         delay(1000);
         motor.write(50);
         delay(1000);
         motor.write(90);
         delay(1000);
         motor.write(0);
         selectpulsado = LOW;
         contador = 0;
         
      }
      break;
}
   //switch(contador_sumaseg) {
                  
                  //case 1:
                  
                  //Serial.println(selectpulsado);
                        if((contador_sumaseg  > 0  )&&(selectpulsado == LOW))
                            {
                         
                           tiemposeg = (contador_sumaseg * tiemposeg);
                           tiempomin = (contador_sumamin * tiempomin);    
                        float  tiempodelay = (tiempomin + tiemposeg);  
                              
                              Serial.println(tiempodelay);
                              
                              delay(1000);
                              motor.write(90);
                              
                              //for (int contador_sumaseg =+1;contador_sumaseg<60000;contador_sumaseg=+6000){
                              
                              delay(tiempodelay);
                              motor.write(0);
                              contador_sumaseg = 0;
                              contador_sumamin = 0 ;
                              contador = 0;
                              programa_personalizado = 0;
                              tiemposeg = 1000;
                              tiempomin = 60000;
                              //}
                            }


if((contador_sumamin  > 0  )&&(selectpulsado == LOW))
                            {
                         
                           tiemposeg = (contador_sumaseg * tiemposeg);
                           tiempomin = (contador_sumamin * tiempomin);    
                        float  tiempodelay = (tiempomin + tiemposeg);  
                              
                              Serial.println(tiempodelay);
                              
                              delay(1000);
                              motor.write(90);
                              
                              //for (int contador_sumaseg =+1;contador_sumaseg<60000;contador_sumaseg=+6000){
                              
                              delay(tiempodelay);
                              motor.write(0);
                              contador_sumaseg = 0;
                              contador_sumamin = 0 ;
                              contador = 0;
                              programa_personalizado = 0;
                              tiemposeg = 1000;
                              tiempomin = 60000;
                              //}
                            }

                            
                        
                             
                    //break;

                    //case 2 :

                            //if(selectpulsado ==LOW)
                                // {
                              //delay(1000);
                              //motor.write(90);
                              //delay(2000);
                             // motor.write(0);
                             // contador_sumaseg = 0;
                             // contador = 0;
                             // programa_personalizado = 0;
                             //    }
                     //break;

                     //case 3 :
                          // if(selectpulsado == LOW) 
                            // {
                             // delay(1000);
                             // motor.write(90);
                             // delay(1000);
                             // motor.write(120);
                             // delay(1000);
                             // motor.write(0);
                              //contador_sumaseg = 0;
                             //contador = 0;
                              //programa_personalizado = 0;
                           // }    
                      //break;          
                     //} 
}
   
