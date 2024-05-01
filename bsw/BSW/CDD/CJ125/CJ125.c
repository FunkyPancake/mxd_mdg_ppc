#include "CJ125.h"
/*20 ms raster*/
CJ125_HtrCtrl()
{

    /*
    PWM limits 4..97%
    states:
    - low power condensation removal
    - initial heating
    - rampup
    - closed loop
    diagnostyka nagrzewania:
    low temp diag
    start diag
    permament diag
    z timeoutami
    */
}
//1ms raster
CJ125_InputProcessing()
{
    //filter input with filter 3.5ms
}

/*10ms raster*/
CJ125_PumpCtrl()
{
    //pump control task
    //p0 = 1013pha
    //pressure compensation ->ip(p) =  ip(p0)*p/p(0)*(p0+k)/(p+k) k -> mapa
    // ewentualnie zmapowane compensacja(p)
    //temperature comnsation ip real = 1+(0.035/100degC)*(Tsetpoint-tceract)
}