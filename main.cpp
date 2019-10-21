/***********************************************
Author: <insert your name>
Date: <insert today’s date>
Purpose: This program is to development a dynamic array using static array. When a new entry com
            in program simply create new array of which length is 1 greater than original one and copy
            all elements from original one and add new one.
            Deleting is just inverse processing of adding element.
Sources of Help: https://www.tutorialspoint.com/cplusplus/cpp_copy_constructor.htm
Time Spent: 1 hour
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining 
good order in the classroom, providing an enriching learning 
experience for students, and as training as a practicing computing 
professional upon graduation. This practice is manifested in the 
University’s Academic Integrity policy. Students are expected to 
strictly avoid academic dishonesty and adhere to the Academic 
Integrity policy as outlined in the course catalog. Violations will 
be dealt with as outlined therein.
All programming assignments in this class are to be done by the 
student alone. No outside help is permitted except the instructor and 
approved tutors.
I certify that the work submitted with this assignment is mine and was 
generated in a manner consistent with this document, the course 
academic policy on the course website on Blackboard, and the UMass 
Lowell academic code.
Date:
Name:
*/
#include <iostream>
#include <string>
using namespace std;
class DynamicStringArray{
private:
    string* dynamicArray;
    int size;
public:
    DynamicStringArray();
    DynamicStringArray( const DynamicStringArray &obj);
    ~DynamicStringArray();
    int getSize();
    void addEntry(string );
    bool deleteEntry(string);
    string getEntry(int );
    
};

//default constructor
DynamicStringArray::DynamicStringArray(){
    this->dynamicArray = NULL;
    this->size = 0;
}

//compy constructor
//parameter obj : another object to be copied
DynamicStringArray::DynamicStringArray(const DynamicStringArray &obj){
    this->size = obj.size;
    this->dynamicArray =  new string[this->size];
    for(int i = 0; i < this->getSize(); i++)
        this->dynamicArray[i] = obj.dynamicArray[i];
}

//deconstructor
DynamicStringArray::~DynamicStringArray(){
    if(this->dynamicArray != NULL) delete this->dynamicArray;
}

// getter for private variable size
int DynamicStringArray::getSize() { return this->size;}

//function to add a new entry 
//params : newEntry - a string variable to be added into a new array
void DynamicStringArray::addEntry(string newEntry){
    string * newArray = new string[this->getSize() + 1];
    for (int i = 0; i < this->getSize(); i++)
        newArray[i] = this->dynamicArray[i];
    newArray[this->getSize()] = newEntry;
    delete this->dynamicArray;
    this->dynamicArray = newArray;
    this->size ++;
}

//function to delete a entry
//params: entry - a string variable to be deleted from a entry
bool DynamicStringArray::deleteEntry(string entry){
    int index = -1;
    for(int i = 0; i < this->getSize(); i++)
        if(this->dynamicArray[i].compare(entry) == 0){
            index = i;
            break;
        }
    if (index == -1) return false;
    string * newArray = new string[this->getSize() - 1];
    int index2 = 0;
    for(int i = 0; i < this->getSize(); i++){
        if(i == index) continue;
        newArray[index2] = this->dynamicArray[i];
        index2 ++;
    }
    delete this->dynamicArray;
    this->dynamicArray = newArray;
    this->size --;
    return true;
}

//function to get a string on specific index
//params : index - int parameter indicate index
string DynamicStringArray::getEntry(int index){
    if(index < 0 || index >= this->getSize()) return NULL;
    return this->dynamicArray[index];
}



int main(){
    DynamicStringArray array;
    array.addEntry("Hello ");
    array.addEntry("World!");
    DynamicStringArray array2 = array;
    cout << array.getSize() << endl;
    array2.deleteEntry("World!");
    cout << array2.getSize() << endl;
}