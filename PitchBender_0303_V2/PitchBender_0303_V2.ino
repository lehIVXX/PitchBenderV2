
const int inPins[6] = {2,3,4,5,6,7};
unsigned long PTime=0;
const int auxPin=11;
const int SCALE_NUM = 6; 
const int NOTE_NUM = 21; 
int NOTE_INDEX=0;
int buttonCState[6] = {0};    
int buttonPState[6] = {0};       
unsigned long lastDebounceTime[6] = {0}; 
unsigned long debounceDelay = 50;
unsigned long Timer = 0;
int potMin = 64;    
int potMax = 1023;         
int potVal=0;
int prevVal=0;
int potVar=0;
int noteOut=0;
unsigned long loopCount=0;
unsigned long startTime=0;
long duration=0;
int distance=0;

int Notes[SCALE_NUM][NOTE_NUM] { 
{82,87,93,98,104,110,117,123,131,138,
147,156,165,175,185,196,208,220,233,247,262},
{110,117,123,131,139,147,156,165,175,185,
196,208,220,233,247,262,277,294,311,330,349}, 
{147,156,165,175,185,196,208,220,233,247,
262,277,294,311,330,349,370,392,415,440,466},
{196,208,220,233,247,262,277,294,311,330,349,370,392,415,440,466,494,523,554,587,622},
{247,262,277,294,311,330,349,370,392,415,440,466,494,523,554,587,622,659,698,740,784},
{330,349,370,392,415,440,466,494,523,554,587,622,659,698,740,784,831,880,932,988,1047}
};

void setup() {
  Serial.begin(115200);
  for (int i = 0; i < 6; i++) {
    pinMode(inPins[i],    INPUT_PULLUP);
  }
	pinMode(9, OUTPUT); 
	pinMode(10, INPUT);
	pinMode(13, OUTPUT);
	delay(1000);
	
	digitalWrite(13, HIGH);
	
	
	
	
	
}

void loop () {
	     digitalWrite(9, LOW);
				delayMicroseconds(2); 
				digitalWrite(9, HIGH);  
				delayMicroseconds(10); 
				digitalWrite(9, LOW); 
				duration = pulseIn(10, HIGH);
				distance = duration * 0.034 / 2;	
	
	 int dist=map(distance,5,100,0,21);
	 dist=constrain(dist,0,21);
	 NOTE_INDEX=dist;
	
      Serial.print( "  /  FRET =");
		    Serial.println(NOTE_INDEX);
					Serial.print("  /  Range =");		
		    Serial.println(distance)	;		
for (int i = 0; i < 6; i++) {

 if (buttonPState[i] != buttonCState[i]) {
//  lastDebounceTime[i] = millis();
   if (buttonCState[i] == LOW) {
				digitalWrite(13, LOW);
    noteOut = Notes[i][NOTE_INDEX];
    tone(11, noteOut);
		    Serial.print("STRING =");		
		    Serial.print(i+1)	;				
		    
    } else {
						digitalWrite(13, HIGH);		
				noTone(11);
										
     } 
			buttonPState[i] = buttonCState[i];
    }
    }  
 
}
	


