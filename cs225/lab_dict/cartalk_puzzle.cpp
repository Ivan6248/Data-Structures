/**
 * @file cartalk_puzzle.cpp
 * Holds the function which solves a CarTalk puzzler.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include <fstream>

#include "cartalk_puzzle.h"

using namespace std;

/**
 * Solves the CarTalk puzzler described here:
 * http://www.cartalk.com/content/wordplay-anyone.
 * @return A vector of "StringTriples" (a typedef'd std::tuple, see top of
 * cartalk_puzzle.h). Returns an empty vector if no solutions are found.
 * @param d The PronounceDict to be used to solve the puzzle.
 * @param word_list_fname The filename of the word list to be used.
 */
vector<StringTriple> cartalk_puzzle(PronounceDict d,
                                    const string& word_list_fname)
{
    /* Your code goes here! */
    vector<StringTriple> output;
    string str;
    ifstream words(word_list_fname);

    if(words.is_open())
    {
    	while(getline(words, str))
    	{
    		if(str.length()>1)
    		{
    			string newWord1 = str.substr(1);
    			string newWord2 = str[0] + str.substr(2);
    			bool homo = d.homophones(newWord1,newWord2);
    			if(homo==1)
    			{
    				StringTriple temp = make_tuple(str, newWord1, newWord2);
    				output.push_back(temp);
    			}
    		}
    		
    	}
    	return output;
    }

    return vector<StringTriple>();
}
