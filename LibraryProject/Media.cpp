//
//  Media.cpp
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/25/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#include "Media.h"


ostream& operator<<(ostream &os, const Media &media)
{
    return media.display(os);
}


Media::Media(string &call_no,
             string &title,
             string &subjects,
             string &notes) :

             m_call_no(call_no),
             m_title(title),
             m_subjects(subjects),
             m_notes(notes)
{
    
}


Media::~Media()
{
    
}


const string Media::get_notes() const
{
    return m_notes;
}


const bool Media::contains_title(const string &title) const
{
    size_t index;
    index = m_title.rfind(title);
    return (index != string::npos);
}


const bool Media::contains_call_no(const string &call_no) const
{
    size_t index;
    index = m_call_no.rfind(call_no);
    return (index != string::npos);
}


const bool Media::contains_subjects(const string &subjects) const
{
    size_t index;
    index = m_subjects.rfind(subjects);
    return (index != string::npos);
}


ostream &Media::display(ostream &os) const
{
  os << " Title                : "    << m_title   << endl
     << " Call Number          : " << m_call_no << endl
     << " Subject              : "     << m_subjects << endl
     << " Notes                : "       << m_notes   << endl;
    
    return os;
}
