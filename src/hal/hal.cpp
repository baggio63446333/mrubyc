/*! @file
  @brief
  Hardware abstraction layer
        for SPRESENSE Arduino

  <pre>
  Copyright (C) 2016 Kyushu Institute of Technology.
  Copyright (C) 2016 Shimane IT Open-Innovation Center.

  This file is distributed under BSD 3-Clause License.
  </pre>
*/

/***** Feature test switches ************************************************/
/***** System headers *******************************************************/
#include <Arduino.h>


/***** Local headers ********************************************************/
#include "hal.h"


/***** Constat values *******************************************************/
/***** Macros ***************************************************************/
/***** Typedefs *************************************************************/
/***** Function prototypes **************************************************/
void attachInterrupt(uint8_t interrupt, void (*isr)(void), int mode);

/***** Local variables ******************************************************/
/***** Global variables *****************************************************/
/***** Signal catching functions ********************************************/
#ifndef MRBC_NO_TIMER
//================================================================
/*!@brief
  alarm signal handler

*/
static unsigned int timer_isr(void)
{
  mrbc_tick();
  return MRBC_TICK_UNIT * 1000;
}


#endif


/***** Local functions ******************************************************/
/***** Global functions *****************************************************/
#ifndef MRBC_NO_TIMER

//================================================================
/*!@brief
  initialize

*/
void hal_init(void)
{
  attachTimerInterrupt(timer_isr, MRBC_TICK_UNIT * 1000);
}


//================================================================
/*!@brief
  enable interrupt

*/
void hal_enable_irq(void)
{
  interrupts();
}


//================================================================
/*!@brief
  disable interrupt

*/
void hal_disable_irq(void)
{
  noInterrupts();
}


#endif /* ifndef MRBC_NO_TIMER */
