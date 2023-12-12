CC = sdcc-sdcc
PACKER = sdcc-packihx
CFLAGS = -mmcs51 --std-sdcc11
HEADERS = -I/usr/share/sdcc/include

all: LED.hex

LED.hex: LED.ihx
	$(PACKER) $< > $@

LED.ihx: LED.rel
	$(CC) -o $@ $^

LED.rel: LED.c
	$(CC) -c $< $(CFLAGS) $(HEADERS)

.PHONY: flash
flash: LED.hex
	sudo ../stcflash LED.hex

OBJECTS := $(shell find . -name "LED.*")
OBJECTS := $(filter-out %.c, $(OBJECTS))

.PHONY: clean
clean:
	rm -f $(OBJECTS)
