#include <UTFT.h>
#include <URTouch.h>

extern uint8_t SevenSegNumFontPlus[];
extern uint8_t GroteskBold16x32[];
extern uint8_t BigFont[];
extern uint8_t SmallFont[];
extern uint8_t GroteskBold32x64[];
extern uint8_t Grotesk16x32[];
extern uint8_t SixteenSegment16x24[];
extern uint8_t Other_Font[];
extern uint8_t OtherFont[];
extern uint8_t bt_ct[];
extern uint8_t Arial_round_16x24[];
extern uint8_t pwr_warning[];
extern unsigned short etros[];
extern unsigned short srm[];

int i=0,x,y,d=0;

UTFT myGLCD(ITDB50,38,39,40,41); //souf_nucl
URTouch myTouch(6,5,4,3,2);
void setup()
{
    randomSeed(analogRead(0));
    // Setup the LCD
    Serial.begin(115200);
    myGLCD.InitLCD();   
    cbi(myGLCD.P_CS, myGLCD.B_CS);  // CS Active++
    myGLCD.LCD_Write_COM(0x36);
    myGLCD.LCD_Write_DATA(0x48 ^ 0xC0);
    sbi(myGLCD.P_CS, myGLCD.B_CS);  // CS Idle
    myGLCD.clrScr();
    myGLCD.fillScr(0,0,0);
    myGLCD.setBackColor(0,0,0);
    myGLCD.setFont(pwr_warning);
    myGLCD.setColor(0,0,255);
    myGLCD.printNumI(0,280,100);
    myGLCD.setColor(255,255,255);
    myGLCD.setFont(GroteskBold16x32);
    myGLCD.print("TOUCH TO START",290,380);
    myTouch.InitTouch(PORTRAIT);
    myTouch.setPrecision(PREC_MEDIUM);
    while(1){
      if (myTouch.dataAvailable()){
        myTouch.read();
        myGLCD.setColor(0,255,0);
        myGLCD.setFont(pwr_warning);
        myGLCD.printNumI(0,280,100);
        delay(500);
        break;
       }
    }
    myGLCD.clrScr();
    splashScreen();
    start();
}
void start(){
      myGLCD.clrScr();
      myGLCD.fillScr(0,0,0);
      myTouch.InitTouch(PORTRAIT);
      myTouch.setPrecision(PREC_MEDIUM);
      myGLCD.setColor(0,255,255);
      myGLCD.fillRoundRect(440,200,750,290);
      myGLCD.setFont(GroteskBold16x32);
      myGLCD.setColor(0,0,255);
      myGLCD.setBackColor(VGA_TRANSPARENT);
      myGLCD.print("INTERACTIVE SCREEN",450,230);
      myGLCD.setColor(0,255,255);
      myGLCD.fillRoundRect(75,200,325,290);
      myGLCD.setColor(0,0,255);
      myGLCD.print("SENSOR DISPLAY",85,230);
      while(1){
        if (myTouch.dataAvailable()){
            myTouch.read();
            x=myTouch.getX();
            y=myTouch.getY();
            if(x>0){
              myGLCD.clrScr();
              myGLCD.setFont(GroteskBold16x32);
              myGLCD.print("UNDER CONSTRUCTION",200,250);
          }
          else{
              d++;
              myGLCD.clrScr();
              demarcation();
              myGLCD.setColor(255,255,255);
              myGLCD.drawLine(1, 60, 650, 60);
              myGLCD.drawLine(1, 270, 650, 270);
              myGLCD.drawLine(525,270,525,480);
              myGLCD.drawLine(200, 60, 200, 480);
              myGLCD.drawLine(400, 480, 400, 60);
              myGLCD.drawLine(0, 479, 800, 479);
              myGLCD.drawLine(1, 1, 1, 479);
              myGLCD.drawLine(1, 1, 800, 1);
              myGLCD.drawLine(799, 1, 799, 480);
              myGLCD.drawLine(700, 1, 700, 480);
              myGLCD.drawLine(650, 1, 650, 480);
              myGLCD.drawLine(400, 200, 650, 200);
              myGLCD.setFont(BigFont);
              myGLCD.print("Battery Lvl",10,70);
              myGLCD.print("Battery Tmp",10,280);
              myGLCD.print("Car Temp",230,70);
              myGLCD.print("Parking",240,280);
              myGLCD.print("Speed",546,310);
              myGLCD.print("RPM",435,315);
              myGLCD.print("Camber: ",425,212);
              myGLCD.print("Tow: ",425,247);
              myGLCD.setColor(160,32,240);
              myGLCD.setFont(GroteskBold16x32);
              myGLCD.print("ETROS SOLAR RACING",115,20);
              myGLCD.setFont(BigFont);
              myGLCD.setColor(255,255,255);
              myGLCD.print("Smoke",445,145);
              myGLCD.print("Status",445,165);
              myGLCD.drawBitmap(20,5,50,50,srm);
              myGLCD.setBackColor(VGA_TRANSPARENT);
              myGLCD.drawBitmap(445,5,202,50,etros);
              myGLCD.setBackColor(0,0,0);
          }
          break;
      }
   }
}

