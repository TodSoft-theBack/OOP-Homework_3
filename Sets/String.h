#pragma once
#include <iostream>
typedef unsigned char byte;

class String
{
    static const byte SMALL_STRING_MAX_SIZE = sizeof(size_t) + sizeof(char*) + sizeof(size_t); 

    private:
        char* _data = nullptr;
	    size_t _length = 0;
		size_t _capacity = 0;

	    void CopyMemberData(const String& copy);
	    void FreeMemberData();
		void MoveMemberData(String&& temporary);
		bool IsSmallString() const;
		byte LengthByte() const;
		byte LastByteOf(size_t variable) const;
		byte& LastByteOf(size_t& variable);
		byte& LengthByte();

		// Only for small strings
		char CharAt(unsigned index) const; 
		char& CharAt(unsigned index);
		
    public:

	    String();
		String(size_t capacity);
	    String(const char* string);
	    String(const String& string);
		String(String&& temporary);

	    size_t Length() const;
		
		String& operator=(const String& rhs);
		String& operator=(String&& rhs);
		String& operator+=(const String& rhs);
	    char operator[](unsigned index) const;
		char& operator[](unsigned index);
		const char* C_Str() const;
		
		friend String operator+(const String& lhs, const String& rhs);
        friend std::ostream& operator<<(std::ostream& output, const String& string);
		friend std::istream& operator>>(std::istream& input, String& string);
		
	    ~String();
};