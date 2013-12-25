//
//  main.cpp
//  LibraryProject
//
//  Created by Vijay R. Gaonkar on 9/24/13.
//  Copyright (c) 2013 Vijay R. Gaonkar. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

#include "SearchEngine.h"

int main()
{
    int choice = 0;
    string search_string;
    SearchEngine search_engine;
    vector<Media*> results;
    
    while (choice != 5)
    {
        system("clear");
        cout << "\n\t\t\t######################### GAVELTON LIBRARY #########################\n" << endl
        << " Welcome! Looking for something? I can help!" << endl
        << "\n Enter a word or a phrase to get started: ";
        
        getline(cin, search_string);
        
        cout << "\n How do you wanna search?" << endl
        << " 1. Search by call number" << endl
        << " 2. Search by title" << endl
        << " 3. Search by subjects" << endl
        << " 4. Search by other" << endl
        << " 5. Get me out of here!" << endl
        << " Your Choice: ";
        
        cin >> choice;
        cin.ignore();
        
        switch (choice)
        {
            case 1:
            {
                results.clear();
                results = search_engine.search_by_call_no(search_string);
                if (results.size() > 0)
                {
                    cout << "\n\t\t\t************************* Search Results *************************\n" << endl;
                    for (unsigned int i = 0; i < results.size(); i++)
                    {
                        if (i!=0 && i%2==0)
                        {
                            cout << "\n\t\t\t\t\t\t <Press ENTER to view more results>\n" << endl;
                            system("read");
                        }
                        
                        cout << *results[i];
                    }
                }
                
                else
                    cout << "\n Sorry no results found with <" << search_string << "> in call number" << endl;
                
                break;
            }
                
            case 2:
            {
                results.clear();
                results = search_engine.search_by_title(search_string);
                if (results.size() > 0)
                {
                    cout << "\n\t\t\t************************* Search Results *************************\n" << endl;
                    for (unsigned int i = 0; i < results.size(); i++)
                    {
                        if (i!=0 && i%2==0)
                        {
                            cout << "\n\t\t\t\t\t\t <Press ENTER to view more results>\n" << endl;
                            system("read");
                        }
                        
                        cout << *results[i];
                    }
                }
                
                else
                    cout << "\n Sorry no results found with <" << search_string << "> in title." << endl;
                
                break;
            }
                
            case 3:
            {
                results.clear();
                results = search_engine.search_by_subjects(search_string);
                if (results.size()  > 0)
                {
                    cout << "\n\t\t\t************************* Search Results *************************\n" << endl;
                    for (unsigned int i = 0; i < results.size(); i++)
                    {
                        if (i!=0 && i%2==0)
                        {
                            cout << "\n\t\t\t\t\t\t <Press ENTER to view more results>\n" << endl;
                            system("read");
                        }
                        
                        cout << *results[i];
                    }
                }
                
                else
                    cout << "\n Sorry no results found with <" << search_string << "> in subject." << endl;
                
                break;
            }
                
            case 4:
            {
                results.clear();
                results = search_engine.search_by_other(search_string);
                if (results.size() > 0)
                {
                    cout << "\n\t\t\t************************* Search Results *************************\n" << endl;
                    for (unsigned int i = 0; i < results.size(); i++)
                    {
                        if (i!=0 && i%2==0)
                        {
                            cout << "\n\t\t\t\t\t\t <Press ENTER to view more results>\n" << endl;
                            system("read");
                        }
                        
                        cout << *results[i];
                    }
                }
                
                else
                    cout << "\n Sorry no results found with <" << search_string << "> in description, notes or year." << endl;
                
                break;
            }
                
            case 5:
                return 0;
                
            default:
            {
                cout << "\n How do you wanna search?" << endl
                << " 1. Search by call number" << endl
                << " 2. Search by title" << endl
                << " 3. Search by subject" << endl
                << " 4. Search by other" << endl
                << " 5. Get me out of here!" << endl
                << " Your Choice: ";
                
                cin >> choice;
                cin.ignore();
            }
        }
        
        cout << "\n Found what you were looking for?" << endl
        << " 1. Yes, done searching." << endl
        << " 2. No, start a new search." << endl
        << " Your Choice: ";
        
        int end_choice;
        cin >> end_choice;
        cin.ignore();
        
        switch (end_choice)
        {
            case 1:
                return 0;
                
            case 2:
            {
                system("clear");
                break;
            }
                
            default:
            {
                cout << "\n Found what you were looking for?" << endl
                << " 1. Yes, done searching." << endl
                << " 2. No, start a new search." << endl
                << " Your Choice: ";
                
                cin >> end_choice;
                cin.ignore();
            }
        }
        
    }
    
    return 0;
}
