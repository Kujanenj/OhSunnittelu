#include <iostream>
#include <requester.h>


//Ei saatana pojat, ei tää maini voi olla tämmönen ;:D
int main()
{
    Requester requester;
    requester.createMap();
    requester.createJSON();
    requester.startPScript();
    requester.parseData();
}

