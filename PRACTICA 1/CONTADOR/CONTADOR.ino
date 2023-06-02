/*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre:Pablo David Hernandez Ajiataz
 * Carnet: 2022472
 * Proyecto: Uso de interrupciones externas - Bimestre III
*/


//Directivas de preprocesador
#define btn_rising  2     //pin 2 utilizado para una interrupción externa por rising
#define btn_falling 3     //pih 3 utilizado para una interrupción externa por falling
#define A 4
#define B 5
#define C 6
#define D 7

#define A2 8
#define B2 9
#define C2 10
#define D2 11


int NUMERO=0;
int NUMERO2=0;


void funcion_ISR_falling(void);
void funcion_ISR_rising(void);


void setup() {
  pinMode(btn_rising, INPUT);  //pin 2 como entrada
  pinMode(btn_falling, INPUT); //pin 3 como entrada
  attachInterrupt(digitalPinToInterrupt(btn_rising),funcion_ISR_rising,RISING);   //Anclar la interrupción del pin 2 a una funcion de ISR, disparada por el flanco ascendente
  attachInterrupt(digitalPinToInterrupt(btn_falling),funcion_ISR_falling,FALLING); //Anclar la interrupción del pin 3 a una funcion de ISR, disparada por el flanco descendente
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);

  pinMode(A2,OUTPUT);
  pinMode(B2,OUTPUT);
  pinMode(C2,OUTPUT);
  pinMode(D2,OUTPUT); 
}

void loop() {
  LIMITES();
  DECENA();
  UNIDAD();
}
//////Funciones de ISR//////
void funcion_ISR_rising(void)
{
  NUMERO=NUMERO+1;  
}

void funcion_ISR_falling(void)
{
  NUMERO=NUMERO-1;
}


/////FUNCIONES DE NUMEROS BINARIOS/////
void DECENA(){
  switch (NUMERO2){
    case (0):{
      digitalWrite(A2,LOW);
      digitalWrite(B2,LOW);
      digitalWrite(C2,LOW);
      digitalWrite(D2,LOW);
      
    break;
    }
      case (1):{
      digitalWrite(A2,HIGH);
      digitalWrite(B2,LOW);
      digitalWrite(C2,LOW);
      digitalWrite(D2,LOW);
      
    break;
    }

      case (2):{
      digitalWrite(A2,LOW);
      digitalWrite(B2,HIGH);
      digitalWrite(C2,LOW);
      digitalWrite(D2,LOW);
     
    break;
    }
      case (3):{
      digitalWrite(A2,HIGH);
      digitalWrite(B2,HIGH);
      digitalWrite(C2,LOW);
      digitalWrite(D2,LOW);
   
    break;
    }
      case (4):{
      digitalWrite(A2,LOW);
      digitalWrite(B2,LOW);
      digitalWrite(C2,HIGH);
      digitalWrite(D2,LOW);
    
    break;
    }
      case (5):{
      digitalWrite(A2,HIGH);
      digitalWrite(B2,LOW);
      digitalWrite(C2,HIGH);
      digitalWrite(D2,LOW);  
    break;
    }
 }
}
void UNIDAD(){
   switch (NUMERO){
    case (0):{
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    }
      case (1):{
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      
    break;
    }

      case (2):{
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      
    break;
    }
      case (3):{
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
      
    break;
    }
      case (4):{
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      
    break;
    }
      case (5):{
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      
    break;
    }
          case (6):{
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      
    break;
    }
          case (7):{
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
      
    break;
    }
          case (8):{
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
      
    break;
    }
          case (9):{
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH); 
    break;
    }
  }
}
////////FUNCION PARA LOS LIMITES///////
void LIMITES(){
   if(NUMERO>0&&NUMERO2==5){
  NUMERO2=0;
  NUMERO=0;
  }
  else if(NUMERO<0&&NUMERO2==0){
  NUMERO2=5;
  NUMERO=0;
  } 
  else if(NUMERO>9){ 
  NUMERO=0;
  NUMERO2=NUMERO2+1;
  }
  else if(NUMERO<0){
  NUMERO=9;
  NUMERO2=NUMERO2-1;
  }
 
}
