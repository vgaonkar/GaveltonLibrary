//
//  Video.h
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/28/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#ifndef __LibraryProject__Video__
#define __LibraryProject__Video__

#include <iostream>
#include "Media.h"
using namespace std;


class Video : public Media
{
private:
    string m_description;
    string m_distributor;
    string m_series;
    string m_label;
    Video(const Video&);
    
public:
    Video(string &call_no, 
          string &title, 
          string &subjects, 
          string &description, 
          string &distributor, 
          string &notes, 
          string &series, 
          string &label);
    ~Video();
    const bool contains_other(const string &other) const;
    ostream& display(ostream &os) const;
};

#endif /* defined(__LibraryProject__Video__) */
