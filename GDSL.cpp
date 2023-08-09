#include<iostream>
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Structure of Singly Linear and Singly Circular

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
struct NodeS
{
    T data;
    struct NodeS *next;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Structure of Doubly Linear and Doubly Circular

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>   
struct NodeD
{
    T data;
    struct NodeD *next;
    struct NodeD *prev;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Class of Singly Linear LinkedList

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
class SinglyLL
{
    public: 
        struct NodeS<T> * first; 
        int iCount;

        SinglyLL();
        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        void Enqueue(T);
        T Dequeue();

        T SearchFirstOccurance(T);
        T SearchLastOccurance(T);
        int CalculateFrequency(T);
        T MaximumElement();
        T MinimumElement();
        T SummationOfElements();

        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);
        
};

template<class T>
SinglyLL<T>::SinglyLL()
{
    first= NULL;
    iCount= 0;
}

template<class T>
void SinglyLL<T>::Display()
{
    cout<<"The elments of Singly linear LL are:\n";

    NodeS<T> *temp= first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp= temp->next;
    }
    cout<<"|NULL|"<<"\n";
}

template<class T>
int SinglyLL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyLL<T>::InsertFirst(T no)
{
    NodeS<T> *newn= new NodeS<T>;
    newn->data= no;
    newn->next= NULL;

    if(first == NULL)
    {
        first= newn;
    }
    else
    {
        newn->next= first;
        first= newn;
    }
    iCount++;
}

template<class T>
void SinglyLL<T>::InsertLast(T no)
{
    NodeS<T> *newn= new NodeS<T>;
    newn->data= no;
    newn->next= NULL;

    if(first == NULL)
    {
        first= newn;
    }
    else
    {
        NodeS<T> *temp= first;

        while(temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next= newn;
    }
    iCount++;
}

template<class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid input"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount + 1)
    {
        InsertLast(no);
    }
    else 
    {
        NodeS<T> *newn= new NodeS<T>;
        newn->data= no;
        newn->next= NULL;

        NodeS<T> *temp= first;

        for(int iCnt= 1; iCnt < iPos-1; iCnt++)
        {
            temp= temp->next;
        }
        newn->next= temp->next;
        temp->next= newn;

        iCount++;
    }
}

template<class T>
void SinglyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp= first;

        first= first->next;
        delete temp;
    }
    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        NodeS<T> *temp= first;

        while(temp->next->next != NULL)
        {
            temp= temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    iCount= Count();

    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp= first;
        NodeS<T> *temp1= NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp= temp->next;
        }
        temp1= temp->next->next;
        delete temp->next;
        temp->next= temp1;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Class of Singly Circular LinkedList

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
class SinglyCL
{
    public: 
        struct NodeS<T> * first;  
        struct NodeS<T> *last;
        int iCount;  

        SinglyCL();
        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);   

        T SearchFirstOccurance(T);
        T SearchLastOccurance(T);
        int CalculateFrequency(T);
        T MaximumElement();
        T MinimumElement();
        T SummationOfElements();

        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);
};

template<class T>
SinglyCL<T>::SinglyCL()
{
    first= NULL;
    iCount= 0;
}

template<class T>
void SinglyCL<T>::Display()
{
    cout<<"The elements of Single Circular LL are:"<<"\n";

    struct NodeS<T> *temp= first;

    do
    {
        cout<<"|"<<temp->data<<"|->";
        temp= temp->next;
    } while (temp != last->next);
    cout<<"|NULL|"<<"\n";
}

template<class T>
int SinglyCL<T>::Count()
{
    return iCount;
}

template<class T>
void SinglyCL<T>::InsertFirst(T no)
{
    NodeS<T> *newn= new NodeS<T>;
    newn->data= no;
    newn->next= NULL;

    if((first == NULL) && (last == NULL))
    {
        first= newn;
        last= newn;
    }
    else
    {
        newn->next= first;
        first= newn;
    }
    last->next= first;
    iCount++;
}

template<class T>
void SinglyCL<T>::InsertLast(T no)
{
    NodeS<T> *newn= new NodeS<T>;
    newn->data= no;
    newn->next= NULL;

    if((first == NULL) && (last == NULL))
    {
        first= newn;
        last= newn;
    }
    else
    {
        last->next= newn;
        last= newn;
    }
    last->next= first;
    iCount++;
}

