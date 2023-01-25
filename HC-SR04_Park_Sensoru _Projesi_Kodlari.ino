const int trig = 7;  // değişkenler tanımla.
const int echo = 8;
int mesafe;
int zaman;

const int buzzer = 6;
const int kirmizi = 2;
const int sari = 3;
const int yesil = 4;
const int mavi = 5;

void setup() {
  pinMode(trig,OUTPUT); // trig pini çıkış olsun.
  pinMode(echo,INPUT);  // echo pini giriş olsun.
  
  pinMode(buzzer,OUTPUT); // buzzer pini çıkış olsun.
  pinMode(kirmizi,OUTPUT); // LED bağlı pinler çıkış olsun.
  pinMode(sari,OUTPUT);
  pinMode(yesil,OUTPUT);
  pinMode(mavi,OUTPUT);
  Serial.begin(9600);  // seri haberleşme başlat.
}

void loop() {
  digitalWrite(trig,HIGH);
  delay(1);
  digitalWrite(trig,LOW);
  // 1 msn aralıklarla trig pinini HIGH yap.
  
  zaman=pulseIn(echo,HIGH);
  mesafe=(zaman/2)/28.9;
  // sıcaklık 25 derece için katsayı=28,9

Serial.println("UZAKLIK =");
Serial.print(mesafe);
Serial.println("cm"); 
Serial.println("--------------------------"); 

if ((mesafe >= 0) && (mesafe <= 10)){
  //mesafe 0 ile 10cm arasındaysa...
  digitalWrite(kirmizi,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(kirmizi,LOW);
  digitalWrite(buzzer,LOW);
  delay(250);
}
else if ((mesafe >= 10) && (mesafe <= 30)){
  //mesafe 10cm-30cm arasındaysa...
  digitalWrite(sari,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(sari,LOW);
  digitalWrite(buzzer,LOW);
  delay(500);
}
else if ((mesafe >= 30) && (mesafe <= 50)){
  //mesafe 30cm-50cm arasındaysa...
  digitalWrite(yesil,HIGH);
  digitalWrite(buzzer,HIGH);
  delay(50);
  digitalWrite(yesil,LOW);
  digitalWrite(buzzer,LOW);
  delay(750);
}  
else if(mesafe >= 50){
  //mesafe 50cm'den büyükse...
  digitalWrite(mavi,HIGH);
  delay(50);
  digitalWrite(mavi,LOW);
  delay(1000);
}  
else if(mesafe <= 0){
  //mesafe 0'dan küçükse...
  digitalWrite(buzzer,LOW);
  digitalWrite(kirmizi,LOW);
  digitalWrite(sari,LOW);
  digitalWrite(yesil,LOW);
  digitalWrite(mavi,LOW);
} 
}