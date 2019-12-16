#ifndef MAZE_H
#define MAZE_H
#include "Location.h"

class maze
{
    public:
        maze();
        virtual ~maze();

   private:
       Location *arrrayOfLocation;
};

#endif // MAZE_H
