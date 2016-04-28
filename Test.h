/**
*	@author Kate Strombom
*	@date 4/22/16
*	@brief A header file for test class
*/

#ifndef TEST_H
#define TEST_H

#include "LinkedList.h"
#include <iostream>

using namespace std;

class Test
{
  public:
    Test();
    ~Test();
    void run();
  private:
    void testConstructor();
    void testDeconstructor();
    void testIsEmpty();
    void testSize();
    void testSearch();
    void testAddBack();
    void testAddFront();
    void testAddFrontBack();
    void testRemoveBack();
    void testRemoveFront();


};


#endif
