//
//  Film.h
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/28/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#ifndef __LibraryProject__Film__
#define __LibraryProject__Film__

#include <iostream>
#include "Media.h"
using namespace std;


class Film : public Media
{
private:
    string m_director;
    string m_year;
    Film(const Film&);
    
public:
    Film(string &call_no, 
         string &title, 
         string &subjects, 
         string &director, 
         string &notes, 
         string &year);
    ~Film();
    const bool contains_other(const string &other) const;
    ostream& display(ostream &os) const;
};

#endif /* defined(__LibraryProject__Film__) */
