# gen ihx
%.ihx:
	$(CC) $(LDFLAGS) -o $@ $^

# gen rel
%.rel: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: flash clean

# flash
flash:
	$(STCGAL) $(STCGAL_FLAGS) $(f:%=%.ihx)

# clean
objs := *.lk *.lst *.map *.mem *.rst *.sym \
        *.asm *.rel *.ihx *.adb *.cdb *.omf

clean:
	rm -f $(objs)
