#include <SFML/system.hpp>

struct playClass            //The playable classes to vary gameplay a bit
{
    char * name[];          //>Hurr watz a nam guize?
    int classVal;           //what value the class is, to order them into the faction array
    //model playermodel;    //placeholder for when I can figure out how to not make that suck ass
    int weapons[];          //what weapons (pulled from the index) do they have
    char * description;     //the description of what the class is and what it's meant to do
    int vclPriority;        //0. can pilot basic vehicles, 1. can pilot a few intermediate vehicles, 2. can pilot everything
};

struct faction              //the "teams" so to speak
{
    char * name;
    int facVal;             //what value the faction holds in a list (for selecting and easy calling) 1. KG, 2. FLG, 3. MH, 4. WL, 5. MA, 6. DM
    playClass classlist[];  //the classes that go into the faction, load the "classVal" int into those lists
};

struct xpl                  //Bow down to our lord and saviour, Michael Bay!
{
    int dmgType;            //Type of damage (dark eco = 0, fire = 1, red eco = 2, shrapnel = 3, etc)
    //particle particle     //also for the not sucking era
    float rad1;             //The radius of the explosion's first stage
    float rad2;             //Radius of the second stage
    sf::Time dur1;          //Stage 1's duration
    sf::Time dur2;          //Stage 2's duration
    int dmgFromCenter;      //how far away from the origin the damage stretches
    sf::Time dmgFade;       //How long it takes for the damage to fade
};

struct weapon               //Duh?
{
    char * name;            //Name of the weapon
    int indexValue;         //Value on the weapon index
    //model v_model;        //for when this won't suck
    //model w_model;        //see above
    int damage;             //How much damage it does
    sf::Time fireDelay;     //how long between firing and working
    sf::Time det;           //how long the projectile takes to explode after being launched
    xpl resultBlast;        //the explosion resulting from the weapon (if any)
};

struct player               //what a player is
{
   char * playerName;       //"Username not taken"
   int playerFaction        //what team they're on
   playClass playerClass;   //what class they are
   float location[];        //where they are [x, y, z]
   float lookdirection[];   //where they're facing [x, y, z]
   int wepEquipped;         //what weapon they have equpped
};
