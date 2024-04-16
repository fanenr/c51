include ../config.mk

all: lattice1.ihx lattice2.ihx lattice3.ihx

lattice1.ihx: $(addsuffix .rel, lattice1)
lattice2.ihx: $(addsuffix .rel, lattice2 timer)
lattice3.ihx: $(addsuffix .rel, lattice3 lattice timer)

include ../rule.mk
