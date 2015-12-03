################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/MAL/GPIO.c" \
"../Sources/MAL/Global_Init.c" \
"../Sources/MAL/LIN.c" \

C_SRCS += \
../Sources/MAL/GPIO.c \
../Sources/MAL/Global_Init.c \
../Sources/MAL/LIN.c \

OBJS += \
./Sources/MAL/GPIO_c.obj \
./Sources/MAL/Global_Init_c.obj \
./Sources/MAL/LIN_c.obj \

OBJS_QUOTED += \
"./Sources/MAL/GPIO_c.obj" \
"./Sources/MAL/Global_Init_c.obj" \
"./Sources/MAL/LIN_c.obj" \

C_DEPS += \
./Sources/MAL/GPIO_c.d \
./Sources/MAL/Global_Init_c.d \
./Sources/MAL/LIN_c.d \

OBJS_OS_FORMAT += \
./Sources/MAL/GPIO_c.obj \
./Sources/MAL/Global_Init_c.obj \
./Sources/MAL/LIN_c.obj \

C_DEPS_QUOTED += \
"./Sources/MAL/GPIO_c.d" \
"./Sources/MAL/Global_Init_c.d" \
"./Sources/MAL/LIN_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/MAL/GPIO_c.obj: ../Sources/MAL/GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MAL/GPIO.args" -o "Sources/MAL/GPIO_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/MAL/%.d: ../Sources/MAL/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '

Sources/MAL/Global_Init_c.obj: ../Sources/MAL/Global_Init.c
	@echo 'Building file: $<'
	@echo 'Executing target #8 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MAL/Global_Init.args" -o "Sources/MAL/Global_Init_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/MAL/LIN_c.obj: ../Sources/MAL/LIN.c
	@echo 'Building file: $<'
	@echo 'Executing target #9 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/MAL/LIN.args" -o "Sources/MAL/LIN_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '


