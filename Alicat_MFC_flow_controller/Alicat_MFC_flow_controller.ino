#define ALICAT_A_MAX_FLOW 2000.0
#define ALICAT_B_MAX_FLOW 5000.0
#define ALICAT_C_MAX_FLOW 3000.0

void setup() {
  Serial.begin(9600);
  Serial1.begin(19200, SERIAL_8N1_RXINV_TXINV);
  Serial2.begin(19200, SERIAL_8N1_RXINV_TXINV);
  Serial3.begin(19200, SERIAL_8N1_RXINV_TXINV);
  delay(1000);
  Serial.println(" ");
  Serial.println("Initializing MFCs...");

  Serial1.print("A0");
  Serial1.write('\r');
  delay(10);
  while (Serial1.available())
    {       
    Serial.write(Serial1.read());
    delay(1);
    }

  Serial.println(" ");

  Serial2.print("B0");
  Serial2.write('\r');
  delay(10);
  while (Serial2.available())
    {       
    Serial.write(Serial2.read());
    delay(1);
    }

  Serial.println(" ");
  
  Serial3.print("C0");
  Serial3.write('\r');
  delay(10);
  while (Serial3.available())
    {       
    Serial.write(Serial3.read());
    delay(1);
    }
    Serial.println(" ");
    Serial.println("Ready");
}



void loop() {
  if (Serial.available() > 0) {
    // Read until newline \n or carriage return \r
    char buffer[16]; 
    size_t length = Serial.readBytesUntil('\n', buffer, sizeof(buffer) - 1);
    
    if (length > 0) {
      buffer[length] = '\0'; // Null-terminate the string
      processCommand(buffer);
    }
  }

if(Serial3.available())
  {
  while (Serial3.available())
      {       
      Serial.write(Serial3.read());
      delay(1);
      }
  Serial.println(" ");
  }

if(Serial2.available())
  {
  while (Serial2.available())
      {       
      Serial.write(Serial2.read());
      delay(1);
      }
  Serial.println(" ");
  }

if(Serial1.available())
  {
  while (Serial1.available())
      {       
      Serial.write(Serial1.read());
      delay(1);
      }
  Serial.println(" ");
  }

}

void processCommand(char* cmd) {
  char action = cmd[0];      // The first character (A, B, or C)
  int value = atoi(&cmd[1]); // Parse the rest of the string as an integer

  switch (action) {
    case 'A':
    case 'a':
      Serial1.print("A");
      Serial1.print((int)((value / ALICAT_A_MAX_FLOW)*64000));
      Serial1.write('\r');
      break;

    case 'B':
    case 'b':
      Serial2.print("B");
      Serial2.print((int)((value / ALICAT_B_MAX_FLOW)*64000));
      Serial2.write('\r');
      break;

    case 'C':
    case 'c':
      Serial3.print("C");
      Serial3.print((int)((value / ALICAT_C_MAX_FLOW)*64000));
      Serial3.write('\r');
      break;

    default:
      Serial.println("Unknown Command");
      break;
  }
}