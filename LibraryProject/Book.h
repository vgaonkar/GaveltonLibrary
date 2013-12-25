//
//  Book.h
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/25/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#ifndef __LibraryProject__Book__
#define __LibraryProject__Book__

#include <iostream>
#include "Media.h"
using namespace std;

class Book : public Media
{
private:
    string m_author;
    string m_description;
    string m_publisher;
    string m_city;
    string m_year;
    string m_series;
    Book(const Book&);
    
public:
    Book(string &call_no, 
         string &title, 
         string &subjects, 
         string &author, 
         string &description, 
         string &publisher, 
         string &city, 
         string &year, 
         string &series, 
         string &notes);
    ~Book();
    ostream& display(ostream &os) const;
    const bool contains_other(const string &other) const;
};

#endif /* defined(__LibraryProject__Book__) */