template<class T>
void SinglyCL<T>::InsertAtPos(T no, int iPos)
{
    if((iPos < 1) || (iPos > iCount+1))
    {
        cout<<"Invalis Position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeS<T> *newn= new NodeS<T>;
        newn->data= no;
        newn->next= NULL;

        NodeS<T> *temp= first;

        for(int iCnt= 1; iCnt < iPos-1; iCnt++)
        {
            temp= temp->next;
        }
        newn->next= temp->next;
        temp->next= newn;

        iCount++;
    }
}

template<class T>
void SinglyCL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first= NULL;
        last= NULL;
    }
    else
    {
        first= first->next;
        delete last->next;
    }
    last->next= first;
    iCount--;
}

template<class T>
void SinglyCL<T>::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first= NULL;
        last= NULL;
    }
    else
    {
        NodeS<T> *temp= first;

        while(temp->next != last)
        {
            temp= temp->next;
        }
        delete last;
        last= temp;
    }
    last->next= first;
    iCount--;
}

template<class T>
void SinglyCL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position"<<"\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeS<T> *temp= first;
        NodeS<T> *temp1= NULL;

        for(int iCnt = 1; iCnt < iPos -1; iCnt++)
        {
            temp= temp->next;
        }
        temp1= temp->next->next;
        delete temp->next;
        temp->next= temp1;

        iCount--;
    }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Class of Doubly Linear LinkedList

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
class DoublyLL
{
    public: 
        struct NodeD<T> * first;  
        int iCount;

        DoublyLL();
        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        T SearchFirstOccurance(T);
        T SearchLastOccurance(T);
        int CalculateFrequency(T);
        T MaximumElement();
        T MinimumElement();
        T SummationOfElements();

        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);
};

template<class T>
DoublyLL<T>::DoublyLL()
{
    first= NULL;
    iCount= 0;
}

template<class T>
void DoublyLL<T>::Display()
{
    cout<<"The elments of Doubly linear LL are:\n";

    NodeD<T> *temp= first;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|->";
        temp= temp->next;
    }
    cout<<"|NULL|\n";
}

template<class T>
int DoublyLL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyLL<T>::InsertFirst(T no)
{
    NodeD<T> *newn= new NodeD<T>;
    newn->data= no;
    newn->next= NULL;
    newn->prev= NULL;

    if(first == NULL)
    {
        first= newn;
    }
    else
    {
        newn->next= first;
        first->prev= newn;
        first= newn;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertLast(T no)
{
    NodeD<T> *newn= new NodeD<T>;
    newn->data= no;
    newn->next= NULL;
    newn->prev= NULL;

    if(first == NULL)
    {
        first= newn;
    }
    else
    {
        NodeD<T> *temp= first;

        while(temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next= newn;
        newn->prev= temp;
    }
    iCount++;
}

template<class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    NodeD<T> *newn= new NodeD<T>;
    newn->data= no;
    newn->next= NULL;
    newn->prev= NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp= first;

        for(int iCnt= 1; iCnt < iPos - 1; iCnt++)
        {
            temp= temp->next;
        }
        newn->next= temp->next;
        temp->next->prev= newn;
        temp->next= newn;
        newn->prev= temp;

        iCount++;
    }
}

template<class T>
void DoublyLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first= NULL;
    }
    else
    {
        first= first->next;
        delete first->prev;
        first->prev= NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteLast()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first= NULL;
    }
    else
    {
        NodeD<T> *temp= first;

        while(temp->next->next != NULL)
        {
            temp= temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    iCount--;
}

template<class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp= first;

        for(int iCnt= 1; iCnt < iPos - 1; iCnt++)
        {
            temp= temp->next;
        }
        temp->next= temp->next->next;
        delete temp->next->prev;
        temp->next->prev= temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Class of Doubly Circular LinkedList

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
class DoublyCL
{
    public: 
        struct NodeD<T> * first;  
        struct NodeD<T> * last;
        int iCount;   

        DoublyCL();
        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T, int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);

        T SearchFirstOccurance(T);
        T SearchLastOccurance(T);
        int CalculateFrequency(T);
        T MaximumElement();
        T MinimumElement();
        T SummationOfElements();

        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);
};

