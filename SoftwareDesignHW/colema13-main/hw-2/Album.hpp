#ifndef ALBUM_HPP
#define ALBUM_HPP

#include <string>

class Album
{
    private:
    std::string name;
    std::string artist;
    std::string *songs;
    int numSongs;

    public:
    Album(std::string aName, std::string aArtist, std::string* Asongs, int AnumSongs);

    Album(std::string aName, std::string* Asongs, int AnumSongs);

    ~Album();

    std::string getName();

    std::string getArtist();

    std::string getSong(int num);

    int getNumSongs();

    void changeName(std::string nameChange);

    void changeArtist(std::string artistChange);

    void changeSong(int num, std::string songChange);



};



#endif