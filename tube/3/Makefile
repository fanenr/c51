CC      = sdcc-sdcc
PACKER  = sdcc-packihx
FLASHER = ../../stcflash
CFLAGS  = -mmcs51 --std-sdcc11
HEADERS = -I/usr/share/sdcc/include -I../../

targets := test_tube
deps    := tube timer

all: $(targets:%=%.hex)

$(targets:%=%.hex): %.hex: %.ihx
	$(PACKER) $< > $@

$(targets:%=%.ihx): %.ihx: %.rel $(deps:%=%.rel)
	$(CC) -o $@ $^

$(targets:%=%.rel): %.rel: %.c $(deps:%=%.h)
	$(CC) -c $< $(CFLAGS) $(HEADERS)

$(deps:%=%.rel): %.rel: %.c $(deps:%=%.h)
	$(CC) -c $< $(CFLAGS) $(HEADERS)

.PHONY: flash
flash: $(targets:%=%.hex)
	sudo $(FLASHER) $<

OBJECTS := $(shell ls .)
OBJECTS := $(filter-out %.h %.c Makefile, $(OBJECTS))

.PHONY: clean
clean:
	rm -f $(OBJECTS)