template<class T>
DoublyCL<T>::DoublyCL()
{
    first= NULL;
    last= NULL;
    iCount= 0;
}

template<class T>
void DoublyCL<T>::Display()
{
    cout<<"The elements of Doubly Circular LL are:"<<"\n";

    NodeD<T> *temp= first;

    do
    {
        cout<<"|"<<temp->data<<"|<=>";
        temp= temp->next;
    } while (temp != last->next);
    cout<<"|NULL|<=>"<<"\n";
}

template<class T>
int DoublyCL<T>::Count()
{
    return iCount;
}

template<class T>
void DoublyCL<T>::InsertFirst(T no)
{
    NodeD<T> *newn= new NodeD<T>;
    newn->data= no;
    newn->next= NULL;
    newn->prev= NULL;

    if((first == NULL) && (last == NULL))
    {
        first= newn;
        last= newn;
    }
    else
    {
        newn->next= first;
        first->prev= newn;
        first= newn;
    }
    first->prev= last;
    last->next= first;
    iCount++;
}

template<class T>
void DoublyCL<T>::InsertLast(T no)
{
    NodeD<T> *newn= new NodeD<T>;
    newn->data= no;
    newn->next= NULL;
    newn->prev= NULL;

    if((first == NULL) && (last == NULL))
    {
        first= newn;
        last= newn;
    }
    else
    {
        newn->prev= last;
        last->next= newn;
        last= newn;
    }
    first->prev= last;
    last->next= first;
    iCount++;
}

template<class T>
void DoublyCL<T>::InsertAtPos(T no, int iPos)
{
    NodeD<T> *newn= new NodeD<T>;
    newn->data= no;
    newn->next= NULL;
    newn->prev= NULL;

    if((iPos < 1) || (iPos > iCount + 1))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        NodeD<T> *temp= first;

        for(int iCnt= 1; iCnt < iPos - 1; iCnt++)
        {
            temp= temp->next;
        }
        newn->next= temp->next;
        temp->next->prev= newn;
        temp->next= newn;
        newn->prev= temp;

        iCount++;
    }
}

template<class T>
void DoublyCL<T>::DeleteFirst()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first->next == last)
    {
        delete first;
        first= NULL;
        last = NULL;
    }
    else
    {
        first= first->next;
        delete first->prev;
    }
    first->prev= last;
    last->next= first;
    iCount--;
}

template<class T>
void DoublyCL<T>::DeleteLast()
{
    if((first == NULL) && (last == NULL))
    {
        return;
    }
    else if(first->next == last)
    {
        delete first;
        first= NULL;
        last = NULL;
    }
    else
    {
        last= last->prev;
        delete last->next;
    }
    first->prev= last;
    last->next= first;

    iCount--;
} 

template<class T>
void DoublyCL<T>::DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iCount))
    {
        cout<<"Invalid position\n";
        return;
    }

    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iCount)
    {
        DeleteLast();
    }
    else
    {
        NodeD<T> *temp= first;

        for(int iCnt= 1; iCnt < iPos - 1; iCnt++)
        {
            temp= temp->next;
        }
        temp->next= temp->next->next;
        delete temp->next->prev;
        temp->next->prev= temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Functions (SearchFirstOccurance, SearchLast Ocurance, CalculateFrequency, Maximum, Minimum, SummationOfElements)

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Singly Linear

template<class T>
T SinglyLL<T>::SearchFirstOccurance(T no)
{
    struct NodeS<T> *temp= first;
    int iPos= -1;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data == no)
        {
            iPos = iCnt;
            break;
        }
        temp= temp->next;
    }
    return iPos;
}

template<class T>
T SinglyLL<T>::SearchLastOccurance(T no)
{
    struct NodeS<T> *temp = first;
    int iPos= -1;
    int Length= Count();

    for(int iCnt= 1; iCnt <= Length; iCnt++)
    {
        if(temp->data == no)
        {
            iPos = iCnt;
        }
        temp= temp->next;
    }
    return iPos;

}

template<class T>
int SinglyLL<T>::CalculateFrequency(T no)
{
    struct NodeS<T> *temp= first;
    int Counter= 0;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data == no)
        {
            Counter++;
        }
        temp= temp->next;
    }
    return Counter;
}

