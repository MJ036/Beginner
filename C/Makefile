Src := $(wildcard *.c)
Outs := $(patsubst %.c,%,$(Src))

CC := gcc
CFLAGS = -Wall -g

ALL : $(Outs)
	CC $< -o %@ $(CFLAGS)

.PHONY : clean rebuild ALL

clean:
	$(RM) $(Outs)
