include ../config.mk

all: tube1.ihx tube2.ihx tube3.ihx

tube1.ihx: $(addsuffix .rel, tube1 timer)
tube2.ihx: $(addsuffix .rel, tube2 timer)
tube3.ihx: $(addsuffix .rel, tube3 tube timer)

include ../rule.mk