void splashScreen() {
  myGLCD.setColor(0,0,255);
  myGLCD.setFont(GroteskBold32x64);
  myGLCD.print("H", 100, 200);
  delay(100);
  myGLCD.print("E", 150, 200);
  delay(100);
  myGLCD.print("L", 200, 200);
  delay(100);
  myGLCD.print("L", 250, 200);
  delay(100);
  myGLCD.print("O", 300, 200);
  delay(100);
  myGLCD.print(" ", 350, 200);
  delay(100);
  myGLCD.print("D", 400, 200);
  delay(100);
  myGLCD.print("R", 450, 200);
  delay(100);
  myGLCD.print("I", 500, 200);
  delay(100);
  myGLCD.print("V", 550, 200);
  delay(100);
  myGLCD.print("E", 600, 200);
  delay(100);
  myGLCD.print("R", 650, 200);
  delay(1000);
  myGLCD.clrScr();
}

void camber(int n){
  myGLCD.setFont(BigFont);
  myGLCD.setColor(255,255,255);
  myGLCD.printNumI(n,550,212);
  myGLCD.setBackColor(VGA_TRANSPARENT);
  myGLCD.setFont(Arial_round_16x24);
  myGLCD.print("`",585,212);
  myGLCD.setBackColor(0,0,0);
}
void tow(int n){
  myGLCD.setFont(BigFont);
  myGLCD.setColor(255,255,255);
  myGLCD.printNumI(n,550,247);
  myGLCD.setBackColor(VGA_TRANSPARENT);
  myGLCD.setFont(Arial_round_16x24);
  myGLCD.print("`",585,247);
  myGLCD.setBackColor(0,0,0);
}
void rpm(int n){
  myGLCD.setFont(SixteenSegment16x24);
  myGLCD.setColor(255,255,255);
  myGLCD.printNumI(n,435,355);
}
void demarcation(){
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(SmallFont);
  for(int i=0,j=80;i<480;i+=6){
    if(i%60==0){
      if(j!=0 && j!=80){
      myGLCD.printNumI(j,660,i-5);
      }
      if(i!=0){
      myGLCD.drawLine(675,i,700,i);
      }
      j-=10;
    }
    else
    myGLCD.drawLine(690,i,700,i);
  }
  myGLCD.print("80",660,5);
  myGLCD.print("0",660,465);
}
void battery_level(int n){
  myGLCD.setColor(0,0,0);
  myGLCD.fillRect(60,190,130,260);
  myGLCD.setFont(bt_ct);
  if(n<10){
    myGLCD.setColor(0,0,255);
    myGLCD.printNumI(5,60,100);
  }
  if(n>10 && n<20){
    myGLCD.setColor(0,0,255);
    myGLCD.printNumI(4,60,100);
  }
  else if(n>=20 && n<40){
    myGLCD.setColor(0,255,255);
    myGLCD.printNumI(3,60,100);
  }
  else if(n>=40 && n<60){
    myGLCD.setColor(0,255,255);
    myGLCD.printNumI(2,60,100);
  }
  else if(n>=60 && n<80){
    myGLCD.setColor(0,255,0);
    myGLCD.printNumI(1,60,100);
  }
  else if(n>=80 && n<100){
    myGLCD.setColor(0,255,0);
    myGLCD.printNumI(0,60,100);
  }
  myGLCD.setColor(255,255,255);
  myGLCD.setFont(SevenSegNumFontPlus);
  myGLCD.printNumI(n,47,190);
  myGLCD.setFont(Grotesk16x32);
  myGLCD.print("%",149,200);
}
void car_temp(int n){
  myGLCD.setFont(bt_ct);
  if(n<30){
    myGLCD.setColor(255,255,255);
    myGLCD.printNumI(6,260,100);
  }
  else if(n>=30 && n<40){
    myGLCD.setColor(200,120,0);
    myGLCD.printNumI(7,260,100);
  }
  else if(n>=40 && n<50){
    myGLCD.setColor(0,80,255);
    myGLCD.printNumI(8,260,100);
  }
  else{
    myGLCD.setColor(0,0,255);
    myGLCD.printNumI(9,260,100);
  }
  myGLCD.setFont(SevenSegNumFontPlus);
  myGLCD.setColor(255,255,255);
  myGLCD.printNumI(n,252,190);
  myGLCD.setFont(Arial_round_16x24);
  myGLCD.print("`C",319,190);
}
void battery_temp(int n){
    myGLCD.setFont(OtherFont);
    if(n<30){
      myGLCD.setColor(255,255,255);
      myGLCD.printNumI(0,60,310);
    }
    else if(n>=30 && n<40){
      myGLCD.setColor(200,120,0);
      myGLCD.printNumI(1,60,310);
    }
    else if(n>=40 && n<50){
      myGLCD.setColor(0,255,255);
      myGLCD.printNumI(2,60,310);
    }
    else{
      myGLCD.setColor(0,0,255);
      myGLCD.printNumI(3,60,310);
    }
    myGLCD.setColor(255,255,255);
    myGLCD.setFont(SevenSegNumFontPlus);
    myGLCD.printNumI(n,53,417);
    myGLCD.setFont(Arial_round_16x24);
    myGLCD.print("`C",120,417);
}
void parking(int n){
    myGLCD.setColor(0,0,0);
    myGLCD.fillRect(330,347,370,470);
    myGLCD.setFont(Other_Font);
    if (n>20){
      myGLCD.setColor(255,128,0);
    }
    else{
      myGLCD.setColor(0,0,255);
    }
    myGLCD.printNumI(4,240,340);
    myGLCD.setColor(255,255,255);
    myGLCD.setFont(SixteenSegment16x24);
    myGLCD.printNumI(n,330,350);
    myGLCD.printNumI(n,330,417);
    myGLCD.setFont(BigFont);
    myGLCD.print("m",365,357);
    myGLCD.print("m",365,424);
}
void speedometer(int i,int x){
    myGLCD.setColor(0,0,0);
    myGLCD.fillRect(540,350,630,430);
    myGLCD.setFont(GroteskBold32x64);
    myGLCD.setColor(0,0,255);
    myGLCD.fillRect(703,475-x,795,475);
    myGLCD.setColor(0,0,0);
    myGLCD.fillRect(703,5,795,475-x);
    myGLCD.setColor(255,255,255);
    myGLCD.printNumI(i,550,350);
    myGLCD.setFont(GroteskBold16x32);
    myGLCD.print("km/h",550,430);
}
void time1(){
    myGLCD.setColor(255,255,255);
    myGLCD.setFont(Other_Font);
    myGLCD.setBackColor(VGA_TRANSPARENT);
    myGLCD.printNumI(5,445,50);
    myGLCD.setBackColor(0,0,0);
    myGLCD.setFont(SixteenSegment16x24);
    myGLCD.print(": 20:02",495,90);
}
void smoke(){
    myGLCD.setFont(Other_Font);
    myGLCD.setColor(0,255,0);
    myGLCD.setBackColor(VGA_TRANSPARENT);
    myGLCD.printNumI(6,555,115);
}

