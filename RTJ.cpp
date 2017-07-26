#include "RTJtools.h"

using namespace std;

map<char ,char> TransMap{
    {'A','U'},
    {'T','A'},
    {'G','C'},
    {'C','G'}
};

void ShowFile(char* theFilePath){
    char text;
    fstream openfile(theFilePath);
    if(!openfile){
        cout<<"open failed!"<<endl;
        exit(1);
    }
    do{
        openfile.get(text);
        if(openfile.eof())
            break;
        cout<<text;
        }while(!openfile.eof());
        cout<<endl;
}

void ReadSeq(char* theFilePath ,vector<string> &SS){

    ifstream fin(theFilePath);
    string s;
    string newSeq;
    while(getline(fin,s)){
        if(s[0]!='>'){
            newSeq = newSeq + s;}
        else{
            SS.push_back(newSeq);
            newSeq = "";}
    }
    SS.push_back(newSeq);
}

void Transcript(string seq, vector<string>& result){
    string::reverse_iterator it = seq.rbegin();
    string newReverse;

    while(it!=seq.rend()){
        newReverse = newReverse + TransMap[*it];
        it ++;
    }
    result.push_back(newReverse);
}

void ReadAll(char* theFilePath, vector<string> &SS, vector<string> &Anno){
    ifstream fin(theFilePath);
    string s;
    string newSeq;
    string newAnno;
    Anno.push_back(newAnno);
    while(getline(fin,s)){
        if(s[0]!='>'){
            newSeq = newSeq + s;}
        else{
            SS.push_back(newSeq);
            Anno.push_back(s);
            newSeq = "";}
    }
    SS.push_back(newSeq); /*now , Either Anno & Seq is began with 1, 0 is empty loci*/
}

void SeqSet::AddSeq(const string newSeq){
    SeqList.push_back(newSeq);
    nSize++;
}

void Transcript2file(char* theFilePAth){
    vector<string> Transequences;
    vector<string> Annotations;
    vector<string> Result;

    ReadAll(theFilePAth,Transequences, Annotations);

    vector<string>::iterator Tit = Transequences.begin();
    Tit++;
    Result.push_back("");
    while(Tit!=Transequences.end()){
        Transcript(*Tit, Result);
        Tit++;
    }


    vector<string>::iterator Rit = Result.begin();
    while(Rit!=Result.end()){
        cout<<*Rit<<endl;
        Rit++;
    }
    /*  cout<<"Result [5] is "<<Result[5]<<endl;*/

    ofstream fout("./out.fastq");


    /* cout<<"The size of Result is "<<Result.size()<<endl;*/

    int i =1;
    int j =1;
    while(i < Annotations.size() && j < Result.size()){
        fout<<Annotations[i]<<"\n";
        fout<<Result[j]<<"\n";
        i++;j++;
                    /*
                    cout<<Annotations[i]<<"\n";
                    cout<<Result[j]<<"\n";
                    cout << j<<endl;
                    i++;
                    j++;*/
    }
    fout.close();
}

void BowtieIndex(char* theFilePath, string pthread = "4"){
    string fpstring = theFilePath;
    string command = "Bowtie -i " + fpstring + " -p " +pthread;
    //cout<<"Now the genome index is building......"<<endl;
    //system(command);
    cout<<command<<endl;
}
