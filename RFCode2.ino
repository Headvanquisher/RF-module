#include <VirtualWire.h>
#include <VirtualWire_Config.h>


char t;
char *data;


void setup ()
{
  pinMode (10, OUTPUT); //left motors forward
  pinMode (11, OUTPUT); //left motors reverse
  pinMode (12, OUTPUT); //right motors forward
  pinMode (13, OUTPUT); //right motors reverse
  
  Serial.begin(9600);

  vw_set_tx_pin (3);
  vw_setup (2000);

}

void loop()
{

  if(Serial.available())
  {
      t = Serial.read();

    if(t == 'F')
    {
      data="f";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      forward();
      Serial.println(data);
      
    }
    else if (t =='G')
    {
      data="g";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      backward();
      Serial.println(data);
    }
    else if(t == 'L') 
    {
      data="l";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();
      left();
      Serial.println(data);
    }
    else if(t == 'R') 
    {
      data="r";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();//turn right (left side motors rotate in forward direction, right side motors doesn't rotate)
      right();
      Serial.println(data);
    }
    else if(t == 'S') 
    {
      data="s";
      vw_send((uint8_t *)data, strlen (data));
      vw_wait_tx();//STOP (all motors stop)
      stop();
      Serial.println(data);
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