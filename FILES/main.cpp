#include <iostream>
#include "files.hpp"


int main(int argc, char const *argv[])
{
    
    file<int> fi;

    fi.enfiler(15);
    fi.enfiler(16);
    fi.enfiler(17);
    fi.enfiler(18);
    fi.enfiler(19);

    fi.afficherFile();

    std::cout << "Supression de 15 16 17" << std::endl;

    fi.defiler();
    fi.defiler();

    fi.afficherFile();




    return 0;
}