template<class T>
T SinglyLL<T>::MaximumElement()
{
    struct NodeS<T> *temp= first;
    int Counter= 0;
    T Max= temp->data;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data > Max)
        {
            Max= temp->data;
        }
        temp= temp->next;
    }
    return Max;
}
template<class T>
T SinglyLL<T>::MinimumElement()
{
    struct NodeS<T> *temp= first;
    int Counter= 0;
    T Min= temp->data;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data < Min)
        {
            Min= temp->data;
        }
        temp= temp->next;
    }
    return Min;
}

template<class T>
T SinglyLL<T>::SummationOfElements()
{
    struct NodeS<T> *temp= first;
    int iSum= 0;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        iSum= iSum + temp->data;
        temp= temp->next;
    }
    return iSum; 
}

// Singly Circular

template<class T>
T SinglyCL<T>::SearchFirstOccurance(T no)
{
    struct NodeS<T> *temp= first;
    int iPos= -1;
    int iCnt= 0;

    do
    {
        if(temp->data == no)
        {
            iPos= iCnt;
            break;
        }
        iCnt++;
        temp= temp->next;
    } while(temp != last->next);

    return iPos+1;
}

template<class T>
T SinglyCL<T>::SearchLastOccurance(T no)
{
    struct NodeS<T> *temp= first;
    int iPos= -1;
    int iCnt= 0;

    do
    {
        if(temp->data == no)
        {
            iPos= iCnt;
        }
        temp= temp->next;
        iCnt++;
    } while(temp != last->next);

    return iPos+1;

}

template<class T>
int SinglyCL<T>::CalculateFrequency(T no)
{
    NodeS<T> *temp= first;
    int Counter= 0;

    do
    {
        if(temp->data == no)
        {
            Counter++;
        }
        temp= temp->next;
    } while(temp != last->next);

    return Counter;
}

template<class T>
T SinglyCL<T>::MaximumElement()
{
    struct NodeS<T> *temp= first;
    int Counter= 0;
    T Max= temp->data;

    do
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }
        temp= temp->next;
    } while(temp != last->next);

    return Max;
}
template<class T>
T SinglyCL<T>::MinimumElement()
{
    struct NodeS<T> *temp= first;
    int Counter= 0;
    T Min= temp->data;

    do
    {
        if(temp->data < Min)
        {
            Min= temp->data;
        }
        temp= temp->next;
    } while(temp != last->next);

    return Min;
}

template<class T>
T SinglyCL<T>::SummationOfElements()
{
    struct NodeS<T> *temp= first;
    int iSum= 0;

    do
    {
        iSum= iSum + temp->data;
        temp= temp->next;
    } while(temp != last->next);

    return iSum; 
}

// Doubly Linear

template<class T>
T DoublyLL<T>::SearchFirstOccurance(T no)
{
    struct NodeD<T> *temp= first;
    int iPos= -1;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data == no)
        {
            iPos = iCnt;
            break;
        }
        temp= temp->next;
    }
    return iPos;
}

template<class T>
T DoublyLL<T>::SearchLastOccurance(T no)
{
    struct NodeD<T> *temp = first;
    int iPos= -1;
    int Length= Count();

    for(int iCnt= 1; iCnt <= Length; iCnt++)
    {
        if(temp->data == no)
        {
            iPos = iCnt;
        }
        temp= temp->next;
    }
    return iPos;

}

template<class T>
int DoublyLL<T>::CalculateFrequency(T no)
{
    struct NodeD<T> *temp= first;
    int Counter= 0;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data == no)
        {
            Counter++;
        }
        temp= temp->next;
    }
    return Counter;
}

template<class T>
T DoublyLL<T>::MaximumElement()
{
    struct NodeD<T> *temp= first;
    int Counter= 0;
    T Max= temp->data;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data > Max)
        {
            Max= temp->data;
        }
        temp= temp->next;
    }
    return Max;
}
template<class T>
T DoublyLL<T>::MinimumElement()
{
    struct NodeD<T> *temp= first;
    int Counter= 0;
    T Min= temp->data;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        if(temp->data < Min)
        {
            Min= temp->data;
        }
        temp= temp->next;
    }
    return Min;
}

