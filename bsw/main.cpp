/*
 * main implementation: use this 'C++' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
//#include "FreeRTOS.h"
#ifdef __cplusplus
extern "C" {
#endif

extern void xcptn_xmpl(void);

#ifdef __cplusplus
}
#endif

class counterclass
{
private:
  	int m_counter;
public:  
	counterclass(void) 
	{
		m_counter = 0;
	};
	void increment(void) 
	{
		m_counter++;
	};  	
};

int main()
{
	counterclass myccounter;

    xcptn_xmpl ();              /* Configure and Enable Interrupts */

    /* Loop forever */
	for(;;) {	
			myccounter.increment();
		}
}
