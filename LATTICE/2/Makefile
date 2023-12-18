CC = sdcc-sdcc
PACKER = sdcc-packihx
CFLAGS = -mmcs51 --std-sdcc11
HEADERS = -I/usr/share/sdcc/include

all: LATTICE.hex

LATTICE.hex: LATTICE.ihx
	$(PACKER) $< > $@

LATTICE.ihx: LATTICE.rel TIMER.rel
	$(CC) -o $@ $^

LATTICE.rel: LATTICE.c TIMER.h
	$(CC) -c $< $(CFLAGS) $(HEADERS)

TIMER.rel: TIMER.c TIMER.h
	$(CC) -c $< $(CFLAGS) $(HEADERS)

.PHONY: flash
flash: LATTICE.hex
	sudo ../../stcflash $<

OBJECTS := $(shell find . -name "LATTICE.*")
OBJECTS := $(filter-out %.c, $(OBJECTS))

.PHONY: clean
clean:
	rm -f $(OBJECTS)
