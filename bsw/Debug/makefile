
	EEOPT  += EE_MPC5644A
### Setting Erika's variables:
# ERIKA_FILES= ../../..
# APPBASE = .
# 
# EEOPT =


RTDRUID_CONFIGURATOR_NUMBER:=1278



############################################################################
#
# User options
#
############################################################################
EEOPT += DEBUG
EEOPT += __CODEWARRIOR__
EEOPT += EE_ISR_DYNAMIC_TABLE
EEOPT += EE_SYSTEM_TIMER_DEVICE_DECREMENTER
EEOPT += __USE_CUSTOM_LINKER_SCRIPT__
EEOPT += __USE_CUSTOM_CRT0__


############################################################################
#
# Automatic options
#
############################################################################
EEOPT += __RTD_CYGWIN__
EEOPT += __PPCE200ZX__
EEOPT += EE_PPCE200Z4
EEOPT += ENABLE_SYSTEM_TIMER
EEOPT += __VLE__
EEOPT += __DIAB__
EEOPT += __OO_ORTI_LASTERROR__
EEOPT += __OO_ORTI_SERVICETRACE__
EEOPT += __OO_ORTI_PRIORITY__
EEOPT += __OO_ORTI_RES_LOCKER_TASK__
EEOPT += __OO_ORTI_RES_ISLOCKED__
EEOPT += __OO_ORTI_STACK__
EEOPT += __OO_ORTI_ALARMTIME__
EEOPT += __OO_ORTI_RUNNINGISR2__
EEOPT += __OO_ECC2__
EEOPT += __OO_EXTENDED_STATUS__
EEOPT += __OO_HAS_STARTUPHOOK__
EEOPT += __OO_HAS_PRETASKHOOK__
EEOPT += __IRQ_STACK_NEEDED__
EEOPT += __MULTI__
EEOPT += __OO_AUTOSTART_TASK__
EEOPT += __OO_AUTOSTART_ALARM__
EEOPT += __ALLOW_NESTED_IRQ__
EEOPT += __DISABLE_EEOPT_DEFINES__


############################################################################
#
# Erika base directory
#
############################################################################
ifdef ERIKA_FILES
ifdef EEBASE
    $(warning EEBASE is set, but it has been overridden by ERIKA_FILES)
endif
EEBASE := $(shell cygpath `cygpath -ms '${ERIKA_FILES}'`)

else # ERIKA_FILES

ifndef EEBASE
        EEBASE := $(shell cygpath `cygpath -ms 'G:\projects\ErikaOs_MPC5644A\src\BSW\OS\ee_files'`)
else
        $(warning The usage of EEBASE is deprecated. Please use ERIKA_FILES)
endif
endif # ERIKA_FILES
# ERIKA_FILES has fulfilled its role. Make sure it's not used inside Erika makefiles
ERIKA_FILES :=
$(info Using erika files in $(EEBASE))


############################################################################
#
# Freescale MPC5644A, PPC E200Z4
#
############################################################################
-include $(EEBASE)/pkg/cfg/path_helper.mk
APPBASE := ..
OUTBASE := Debug

$(eval $(call check_and_set_cygwin_compiler_path,PPC_CW_BASEDIR,C:\Programy\Freescale\CW MCU v10.7\MCU))


############################################################################
#
# Flags
#
############################################################################
CFLAGS  += -warn illpragmas -warn unwanted -warn extended -warn hidevirtual -warn implicitconv -warn impl_int2float -warn impl_float2int -warn impl_signedunsigned -warn ptrintconv -warn unusedarg -warn unusedvar -warn missingreturn -warn unusedexpr -warn extracomma -warn emptydecl -warn structclass -warn filecaps -warn sysfilecaps -warn undefmacro -inline on -inline nobottomup -align powerpc -func_align 4  -pooldata on -use_lmw_stmw on -I../src/ -I../Project_Headers -ir ../src/BSW -ir ../src/ASW -ir ../src/IL -ir ../src/Utils -ir ../src/ASW/Sensors
ASFLAGS += 
LDFLAGS += -lcf ../Project_Settings/Linker_Files/MPC5644A_FLASH.lcf -romaddr 0x00040000 -rambuffer 0x00040000 -code_merging safe -model absolute -sym full -msgstyle parseable 
LDDEPS  += 
LIBS    += 



############################################################################
#
# Sources
#
############################################################################
APP_SRCS += eecfg.c src/main.c src/ee_boot.c src/BSW/OS/OS_Task.c src/BSW/OS/InitHW.c src/IL/IL_Tasks.c src/BSW/BSW_Tasks.c src/ASW/ASW_Tasks.c src/BSW/HAL/FMPLL/fmpll.c src/BSW/HAL/GPIO/gpio.c src/BSW/HAL/FLASH/flash.c src/BSW/HAL/ESCI/esci.c src/BSW/HAL/PIT/PIT.c src/BSW/HAL/EMIOS/EMIOS.c src/BSW/HAL/EQADC/EQADC.c src/BSW/CDD/MC33926/CDD_MC33926.c src/BSW/CDD/MC33926/CDD_MC33926_Out.c src/BSW/HAL/GPIO/GPIO_Cfg.c src/BSW/HAL/PIT/PIT_Cfg.c src/BSW/HAL/EMIOS/EMIOS_Cfg.c src/BSW/HAL/ESCI/ESCI_Cfg.c src/BSW/HAL/EQADC/EQADC_Out.c src/BSW/HAL/EQADC/EQADC_Cfg.c src/BSW/COM/XCP/xcp_if.c src/BSW/COM/XCP/xcp_par.c src/BSW/COM/XCP/XcpBasic.c src/IL/IL_An.c src/IL/IL_GPIO.c src/ASW/Sensors/FAirIntk/FAirIntk.c src/ASW/Sensors/FAirIntk/FAirIntk_Out.c src/ASW/Sensors/TDev/NTC12_Cal.c src/ASW/Sensors/TDev/TAirIntk/TAirIntk.c src/ASW/Sensors/TDev/TAirIntk/TAirIntk_Out.c src/ASW/Sensors/TDev/TEngClt/TEngClt_Out.c src/ASW/Sensors/TDev/TEngClt/TEngClt.c src/ASW/Sensors/TDev/TEngOil/TEngOil_Out.c src/ASW/Sensors/TDev/TEngOil/TEngOil.c src/ASW/Sensors/PDev/PEngOil/PEngOil.c src/ASW/Sensors/PDev/PEngOil/PEngOil_Out.c src/ASW/Sensors/PDev/PAirIntk/PAirIntk.c src/ASW/Sensors/PDev/PAirIntk/PAirIntk_Out.c src/ASW/Sensors/PDev/PFuRail/PFuRail.c src/ASW/Sensors/PDev/PFuRail/PFuRail_Out.c src/ASW/Sensors/PDev/PBrkServo/PBrkServo.c src/ASW/Sensors/PDev/PBrkServo/PBrkServo_Out.c src/ASW/Sensors/RIntkThr/RIntkThr.c src/ASW/Sensors/RIntkThr/RIntkThr_Out.c src/ASW/Sensors/RTrbVtgPos/RTrbVtgPos.c src/ASW/Sensors/RTrbVtgPos/RTrbVtgPos_Out.c src/ASW/Actuators/TrbChgVtgActr/TrbChgVtgActr.c src/ASW/Actuators/TrbChgVtgActr/TrbChgVtgActr_Out.c src/Utils/Ifl.c src/Utils/Ifx.c


############################################################################
#
# end
#
############################################################################
include $(EEBASE)/pkg/cfg/rules.mk
