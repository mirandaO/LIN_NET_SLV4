################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/Application/LED_App.c" \

C_SRCS += \
../Sources/Application/LED_App.c \

OBJS += \
./Sources/Application/LED_App_c.obj \

OBJS_QUOTED += \
"./Sources/Application/LED_App_c.obj" \

C_DEPS += \
./Sources/Application/LED_App_c.d \

OBJS_OS_FORMAT += \
./Sources/Application/LED_App_c.obj \

C_DEPS_QUOTED += \
"./Sources/Application/LED_App_c.d" \


# Each subdirectory must supply rules for building sources it contributes
Sources/Application/LED_App_c.obj: ../Sources/Application/LED_App.c
	@echo 'Building file: $<'
	@echo 'Executing target #10 $<'
	@echo 'Invoking: PowerPC Compiler'
	"$(PAToolsDirEnv)/mwcceppc" @@"Sources/Application/LED_App.args" -o "Sources/Application/LED_App_c.obj" "$<" -MD -gccdep
	@echo 'Finished building: $<'
	@echo ' '

Sources/Application/%.d: ../Sources/Application/%.c
	@echo 'Regenerating dependency file: $@'
	
	@echo ' '


