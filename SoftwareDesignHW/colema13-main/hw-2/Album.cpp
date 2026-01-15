#include "Album.hpp"
#include <iostream>

//Single Artist
Album::Album(std::string aName, std::string aArtist, std::string* Asongs, int AnumSongs) : name(aName), artist(aArtist), songs(Asongs), numSongs(AnumSongs)
{
    songs = new std::string[numSongs];

    for (int i = 0; i < numSongs; ++i) {
        songs[i] = Asongs[i];
    }

//Multiple Artist
}
Album::Album(std::string aName, std::string* Asongs, int AnumSongs) : Album(aName, "Various Artists", Asongs, AnumSongs){};

Album::~Album()
{
    delete[] songs;
}

std::string Album::getName()
{
    return name;
}

std::string Album::getArtist()
{
    return artist;
}

std::string Album::getSong(int num)
{
    --num;
    if(num >= 0 && num < numSongs)
    {
        return songs[num];
    }
    else
    {
        return "Invalid";
    }
}

int Album::getNumSongs()
{
    return numSongs;
}

void Album::changeName(std::string nameChange)
{
    name = nameChange;
    std::cout << "Album name has been changed" << std::endl;
}

void Album::changeArtist(std::string artistChange)
{
    artist = artistChange;
    std::cout << "Artist name has been changed" << std::endl;
}

void Album::changeSong(int num, std::string songChange)
{
    --num;
    if(num >= 0 && num < numSongs)
    {
        songs[num] = songChange;
        std::cout << "Song name has been changed" << std::endl;
    }
    else
    {
        std::cout << "Invalid" << std::endl;
    }

}