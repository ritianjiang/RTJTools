/*A tools to analyze sequence*/

#include "RTJtools.h"

using namespace std;

int main (int argc, char **argv)
{
    string numP = "4";
    int oc;
    while((oc = getopt(argc, argv, "ngf:s:t:p:i:")) != -1)
    {
        switch(oc)
        {
            case 'n':
                printf("My name is Lyong.\n");
                break;

            case 'g':
                printf("Her name is Xxiong.\n");
                break;

            case 'f':
                printf("Our love is %s\n", optarg);
                ShowFile(optarg);
                break;

            case 's':{
                printf("the file is %s", optarg);
                cout<<endl;
                vector<string> Sequences;
                cout<<Sequences.empty()<<endl;
                ReadSeq(optarg,Sequences);
                vector<string>::iterator it = Sequences.begin();//the vector is began with a empty string,so the 1st is in Sequences[1]
                while(it!=Sequences.end()){
                    cout<<*it<<endl;
                    it++;
                }

                cout<<Sequences.size()<<endl;
                SeqSet firstSet(Sequences);
                cout<<firstSet.getLength()<<endl;
                cout<<Sequences.empty()<<endl;
                break;
                }

            case 't':               //Transcript to RNA; for exap: (5)ATGC(3) ===> (5)GCAU(3) "
                printf("the file to be transcripted is %s" , optarg);
                cout<<endl;

                Transcript2file(optarg);

                break;
            case 'p':
                numP = *optarg;
                break;
            case 'i':
                BowtieIndex(optarg, numP);



        }
    }
   return 0;
}



/*
int main(int argc, char **argv){
    system("bowtie");
    return 0;

}*/

