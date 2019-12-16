#ifndef LOCATION_H
#define LOCATION_H


class Location
{
    public:
        Location();
        virtual ~Location();

    private:
        bool right_wall;
        bool down_wall;
};

#endif // LOCATION_H