template<class T>
T DoublyLL<T>::SummationOfElements()
{
    struct NodeD<T> *temp= first;
    int iSum= 0;

    for(int iCnt= 1; iCnt <= iCount; iCnt++)
    {
        iSum= iSum + temp->data;
        temp= temp->next;
    }
    return iSum; 
}

// Doubly Circular

template<class T>
T DoublyCL<T>::SearchFirstOccurance(T no)
{
    struct NodeD<T> *temp= first;
    int iPos= -1;
    int iCnt= 0;

    do
    {
        if(temp->data == no)
        {
            iPos= iCnt;
            break;
        }
        iCnt++;
        temp= temp->next;
    } while(temp != last->next);

    return iPos+1;
}

template<class T>
T DoublyCL<T>::SearchLastOccurance(T no)
{
    struct NodeD<T> *temp= first;
    int iPos= -1;
    int iCnt= 0;

    do
    {
        if(temp->data == no)
        {
            iPos= iCnt;
        }
        temp= temp->next;
        iCnt++;
    } while(temp != last->next);

    return iPos+1;

}

template<class T>
int DoublyCL<T>::CalculateFrequency(T no)
{
    NodeD<T> *temp= first;
    int Counter= 0;

    do
    {
        if(temp->data == no)
        {
            Counter++;
        }
        temp= temp->next;
    } while(temp != last->next);

    return Counter;
}

template<class T>
T DoublyCL<T>::MaximumElement()
{
    NodeD<T> *temp= first;
    int Counter= 0;
    T Max= temp->data;

    do
    {
        if(temp->data > Max)
        {
            Max = temp->data;
        }
        temp= temp->next;
    } while(temp != last->next);

    return Max;
}
template<class T>
T DoublyCL<T>::MinimumElement()
{
    struct NodeD<T> *temp= first;
    int Counter= 0;
    T Min= temp->data;

    do
    {
        if(temp->data < Min)
        {
            Min= temp->data;
        }
        temp= temp->next;
    } while(temp != last->next);

    return Min;
}

