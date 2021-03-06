// TRS-80 CoCo Keyboard driver
// Kevin John O'Neill


#include <Keyboard.h>

// write_pin_size; read_pin_size
int wps=8;
int rps=7;

// write pins
int writepins [8] = {10,16,14,15,18,19,20,21};
int readpins [7] ={9,8,7,6,5,3,2};

// keystate keeps track of what keys are pressed
bool  keystate [8][7];
// we declare key_pressed here just so we aren't declaring it within a loop over and over
bool key_pressed;

//NON DISPLAYING ASCII CHARACTERS
// key for key_table below:
// shift                                                                                                                    break                     clear                     enter
//                          right arrow             left arrow               down arrow             up arrow



// the underscore characters in the top row (_) don't correspond to any buttons on the coco keyboard
char key_table [7][8][2] =
{
  {{char(133),char(133)},   {'_','_'},              {'_','_'},              {'_','_'},              {'_','_'},              {char(178),char(178)},    {char(212),char(212)},    {char(176),char(176)}},
  {{'/','?'},               {'.','>'},              {'-','='},              {',','<'},              {';','+'},              {':','*'},                {'9',')'},                {'8','('}},
  {{'7','\''},              {'6','&'},              {'5','%'},              {'4','$'},              {'3','#'},              {'2','"'},                {'1','!'},                {'0','0'}},
  {{' ',' '},               {char(215),char(215)},  {char(216),char(216)},  {char(217),char(217)},  {char(218),char(218)},  {'z','Z'},                {'y','Y'},                {'x','X'}},
  {{'w','W'},               {'v','V'},              {'u','U'},              {'t','T'},              {'s','S'},              {'r','R'},                {'q','Q'},                {'p','P'}},
  {{'o','O'},               {'n','N'},              {'m','M'},              {'l','L'},              {'k','K'},              {'j','J'},                {'i','I'},                {'h','H'}},
  {{'g','G'},               {'f','F'},              {'e','E'},              {'d','D'},              {'c','C'},              {'b','B'},                {'a','A'},                {'@','@'}}  
};



void type_key(bool keypress, int i, int j){
  bool shift=keystate[0][0];

  if(keypress){
    Keyboard.write(key_table[j][i][shift]);
  }
  
}

//for testing purposes
void print_key(bool keypress, int i, int j){
  //if key is pressed do following:
  if(keypress){
    Serial.print("key_pressed  ");
  }
  else{
    Serial.print("key_released  ");
  }
  Serial.print(writepins[i]);
  Serial.print("  ");
  Serial.print(readpins[j]);
  Serial.print("\n");
}


void setup() {

  Keyboard.begin();

  // initialize arduino pins for multiplexed input
  for(int i=0; i<wps; i++){
    pinMode(writepins[i],OUTPUT);
    digitalWrite(writepins[i],HIGH);
  }
  for(int j=0; j<rps; j++){
    pinMode(readpins[j],INPUT_PULLUP);
  }
  // input_pullup lets us use internal pullup resistors in the arduino itself
  // simplifies the amount of external circuitry that needs to be done
  
  // it does however that we will be interpreting a LOW signal
  // on the read pins as a key press since they will default HIGH
  

  //initialize table to keep track of which keys are pressed
  for(int i=0; i<wps; i++){
    for(int j=0; j<rps; j++){
      keystate[i][j]=0;
    }
  }
}

void loop() {

  // multiplexed input
  // pull each write pin low in turn
  // and check each read pin to see which keys are pressed
  for(int i=0; i<wps; i++){
    digitalWrite(writepins[i],LOW);
    
    for(int j=0; j<rps; j++){
      // if this key reads low, the button is pressed
      key_pressed=digitalRead(readpins[j])==LOW;

      // if the state of this key is different from what it was previously (either pressed or unpressed)
      if(key_pressed!=keystate[i][j]){
        // keep track of the new state in the keystate table
        keystate[i][j]= !keystate[i][j];
        
        // call the type_key function to actually output the character
        type_key(key_pressed, i, j);
        
      }
    }
    
    digitalWrite(writepins[i],HIGH);
  }

}
