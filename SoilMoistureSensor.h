#include "esphome.h"

using namespace esphome;

class SoilMoistureSensor : public PollingComponent, public sensor::Sensor {
  public:
	
//define the receiver pin
int output_value ;
//integer to store the output value of soil moiture sensor
//const int analogOutPin = 1; 
//set analog output pin to pin 1
int threshold = 800;
//set the threshold value = 800
int current_value;

    SoilMoistureSensor() : PollingComponent(15000) {}
    
    void setup() override {
      Serial.begin(115200);
      Serial.println("Soil Moisture Sensor");
      Serial.println("--------------------------------------");
    }

    void update() override {
      // Serial.println("-- update --");

      // Serial.println(analogRead(A0));

      output_value= analogRead(A0);
      
      Serial.println("-- analogRead --");
      Serial.println(output_value);
      //read the value of soil moisture sensor and store it in output_value 
      current_value = output_value;
      //set current_value equal to output_value
      output_value= constrain(output_value,10,1023); 
      //set the contrain on output_value. Minimum = 10 Maximum = 1023 
      output_value= map(output_value,300,700,120,0); 
        
      Serial.println("-- output_value --");
      Serial.println(output_value);

      publish_state(output_value);
    }
};