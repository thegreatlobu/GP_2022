a.out: 2_person.o 2_client.o
	g++ 2_person.o 2_client.o
2_person.o: 2_person.cpp 2_person.h
	g++ -c 2_person.cpp 
2_client.o: 2_client.cpp 2_person.h
	g++ -c 2_client.cpp 