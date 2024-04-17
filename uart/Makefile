include ../config.mk

all: uart1.ihx uart2.ihx

uart1.ihx: $(addsuffix .rel, uart1 timer)
uart2.ihx: $(addsuffix .rel, uart2 btns timer)

include ../rule.mk
