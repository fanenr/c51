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
objs := *.lk *.lst *.map *.mem \
          *.rst *.sym *.asm *.rel *.ihx

clean:
	rm -f $(objs)
