# gen ihx
%.ihx:
	$(CC) -o $@ $^

# gen rel
%.rel: %.c
	$(CC) $(CFLAGS) -c $<

.PHONY: flash clean

# flash
flash:
	$(STCGAL) $(STCGAL_FLAGS) $(f:%=%.ihx)

# clean
cleans := *.lk *.ihx *.lst *.map *.mem \
          *.rel *.rst *.sym *.asm *.hex
clean:
	rm -f $(cleans)
