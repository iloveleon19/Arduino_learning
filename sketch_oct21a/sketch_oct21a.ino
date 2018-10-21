#define C41 262  //1 Do
#define D41 294  //2 Re
#define E41 330  //3 Mi
#define F41 349  //4 Fa
#define G41 392  //5 Sol
#define G42 415  //#5 #Sol
#define A41 440  //6 La
#define B41 494  //7 Si
#define C51 523  //1 Do_h
#define D51 587  //2 Re_h
#define D52 622  //#2 #Re_h
#define E51 659  //3 Mi_h
#define F51 698  //4 Fa_h
#define G51 784  //5 Sol_h
#define A51 880  //6 La_h
#define B51 988  //7 Si_h
#define O1 000  //休止符

const int buzzer =15;

int music[]={E51,D52,E51,D52,E51,B41,D51,C51,A41,O1,E41,A41,B41,E41,G42,B41,C51,E41,E51,
D52,E51,D52,E51,B41,D51,C51,A41,O1,E41,A41,B41,E41,C51,B41,A41};  //輸入歌曲音調.

int length;

void setup() {
  // put your setup code here, to run once:
  length=sizeof(music)/sizeof(music[0]);  //取得曲譜陣列的長度
  pinMode(buzzer, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int ii=0; ii<length; ii++) {
    tone(buzzer, music[ii]);
    delay(50);
//    tone(buzzer,500);
//    delay(50);
  }
//  noTone(buzzer);
//  delay(2000);
}
