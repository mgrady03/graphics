OPTIONS = -framework GLUT -framework OpenGL 
DEFINES = -D GL_SILENCE_DEPRECATION

OBJDIR = ../mylib
OBJS = $(OBJDIR)/initShader.o $(OBJDIR)/library.o

lab03: lab03.c $(OBJS)
	gcc -o lab03 lab03.c $(OBJS) $(OPTIONS) $(DEFINES)

initShader.o: mylib/initShader.c mylib/initShader.h
	gcc -c initShader.c $(DEFINES)

$(OBJDIR)/%.o: %.c %.h
	$(CC) -c @< -o $@ $(CFLAGS)
