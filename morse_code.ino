//Aladin Sidahmed
//Morse Code

const int dotDelay = 200;
const int ledPin = 13;

char* letters[] = {
  ".-" , "-..." , "-.-." , "-.." , "." , "..-." , "--." , "...." , ".." ,
  ".---" , "-.-" , ".-.." , "--" , "-." , "---" , ".--." , "--.-" , ".-." ,
  "..." , "-" , "..-" , "...-" , ".--" , "-..-","-.--","--.."
};

char* numbers[] = {
  "-----",".----","..---","...--","....-",".....","-....","--...","---..","----"
};


void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char ch;
  if(Serial.available() > 0){
    ch = Serial.read();
    Serial.print((int)ch);
    Serial.print(" ");
    Serial.print(ch);
    Serial.print(" ");
    if(ch >= 'a' && ch<= 'z'){
      Serial.println(letters[ch - 'a']);
      flashSequence(letters[ch - 'a']);
    }else if ( ch >= 'A' && ch <= 'Z'){
      Serial.println(letters[ch - 'A']);
      flashSequence(letters[ch - 'A']);
    }else if (ch >= '0' && ch <= '9'){
      Serial.println(numbers[ch - '0']);
      flashSequence(numbers[ch - '0']);
    }else if (ch == ' '){
      Serial.println("\' \'");
      delay(dotDelay*4);
    }
  }
}

void flashSequence (char* sequence){
  int i = 0;
  while(sequence[i] != '\0'){
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay*3);
}


void flashDotOrDash(char dotOrDash){
  digitalWrite(ledPin, HIGH);
  if(dotOrDash == '.'){
    delay(dotDelay) ;
  }else{
    delay(dotDelay * 3);
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay);

}
