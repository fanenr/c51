CC = sdcc-sdcc
PACKER = sdcc-packihx
CFLAGS = -mmcs51 --std-sdcc11
HEADERS = -I/usr/share/sdcc/include

all: TUBE2.hex

TUBE2.hex: TUBE2.ihx
	$(PACKER) $< > $@

TUBE2.ihx: TUBE2.rel TIMER.rel
	$(CC) -o $@ $^

TUBE2.rel: TUBE2.c
	$(CC) -c $< $(CFLAGS) $(HEADERS)

TIMER.rel: TIMER.c TIMER.h
	$(CC) -c $< $(CFLAGS) $(HEADERS)

.PHONY: flash
flash: TUBE2.hex
	sudo ../stcflash $<

OBJECTS := $(shell find . -name "TUBE2.*" -o -name "TIMER.*")
OBJECTS := $(filter-out %.c %.h, $(OBJECTS))

.PHONY: clean
clean:
	rm -f $(OBJECTS)
