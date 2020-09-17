#define s0 4
#define s1 5
#define s2 6                   
#define s3 7
#define sensorOut 8
#define control1 13
// Arduino 2
//#define control2 12
//#define control3 2
#define motor1 9
#define motor2 10
#define motor3 11
//#define crop1 3
#define crop2 4
//#define crop3 9
#include <LiquidCrystal.h>

int frequency1 = 0, Nvalue=0, Pvalue=0, Kvalue=0;

int frequency2 = 0;

int frequency3 = 0;
int x1;
int x2;
int x3;
int crop1;
int button1;
int button2;
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(14, 15, 16, 17, 18, 19);


void setup() {
   // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("HELL0");
  delay(1000);
  lcd.clear();
  x1 =0;
  x2 =0;
  x3 =0;
  crop1 =3;
  button1 = 2;
  button2 = 12;
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(crop1,INPUT);

 pinMode(motor1,OUTPUT);
 pinMode(motor2,OUTPUT);
 pinMode(motor3,OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(control1, INPUT);
 
  pinMode(button1,INPUT_PULLUP);
  pinMode(button2,INPUT_PULLUP);
  digitalWrite(s0, HIGH);
  digitalWrite(s1, LOW);
  Serial.begin(115200);
  // set up the LCD's number of columns and rows:
 // lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hell0");
}

void loop() {


  // FOR NITROGEN
  if (digitalRead(control1) == LOW)
  {
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    frequency1 = pulseIn(sensorOut, LOW);
    Serial.print("Rn= ");
    Serial.print(frequency1);
    Serial.print("    ");
    delay(1000);
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    frequency2 = pulseIn(sensorOut, LOW);
    Serial.print("Gn= ");
    Serial.print(frequency2);
    Serial.print("    ");
    delay(1000);
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    frequency3 = pulseIn(sensorOut, LOW);
    Serial.print("Bn=  ");
    Serial.println(frequency3);
    //Serial.println("\n");
  //delay(1000);
    // Turn off the display:
   //lcd.noDisplay();
  //delay(500);
    // Turn on the display:
  //lcd.display();
  //delay(500);
  

    // comparing values low, medium , low
    if ((frequency1 < 11 ) && ((frequency2 > 36) &&(frequency2 < 46)) && ((frequency3 >20) && (frequency3 < 30))) {
          lcd.noDisplay();
          delay(500);
    // Turn on the display:
          lcd.display();
          //delay(500);
          lcd.print("N IS L0W");
          Serial.print("n is low");
          Nvalue=1;
      // value '1' for low
    }
    
    else if (((frequency1 > 11 ) && (frequency1 < 22)) && ((frequency2 > 46 ) && (frequency2 < 63)) && ((frequency3 > 30 ) && (frequency3 < 41))) {
          lcd.clear();
          lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
    lcd.print("N IS MEDIUM");
       Serial.print("n is medium");
      Nvalue=2;
      // value '2' for medium
    }
    
    //if (((frequency1 >22) && (frequency1< 47)) &&(frequency2 >63)&& (frequency3 >41))
    else {
          lcd.clear();
          lcd.noDisplay();
          delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
    lcd.print("N IS HIGH");
       Serial.print("n is high");
      Nvalue=3;
      // value '3' for high
    }
  }

  //FOR PHOSPHOROUS
  else if (digitalRead(button1) == LOW)
  { 
    
      x1 = 1;
      
     }
  if(x1 > 0){
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    frequency1 = pulseIn(sensorOut, LOW);
    Serial.print("Rp= ");
    Serial.print(frequency1);
    Serial.print("    ");
    delay(1000);

    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    frequency2 = pulseIn(sensorOut, LOW);
    Serial.print("Gp= ");
    Serial.print(frequency2);
    Serial.print("    ");
    delay(1000);
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    frequency3 = pulseIn(sensorOut, LOW);
    Serial.print("Bp=  ");
    Serial.println(frequency3);
    //Serial.println("\n");
   //delay(1000);
    // Turn off the display:
  //lcd.noDisplay();
  //delay(500);
    // Turn on the display:
  //lcd.display();
   //delay(500);


    // comparing values low, medium , low
    if ((frequency1 >12) && (frequency1 < 47 ) && (frequency2 < 36) && (frequency3 < 20)) {
      lcd.clear();
          lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
    lcd.print("P IS L0W");
       Serial.print("p is low");
      Pvalue=1;
    }
    else if (((frequency1 > 47 ) && (frequency1 < 59)) && ((frequency2 > 36 ) && (frequency2 < 46)) && ((frequency3 > 20 ) && (frequency3 < 28))) {
       lcd.clear();
          lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
    lcd.print("P IS MEDIUM");
       Serial.print("p is medium");
      Pvalue=2;
    }
    else {
       lcd.clear();
          lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
     lcd.print("P IS HIGH");
      Serial.print("p is high");
      Pvalue=3;
    }
    x1 = 0;
  }

  //FOR POTASSIUM
  else if (digitalRead(button2) == LOW)
  {  
    
      x2 = 1;
  }
  if(x2 > 0){
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);
    frequency1 = pulseIn(sensorOut, LOW);
    Serial.print("Rk= ");
    Serial.print(frequency1);
    Serial.print("    ");
    delay(1000);
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
    frequency2 = pulseIn(sensorOut, LOW);
    Serial.print("Gk= ");
    Serial.print(frequency2);
    Serial.print("    ");
    delay(1000);
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
    frequency3 = pulseIn(sensorOut, LOW);
    Serial.print("Bk=  ");
    Serial.println(frequency3);
    //Serial.println("\n");
  //delay(1000);                
    // Turn off the display:
  //lcd.noDisplay();
    //delay(500);
    // Turn on the display:
  //lcd.display();
  //delay(500);
    


    // comparing values low, medium , low
    if ((frequency1 > 31 ) && (frequency2 > 42) && (frequency3 > 36)) {
       lcd.clear();
          lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
    lcd.print("K IS L0W");
      Kvalue=1;
    }
    else if (((frequency1 > 21 ) && (frequency1 < 30)) && ((frequency2 > 30 ) && (frequency2 < 42)) && ((frequency3 > 25 ) && (frequency3 < 35))) {
       lcd.clear();
          lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
     lcd.print("K IS MEDIUM");
      Kvalue=2;
    }
    else {
       lcd.clear();
          lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
    lcd.print("K IS HIGH");
      Kvalue=3;
    }
    x2 = 0;
    delay(1000);
       lcd.clear();
          lcd.noDisplay();
    delay(500);
    // Turn on the display:
    lcd.display();
    delay(500);
    lcd.print("SELECT CR0P");
  }

   if (digitalRead(crop1) == LOW)
  {  
    
      x3 = 10;
  }
    if(x3 > 0){
      Serial.print("entered loop1");
      if(Nvalue==1)
      {
      digitalWrite(motor1, HIGH);//if N value is low for 1st crop
      delay(10000);
      digitalWrite(motor1, LOW);
    }
    else if(Nvalue==2)
    {
      digitalWrite(motor1, HIGH);
      delay(2000);
      digitalWrite(motor1, LOW);
    }
    else if(Nvalue==3)
    {
      digitalWrite(motor1, HIGH);
      delay(5000);
      digitalWrite(motor1, LOW);
    }
    // code to dispense P for crop1
     if(Pvalue==1)
      {
      digitalWrite(motor2, HIGH);//if N value is low for 1st crop
      delay(10000);
      digitalWrite(motor2, LOW);
    }
    else if(Pvalue==2)
    {
      digitalWrite(motor2, HIGH);
      delay(10000);
      digitalWrite(motor2, LOW);
    }
    else if(Pvalue==3)
    {
      digitalWrite(motor2, HIGH);
      delay(10000);
      digitalWrite(motor2, LOW);
    }
      if(Kvalue==1)
      {
      digitalWrite(motor3, HIGH);//if N value is low for 1st crop
      delay(10000);
      digitalWrite(motor3, LOW);
    }
    else if(Kvalue==2)
    {
      digitalWrite(motor3, HIGH);
      delay(10000);
      digitalWrite(motor3, LOW);
    }
    else if(Kvalue==3)
    {
      digitalWrite(motor3, HIGH);
      delay(10000);
      digitalWrite(motor3, LOW);
    }
    x3=0;
 }
} 
 /*else if(crop2 == LOW){
  if(digitalRead(crop1) ==LOW)
    {
      Serial.print("entered loop");
      if(Nvalue==1)
      {
      digitalWrite(motor1, HIGH);//if N value is low for 1st crop
      delay(10000);
      digitalWrite(motor1, LOW);
    }
    else if(Nvalue==2)
    {
      digitalWrite(motor1, HIGH);
      delay(2000);
      digitalWrite(motor1, LOW);
    }
    else if(Nvalue==3)
    {
      digitalWrite(motor1, HIGH);
      delay(5000);
      digitalWrite(motor1, LOW);
    }
    // code to dispence P for crop1
     if(Pvalue==1)
      {
      digitalWrite(motor2, HIGH);//if N value is low for 1st crop
      delay(10000);
      digitalWrite(motor2, LOW);
    }
    else if(Pvalue==2)
    {
      digitalWrite(motor2, HIGH);
      delay(10000);
      digitalWrite(motor2, LOW);
    }
    else if(Pvalue==3)
    {
      digitalWrite(motor2, HIGH);
      delay(10000);
      digitalWrite(motor2, LOW);
    }
      if(Kvalue==1)
      {
      digitalWrite(motor3, HIGH);//if N value is low for 1st crop
      delay(10000);
      digitalWrite(motor3, LOW);
    }
    else if(Kvalue==2)
    {
      digitalWrite(motor3, HIGH);
      delay(10000);
      digitalWrite(motor3, LOW);
    }
    else if(Kvalue==3)
    {
      digitalWrite(motor3, HIGH);
      delay(10000);
      digitalWrite(motor3, LOW);
    }   }}*/
    
