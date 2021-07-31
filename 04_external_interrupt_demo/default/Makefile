###############################################################################
# Makefile for the project 04_interrupt_demo
###############################################################################

## General Flags
PROJECT = 04_interrupt_demo
MCU = atmega128
TARGET = 04_interrupt_demo.elf
CC = avr-gcc

CPP = avr-g++

## Options common to compile, link and assembly rules
COMMON = -mmcu=$(MCU)

## Compile options common for all C compilation units.
CFLAGS = $(COMMON)
CFLAGS += -Wall -gdwarf-2 -std=gnu99   -DF_CPU=16000000UL -O0 -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
CFLAGS += -MD -MP -MT $(*F).o -MF dep/$(@F).d 

## Assembly specific flags
ASMFLAGS = $(COMMON)
ASMFLAGS += $(CFLAGS)
ASMFLAGS += -x assembler-with-cpp -Wa,-gdwarf2

## Linker flags
LDFLAGS = $(COMMON)
LDFLAGS +=  -Wl,-Map=04_interrupt_demo.map


## Intel Hex file production flags
HEX_FLASH_FLAGS = -R .eeprom -R .fuse -R .lock -R .signature

HEX_EEPROM_FLAGS = -j .eeprom
HEX_EEPROM_FLAGS += --set-section-flags=.eeprom="alloc,load"
HEX_EEPROM_FLAGS += --change-section-lma .eeprom=0 --no-change-warnings


## Objects that must be built in order to link
OBJECTS = 04_interrupt_demo.o 04_interrupt_1.o 04_interrupt_2.o 04_interrupt_3.o 

## Objects explicitly added by the user
LINKONLYOBJECTS = 

## Build
all: $(TARGET) 04_interrupt_demo.hex 04_interrupt_demo.eep 04_interrupt_demo.lss size

## Compile
04_interrupt_demo.o: ../04_interrupt_demo.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

04_interrupt_1.o: ../04_interrupt_1.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

04_interrupt_2.o: ../04_interrupt_2.c
	$(CC) $(INCLUDES) $(CFLAGS) -c  $<

04_interrupt_3.o: ../04_interrupt_3.c
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
	-rm -rf $(OBJECTS) 04_interrupt_demo.elf dep/* 04_interrupt_demo.hex 04_interrupt_demo.eep 04_interrupt_demo.lss 04_interrupt_demo.map


## Other dependencies
-include $(shell mkdir dep 2>NUL) $(wildcard dep/*)

