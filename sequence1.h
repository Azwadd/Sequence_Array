// FILE: sequence1.h
// CLASS PROVIDED: sequence (part of the namespace main_savitch_3)
// There is no implementation file provided for this class since it is
// an exercise from Section 3.2 of "Data Structures and Other Objects Using C++"
//
// TYPEDEFS and MEMBER CONSTANTS for the sequence class:
//   typedef ____ value_type
//     sequence::value_type is the data type of the items in the sequence. It
//     may be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, an assignment operator, and a copy constructor.
//
//   typedef ____ size_type
//     sequence::size_type is the data type of any variable that keeps track of
//     how many items are in a sequence.
//
//   static const size_type CAPACITY = _____
//     sequence::CAPACITY is the maximum number of items that a sequence can hold.
//

// MODIFICATION MEMBER FUNCTIONS for the sequence class:
//
// CONSTANT MEMBER FUNCTIONS for the sequence class:
//   size_type size( ) const
//     Postcondition: The return value is the number of items in the sequence.
//
//   bool is_item( ) const
//     Postcondition: A true return value indicates that there is a valid
//     "current" item that may be retrieved by activating the current
//     member function (listed below). A false return value indicates that
//     there is no valid current item.
//
//   value_type current( ) const
//     Precondition: is_item( ) returns true.
//     Postcondition: The item returned is the current item in the sequence.
//
// VALUE SEMANTICS for the sequence class:
//    Assignments and the copy constructor may be used with sequence objects.

#ifndef MAIN_SAVITCH_SEQUENCE_H
#define MAIN_SAVITCH_SEQUENCE_H
#include <cstdlib>  // Provides size_t
#include <cassert>

namespace weimin_csc212
{

    class sequence1
    {
    public:
        // TYPEDEFS and MEMBER CONSTANTS
        typedef double value_type;
        typedef size_t size_type; //typedef std::size_t size_type;
        static const size_type CAPACITY = 30; // enum {CAPACITY = 30}; //
        // CONSTRUCTOR
        sequence1() { u = c = 0; }
        // MODIFICATION MEMBER FUNCTIONS
        void start() { if (size() != 0) { c = 0; } }
        void advance() { ++c; }
        void insert(const value_type& entry);
        void attach(const value_type& entry);
        void remove_current();
        // CONSTANT MEMBER FUNCTIONS
        size_type size() const { return u; }
        bool is_item() const 
        {
            if (u == 0) {
                return false;
            }
            else if (c >= 0 && c <= u - 1) {
                return true;
            }
            else if (c >= u) {
                return false;
            }
            return false;
        }
        value_type current() const { assert(is_item()); return data[c]; }
    private:
        //--Fill in your private member variables here.
        //    --Read Section 3.2 for guidelines.
        value_type data[CAPACITY];
        size_type u;
        size_type c;
    };
}

#endif

