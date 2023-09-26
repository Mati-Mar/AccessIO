/*******************************************************************************************************************************//**
 *
 * @file		inicializar.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		5 jul. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef INICIALIZAR_H_
#define INICIALIZAR_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include <12-USART/uart.h>
#include <vector>
#include <list>

#include "LPC845.h"
#include "dr_pll.h"
#include "systick.h"
#include "gpio.h"
#include "timer.h"
#include "I4017.h"
#include "I4511.h"
#include "display7Segmentos.h"
#include "teclado.h"
#include "Lcd.h"

using namespace std;

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES
 **********************************************************************************************************************************/
//!<	ENTRADAS DIGITALES
extern gpio 	g_in0 ;
extern gpio 	g_in1 ;

//!<	SALIDAS DIGITALES
extern gpio g_out0 ;
extern gpio g_out1 ;
extern gpio g_out2 ;

//!<    DISPLAY
extern display7Segmentos *Display;

//!<	TECLADO
extern teclado *Teclado;

//!<	TECLADO
extern Lcd *lcd;

//!<	LEDS

// 		ADC
//extern adc canal1;

// 		UART
extern uart *uart0 ;

/***********************************************************************************************************************************
 *** PROTOTIPOS GLOBALES
 **********************************************************************************************************************************/
void InicializarInfotronic ( void ) ;
void systick_callback ( void  );
// void Callback_Leds_gpio ( uint8_t nLed , Led::led_t estado );

#endif /* INICIALIZAR_H_ */
