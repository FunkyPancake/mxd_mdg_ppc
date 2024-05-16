#include "ee.h"
#include "InitHW.h"

/* insert a stub for the functions not directly supported by __FP__ */
#ifdef __FP__
__INLINE__ void __ALWAYS_INLINE__ DisableAllInterrupts(void)
{
  EE_hal_disableIRQ();
}

__INLINE__ void __ALWAYS_INLINE__ EnableAllInterrupts(void)
{
  EE_hal_enableIRQ();
}

__INLINE__ void __ALWAYS_INLINE__ TerminateTask(void)
{
}

#define OSDEFAULTAPPMODE 1
__INLINE__ void __ALWAYS_INLINE__ StartOS(int i)
{
}
#endif

int main(void)
{
  /* Init HW: PLLs, clock (120 Mhz), clear error flags, etc */
  InitHW();
  EnableIsr();

  /* let's start the multiprogramming environment...*/
  StartOS(OSDEFAULTAPPMODE);

  /* now the background activities... */
  for (;;)
    ;

  return 0;
}
