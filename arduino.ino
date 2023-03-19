#include <Keypad.h>
int count =0;
char a[5]={'1','2','3','4','D'};
char b[5];

const byte ROWS = 4; //four rows
const byte COLS = 4; //three columns
char keys[ROWS][COLS] = {
                          {'1','2','3','A'},
                          {'4','5','6','B'},
                          {'7','8','9','C'},
                          {'*','0','#','D'}
                        };
byte rowPins[ROWS] = {2, 3, 4, 5}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {A5, A4, A3, A2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){
  Serial.begin(9600);
  Serial.println("Enter the password and hit D: ");
}

void loop(){

  char c =keypad.getKey();
  if (c !=0){
    Serial.println(c);
    b[count]={c} ;
    count++;
  }

  if (count == 6){
    Serial.println("Validating...");
    for (int j=0; j<5; j++){
      if (b[j] == a[j]){
        Serial.println("Welcome! ");
      }
      else {
        Serial.println("Incorrect password");
      }
    }
  }
}
