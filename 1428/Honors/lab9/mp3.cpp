/*
 *This is the skeleton outline of an mp3 manager application.
 *I have included some stuff for you, namely the ability to
 *actually play the mp3 from your own application. Your job
 *is to implement the struct to hold the relevant data about
 *each song. Ignore any code you don't understand (that I wrote)
 *as it is not essential for you to understand.
 *
 *This program MUST be run on Linux to compile and function.
 */
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <libgen.h>
#include <string>

void PlayMusic(std::string filename);
void KillVLC();

int main()
{
    std::string filename = "suavemente.mp3";
    std::ifstream f;
    char instruction = 'c';
    pid_t pid = 0;
    ///////////////////////////////////////////////////////////////////////////
    // Insert your struct declaration here                                   //
    ///////////////////////////////////////////////////////////////////////////

    while (instruction != 'q' && instruction != 'Q')
    {
        ///////////////////////////////////////////////////////////////////////
        // Insert menu presentation code here                                //
        ///////////////////////////////////////////////////////////////////////
        std::cout << "Enter your choice ";
        std::cin >> instruction;

        switch (instruction)
        {
            ///////////////////////////////////////////////////////////////////
            // You need to write the rest of the cases, according to the     //
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

                // Let's verify existence of the file
                f.open(filename.c_str());
                if (f.good()){
                    f.close();
                    // Kill any existing instances of VLC
                    KillVLC();
                    // Create a new process
                    pid = fork();
                    // If we are a child, call the function
                    if (pid == 0)
                        PlayMusic(filename);
                    else if (pid < 0)
                    {
                        std::cerr << "Failed to fork";
                    }
                    else {}
                }
                else
                {
                    f.close();
                    std::cerr << "Filename doesn't exist";
                }
                break;
            default:
                break;
        }

    }

    return EXIT_SUCCESS;
}


/*
 *This function seeks and destroys any and all instances of vlc.
 *It walks the /proc directory, examining each process it finds and
 *comparing the process name to the string "vlc".
 *Pre: None
 *Post: All existing instances of vlc are terminated
 *Invariant: None
 */
void KillVLC()
{
    DIR *directory_pointer;
    struct dirent *entry;
    std::string path, process_name;
    std::ifstream f;

    // Get our handle
    directory_pointer = opendir ("/proc/");
    if (directory_pointer == NULL)
    {
        std::cerr << "Failed to open proc";
        return;
    }

    // These boots are made for walking
    while ((entry = readdir (directory_pointer)) != NULL)
    {
        path = "/proc/";
        path += entry->d_name;
        path += "/comm";
        f.open(path.c_str());
        // Since the process may terminate between
        // the start of the loop and now...
        if (f.good())
        {
            f >> process_name;
            if (process_name == "vlc")
                kill(atoi(entry->d_name), SIGTERM);
        }
        f.close();
    }
    closedir (directory_pointer);
}


/*
 *This function works similar to a daemon, in that
 *it creates a new session with a corresponding new
 *process id (pid). This allows our original program
 *to resume operation immediately, instead of waiting
 *for vlc to terminate.
 *Pre: A valid (existing) filename as first argument
 *Post: vlc has been started and control returned to
 *    the parent process.
 *Invariant: None
 */
void PlayMusic(std::string filename)
{
    // Change file mask
    // We don't need no stinkin permissions
    umask(0);
    // Create new signature id
    // In other words, grab a new pid
    pid_t sid = setsid();
    if (sid < 0)
    {
        std::cerr << "Failed spawn"
        return;
    }
    // Close standard file descripters, except
    // for stdout ofc, we want to hear the music :)
    close(STDIN_FILENO);
    close(STDERR_FILENO);

    fflush(NULL);
    execl("/usr/bin/vlc", "vlc", filename.c_str(), NULL);
    return;
}
