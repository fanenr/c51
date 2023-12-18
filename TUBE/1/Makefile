CC = sdcc-sdcc
PACKER = sdcc-packihx
CFLAGS = -mmcs51 --std-sdcc11
HEADERS = -I/usr/share/sdcc/include

all: TUBE.hex

TUBE.hex: TUBE.ihx
	$(PACKER) $< > $@

TUBE.ihx: TUBE.rel TIMER.rel
	$(CC) -o $@ $^

TUBE.rel: TUBE.c
	$(CC) -c $< $(CFLAGS) $(HEADERS)

TIMER.rel: TIMER.c TIMER.h
	$(CC) -c $< $(CFLAGS) $(HEADERS)

.PHONY: flash
flash: TUBE.hex
	sudo ../stcflash $<

OBJECTS := $(shell find . -name "TUBE.*" -o -name "TIMER.*")
OBJECTS := $(filter-out %.c %.h, $(OBJECTS))

.PHONY: clean
clean:
	rm -f $(OBJECTS)
