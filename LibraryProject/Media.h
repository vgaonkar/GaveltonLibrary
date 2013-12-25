//
//  Media.h
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/25/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#ifndef __LibraryProject__Media__
#define __LibraryProject__Media__

#include <iostream>
#include <string>
using namespace std;


class Media
{
private:
    string m_call_no;
    string m_title;
    string m_subjects;
    string m_notes;
    Media(const Media&); //copy constructor

public:
    Media(string &call_no,
          string &title,
          string &subject,
          string &notes);
    virtual ~Media();
    const string get_notes() const;
    const bool contains_title(const string &title) const;
    const bool contains_call_no(const string &call_no) const ;
    const bool contains_subjects(const string &subject) const;
    const virtual bool contains_other(const string &other) const = 0; //pure virtual
    virtual ostream& display(ostream &os) const;
};

ostream& operator<<(ostream& os, const Media &media);

#endif /* defined(__LibraryProject__Media__) */
