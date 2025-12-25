CC=gcc
CFLAGS=-c  -Wall -I. -fpic -s -o2  -Wno-stringop-overflow  -Werror 

OBJS=tester.o  student.o  

%.o:	%.c %.h
	$(CC) $(CFLAGS) $< -o $@ 

tester:	$(OBJS) ref.o
	$(CC) $(LDFLAGS)  -o $@ $^

clean:
	rm -f student.o  tester.o tester