template<class T>
T DoublyCL<T>::SummationOfElements()
{
    struct NodeD<T> *temp= first;
    int iSum= 0;

    do
    {
        iSum= iSum + temp->data;
        temp= temp->next;
    } while(temp != last->next);

    return iSum; 
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Class of Stack

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Stack
{
    public:
        NodeS<T> *first;
        int iCount;

        Stack(T);
        void Display();
        int Count();
        void Push(T);
        T Pop();
};

template<class T>
Stack<T>::Stack(T)
{
    first= NULL;
    iCount= 0;
}

template<class T>
void Stack<T>::Display()
{
   NodeS<T> *temp= first;

   while(temp != NULL)
   {
        cout<<temp->data<<"\t";
        temp= temp->next;
   } 
   cout<<"\n";
}

template<class T>
int Stack<T>::Count()
{
    return iCount;
}

template<class T>
void Stack<T>::Push(T iNo)
{
    struct NodeS<T> *newn= new NodeS<T>;
    newn->data= iNo;
    newn->next= NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        struct NodeS<T> *temp= first;

        while(temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next= newn;
    }
    iCount++;
}

template<class T>
T Stack<T>::Pop()                                                                             
{
    int Value= 0;

    if(first == NULL)
    {
        return 0;
    }
    else if(first->next == NULL)
    {
        delete first;
        first= NULL;
    }
    else
    {
        struct NodeS<T> *temp= first;

        while(temp->next->next != NULL)
        {
            temp= temp->next;
        }
        Value= temp->next->data;
        delete temp->next;
        temp->next= NULL;
    }
    iCount--;
    return Value;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Class of Queue

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class Queue
{
    public:
        NodeS<T> *first;
        int iCount;

        Queue();
        void Display();
        int Count();
        void Enqueue(T);
        T Dequeue();
};

template<class T>
Queue<T>::Queue()
{
    first= NULL;
    iCount= 0;
}

template<class T>
void Queue<T>::Display()
{
    NodeS<T> *temp= first;

    while(temp != NULL)
    {
            cout<<temp->data<<"\t";
            temp= temp->next;
    } 
    cout<<"\n";
}

template<class T>
int Queue<T>::Count()
{
    return iCount;
}

template<class T>
void Queue<T>::Enqueue(T no)
{
    struct NodeS<T> *newn= new NodeS<T>;
    newn->data= no;
    newn->next= NULL;

    if(first == NULL)
    {
        first= newn;
    }
    else
    {
        struct NodeS<T> *temp= first;

        while(temp->next != NULL)
        {
            temp= temp->next;
        }
        temp->next= newn;
    }
    iCount++;
}

template<class T>
T Queue<T>::Dequeue()
{
    T Value= 0;

    if(first == NULL)
    {
        cout<<"Queue is empty\n";
        return 0;
    }
    else if(first->next= NULL)
    {
        delete first;
        first= NULL;
    }
    else
    {
        struct NodeS<T> *temp= first;
        Value= temp->data;
        temp= temp->next;
        delete temp;
    }
    iCount--;
    return Value;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Class ArrayX

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
class ArrayX
{
    public:
        T *Arr;
        int iSize;

        ArrayX(int X);
        void Accept();
        void Display();

        bool LinearSearch(T);
        bool BidirectionalSearch(T);
        bool BinarySearch(T);

        void BubbleSort();
        void EfficientBubbleSort();
        void SelectionSort();
        void InsertionSort();
};

// Constructor
template<class T>
ArrayX<T>::ArrayX(int X)
{
    Arr= new T[iSize];
    iSize= X;
}

// Accept the elements of array
template<class T>
void ArrayX<T>::Accept()
{
    cout<<"enter the elements:"<<"\n";
    int iCnt= 0;

    for(iCnt= 0; iCnt < iSize; iCnt++)
    {
        cin>>Arr[iCnt];
    }
}

// Display the elements of array
template<class T>
void ArrayX<T>::Display()
{
    cout<<"elements of array are:"<<"\n";
    int iCnt= 0;

    for(iCnt= 0; iCnt < iSize; iCnt++)
    {
        cout<<Arr[iCnt]<<"\t";
    }
    cout<<"\n";
}

// Linear Search function
template<class T>
bool ArrayX<T>::LinearSearch(T iNo)
{
    int iCnt= 0;
    bool bFlag= false;

    for(iCnt= 0; iCnt < iSize; iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            bFlag= true;
            break;
        }
    }
    return bFlag;
}

// Bidirectional Search function
template<class T>
bool ArrayX<T>::BidirectionalSearch(T iNo)
{
    bool bFlag= false;

    int Start= 0;
    int End= iSize - 1;

    while(Start <= End)
    {
        if((Arr[Start]== iNo) || (Arr[End] == iNo))
        {
            bFlag= true;
            break;
        }
        Start++;
        End--;
    }
    return bFlag;
}

// Binary search Function
template<class T>
bool ArrayX<T>::BinarySearch(T iNo)
{
    bool bFlag= false;
    int Start= 0;
    int End= iSize - 1;
    int Mid= 0;

    while(Start <= End)
    {
        Mid= Start + (End - Start)/2;

        if((Arr[Start] == iNo) || (Arr[Mid] == iNo) || (Arr[End] == iNo))
        {
            bFlag= true;
            break;
        }
        else if(Arr[Mid] < iNo)
        { 
            Start = Mid + 1;
        }
        else if(Arr[Mid] > iNo)
        {
            End= Mid - 1;
        }
    }
    return bFlag;
}

// Bubble Sort function
template<class T>
void ArrayX<T>::BubbleSort()
{
    int i= 0;
    int j= 0;
    T temp= 0;

    cout<<"data after sorting is:"<<"\n";

    for(i= 0; i < iSize; i++)
    {
        for(j= 0; j < iSize - i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp= Arr[j];
                Arr[j]= Arr[j+1];
                Arr[j+1]= temp;
            }
        }
    }
}

// Efficient Bubble Sort function
template<class T>
void ArrayX<T>::EfficientBubbleSort()
{
    int i= 0;
    int j= 0;
    T temp= 0;
    bool bFlag= false;

    cout<<"data after sorting is:\n";

    for(i= 0; i < iSize; i++)
    {
        bFlag= false;

        for(j= 0; j < iSize - i-1; j++)
        {
            if(Arr[j] > Arr[j+1])
            {
                temp= Arr[j];
                Arr[j]= Arr[j+1];
                Arr[j+1]= temp;
                bFlag= true;
            }
        }
        if(bFlag == false)
        {
            break;
        }
        cout<<"Sorting at pass no.:"<<i+1<<"\n";
        Display();
    }
}

// Selection Sort function
template<class T>
void ArrayX<T>::SelectionSort()
{
    T temp= 0;
    int min_index= 0;
    int i= 0;
    int j= 0;

    for(i= 0; i < iSize -1; i++)
    {
        min_index= i;

        for(j= i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            {
                min_index= j;
            }
        }
        temp= Arr[i];
        Arr[i]= Arr[min_index];
        Arr[min_index]= temp;
    }
}

// Insertion Sort function
template<class T>
void ArrayX<T>::InsertionSort()
{
    int i= 0;
    int j= 0;
    T selected= 0;

    for(i= 1; i < iSize; i++)
    {
        for(j= i-1, selected= Arr[i]; ((j>= 0) && (Arr[j] > selected)); j--)
        {
            Arr[j+1]= Arr[j];
        }
        Arr[j+1]= selected;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Binary Search Tree

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct NodeB
{
    public:
        T data;
        NodeB<T> *rchild;
        NodeB<T> *lchild;

};

template<class T>
class BST
{
    public:
        BST();
        void Insert(NodeB<T> **Head, int No);
        void Display(NodeB<T> *Head);
        void PreOrder(NodeB<T> *Head);
        void PostOrder(NodeB<T> *Head);
        void InOrder(NodeB<T> *Head);
        int CountNodes(NodeB<T> *Head);
        int CountLeafNodes(NodeB<T> *Head);
        int CountParentNodes(NodeB<T> *Head);
};

template<class T>
BST<T>::BST()
{}

template<class T>
void BST<T>::Insert(NodeB<T> **Head, int No)
{
    NodeB<T> *newn= new NodeB<T>();
    newn->data= No;
    newn->lchild= NULL;
    newn->rchild= NULL;

    NodeB<T> *temp= *Head;

    if(*Head == NULL)
    {
        *Head= newn;
    }
    else
    {
        while(1)
        {
            if(No == temp->data)
            {
                free(newn);
                break;
            }
            else if(No < temp->data)
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild= newn;
                    break;
                }
                temp= temp->lchild;
            }
            else if(No > temp->data)
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild= newn;
                    break;
                }
                temp= temp->rchild;
            }
        }
    }
}

