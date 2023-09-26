/*******************************************************************************************************************************//**
 *
 * @file		timers.h
 * @brief		Clase para creacion de temporizadores
 * @date		4 may. 2022
 * @author		Ing. Marcelo Trujillo
 *
 **********************************************************************************************************************************/
#ifndef TIMER_H
#define TIMER_H

/***********************************************************************************************************************************
 *** INCLUDES GLOBALES
 **********************************************************************************************************************************/
#include "systick.h"
#include "tipos.h"

/***********************************************************************************************************************************
 *** DEFINES GLOBALES
 **********************************************************************************************************************************/

/***********************************************************************************************************************************
 *** MACROS GLOBALES
 **********************************************************************************************************************************/
/***********************************************************************************************************************************
 *** TIPO DE DATOS GLOBALES
 **********************************************************************************************************************************/
typedef void (*Timer_Handler)(void);

/***********************************************************************************************************************************
 *** IMPLANTACION DE LA CLASE
 **********************************************************************************************************************************/
class timer : public Callback
{
	protected:
		volatile uint32_t 	m_TmrRun;
		volatile bool  		m_TmrEvent;
		void   				(* m_TmrHandler ) (void);
		volatile bool  		m_TmrStandBy ;
		volatile uint8_t  	m_TmrBase ;
	public:
		enum 		bases_t 			{ DEC , SEG , MIN };
		enum 		ticks_t 			{ DECIMAS = 100 , SEGUNDOS = 10 , MINUTOS  = 60 };
		enum 		erroresTimers_t 	{ errorTimer , OKtimers };
		enum 		standby_t 			{ RUN , PAUSE };

		timer( ) ;
		timer(const Timer_Handler handler , const bases_t base );

		void 		TimerStart( uint32_t time, const Timer_Handler handler , const bases_t base );
		void 		SetTimer(  uint32_t time );
		void 		GetTimer(  uint32_t &time) const;
		void 		StandByTimer( const standby_t accion );
		void 		TimerStop( void );
		void  		SetmrStandBy( uint8_t accion) { m_TmrStandBy = accion ;}
		void 		TimerStart( uint32_t time );
		void 		TmrEvent ( void );

		timer& 		operator=( uint32_t t );
		bool 		operator!( );
		bool 		operator==( uint32_t t );

		friend bool operator==( uint32_t t , timer &T );

		// por el hecho de haber convertido el operador bool como explicit
		// me obligo a realizar las funciones amigas del operador==
		// con sus dos prototipos, porque dejo de aceptar
		// la promocion automatica de tipos
		explicit 	operator bool () ;

		void 		callback( void );

		virtual 	~timer();
};

#endif /* TIMER_H */
