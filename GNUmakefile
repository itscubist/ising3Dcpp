CC = g++
LIBS = 

INC = -I/media/cubist/files/all/cpp/tools/eigen/eigen-eigen-b3f3d4950030/Eigen \
			-I/media/cubist/files/all/cpp/tools/myheaders \

CFLAGS = $(INC)

DEPS = $(find /media/cubist/files/all/cpp/tools/myheaders -name '*.h')
COBJS = $(find /media/cubist/files/all/cpp/tools/myheaders -name '*.o')

%.o : %.cc %.cpp $(DEPS) ising3D.o
	$(CC) -c `root-config --libs --cflags` -o $@ $< $(CFLAGS)

ising3D: $(COBJS) ising3D.cc
	$(CC) $^ -o $@ `root-config --libs --cflags` $(CFLAGS)

ising3Dv2: $(COBJS) ising3Dv2.cc
	$(CC) $^ -o $@ `root-config --libs --cflags` $(CFLAGS)

ising3Dspeedy: $(COBJS) ising3Dspeedy.cc
	$(CC) $^ -o $@ `root-config --libs --cflags` $(CFLAGS)

clean:
	rm *~ *.o
