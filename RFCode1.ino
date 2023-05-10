#include <VirtualWire.h>
#include <VirtualWire_Config.h>


char input;
char *data;

void setup ()
{
  pinMode (10, OUTPUT); //left motors forward
  pinMode (11, OUTPUT); //left motors reverse
  pinMode (12, OUTPUT); //right motors forward
  pinMode (13, OUTPUT); //right motors reverse

  Serial.begin(9600);

  vw_set_rx_pin(3);
  vw_setup (2000);
  pinMode(3,INPUT);
  vw_rx_start();
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen=VW_MAX_MESSAGE_LEN;
  Serial.println(buf[0]);
  if(vw_get_message(buf,&buflen)){
    if(buf[0]=='f')
    {
      forward();
    }
    else if(buf[0]=='g')
    {
      backward();
    }
    else if(buf[0]=='l')
    {
      left(); 
    }
    else if(buf[0]=='r')
    {
      right();  
    }
    else if(buf[0]=='s')
    { 
      stop(); 
    }


  }
}
void forward() {
  digitalWrite(11, LOW);
  digitalWrite(13, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
}
void backward() {
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  digitalWrite(13, LOW);
  digitalWrite(10, HIGH);
}
void right() {
  digitalWrite(11, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}
void left() {
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, HIGH); 
}
void stop() {
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}