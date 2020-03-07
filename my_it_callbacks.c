#include "my_it_callbacks.h"
#include "main.h"
#include "gpio.h"
#include "usart.h"
//#include "stm32l4xx_hal_gpio.h"


#define tiempo1 150
#define tiempo2 300
int c=0;

void f1_port (void) {
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	  HAL_Delay(tiempo1) ;
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	  HAL_Delay(tiempo1) ;
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	  HAL_Delay(tiempo1) ;
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
	  HAL_Delay(tiempo1) ;
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
	  HAL_Delay(tiempo1) ;
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
	  HAL_Delay(tiempo1) ;
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
	  HAL_Delay(tiempo1) ;
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
	  HAL_Delay(tiempo1) ;
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);

}

void f2_port (void) {
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_0, GPIO_PIN_SET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_1, GPIO_PIN_SET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_4, GPIO_PIN_SET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_6, GPIO_PIN_SET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_7, GPIO_PIN_SET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, GPIO_PIN_SET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_9, GPIO_PIN_SET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_10, GPIO_PIN_SET);
	  HAL_Delay(tiempo2) ;
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_0, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_1, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_4, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_6, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_7, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_8, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_9, GPIO_PIN_RESET);
	  HAL_GPIO_WritePin (GPIOA, GPIO_PIN_10, GPIO_PIN_RESET);
	  HAL_Delay(tiempo2) ;
}

void (*funcion)(void)= &f1_port;

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin){
  /* Prevent unused argument(s) compilation warning */
	if(GPIO_Pin == GPIO_PIN_15){
		c++;
	}
	if (c%2 == 0){
		funcion = &f2_port;
	}
	else{
		funcion = &f1_port;
	}

}


