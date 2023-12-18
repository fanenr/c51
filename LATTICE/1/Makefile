CC = sdcc-sdcc
PACKER = sdcc-packihx
CFLAGS = -mmcs51 --std-sdcc11
HEADERS = -I/usr/share/sdcc/include

all: LATTICE.hex

LATTICE.hex: LATTICE.ihx
	$(PACKER) $< > $@

LATTICE.ihx: LATTICE.rel
	$(CC) -o $@ $^

LATTICE.rel: LATTICE.c
	$(CC) -c $< $(CFLAGS) $(HEADERS)

.PHONY: flash
flash: LATTICE.hex
	sudo ../../stcflash $<

OBJECTS := $(shell find . -name "LATTICE.*")
OBJECTS := $(filter-out %.c, $(OBJECTS))

.PHONY: clean
clean:
	rm -f $(OBJECTS)
