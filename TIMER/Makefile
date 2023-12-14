CC = sdcc-sdcc
PACKER = sdcc-packihx
CFLAGS = -mmcs51 --std-sdcc11
HEADERS = -I/usr/share/sdcc/include

all: TIMER.hex

TIMER.hex: TIMER.ihx
	$(PACKER) $< > $@

TIMER.ihx: TIMER.rel
	$(CC) -o $@ $^

TIMER.rel: TIMER.c
	$(CC) -c $< $(CFLAGS) $(HEADERS)

.PHONY: flash
flash: TIMER.hex
	sudo ../stcflash $<

OBJECTS := $(shell find . -name "TIMER.*")
OBJECTS := $(filter-out %.c, $(OBJECTS))

.PHONY: clean
clean:
	rm -f $(OBJECTS)
