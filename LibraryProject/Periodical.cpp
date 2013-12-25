//
//  Periodical.cpp
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/28/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#include "Periodical.h"


Periodical::Periodical(string &call_no, 
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
                       string &govt_doc_no) : 
                       
                       Media(call_no, title, subjects, notes), 
                       m_author(author), 
                       m_description(description), 
                       m_publisher(publisher), 
                       m_publishing_history(publishing_history), 
                       m_series(series), 
                       m_related_titles(related_titles), 
                       m_other_forms_of_title(other_forms_of_title), 
                       m_govt_doc_no(govt_doc_no)
{
    
}


Periodical::~Periodical()
{
    
}


ostream& Periodical::display(ostream &os) const
{
    os  << endl << "\t\t\t  ========================= PERIODICAL =========================\n" << endl;
    Media::display(os);
    os  << " Author               : " << m_author                 << endl
        << " Description          : " << m_description            << endl
        << " Publisher            : " << m_publisher              << endl
        << " Publishing History   : " << m_publishing_history     << endl
        << " Series               : " << m_series                 << endl
        << " Related Titles       : " << m_related_titles         << endl
        << " Other Forms of Title : " << m_other_forms_of_title   << endl
        << " Govt. Doc. Number    : " << m_govt_doc_no            << endl;
    return os;
    
}


const bool Periodical::contains_other(const string &other) const
{
    size_t i_desc, i_notes, i_series, i_related_titles;
    
    i_desc           = m_description.rfind(other);
    i_notes          = this->get_notes().rfind(other);
    i_series         = m_series.rfind(other);
    i_related_titles = m_related_titles.rfind(other);
    
    return (i_desc != string::npos || i_notes != string::npos || i_series != string::npos || i_related_titles != string::npos);
}
