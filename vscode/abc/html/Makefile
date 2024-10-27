CFILES += ../util/scf_string.c

CFILES += main.c
CFILES += abc_obj.c
CFILES += abc_html.c
CFILES += abc_html_util.c

CFLAGS += -g
CFLAGS += -I../util

LDFLAGS += -ldl

all:
	gcc $(CFLAGS) $(CFILES) $(LDFLAGS)

clean:
	rm *.o
