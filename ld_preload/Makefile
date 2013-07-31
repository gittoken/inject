CFLAGS = -g  -fPIC

FOPEN_LIB_OBJS = fopen.o
FOPEN_WRAP_LIB_OBJS = fopen_wrap.o
XCB_WRAP_LIB_OBJS = xcb_writev_wrap.o
TEST_FOPENOBJS = test_fopen.o

TARGET = libfopen.so libfopenwrap.so libxcbwrap.so test_fopen

all : $(TARGET)

libfopen.so : $(FOPEN_LIB_OBJS)
	$(CC) $(CFLAGS) -shared -o $@ $^

libfopenwrap.so : $(FOPEN_WRAP_LIB_OBJS)
	$(CC) $(CFLAGS) -shared -o $@ $^ -ldl

libxcbwrap.so : $(XCB_WRAP_LIB_OBJS)
	$(CC) $(CFLAGS) -shared -o $@ $^ -ldl -lxcb

test_fopen: $(TEST_FOPENOBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) *.o
	$(RM) $(TARGET)
