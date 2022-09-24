a.exe: 1_person.o 1_client.o
	g++ 1_person.o 1_client.o
1_person.o: 1_person.cpp 1_person.h
	g++ -c 1_person.cpp 
1_client.o: 1_client.cpp 1_person.h
	g++ -c 1_client.cpp 