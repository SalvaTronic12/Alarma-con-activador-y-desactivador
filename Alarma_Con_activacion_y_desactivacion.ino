char data[4];
char data1[20];
char ClaveInicio[4] = {'A','B','C','D'};
int iden,iden1,Contador,dataIndex = 0,sensor;
int claveFinal = 1234;
void setup()
{
   Serial.begin(9600);
  pinMode(7,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
   
}
void loop()
{
  
  
    
   while (Serial.available())
   {
      char character = Serial.read();
      if (character != '\n')
      {
         data[dataIndex] = character;
         dataIndex ++;
      }
  
   }
 
    
  
  
  for(int i=0;i<4;i++){
    if(ClaveInicio[i] == data[i]){
      iden=1;
    }
  }
  if(iden == 1){
  Serial.println("Alarma Activada");
  }
  
  while(iden==1){
    sensor = digitalRead(8);
     
    if(sensor==1){
      
      while(iden==1){
        digitalWrite(9,HIGH);
        digitalWrite(10,HIGH);
        delay(1000);
        digitalWrite(10,LOW);
        digitalWrite(7,HIGH);
        delay(1000);
        digitalWrite(7,LOW);
      
    Contador = 0;
        
        while (Serial.available())
   {
      char caracter = Serial.read();
      if (caracter != '\n')
      {
         data1[Contador] = caracter;
         Contador++;
      }
     
   }
   
 
  int convertido = String(data1).toInt();
        
   
        
        //-------------
        if(convertido == claveFinal){
        Serial.println("Alarma Desactivada");
        digitalWrite(9,LOW);
        digitalWrite(10,LOW);
        digitalWrite(7,LOW);
         
          iden = 0;
          data[0] = 'a';
        }
      
      }
    }
     
    
    
    
  }
  
   dataIndex = 0;
   iden =0;

 
}
