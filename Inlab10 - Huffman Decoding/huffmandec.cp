// Alisha Agrawal
// aa3se
// 04/28/2021

// This program uses the skeleton code provided for the lab 10 in-lab.
// It uses C++ streams for the file input,
// and just prints out the data when read in from the file.

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <string>
#include "huffNode.h"

using namespace std;

// creates a huffman tree that will be used for decoding 
void decodeTree(huffNode* n, string p, char c);

// returns the character from the leaf node in the huffman tree
char getCharFromTree(huffNode* n, char bit);

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    huffNode* root = new huffNode();
    // read in the first section of the file: the prefix codes
    while (true) {
        string character, prefix;
        // read in the first token on the line
        file >> character;

        // did we hit the separator?
        if (character[0] == '-' && character.length() > 1) {
            break;
        }

        // check for space
        if (character == "space") {
            character = " ";
        }

        // read in the prefix code
        file >> prefix;
        // do something with the prefix code
        //cout << "character '" << character << "' has prefix code '" << prefix << "'" << endl;

	// create a huffman tree using prefixes
	decodeTree(root, prefix, character[0]);
    }

    // read in the second section of the file: the encoded message
    stringstream sstm;
    while (true) {
        string bits;
        // read in the next set of 1's and 0's
        file >> bits;
        // check for the separator
        if (bits[0] == '-') {
            break;
        }
        // add it to the stringstream
        sstm << bits;
    }

    string allbits = sstm.str();
    // at this point, all the bits are in the 'allbits' string
    //cout << "All the bits: " << allbits << endl;
    // close the file before exiting
    file.close();

    // decode

    huffNode* n = root;
    string dec = ""; // stores decoded message

    for(int i=0; i<allbits.length(); i++) {
      if(allbits.at(i) == '0') {
	// go left of tree
	n = n->left;
      }
      else if (allbits.at(i) == '1') {
	// go right of tree
	n = n->right;
      }

      // if at leaf node get character
      char c = getCharFromTree(n, allbits[i]);
      if(c != '\0') {
	// add character to decoded message 
	dec += c;
	// start over
	n = root;
      }
    }

    cout << dec << endl; 
      
}


void decodeTree(huffNode* n, string p, char c) {
  // check left
  if(p.at(0) == '0') {
    // at leaf node
    if(0 == p.length()-1) {
      huffNode* newNode = new huffNode(0, c);
      n->left = newNode;
    }
    else {
      if(n->left == NULL) {
	huffNode* newNode = new huffNode();
	n->left = newNode;
      }

      // get next number in prefix code
      p = p.substr(1, p.length());
      decodeTree(n->left, p, c);
    }
  }
  // check right
  else if(p.at(0) == '1') {
    // at leaf node
    if(0 == p.length()-1) {
      huffNode* newNode = new huffNode(0, c);
      n->right = newNode;
    }
    else {
      if (n->right == NULL) {
	huffNode* newNode = new huffNode();
	n->right = newNode;

      }

      // get next number in prefix code
      p = p.substr(1, p.length());
      decodeTree(n->right, p, c);
    }
  }
}

char getCharFromTree(huffNode* n, char bit) {
  // return character at leaf node
  if(bit == '1' || bit == '0') {
    if(n->right == NULL || n->left == NULL) {
      return n->getChar();
    }
  }
  return '\0';
}
