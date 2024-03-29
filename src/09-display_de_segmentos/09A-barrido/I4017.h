/*******************************************************************************************************************************//**
 *
 * @file		I4017.h
 * @brief		Breve descripción del objetivo del Módulo
 * @date		27 jul. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MODULO
 **********************************************************************************************************************************/

#ifndef SRC_I0_DISPLAY7SEGMENTOS_I4017_H_
#define SRC_I0_DISPLAY7SEGMENTOS_I4017_H_

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "barrido.h"
#include "gpio.h"
#include <vector>
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

/***********************************************************************************************************************************
 *** IMPLANTACION DE UNA CLASE
 **********************************************************************************************************************************/

class I4017 : public barrido
{
	uint8_t m_indice ;
	const vector <gpio * > &m_pins4017;
	const uint8_t m_maxsalidas ;

	public:
	// tiene que recibir los gpio clk y reset
		I4017( const vector <gpio * > &pins4017 , uint8_t maxsalidas ) : m_indice (maxsalidas) , m_pins4017 (pins4017 ) , m_maxsalidas ( (maxsalidas <= 10 ) ? maxsalidas:10) {}

		void SetDigito ( void );
		void SetReset( void );
		void SetClock( void );
		virtual ~I4017();
};

#endif /* SRC_I0_DISPLAY7SEGMENTOS_I4017_H_ */
