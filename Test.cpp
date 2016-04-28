/**
*	@author Kate Strombom
*	@date 4/22/16
*	@file Test.cpp
*/

//size begins at size 1
//addBack adds the values incorrectly, need to output the addBack vector


#include "Test.h"

  Test::Test(){}
  Test::~Test(){}

  void Test::run()
  {
    testConstructor();
    testDeconstructor();
    testIsEmpty();
    testSize();
    testAddFront();
    testAddBack();
    testAddFrontBack();
    testSearch();
    testRemoveBack();
    testRemoveFront();
  }


  //Not sure that this works
  void Test::testConstructor()
  {
    cout<<"\n-----CONSTRUCTOR-----"<<endl;
    LinkedList<int>* list = new LinkedList<int> ();

    if(list == nullptr)
    {
      cout << "Constructor: failed" << endl;
    }
    else
    {
      cout << "Constructor: passed" << endl;
    }

    delete list;
  }


  //I don't think this is the proper way to check
  void Test::testDeconstructor()
  {
    cout<<"\n-----DECONSTRUCTOR-----"<<endl;
    LinkedList<int>* list = new LinkedList<int> ();
    delete list;

    try
    {
      list->addFront(1);
    }
    catch(exception& e)
    {
      cout<<e.what()<<endl;
    }
  }


  void Test::testIsEmpty()
  {
    cout<<"\n-----IS EMPTY-----"<<endl;

    LinkedList<int>* list = new LinkedList<int> ();
    cout<<"Testing and freshly created list"<<endl;
    //testing isEmpty on an empty list that was just created
    if(list->isEmpty()==true)
    {
      cout << "   IsEmpty on empty list: passed" << endl;
    }
    else
    {
      cout << "   IsEmpty on empty list: failed" << endl;
    }

    cout<<"Testing using addFront and Remove Front"<<endl;
    //testing isEmpty on a list with one node
    list->addFront(1);
    if(list->isEmpty()==false)
    {
      cout << "   IsEmpty on list that added 1 to the front: passed" << endl;
    }
    else
    {
      cout << "   IsEmpty on list that added 1 to the front: failed" << endl;
    }

    //testing after a node has been removed and thus the list should be empty
    list->removeFront();
    if(list->isEmpty()==true)
    {
      cout << "   IsEmpty on list after addFront then removeFront: passed" << endl;
    }
    else
    {
      cout << "   IsEmpty on elist after addFront then removeFront: failed" << endl;
    }

    //delete list
    delete list;


    cout<<"Testing using addFront and Remove Front"<<endl;
    LinkedList<int>* list2 = new LinkedList<int> ();
    list2->addBack(1);
    if(list->isEmpty()==false)
    {
      cout << "   IsEmpty on list with one node from addBack: passed" << endl;
    }
    else
    {
      cout << "   IsEmpty on list with one node from addBack: failed" << endl;
    }

    //testing after a node has been removed and thus the list should be empty
    list2->removeBack();
    if(list2->isEmpty()==true)
    {
      cout << "   IsEmpty on list after addBack removeBack: passed" << endl;
    }
    else
    {
      cout << "   IsEmpty on empty list after addBack removeBack: failed" << endl;
    }

    //delete list2
    delete list2;
  }


  void Test::testSize()
  {
    cout<<"\n-----SIZE-----"<<endl;
    //create two lists
    LinkedList<int>* list = new LinkedList<int> ();
    LinkedList<int>* list2 = new LinkedList<int> ();

    //test before something was added
    if(list->size()==0)
    {
      cout << "Size for an empty list: passed" << endl;
    }
    else
    {
      cout << "Size for an empty list: failed" << endl;
      cout <<"    The size returned was " << list->size()<<endl;
    }


    //test size after something has been added to front
    list->addFront(1);
    if(list->size()==1)
    {
      cout << "Size for list with one element(from addFront): passed" << endl;
    }
    else
    {
      cout << "Size for list with one element(from addFront): failed" << endl;
      cout <<"    The size returned was " << list->size()<<endl;
    }
    list->addFront(1);
    if(list->size()==2)
    {
      cout << "Size for list with one element(from addFront addFront): passed" << endl;
    }
    else
    {
      cout << "Size for list with one element(from addFront addFront): failed" << endl;
      cout <<"    The size returned was " << list->size()<<endl;
    }

    //test size after something has been added to back
    list2->addBack(1);
    if(list2->size()==1)
    {
      cout << "Size for list with one element(from addBack): passed" << endl;
    }
    else
    {
      cout << "Size for list with one element(from addBack): failed" << endl;
      cout <<"    The size returned was " << list2->size()<<endl;
    }

    //addBack twice
    list2->addBack(2);
    if(list2->size()==2)
    {
      cout << "Size for list with one element(from addBack addBack): passed" << endl;
    }
    else
    {
      cout << "Size for list with one element(from addBack addBack): failed" << endl;
      cout <<"    The size returned was " << list2->size()<<endl;
    }

    //remove Back 3 times
    list2->removeBack();
    list2->removeBack();
    if(list2->size()==0)
    {
      cout << "Size for list with one element(from addBack addBack removeBack removeBack): passed" << endl;
    }
    else
    {
      cout << "Size for list with one element(from addBack addBack removeBack removeBack): failed" << endl;
      cout <<"    The size returned was " << list2->size()<<endl;
    }


    delete list2;
    delete list;
  }


  void Test::testSearch()
  {
    cout<<"\n-----SEARCH-----"<<endl;
      LinkedList<int>* list = new LinkedList<int> ();
      LinkedList<int>* list2 = new LinkedList<int> ();

      list->addFront(1);
      list->addFront(2);
      list->addFront(3);

      cout<<"Added front 1 then 2 then 3."<<endl;

      if(list->search(1))
      {
        cout << "   search1: passed" << endl;
      }
      else
      {
        cout << "   search1: failed" << endl;
      }

      if(list->search(2))
      {
        cout << "   search2: passed" << endl;
      }
      else
      {
        cout << "   search2: failed" << endl;
      }

      if(list->search(3))
      {
        cout << "   search3: passed" << endl;
      }
      else
      {
        cout << "   search3: failed" << endl;
      }

      if(!list->search(9))
      {
        cout << "   search9: passed" << endl;
      }
      else
      {
        cout << "   search9: failed" << endl;
      }

      list2->addBack(1);
      list2->addBack(2);
      list2->addBack(3);

      cout<<"Added back 1 then 2 then 3."<<endl;

      if(list2->search(1))
      {
        cout << "   search1: passed" << endl;
      }
      else
      {
        cout << "   search1: failed" << endl;
      }

      if(list2->search(2))
      {
        cout << "   search2: passed" << endl;
      }
      else
      {
        cout << "   search2: failed" << endl;
      }

      if(list2->search(3))
      {
        cout << "   search3: passed" << endl;
      }
      else
      {
        cout << "   search3: failed" << endl;
      }

      if(!list2->search(9))
      {
        cout << "   search9: passed" << endl;
      }
      else
      {
        cout << "   search9: failed" << endl;
      }

      delete list;
      delete list2;

  }
  void Test::testAddBack()
  {
    cout<<"\n-----ADD BACK-----"<<endl;
    LinkedList<int>* list = new LinkedList<int> ();

    //test addBack for single element list
    list->addBack(1);
    vector<int> testVector = list->toVector();
    if(testVector[0]==1)
    {
      cout<< "AddBack for a single add: passed"<<endl;
    }
    else
    {
      cout<< "AddBack for a single add: failed"<<endl;
    }

    cout<<"   What's in the vector(1): ";
    for(int i=0; i<testVector.size();i++)
    {
      cout<<testVector[i]<<" ";
    }
    cout<<endl;

    //test for a double add back list
    list->addBack(2);
    vector<int> testVector2 = list->toVector();
    if(testVector2[0]==1&&testVector2[1]==2)
    {
      cout<<"Double add back: passed"<<endl;
    }
    else
    {
      cout<<"Double add back: failed"<<endl;
    }

    cout<<"   What's in the vector(should be 1 2): ";
    for(int i=0; i<testVector2.size();i++)
    {
      cout<<testVector2[i] <<" ";
    }
    cout<<endl;

    //test for a triple add back
    list->addBack(5);
    vector<int> testVector3 = list->toVector();
    if(testVector3[0]==1&&testVector3[1]==2&&testVector3[2]==5)
    {
      cout<<"Triple add back: passed"<<endl;
    }
    else
    {
      cout<<"Triple add back: failed"<<endl;
    }

    cout<<"   What's in the vector (should be 1 2 5): ";
    for(int i=0; i<testVector3.size();i++)
    {
      cout<<testVector3[i]<<" ";
    }
    cout<<endl;

    delete list;
  }


  void Test::testAddFront()
  {
    cout<<"\n-----ADD FRONT-----"<<endl;
    LinkedList<int>* list = new LinkedList<int> ();

    //test addFront for single element list
    list->addFront(1);
    vector<int> testVector = list->toVector();
    if(testVector[0]==1)
    {
      cout<< "AddFront for a single add: passed"<<endl;
    }
    else
    {
      cout<< "AddFront for a single add: failed"<<endl;
    }

    cout<<"   What's in the vector(1): ";
    for(int i=0; i<testVector.size();i++)
    {
      cout<<testVector[i]<<" ";
    }
    cout<<endl;

    //test for a double add front list
    list->addFront(2);
    vector<int> testVector2 = list->toVector();
    if(testVector2[0]==2&&testVector2[1]==1)
    {
      cout<<"Double add front: passed"<<endl;
    }
    else
    {
      cout<<"Double add front: failed"<<endl;
    }

    cout<<"   What's in the vector(should be 2 1): ";
    for(int i=0; i<testVector2.size();i++)
    {
      cout<<testVector2[i] <<" ";
    }
    cout<<endl;

    //test for a triple add back
    list->addFront(5);
    vector<int> testVector3 = list->toVector();
    if(testVector3[0]==5&&testVector3[1]==2&&testVector3[2]==1)
    {
      cout<<"Triple add front: passed"<<endl;
    }
    else
    {
      cout<<"Triple add front: failed"<<endl;
    }

    cout<<"   What's in the vector (should be 5 2 1): ";
    for(int i=0; i<testVector3.size();i++)
    {
      cout<<testVector3[i]<<" ";
    }
    cout<<endl;

    delete list;
  }


  void Test::testAddFrontBack()
  {
    cout<<"\n-----ADD FRONT BACK-----"<<endl;
    //test addfront then and addback
    LinkedList<int>* list = new LinkedList<int> ();
    list->addFront(1);
    list->addBack(2);
    vector<int> testVector = list->toVector();
    if(testVector[0]==1 && testVector[1]==2)
    {
      cout<< "addFront addBack: passed"<<endl;
    }
    else
    {
      cout<< "addFront addBack: failed"<<endl;
    }
    cout<<"   What's in the vector (should be 1 2): ";
    for(int i=0; i<testVector.size();i++)
    {
      cout<<testVector[i]<<" ";
    }
    cout<<endl;

    delete list;

    //test and addback then and addfront
    LinkedList<int>* list2 = new LinkedList<int> ();
    list2->addBack(1);
    list2->addFront(2);
    vector<int> testVector2 = list2->toVector();
    if(testVector2[0]==2 && testVector2[1]==1)
    {
      cout<< "addBack addFront: passed"<<endl;
    }
    else
    {
      cout<< "addBack addFront: failed"<<endl;
    }
    cout<<"   What's in the vector (should be 2 1): ";
    for(int i=0; i<testVector2.size();i++)
    {
      cout<<testVector2[i]<<" ";
    }
    cout<<endl;

    delete list2;

  }


  void Test::testRemoveBack()
  {
    cout<<"\n-----REMOVE BACK-----"<<endl;

    //add front three times
    cout<<"Testing by adding front 1 then 2 then 3"<<endl;
      LinkedList<int>* list = new LinkedList<int> ();
      list->addFront(1);
      list->addFront(2);
      list->addFront(3);

      cout<<"   List before: ";
      vector<int> testVector = list->toVector();
      for(int i=0; i<testVector.size();i++)
      {
        cout<<testVector[i]<<" ";
      }
      cout<<endl;

      list->removeBack();

      cout<<"   List after: ";
      vector<int> testVector2 = list->toVector();
      for(int i=0; i<testVector2.size();i++)
      {
        cout<<testVector2[i]<<" ";
      }
      cout<<endl;

      if(testVector2[0]==3 && testVector2[1]==2)
      {
        cout<< "    removeback 1: passed"<<endl;
      }
      else
      {
        cout<< "    removeback 1: failed"<<endl;
      }

      delete list;

      //add back three times
      cout<<"Testing by adding back 1 then 2 then 3"<<endl;
        LinkedList<int>* list2 = new LinkedList<int> ();
        list2->addBack(1);
        list2->addBack(2);
        list2->addBack(3);

        cout<<"   List before: ";
        vector<int> testVector3 = list2->toVector();
        for(int i=0; i<testVector3.size();i++)
        {
          cout<<testVector3[i]<<" ";
        }
        cout<<endl;

        list->removeBack();

        cout<<"   List after: ";
        vector<int> testVector4 = list2->toVector();
        for(int i=0; i<testVector4.size();i++)
        {
          cout<<testVector4[i]<<" ";
        }
        cout<<endl;

        if(testVector4[0]==1 && testVector4[1]==2)
        {
          cout<< "    removeback 2: passed"<<endl;
        }
        else
        {
          cout<< "    removeback 2: failed"<<endl;
        }

        delete list2;
  }


  void Test::testRemoveFront()
  {
    cout<<"\n-----REMOVE FRONT-----"<<endl;

    //add front three times
    cout<<"Testing by adding front 1 then 2 then 3"<<endl;
      LinkedList<int>* list = new LinkedList<int> ();
      list->addFront(1);
      list->addFront(2);
      list->addFront(3);

      cout<<"   List before: ";
      vector<int> testVector = list->toVector();
      for(int i=0; i<testVector.size();i++)
      {
        cout<<testVector[i]<<" ";
      }
      cout<<endl;

      list->removeFront();

      cout<<"   List after: ";
      vector<int> testVector2 = list->toVector();
      for(int i=0; i<testVector2.size();i++)
      {
        cout<<testVector2[i]<<" ";
      }
      cout<<endl;

      if(testVector2[0]==2 && testVector2[1]==1)
      {
        cout<< "    removefront 1: passed"<<endl;
      }
      else
      {
        cout<< "    removefront 1: failed"<<endl;
      }

      delete list;

      //add back three times
      cout<<"Testing by adding back 1 then 2 then 3"<<endl;
        LinkedList<int>* list2 = new LinkedList<int> ();
        list2->addBack(1);
        list2->addBack(2);
        list2->addBack(3);

        cout<<"   List before: ";
        vector<int> testVector3 = list2->toVector();
        for(int i=0; i<testVector3.size();i++)
        {
          cout<<testVector3[i]<<" ";
        }
        cout<<endl;

        list->removeFront();

        cout<<"   List after: ";
        vector<int> testVector4 = list2->toVector();
        for(int i=0; i<testVector4.size();i++)
        {
          cout<<testVector4[i]<<" ";
        }
        cout<<endl;

        if(testVector4[0]==2 && testVector4[1]==3)
        {
          cout<< "    removefront 2: passed"<<endl;
        }
        else
        {
          cout<< "    removefront 2: failed"<<endl;
        }

        delete list2;
  }
