#include "LinkedList.h"
#include <iostream>
#include <string>
using namespace std;


// This function makes sure something was true; complains if not
void assertTrue(bool b, string testName) {
    if(b) {
        cout << "PASSED: " << testName << endl;
    }
    else{
        cout << "FAILED: " << testName << endl;
    }
}

class LinkedListTest {
    public:
        void test_operator_eqeq() {
            LinkedList l1;
            LinkedList l2;

            // Test 1 -- Trivial Case: Empty Lists should be equal
            assertTrue(l1 == l2, "empty list ==");

            l1.append(1);

            // Test 2 -- Lists not the same length
            assertTrue(!(l1 == l2), "l1 = [1], l2 = []"); // testing lists not same length

            l2.append(1);

            // Test 3 -- Lists are the same values and length
            assertTrue(l1 == l2, "l1 = [1], l2 = [1]");
        }

        void testAppend() {
            LinkedList l1;
            LinkedList l2(l1); // uses copy constructorgma

            l2.append(1);

            //Test 1 -- l2 should have one node

            assertTrue(!(l2 == l1), "l2 = [1]");
            l2.print();
        }

};

int main() {
    LinkedListTest test;

    test.test_operator_eqeq(); // runs our test for the == operator on linked list
    test.testAppend();
    return 0;
}