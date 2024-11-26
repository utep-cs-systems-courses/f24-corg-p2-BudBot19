# makfile configuration
COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include


#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as


all: button.elf led.elf buzzer.elf


#additional rules for files
button.elf: ${COMMON_OBJECTS} buzzer.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

led.elf: ${COMMON_OBJECTS} buzzer.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

buzzer.elf: ${COMMON_OBJECTS} buzzer.o main.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf led.elf buzzer.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

main.o: led.h buzzer.h siren_c.c

buzzer.o: buzzer.h

siren_c.o: buzzer.h led.h

siren_s.o: buzzer.h led.h
