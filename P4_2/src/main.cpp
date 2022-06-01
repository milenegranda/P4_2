#include <Arduino.h>

const int led1 = 16; // Pin of the LED
const int led2 = 17; // Pin of the LED
void toggleLED2(void * parameter);
void toggleLED(void * parameter);

void setup(){
  Serial.begin(115200);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

xTaskCreate(
    toggleLED2,      // Function that should be called
    "Upload to AWS",    // Name of the task (for debugging)
    1000,               // Stack size (bytes)
    NULL,               // Parameter to pass
    1,                  // Task priority
    NULL     
);
    xTaskCreate(
    toggleLED,    // Function that should be called
    "Toggle LED",   // Name of the task (for debugging)
    1000,            // Stack size (bytes)
    NULL,            // Parameter to pass
    1,               // Task priority
    NULL         // Task handle
  );
  


}


void toggleLED(void * parameter){
  for(;;){ // infinite loop
  // Turn the LED on
    digitalWrite(led1, HIGH);

    // Pause the task for 500ms
    vTaskDelay(500 / portTICK_PERIOD_MS);

    // Turn the LED off
    digitalWrite(led1, LOW);

    // Pause the task again for pinMode(led2, OUTPUT);500ms
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
  
    // When you're done, call vTaskDelete. Don't forget this!
    vTaskDelete(NULL);
}


void toggleLED2(void * parameter){
  for(;;){ // infinite loop
  // Turn the LED on
    digitalWrite(led1, LOW);

    // Pause the task for 500ms
    vTaskDelay(500 / portTICK_PERIOD_MS);

    // Turn the LED off
    digitalWrite(led1, HIGH);

    // Pause the task again for pinMode(led2, OUTPUT);500ms
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
  
    // When you're done, call vTaskDelete. Don't forget this!
    vTaskDelete(NULL);
}
/*
VOID
  uploadToAWS(void *parameter)
  {
    // Implement your custom logic here
    Serial.print("Task is running on: ");
    Serial.println(xPortGetCoreID());

    // Turn the LED off
    // Turn the LED off
    digitalWrite(led2, HIGH);
    // Pause the task again for 500ms
    vTaskDelay(500 / portTICK_PERIOD_MS);

    digitalWrite(led2, LOW);

    // Pause the task again for 500ms
    vTaskDelay(500 / portTICK_PERIOD_MS);

    // When you're done, call vTaskDelete. Don't forget this!
    vTaskDelete(NULL);
  }
*/
void loop(){

}