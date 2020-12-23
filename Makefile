CC=cl.exe
CFLAGS=-EHsc -nologo -Zi -Od -std:c++latest

day_1: day_1.cpp
	$(CC) day_1.cpp $(CFLAGS)

day_2: day_2.cpp
	$(CC) day_2.cpp $(CFLAGS)

day_3: day_3.cpp
	$(CC) day_3.cpp $(CFLAGS)


all: day_1 day_2 day_3

clean:
	del *.exe *.pdb *.obj *.ilk 
