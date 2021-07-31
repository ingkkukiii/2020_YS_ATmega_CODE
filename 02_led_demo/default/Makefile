###############################################################################
# Makefile for the project 2_led_demo
###############################################################################

## General Flags
PROJECT = 2_led_demo
MCU = atmega128
TARGET = 2_led_demo.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99     -DF_CPU=16000000UL -O0 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=2_led_demo.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = 02_led_demo.o 02_led_1.o 02_led_2.o 02_led_3.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) 2_led_demo.hex 2_led_demo.eep 2_led_demo.lss size

## Compile
02_led_demo.o: ../02_led_demo.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

02_led_1.o: ../02_led_1.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

02_led_2.o: ../02_led_2.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

02_led_3.o: ../02_led_3.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

##Link
$(TARGET): $(OBJECTS)
	 $(CC) $(LDFLAGS) $(OBJECTS) $(LINKONLYOBJECTS) $(LIBDIRS) $(LIBS) -o $(TARGET)

%.hex: $(TARGET)
	avr-objcopy -O ihex $(HEX_FLASH_FLAGS)  $< $@

%.eep: $(TARGET)
	-avr-objcopy $(HEX_EEPROM_FLAGS) -O ihex $< $@ || exit 0

%.lss: $(TARGET)
	avr-objdump -h -S $< > $@

size: ${TARGET}
	@echo
	@avr-size -C --mcu=${MCU} ${TARGET}

## Clean target
.PHONY: clean
clean:
	-rm -rf $(OBJECTS) 2_led_demo.elf dep/* 2_led_demo.hex 2_led_demo.eep 2_led_demo.lss 2_led_demo.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

