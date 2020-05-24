#include <LiquidCrystal.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
 
MFRC522 rfid(SS_PIN, RST_PIN); // Instance of the class
LiquidCrystal lcd(7,6,5,4,3,2);
const int buzzer=8;
int rled=A1;
int gled=A0;
String UID1="42:3B:71:15";
String UID2="5B:39:28:83";
String UID3="76:D9:7E:F8";
String UID4="7B:41:39:0C";
String name1="Rachit";
String name2="Varsha";
String name3="Richa";
String name4="Anu";

MFRC522::MIFARE_Key key; 


void setup() { 
  Serial.begin(9600);
  SPI.begin(); // Init SPI bus
  lcd.begin(16,2);
  rfid.PCD_Init(); // Init MFRC522 
  pinMode(buzzer,OUTPUT);
  pinMode(rled,OUTPUT);
  pinMode(gled,OUTPUT);
  digitalWrite(rled,LOW);
  digitalWrite(gled,LOW);
  Serial.println("PUT YOUR CARD");
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("PUT YOUR CARD");

 
  }
 
void loop() {
    // Look for new cards
  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  // Verify if the NUID has been readed
  if ( ! rfid.PICC_ReadCardSerial())
    return;
  tone(buzzer,1000);
  delay(500);
  noTone(buzzer);
 
  
  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);
  
  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&  
    piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
    piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

 String ID="";
   
    for (byte i = 0; i < 4; i++) {
      ID+= (rfid.uid.uidByte[i]<0x10 ? "0":"")+String(rfid.uid.uidByte[i],HEX)+(i!=3 ? ":":"");
    }
     ID.toUpperCase();
    Serial.println("YOUR CARD'S UID: ");
    Serial.println(ID);
  if(ID==UID1){
    Serial.println("Rachit Present");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(name1);
    lcd.setCursor(0,1);
    lcd.print("Present");
    tone(buzzer,1000);
    digitalWrite(gled,HIGH);
    delay(1000);
    noTone(buzzer);
    digitalWrite(gled,LOW);
    Serial.println("PUT YOUR CARD");
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("PUT YOUR CARD");
  }
   else if(ID==UID2){
    Serial.println("Varsha Present");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(name2);
    lcd.setCursor(0,1);
    lcd.print("Present");
    tone(buzzer,1000);
    digitalWrite(gled,HIGH);
    delay(1000);
    noTone(buzzer);
    digitalWrite(gled,LOW);
    Serial.println("PUT YOUR CARD");
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("PUT YOUR CARD");
   }
  else if(ID==UID3){
    Serial.println("Richa present");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(name3);
    lcd.setCursor(0,1);
    lcd.print("Present");
    tone(buzzer,1000);
    digitalWrite(gled,HIGH);
    delay(1000);
    noTone(buzzer);
    digitalWrite(gled,LOW);
    Serial.println("PUT YOUR CARD");
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("PUT YOUR CARD");
   }
   else if(ID==UID4){
    Serial.println("Anu Present");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(name2);
    lcd.setCursor(0,1);
    lcd.print("Present");
    tone(buzzer,1000);
    digitalWrite(gled,HIGH);
    delay(1000);
    noTone(buzzer);
    digitalWrite(gled,LOW);
    Serial.println("PUT YOUR CARD");
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("PUT YOUR CARD");
   }
   else{
    Serial.println("Unknown RFID CARD");
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Unknown RFID");
    lcd.setCursor(0,1);
    lcd.print("Card");
    tone(buzzer,1000);
    digitalWrite(rled,HIGH);
    delay(1000);
    noTone(buzzer);
    digitalWrite(rled,LOW);
    Serial.println("PUT YOUR CARD");
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("PUT YOUR CARD");
  }
  // Halt PICC
  rfid.PICC_HaltA();

  // Stop encryption on PCD
  rfid.PCD_StopCrypto1();

}
