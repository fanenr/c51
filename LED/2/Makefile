CC = sdcc-sdcc
PACKER = sdcc-packihx
CFLAGS = -mmcs51 --std-sdcc11
HEADERS = -I/usr/share/sdcc/include

all: LED2.hex

LED2.hex: LED2.ihx
	$(PACKER) $< > $@

LED2.ihx: LED2.rel
	$(CC) -o $@ $^

LED2.rel: LED2.c
	$(CC) -c $< $(CFLAGS) $(HEADERS)

.PHONY: flash
flash: LED2.hex
	sudo ../stcflash $<

OBJECTS := $(shell find . -name "LED2.*")
OBJECTS := $(filter-out %.c, $(OBJECTS))

.PHONY: clean
clean:
	rm -f $(OBJECTS)
