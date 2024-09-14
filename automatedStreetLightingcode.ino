int IR1 = 7;
int LED1 = 5;
int LDR = A0;
int LDRValue;

void setup() 
{
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(IR1, INPUT);
  pinMode(LDR, INPUT);
  
  digitalWrite(LED1, LOW);
}

void loop() 
{
  LDRValue = analogRead(LDR);
  Serial.print("LDR sensor = ");
  Serial.print(LDRValue);
  Serial.print(", IR1 = ");
  Serial.print(digitalRead(IR1));
  

  if (LDRValue > 500) {
    Serial.println(" -> It's dark outside");
  } else {
    Serial.println(" -> It's bright outside");
  }

  if (LDRValue > 500) 
  {
    if (digitalRead(IR1) == HIGH) 
    {
      digitalWrite(LED1, HIGH);
      Serial.println(" -> IR1 triggered; LED1 Lights status: ON");
    }
    else 
    {
      digitalWrite(LED1, LOW);
      Serial.println(" -> IR1 not triggered; LED1 Lights status: OFF");
    }

  }
  else 
  {
    digitalWrite(LED1,LOW);
    Serial.println(" -> Lights status: OFF");
  }

  delay(500); 
}
