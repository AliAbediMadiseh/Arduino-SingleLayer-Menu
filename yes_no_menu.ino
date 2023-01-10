//Created By : Ali Abedi Madiseh///
////////aam.7596@gmail.com/////////
//////////Jan ..... 2023///////////:)


//My Key Values:
//Yes = 42
//No = 64
//Normal = 1023
//check input values :
// value = analogRead(A0); /connect 2 push button to pin A0


# include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd (0x27 , 16, 2);

int buttonst = -1;
int btn = A0;
int buttonvalue;

int yescount;
int nocount;

void setup() {
    lcd.init();
    lcd.clear();
    lcd.backlight();
    
      lcd.setCursor(1,0);
      lcd.print("item1");
      lcd.setCursor(9,0);
      lcd.print("item2");
      lcd.setCursor(1,1);
      lcd.print("item3");
      lcd.setCursor(9,1);
      lcd.print("item4");

}

void loop() {
  
  start();
  
  buttonvalue = analogRead(btn);
  
  //yes button 
  if(buttonvalue == 42){

    //debounce
    delay(1000);

    
    }


  //no button
  else if(buttonvalue == 64){

    //debounce
    buttonst ++ ;
    delay(1000);
      
    if (buttonst == 0){
      
      lcd.setCursor(0,0);
      lcd.print(" ");
      lcd.setCursor(8,0);
      lcd.print(">");
    }
    
    else if (buttonst == 1){
      
      lcd.setCursor(8,0);
      lcd.print(" ");
      lcd.setCursor(0,1);
      lcd.print(">");
    }
    
    else if (buttonst == 2){
      lcd.setCursor(0,1);
      lcd.print(" ");
      lcd.setCursor(8,1);
      lcd.print(">");
    }
    else if (buttonst == 3){
      buttonst = -1 ;
  }
}
}


void start(){
  if(buttonst == -1){
      lcd.setCursor(8,1);
      lcd.print(" ");
      lcd.setCursor(0,0);
      lcd.print(">item1");
      lcd.setCursor(9,0);
      lcd.print("item2");
      lcd.setCursor(1,1);
      lcd.print("item3");
      lcd.setCursor(9,1);
      lcd.print("item4");
  }
}
