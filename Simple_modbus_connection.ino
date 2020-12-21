
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>

modbusDevice regBank;
modbusSlave slave;

#define RedPin 12
#define YellowPin 11
#define GreenPin 10

void setup()
{   
  regBank.setId(1); ///Set Slave ID

  regBank.add(1);//Red
  regBank.add(2);//Yellow
  regBank.add(3);//Green

  pinMode(RedPin,OUTPUT);//Red Light
  pinMode(YellowPin,OUTPUT);//Yellow Light
  pinMode(GreenPin,OUTPUT);//Green light
 
 slave._device = &regBank; 
  slave.setBaud(9600);
}
void loop(){

  //Control LED Lights's 
    int RedLED = regBank.get(1);
      if (RedLED <= 0 && digitalRead(RedPin) == HIGH)digitalWrite(RedPin,LOW);
      if (RedLED >= 1 && digitalRead(RedPin) == LOW)digitalWrite(RedPin,HIGH);
      
    int YellowLED = regBank.get(2);//Controls the 
      if (YellowLED <= 0 && digitalRead(YellowPin) == HIGH)digitalWrite(YellowPin,LOW);
      if (YellowLED >= 1 && digitalRead(YellowPin) == LOW)digitalWrite(YellowPin,HIGH);
      
    int GreenLED = regBank.get(3);//Controls the Green
      if (GreenLED <= 0 && digitalRead(GreenPin) == HIGH)digitalWrite(GreenPin,LOW);
      if (GreenLED >= 1 && digitalRead(GreenPin) == LOW)digitalWrite(GreenPin,HIGH);

slave.run(); 
}
