/*
 *This is the skeleton outline of an mp3 manager application.
 *I have included some stuff for you. Your job
 *is to implement the struct to hold the relevant data about
 *each song.
 *
 */
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

using namespace std;

int main()
{
    string filename = "";
    char instruction = 'c';
    ifstream f;

    ///////////////////////////////////////////////////////////////////////////
    // Insert your struct declaration here                                   //
    ///////////////////////////////////////////////////////////////////////////

    while (instruction != 'q' && instruction != 'Q')
    {
        ///////////////////////////////////////////////////////////////////////
        // Insert menu presentation code here                                //
        ///////////////////////////////////////////////////////////////////////
        cout << "Enter your choice ";
        cin >> instruction;

        switch (instruction)
        {
            ///////////////////////////////////////////////////////////////////
            // You need to write the cases, according to the                 //
            // instructions in the handout                                   //
            ///////////////////////////////////////////////////////////////////
            case 'P':
            case 'p':
                ///////////////////////////////////////////////////////////////
                // Insert selection code here                                //
                // This code needs to eventually populate                    //
                // the variable 'filename' with the actual                   //
                // filename of the mp3 to play.                              //
                ///////////////////////////////////////////////////////////////
                f.open( filename.c_str() );
                if ( f.good() )
                    cout << "Filename valid.";
                else
                    cerr << "Filename doesn't exist.";
                cout << "If you were running on Linux, you'd be hearing music.";
                break;
            default:
                break;
        }

    }

    return EXIT_SUCCESS;
}
