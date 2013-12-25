//
//  Book.cpp
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/25/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#include "Book.h"


Book::Book(string &call_no, 
           string &title, 
           string &subjects, 
           string &author, 
           string &description, 
           string &publisher, 
           string &city, 
           string &year, 
           string &series, 
           string &notes) : 
           
           Media(call_no, title, subjects, notes), 
           m_author(author), 
           m_description(description), 
           m_publisher(publisher), 
           m_city(city), 
           m_year(year), 
           m_series(series)
{

}


Book::~Book()
{
    
}


ostream& Book::display(ostream &os) const
{
    os  << endl << "\t\t\t     ========================= BOOK =========================\n" << endl;
    Media::display(os);
    os  << " Author               : "  << m_author      << endl
        << " Description          : "  << m_description << endl
        << " Publisher            : "  << m_publisher   << endl
        << " City                 : "  << m_city        << endl
        << " Year                 : "  << m_year        << endl
        << " Series               : "  << m_series      << endl;
    return os;
}


const bool Book::contains_other(const string &other) const
{
    size_t i_desc, i_notes, i_year;
    
    i_desc  = m_description.rfind(other);
    i_notes = this->get_notes().rfind(other);
    i_year  = m_year.rfind(other);
    
    return (i_desc != string::npos || i_notes != string::npos || i_year != string::npos);
}
