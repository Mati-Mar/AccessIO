/*******************************************************************************************************************************//**
 *
 * @file		EntradaDigital.cpp
 * @brief		funciones miembro de la clase EntradaDigital
 * @date		27 may. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "digital_inputs.h"

/***********************************************************************************************************************************
 *** DEFINES PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TIPOS DE DATOS PRIVADOS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** TABLAS PRIVADAS AL MODULO
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** VARIABLES GLOBALES PUBLICAS
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** IMPLEMENTACION DE LOS METODODS DE LA CLASE
 **********************************************************************************************************************************/
DigitalInputs::DigitalInputs( uint8_t puerto , uint8_t bit , uint8_t modo , uint8_t actividad , uint8_t MaxBounce  ):
		gpio( puerto , bit , modo , gpio::input , actividad ),m_MaxBounce(MaxBounce)
{
	// Lo engancho con el tick del sistema
	m_CountBounce = 0;
	SetDirInputs();
	SetPinResistor();
	m_BufferEntrada = GetPin( );
	g_CallbackList.push_back( this );
}

DigitalInputs::~DigitalInputs() {
	// TODO Auto-generated destructor stub
}

void DigitalInputs::callback ( void )
{
	uint8_t BufferEntradasInstantaneo = 0 ;

	BufferEntradasInstantaneo = GetPin( );

	if ( BufferEntradasInstantaneo != m_BufferEntrada )
	{
		m_CountBounce++;
		if ( m_CountBounce  >= m_MaxBounce )
				m_BufferEntrada = !m_BufferEntrada  ;
	}
	else
		m_CountBounce = 0 ;
}


uint8_t DigitalInputs::get ( void )
{
	return m_BufferEntrada;
}
/**
	\fn bool  operator bool ()
	\brief Sobrecarga de del operador de contenido
	\return true estado alto y false estado bajo
*/
DigitalInputs::operator bool()
{
	 return m_BufferEntrada;
}
bool DigitalInputs::operator!( void )
{
	return !m_BufferEntrada;
}
