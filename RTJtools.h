/*A tools to analyze sequence*/

#ifndef RTJTOOLS_H_INCLUDED
#define RTJTOOLS_H_INCLUDED

#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>
#include <iterator>
#include <vector>
#include <map>
#include <pthread.h>
#include <stdlib.h>

using namespace std;


void ShowFile(char* theFilePath);
void ReadSeq(char* theFilePath, vector<string>& SS);
void Transcript(string seq, vector<string>& result);
void ReadAll(char* theFilePath, vector<string>& SS, vector<string>& Anno);
void Transcript2file(char* theFilePath);
void BowtieIndex(char* theFilePath, string pthread = "4");

class SeqSet{
public:
    int nSize;
    vector<string> SeqList;
public:
    SeqSet(vector<string>& SS){
        this->nSize = SS.size();
        this->SeqList = SS;
    }
    bool operator<(SeqSet obj){
        return nSize < obj.nSize;
    }

    void AddSeq(string newSeq);
    int getLength(){return nSize-1;}

};
#endif // RTJTOOLS_H_INCLUDED
