# Author: Nohemi Morales
# Date: 07/26/21
CXX = g++ -std=c++11 -g

dependencies = TestLinkedList.cpp LinkedList.cpp

TestLinkedList: ${dependencies}
	${CXX} $^ -o $@
clean:
	rm -f *.o Complex