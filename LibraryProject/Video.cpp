//
//  Video.cpp
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/28/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#include "Video.h"


Video::Video(string &call_no, 
             string &title, 
             string &subjects, 
             string &description, 
             string &distributor, 
             string &notes, 
             string &series, 
             string &label) : 
  
             Media(call_no, title, subjects, notes), 
             m_description(description), 
             m_distributor(distributor), 
             m_series(series), 
             m_label(label)
{
    
}


Video::~Video()
{
    
}


ostream& Video::display(ostream &os) const
{
    os  << endl << "\t\t\t    ========================= VIDEO =========================\n" << endl;
    Media::display(os);
    os  << " Description          : " << m_description << endl
        << " Distributor          : " << m_distributor << endl
        << " Series               : " << m_series      << endl
        << " Label                : " << m_label       << endl;
    
    return os;
}


const bool Video::contains_other(const string &other) const
{
    size_t i_desc, i_notes, i_dist;
    
    i_desc  = m_description.rfind(other);
    i_notes = this->get_notes().rfind(other);
    i_dist  = m_distributor.rfind(other);
    
    return (i_desc != string::npos || i_notes != string::npos || i_dist != string::npos);
}
