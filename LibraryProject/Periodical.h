//
//  Periodical.h
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/28/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#ifndef __LibraryProject__Periodical__
#define __LibraryProject__Periodical__

#include <iostream>
#include "Media.h"
using namespace std;


class Periodical : public Media
{
private:
    string m_author;
    string m_description;
    string m_publisher;
    string m_publishing_history;
    string m_series;
    string m_related_titles;
    string m_other_forms_of_title;
    string m_govt_doc_no;
    Periodical(const Periodical&);
    
public:
    Periodical(string &call_no, 
               string &title, 
               string &subjects, 
               string &author, 
               string &description, 
               string &publisher, 
               string &publishing_history, 
               string &series, 
               string &notes, 
               string &related_titles, 
               string &other_forms_of_title, 
               string &govt_doc_no);
    ~Periodical();
    ostream& display(ostream &os) const;
    const bool contains_other(const string &other) const;
};

#endif /* defined(__LibraryProject__Periodical__) */
