# makfile configuration
COMMON_OBJECTS  = main.o
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h
LDFLAGS		= -L/opt/ti/msp430_gcc/include


#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as


all: button.elf led.elf buzzer.elf draw.elf


#additional rules for files
button.elf: ${COMMON_OBJECTS} buzzer.o draw_face1.o draw_face234.o ../lib/libTimer.a ../lib/libLcd.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

led.elf: ${COMMON_OBJECTS} buzzer.o draw_face1.o draw_face234.o ../lib/libTimer.a ../lib/libLcd.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ 

buzzer.elf: ${COMMON_OBJECTS} buzzer.o main.o draw_face1.o draw_face234.o ../lib/libTimer.a ../lib/libLcd.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

draw.elf: ${COMMON_OBJECTS} buzzer.o main.o draw_face1.o draw_face234.o ../lib/libTimer.a ../lib/libLcd.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ 

load: button.elf led.elf buzzer.elf draw.elf
	msp430loader.sh $^

clean:
	rm -f *.o *.elf

main.o: led.h buzzer.h siren_c.c draw.h

buzzer.o: buzzer.h

siren_c.o: buzzer.h led.h

siren_s.o: buzzer.h led.h

draw_face1.o: draw.h

draw_face234.o: draw.h
