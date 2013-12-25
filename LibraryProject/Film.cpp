//
//  Film.cpp
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/28/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#include "Film.h"


Film::Film(string &call_no, 
           string &title, 
           string &subjects, 
           string &director, 
           string &notes, 
           string &year) : 
           
           Media(call_no, title, subjects, notes), 
           m_director(director), 
           m_year(year)
{
    
}


Film::~Film()
{
    
}


ostream& Film::display(ostream &os) const
{
    os  << endl << "\t\t\t     ========================= FILM =========================\n" << endl;
    Media::display(os);
    os  << " Director             : " << m_director << endl
        << " Year                 : " << m_year     << endl;
    return os;
}


const bool Film::contains_other(const string &other) const
{
    size_t i_dir, i_notes, i_year;
    
    i_dir   = m_director.rfind(other);
    i_notes = this->get_notes().rfind(other);
    i_year  = m_year.rfind(other);
    
    return (i_dir != string::npos || i_notes != string::npos || i_year != string::npos);
}
