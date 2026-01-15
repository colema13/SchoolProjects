#include <iostream>
#include "Album.hpp"

int main()
{
    
    int numSongs = 3;
    std::string songs[] = {"Song 1", "Song 2", "Song 3"};
    Album SomeAlbum("Songs", "Me", songs, numSongs);
    std::cout << SomeAlbum.getName() << std::endl;
    std::cout << SomeAlbum.getArtist() << std::endl;
    std::cout << SomeAlbum.getNumSongs() << std::endl;
    std::cout << SomeAlbum.getSong(1) << std::endl;
    std::cout << SomeAlbum.getSong(0) << std::endl;
    std::cout << "---------------------------------------------------------------" << std::endl;

    SomeAlbum.changeArtist("Connor");
    SomeAlbum.changeName("Connor's Album");
    SomeAlbum.changeSong(1, "Connor's Song");

    std::cout << SomeAlbum.getName() << std::endl;
    std::cout << SomeAlbum.getArtist() << std::endl;
    std::cout << SomeAlbum.getNumSongs() << std::endl;
    std::cout << SomeAlbum.getSong(1) << std::endl;
    std::cout << SomeAlbum.getSong(0) << std::endl;
    std::cout << SomeAlbum.getSong(3) << std::endl;



    Album SomeOtherAlbum("Rock", songs, numSongs);
    std::cout << SomeOtherAlbum.getName() << std::endl;
    std::cout << SomeOtherAlbum.getArtist() << std::endl;
    std::cout << SomeOtherAlbum.getNumSongs() << std::endl;
    std::cout << SomeOtherAlbum.getSong(1) << std::endl;

    return 0;
}