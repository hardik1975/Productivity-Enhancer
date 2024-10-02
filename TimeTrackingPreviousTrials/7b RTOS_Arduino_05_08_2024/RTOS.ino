#if CONFIG_FREERTOS_UNICORE
static const BaseType_t app_cpu = 0;
#else
static const BaseType_t app_cpu = 1;
#endif  

//pins
//static const int led_pin = 27;
static const int led_pin1 = 25;
static const int led_pin2 = 26;
static const int led_pin3 = 27; 

/*task
void toggleLED(void *parameter)
{
  while(1)
  {
    digitalWrite(led_pin, 1);
    vTaskDelay(500 / portTICK_PERIOD_MS);
    digitalWrite(led_pin, 0);
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}
*/

void toggleLED_1(void *parameter)
{
  while(1)
  {

    digitalWrite(led_pin1, 1);
    {
      Serial.println("led 1 on");
    }
    vTaskDelay(550 / portTICK_PERIOD_MS);
    digitalWrite(led_pin1, 0);
    vTaskDelay(550 / portTICK_PERIOD_MS);
  }
}

void toggleLED_2(void *parameter)
{
  while(1)
  {
    digitalWrite(led_pin2, 1);
    {
      Serial.println("led 2 on");
    }
    vTaskDelay(200 / portTICK_PERIOD_MS);
    digitalWrite(led_pin2, 0);
    vTaskDelay(200 / portTICK_PERIOD_MS);
  }
}

void toggleLED_3(void *parameter)
{
  while(1)
  {
    digitalWrite(led_pin3, 1);
    {
      Serial.println("led 3 on");
    }
    vTaskDelay(400 / portTICK_PERIOD_MS);
    digitalWrite(led_pin3, 0);
    vTaskDelay(400 / portTICK_PERIOD_MS);
  }
}


void setup()
{
  Serial.begin(115200);
  pinMode(led_pin1, OUTPUT);
  pinMode(led_pin2, OUTPUT);
  pinMode(led_pin3, OUTPUT);

  xTaskCreatePinnedToCore(     //use xTaskCreate in vanilla RTOS  
               toggleLED_1,      //function to be called
               "Toggle LED 1",   //name of stack
               1024,           //stack size
               NULL,           //Parameter to pass function
               1,              //task priority
               NULL,           //task handler 
               app_cpu);       //run on one core for demo purpose  

  xTaskCreatePinnedToCore(     //use xTaskCreate in vanilla RTOS  
               toggleLED_2,      //function to be called
               "Toggle LED 2",   //name of stack
               1024,           //stack size
               NULL,           //Parameter to pass function
               1,              //task priority
               NULL,           //task handler 
               app_cpu);       //run on one core for demo purpose  
  
  xTaskCreatePinnedToCore(     //use xTaskCreate in vanilla RTOS  
               toggleLED_3,      //function to be called
               "Toggle LED 3",   //name of stack
               1024,           //stack size
               NULL,           //Parameter to pass function
               1,              //task priority
               NULL,           //task handler 
               app_cpu);       //run on one core for demo purpose  


}

void loop()
{

}