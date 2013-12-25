//
//  SearchEngine.h
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/28/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#ifndef __LibraryProject__SearchEngine__
#define __LibraryProject__SearchEngine__

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>
#include "Media.h"
#include "Book.h"
#include "Periodical.h"
#include "Video.h"
#include "Film.h"
using namespace std;


class SearchEngine
{
private:
    vector <Media *> m_card_catalog;
    SearchEngine(const SearchEngine&);
    
public:
    SearchEngine();
    ~SearchEngine();
    const vector <Media *> search_by_title(const string &search_str) const;
    const vector <Media *> search_by_call_no(const string &search_str) const;
    const vector <Media *> search_by_subjects(const string &search_str) const;
    const vector <Media *> search_by_other(const string &search_str) const;
};

#endif /* defined(__LibraryProject__SearchEngine__) */
