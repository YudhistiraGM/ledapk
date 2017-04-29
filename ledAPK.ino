
#define led 3 // Pin PWM D3

#define serial_TX 1
#define serial_RX 0

int PWM = 0;

char inSerial[5];

void setup() {
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);

  pinMode(serial_TX, OUTPUT);
  pinMode(serial_RX, INPUT);

  Serial.println("Bluetooth conectado:");
}

void loop() {
  
  int i=0;
  delay(100);
  
  if (Serial.available() > 0) {
    
    while (Serial.available() > 0) {
      
      inSerial[i]=Serial.read();
      i++;
    }
    
  inSerial[i]='\0';
  Check_Protocol(inSerial);
  }
}

void Check_Protocol(char inStr[]) {

  Serial.println(inStr);
  
  if(!strcmp(inStr,"off")) { //Led Off

    analogWrite(led, 0);
    inStr = "0";
    Serial.println("led OFF");
  }
    
  if(!strcmp(inStr,"on")) { //Led on

    analogWrite(led, 255);
    inStr = "255";
    Serial.println("led ON");
  }

  PWM = atol(inStr);
  Serial.print("PWM = ");
  Serial.println(PWM);

  if(PWM >= 0 && PWM <= 255) {

    analogWrite(led, PWM);
  }
}
