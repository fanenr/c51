CC = sdcc-sdcc
PACKER = sdcc-packihx
CFLAGS = -mmcs51 --std-sdcc11
HEADERS = -I/usr/share/sdcc/include

all: TUBE3.hex

TUBE3.hex: TUBE3.ihx
	$(PACKER) $< > $@

TUBE3.ihx: TUBE3.rel TUBE.rel TIMER.rel
	$(CC) -o $@ $^

TUBE3.rel: TUBE3.c TIMER.h TUBE.h
	$(CC) -c $< $(CFLAGS) $(HEADERS)

TIMER.rel: TIMER.c TIMER.h
	$(CC) -c $< $(CFLAGS) $(HEADERS)

TUBE.rel: TUBE.c TUBE.h TIMER.h
	$(CC) -c $< $(CFLAGS) $(HEADERS)

.PHONY: flash
flash: TUBE3.hex
	sudo ../stcflash $<

OBJECTS := $(shell find . -name "TUBE3.*")
OBJECTS += $(shell find . -name "TIMER.*")
OBJECTS += $(shell find . -name "TUBE.*")
OBJECTS := $(filter-out %.c %.h, $(OBJECTS))

.PHONY: clean
clean:
	rm -f $(OBJECTS)
