// sonar.ino

int sonar_trig_esq = 2;
int sonar_echo_esq = 3;

int sonar_trig_dir = 4;
int sonar_echo_dir = 5;

#define MotorDir1 11
#define MotorDir2 10
#define MotorEsq2 8
#define MotorEsq1 9

#define sensor_cor A0
#define sensor_chama A1

//Valores cartolina, teste na arena
// Branco -> 
// Verde ->
// Vermelho ->
// Preto -> 

int branco = 500; // Valor intermedio entre o preto e branco
int valor_chama = 15; // A vela estava pequena

boolean quarto = false;
boolean apagar = false;


void setup(){
   pinMode(MotorDir1, OUTPUT);
   pinMode(MotorDir2, OUTPUT);
   pinMode(MotorEsq1, OUTPUT);
   pinMode(MotorEsq2, OUTPUT);
        
   pinMode(sonar_trig_esq, OUTPUT);
   pinMode(sonar_echo_esq, INPUT);
   pinMode(sonar_trig_dir, OUTPUT);
   pinMode(sonar_echo_dir, INPUT);
   
    pinMode(sensor_cor, INPUT);
   
   Serial.begin(9600);
}

void loop() {
  
  unsigned long val = millis();
  
  if(sonares(sonar_trig_dir, sonar_echo_dir) >= 40){
    Motores(100,55); //70
    delay(20);
  }
  else if( sonares(sonar_trig_dir, sonar_echo_dir) < 30 ){
    Motores(20,100); //30
  }else if( sonares(sonar_trig_dir, sonar_echo_dir) >= 35 ){
    Motores(100,40);
  }else{
    Motores(100,100);
  }
  
  Serial.println(millis()-val);
  
  while(millis()-val < 45 /*sensor != branco*/){ 
    
//    if(cor() > branco){
//        quarto = true; // entrou no quarto
//        //room();
//        Motores(0,0);
//        delay(5000);
//    } 

    if(chama() > valor_chama){
       vela();
    }
    
  }
  delay(20);
 	
}

void vela(){
  
  while(!apagar){
      
    // Virar a esquerda
    while(true){
       Motores(0,60);
       if(chama() < 300){
         break;
       }
       delay(800);
    }
    
    //Virar a direita
    while(true){
       Motores(60,0);
       if(chama() < 300){
         break;
       }
       delay(800); //Se diminuir a velocidade compensar com o delay
    }
    
    if(chama() > 20){
      Motores(0,0);
      delay(5000);
    }
     
  }
}

void room(){
 
    Serial.println("ENTROU EM ROOM");
 
    if(chama() > valor_chama){ // Tambem tem que saber q entrou no quarto, se nao no quarto 3 ele detecta no corredor a vela
       encontra_vela();  
    }
    
    if (cor() > branco){ // Se voltar a encontrar branco ( linha ) quer dizer q esta a sair do quarto
      quarto = false; // saiu do quarto
    }

   //Se entrar na porta torto
   if(sonares(sonar_trig_esq, sonar_echo_esq) > 30){
     //Roda
     Motores(0,50);
     delay(300);
   }

}

void encontra_vela() {
  
  //Debug
  Motores(0,0);
  delay(5000);
  
}
