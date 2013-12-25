//
//  SearchEngine.cpp
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/28/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#include "SearchEngine.h"


SearchEngine::SearchEngine()
{
    //Read film and create Book objects
    ifstream ifile_book("book.txt", ios::in);
    if (!ifile_book)
    {
        cerr << "\nError: file <book.txt> does not exist\n" << endl;
        exit(1);
    }

    string callnumber;
    string title;
    string subjects;
    string author;
    string description;
    string publisher;
    string city;
    string year;
    string series;
    string notes;
    
    while (!getline(ifile_book, callnumber, '|').eof())
    {
        getline(ifile_book, title, '|');
        getline(ifile_book, subjects, '|');
        getline(ifile_book, author, '|');
        getline(ifile_book, description, '|');
        getline(ifile_book, publisher, '|');
        getline(ifile_book, city, '|');
        getline(ifile_book, year, '|');
        getline(ifile_book, series, '|');
        getline(ifile_book, notes);
        
        Book *book = new Book(callnumber,
                              title,
                              subjects,
                              author,
                              description,
                              publisher,
                              city,
                              year,
                              series,
                              notes);
        
        m_card_catalog.push_back(book);
    }
    ifile_book.close();
    
    //Read file and create Periodical objects
    ifstream ifile_periodical("periodic.txt", ios::in);
    if (!ifile_periodical)
    {
        cerr << "\nError: file <periodic.txt> does not exist\n" << endl;
        exit(1);
    }
    
    string publishing_history;
    string related_titles;
    string other_forms_of_title;
    string govt_doc_no;
  
    while (!getline(ifile_periodical, callnumber, '|').eof())
    {
        getline(ifile_periodical, title, '|');
        getline(ifile_periodical, subjects, '|');
        getline(ifile_periodical, author, '|');
        getline(ifile_periodical, description, '|');
        getline(ifile_periodical, publisher, '|');
        getline(ifile_periodical, publishing_history, '|');
        getline(ifile_periodical, series, '|');
        getline(ifile_periodical, notes, '|');
        getline(ifile_periodical, related_titles, '|');
        getline(ifile_periodical, other_forms_of_title, '|');
        getline(ifile_periodical, govt_doc_no);

        
        Periodical *periodical = new Periodical(callnumber,
                                                title,
                                                subjects,
                                                author,
                                                description,
                                                publisher,
                                                publishing_history,
                                                series,
                                                notes,
                                                related_titles,
                                                other_forms_of_title,
                                                govt_doc_no);
        
        m_card_catalog.push_back(periodical);
    }
    ifile_periodical.close();
    
    //Read file and create Video objects
    ifstream ifile_video("video.txt", ios::in);
    if (!ifile_video)
    {
        cerr << "\nError: file <video.txt> does not exist\n" << endl;
        exit(1);
    }
    
    string distributor;
    string label;
    
    while (!getline(ifile_video, callnumber, '|').eof())
    {
        getline(ifile_video, title, '|');
        getline(ifile_video, subjects, '|');
        getline(ifile_video, description, '|');
        getline(ifile_video, distributor, '|');
        getline(ifile_video, notes, '|');
        getline(ifile_video, series, '|');
        getline(ifile_video, label);
        
        Video *video = new Video(callnumber,
                                 title,
                                 subjects,
                                 description,
                                 distributor,
                                 notes,
                                 series,
                                 label);
        
        m_card_catalog.push_back(video);
    }
    ifile_video.close();
    
    //Read file and create Film objects
    ifstream ifile_film("film.txt", ios::in);
    if (!ifile_film)
    {
        cerr << "\nError: file <film.txt> does not exist\n" << endl;
        exit(1);
    }
    
    string director;
    
    while (!getline(ifile_film, callnumber, '|').eof())
    {
        getline(ifile_film, title, '|');
        getline(ifile_film, subjects, '|');
        getline(ifile_film, director, '|');
        getline(ifile_film, notes, '|');
        getline(ifile_film, year);
        
        Film *film = new Film(callnumber,
                              title,
                              subjects,
                              director,
                              notes,
                              year);
       
        m_card_catalog.push_back(film);
    }
    ifile_film.close();
}


SearchEngine::~SearchEngine()
{
    for(unsigned int i = 0; i < m_card_catalog.size(); i++)
        delete m_card_catalog[i];
}


const vector<Media *> SearchEngine::search_by_call_no(const string &search_str) const
{
    vector<Media *> results;
    
    for (unsigned int i = 0; i < m_card_catalog.size(); i++)
        if (m_card_catalog[i]->contains_call_no(search_str))
            results.push_back(m_card_catalog[i]);
    
    return results;
}


const vector<Media *> SearchEngine::search_by_title(const string &search_str) const
{
    vector<Media *> results;
    
    for (unsigned int i = 0; i < m_card_catalog.size(); i++)
        if (m_card_catalog[i]->contains_title(search_str))
            results.push_back(m_card_catalog[i]);
    
    return results;
}


const vector<Media *> SearchEngine::search_by_subjects(const string &search_str) const
{
    vector<Media *> results;
    
    for (unsigned int i = 0; i < m_card_catalog.size(); i++)
        if (m_card_catalog[i]->contains_subjects(search_str))
            results.push_back(m_card_catalog[i]);
    
    return results;
}


const vector<Media *> SearchEngine::search_by_other(const string &search_str) const
{
    vector<Media *> results;
    
    for (unsigned int i = 0; i < m_card_catalog.size(); i++)
        if (m_card_catalog[i]->contains_other(search_str))
            results.push_back(m_card_catalog[i]);
    
    return results;
}