void smoke_alert(){
    myGLCD.fillScr(0,0,0);
    myGLCD.setColor(0,0,255);
    myGLCD.setFont(pwr_warning);
    myGLCD.printNumI(1,280,80);
    myGLCD.setFont(GroteskBold32x64);
    myGLCD.print("SMOKE ALERT!!!",200,360);
    delay(1000);
}

void loop(){
  if(myTouch.dataAvailable()){
    myTouch.read();
    start();
  }
   else{ 
      if(d>0){
      i=random(0,2);
      int a=0;
      do{
        if(i==0)
        smoke();
        else{
         smoke_alert();
         a++;
         i=random(0,2);
        }
      }while(i!=0);
      myGLCD.setBackColor(0,0,0);
      if(a>0){
        a=0;
        randomSeed(analogRead(0));
        // Setup the LCD
        Serial.begin(115200);
        myGLCD.InitLCD();   
        cbi(myGLCD.P_CS, myGLCD.B_CS);  // CS Active++
        myGLCD.LCD_Write_COM(0x36);
        myGLCD.LCD_Write_DATA(0x48 ^ 0xC0);
        sbi(myGLCD.P_CS, myGLCD.B_CS);  // CS Idle
        myGLCD.clrScr();
        myGLCD.fillScr(0,0,0);
        myGLCD.setBackColor(0,0,0);
        demarcation();
        myGLCD.setColor(255,255,255);
        myGLCD.drawLine(1, 60, 650, 60);
        myGLCD.drawLine(1, 270, 650, 270);
        myGLCD.drawLine(525,270,525,480);
        myGLCD.drawLine(200, 60, 200, 480);
        myGLCD.drawLine(400, 480, 400, 60);
        myGLCD.drawLine(0, 479, 800, 479);
        myGLCD.drawLine(1, 1, 1, 479);
        myGLCD.drawLine(1, 1, 800, 1);
        myGLCD.drawLine(799, 1, 799, 480);
        myGLCD.drawLine(700, 1, 700, 480);
        myGLCD.drawLine(650, 1, 650, 480);
        myGLCD.drawLine(400, 200, 650, 200);
        myGLCD.setFont(BigFont);
        myGLCD.print("Battery Lvl",10,70);
        myGLCD.print("Battery Tmp",10,280);
        myGLCD.print("Car Temp",230,70);
        myGLCD.print("Parking",240,280);
        myGLCD.print("Speed",546,310);
        myGLCD.print("RPM",435,310);
        myGLCD.print("Camber: ",425,212);
        myGLCD.print("Tow: ",425,247);
        myGLCD.setColor(160,32,240);
        myGLCD.setFont(GroteskBold16x32);
        myGLCD.print("ETROS SOLAR RACING",115,20);
        myGLCD.setFont(BigFont);
        myGLCD.setColor(255,255,255);
        myGLCD.print("Smoke",445,145);
        myGLCD.print("Status",445,165);
        myGLCD.drawBitmap(20,5,50,50,srm);
        myGLCD.setBackColor(VGA_TRANSPARENT);
        myGLCD.drawBitmap(445,5,202,50,etros);
        myGLCD.setBackColor(0,0,0);
      }
      myGLCD.setBackColor(0,0,0);
      i=random(0,100);
      battery_level(i);
      i=random(30,60);
      car_temp(i);
      i=random(25,60);
      battery_temp(i);
      i=random(0,50);
      parking(i);
      int num=random(0,2);
      myGLCD.setFont(GroteskBold16x32);
      myGLCD.setColor(255,255,255);
      while(num==0){
        myGLCD.print("R",450,400);
        num=random(0,2);
        delay(1000);
        myGLCD.setColor(0,0,0);
        myGLCD.print("R",450,400);
        delay(1000);
        myGLCD.setColor(255,255,255);
      }
      i=random(0,80);
      int n=i;
      i=map(i,0,80,5,475);
      speedometer(n,i);
      i=random(0,1000);
      rpm(i);
      i=random(0,100);
      camber(i);
      i=random(0,100);
      tow(i);
      time1();
      smoke();
      myGLCD.setBackColor(0,0,0);
      delay(1000);
      }
  }
  }
  
