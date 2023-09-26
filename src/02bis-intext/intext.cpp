/*******************************************************************************************************************************//**
 *
 * @file		intext.cpp
 * @brief		Descripcion del modulo
 * @date		13 jun. 2023
 * @author		Ing. Federico Bua
 *
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** INCLUDES
 **********************************************************************************************************************************/
#include "LPC845.h"
#include "intext.h"
#include "tipos.h"
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
 *** VARIABLES GLOBALES PRIVADAS AL MODULO
 **********************************************************************************************************************************/
static Intext* intexts[8];
/***********************************************************************************************************************************
 *** IMPLEMENTACION DE LOS METODODS DE LA CLASE
 **********************************************************************************************************************************/
#define SYSAHBCLKCTRL0_GPIO_INT_BIT 28
#define NVIC_PININT0_BIT 24

Intext::Intext(uint8_t pint, uint8_t port, uint8_t pin, void (*callback) (void))
{
	m_pint = pint; //Pin de interrupcion asociado al pin fisico
	m_port = port; //Puerto fisico donde se encuentra el pin
	m_pin = pin; //Pin fisico del puerto
	m_callback = callback;
	m_cant_irq = 0;
}

void Intext::setup()
{
	SYSCON->PINTSEL[m_pint] = m_port*32 + m_pin; //Selecciona ese pin como fuente de esa interrupcion externa
	SYSCON->SYSAHBCLKCTRL0 |= (1 << SYSAHBCLKCTRL0_GPIO_INT_BIT);//Habilita las interrupciones por GPIO
	SYSCON->STARTERP0 &= ~(1 << m_pint);//Deshabilitamos la funcion wake-up de la interrupcion ya que no la usamos
	NVIC->ISER[0] |= (1 << (NVIC_PININT0_BIT+m_pint)); //Habilitamos la interrupcion externa en el NVIC
	intexts[m_pint] = this; //Guardamos esta interrupcion externa en un vector de interrupciones externas
}

void Intext::set_callback(void (*callback) (void))
{
	m_callback = callback; //Setea la funcion que queremos que se ejecute cuando salta la interrupcion
}

int Intext::set_flanco(Intext::flanco_t flanco)
{
	if((m_pint > 7 ) || (m_port > 2) || (m_pin > 31))
		return -1;
	setup();//Configura el setup
	PINT->ISEL &= ~(1 << m_pint);//Define que que la interrupcion sea por flanco

	PINT->IENF &= ~(1 << m_pint); //Pone el bit correspondiente al pinint en 0 para despues configurarlo
	PINT->IENR &= ~(1 << m_pint); //Pone el bit correspondiente al pinint en 0 para despues configurarlo
	if((flanco == ASCENDENTE) || (flanco == AMBOS_FLANCOS))
		PINT->IENR |= (1 << m_pint); //Habilita o deshabilita que sea por flanco ascendente
	if((flanco == DESCENDENTE) || (flanco == AMBOS_FLANCOS))
		PINT->IENF |= (1 << m_pint); //Habilita o deshabilita que sea por flanco descendente

	return 0;
}

int Intext::set_nivel(Intext::nivel_t nivel)
{
	if((m_pint > 7 ) || (m_port > 2) || (m_pin > 31))
		return -1;
	setup();//Configura el setup
	PINT->ISEL |= (1 << m_pint); //Define que la interrupcion sea por nivel
	PINT->IENF &= ~(1 << m_pint);//Pone el bit correspondiente al pinint en 0 para despues configurarlo
	PINT->IENF |= (nivel << m_pint);//Setea el IRQ por nivel alto o nivel bajo
	PINT->IENR |= (1 << m_pint);//Habilita o deshabilita la interrupcion
	return 0;
}

void Intext::limpiar_irq()
{
	if(PINT->IST & (1 << m_pint))
	{
		PINT->IST |= (1 << m_pint); //En caso de ser nivel, cambia el nivel para que no interrumpa siempre
		if(m_callback)
			m_callback(); //Ejecuta la funcion que queremos que se active cuadno pasa la interrupcion
	}
	m_cant_irq++;
}

void PININT0_IRQHandler(void){ intexts[0]->limpiar_irq();}//Handlers que se activan cuando detectan la interrupcion
void PININT1_IRQHandler(void){ intexts[1]->limpiar_irq();}
void PININT2_IRQHandler(void){ intexts[2]->limpiar_irq();}
void PININT3_IRQHandler(void){ intexts[3]->limpiar_irq();}
void PININT4_IRQHandler(void){ intexts[4]->limpiar_irq();}
void PININT5_IRQHandler(void){ intexts[5]->limpiar_irq();}
// void PININT6_IRQHandler(void){ intexts[6]->limpiar_irq();}
// void PININT7_IRQHandler(void){ intexts[7]->limpiar_irq();}
