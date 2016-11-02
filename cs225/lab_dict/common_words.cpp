/**
 * @file common_words.cpp
 * Implementation of the CommonWords class.
 *
 * @author Zach Widder
 * @date Fall 2014
 */

#include "common_words.h"

#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

using std::string;
using std::vector;
using std::ifstream;
using std::cout;
using std::endl;
using std::feof;

string remove_punct(const string& str)
{
    string ret;
    std::remove_copy_if(str.begin(), str.end(), std::back_inserter(ret),
                        std::ptr_fun<int, int>(&std::ispunct));
    return ret;
}

CommonWords::CommonWords(const vector<string>& filenames)
{
    // initialize all member variables
    init_file_word_maps(filenames);
    init_common();
}

void CommonWords::init_file_word_maps(const vector<string>& filenames)
{
    // make the length of file_word_maps the same as the length of filenames
    file_word_maps.resize(filenames.size());

    // go through all files
    for (size_t i = 0; i < filenames.size(); i++) {
        // get the corresponding vector of words that represents the current
        // file
        /* Your code goes here! */
        vector<string> words = file_to_vector(filenames[i]);
        for(auto lookup = words.begin();lookup!=words.end();lookup++){
            file_word_maps[i][*lookup]++;
        }
    }
}
    

void CommonWords::init_common()
{
    /* Your code goes here! */
    for (size_t i = 0; i < file_word_maps.size(); i++) {
    for(auto lookup = file_word_maps[i].begin();lookup!=file_word_maps[i].end();lookup++){
                common[lookup->first]++;
    }
}
}

/**
 * @param n The number of times to word has to appear.
 * @return A vector of strings. The vector contains all words that appear
 * in each file >= n times.
 */
vector<string> CommonWords::get_common_words(unsigned int n) const
{
    vector<string> out;
    unsigned int fileSize = file_word_maps.size();
   
    for(auto i = common.begin(); i != common.end(); i++)
    {
        if(i->second==fileSize) //check if the number of times the word shows up is equal 
        { 
            unsigned int count = 0;
            for(unsigned int j = 0; j<fileSize;j++)
            {
                if((file_word_maps[j].find(i->first))->second>=n)
                    count++;
            }

        if(count==fileSize)
            out.push_back(i->first); //push the word back into the vector
        }
    }

    return out;
}

/**
 * Takes a filename and transforms it to a vector of all words in that file.
 * @param filename The name of the file that will fill the vector
 */
vector<string> CommonWords::file_to_vector(const string& filename) const
{
    ifstream words(filename);
    vector<string> out;

    if (words.is_open()) {
        std::istream_iterator<string> word_iter(words);
        while (!words.eof()) {
            out.push_back(remove_punct(*word_iter));
            ++word_iter;
        }
    }
    return out;
}