template<class T>
void BST<T>::PreOrder(NodeB<T> *Head)
{
    if(Head != NULL)
    {
        printf("%d\t",Head->data);
        PreOrder(Head->lchild);
        PreOrder(Head->rchild);
    }
}

template<class T>
void BST<T>::PostOrder(NodeB<T> *Head)
{
    if(Head != NULL)
    {
        PreOrder(Head->lchild);
        PreOrder(Head->rchild);
        printf("%d\t",Head->data);
    }
}

template<class T>
void BST<T>::InOrder(NodeB<T> *Head)
{
    if(Head != NULL)
    {
        PreOrder(Head->lchild);
        printf("%d\t",Head->data);
        PreOrder(Head->rchild);
    }
}

template<class T>
int BST<T>::CountNodes(NodeB<T> *Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        iCnt++;
        CountNodes(Head->lchild);
        CountNodes(Head->rchild);
    }

    return iCnt;
}

template<class T>
int BST<T>::CountLeafNodes(NodeB<T> *Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild == NULL) && (Head->rchild == NULL))
        {
            iCnt++;
        }
        CountLeafNodes(Head->lchild);
        CountLeafNodes(Head->rchild);
    }

    return iCnt;
}

template<class T>
int BST<T>::CountParentNodes(NodeB<T> *Head)
{
    static int iCnt = 0;

    if(Head != NULL)
    {
        if((Head->lchild != NULL) || (Head->rchild != NULL))
        {
            iCnt++;
        }
        CountParentNodes(Head->lchild);
        CountParentNodes(Head->rchild);
    }

    return iCnt;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Entry Point Function

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    bool bRet= false;
    int iLength= 0;
    int X= 0;

    cout<<"enter the length of array:\n";
    cin>>iLength;

    SinglyLL <int>obj1;
    SinglyLL <double>dobj1;
    SinglyCL <int>obj2;
    DoublyLL <int>obj3;
    DoublyCL <int>obj4;

    ArrayX <int>obj6(iLength);

    BST <int>obj7;

    return 0;
}