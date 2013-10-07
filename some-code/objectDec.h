#ifndef objectDec_h
#define objectDec_h

#include <SFML/system.hpp>
#include <string>

/*
This file declares what all of the objects are in Project Krimzon.
Key:
xpl = explosion
kg = Krimzon Guard
fl = Freedom League Guard
ind = independant
mh = Metal Heads
wl = wastelander
ma = marauder
dm = dark maker
*/

    enum dmgType            //Type of damage (listed below)
    {darkEco, blueEco, fireDmg, physDmg, projDmg, redEco, yellowEco};
    enum ammoType           //for universal ammo pickups
    {darkAmmo, coolantAmmo, blueAmmo, redAmmo, shrapnelAmmo, explosiveAmmo, yellowAmmo};
    enum whatBuilder        //is this a builder? if so, which faction?
    {no, kg, wl, ma};

struct xpl                  //Bow down to our lord and saviour, Michael Bay!
{
    dmgType xplDmg;
    //particle particle     //also for the not sucking era
    float rad1;             //The radius of the explosion's first stage
    float rad2;             //Radius of the second stage
    sf::Time dur1;          //Stage 1's duration
    sf::Time dur2;          //Stage 2's duration
    int dmgFromCenter;      //how far away from the origin the damage stretches
    int dmgAtCenter;        //How much damage is at the center
    float dmgSpreadRatio;   //how the damage gradiates away from the center
    sf::Time dmgFade;       //How long it takes for the damage to fade
};

struct weapon               //Duh?
{
    std::string name;       //Name of the weapon
    dmgType wepDmg;
    int indexValue;         //Value on the weapon index
    whatBuilder isBuilder;  //is this weapon a "builder"? If so, to which faction?
    //model v_model;        //for when this won't suck
    //model w_model;        //see above
    int ammoCount[];        //how much ammo the weapon can contain [magsize, total]
    ammoType ammo;          //So that universal ammo pickups can be a thing
    int baseDamage;         //How much damage it does before resistances take into effect
    float overheatProgress; //how much closer the weapon gets to overheating with every shot fired (0 -> 0.5 -> 1 etc)
    float overheatDec;      //how long it takes for the wep to cooldown
    float overheatDecAtCap; //how long it takes for the weapon to cool down after hitting its cap
    float range;            //How far the round goes before evaporating
    float accuracy;         //How accurate the weapon is
    float projSpeed;        //How fast the projectile fired is
    sf::Time fireDelay;     //how long between firing
    sf::Time reloadTime;    //How long it takes to reload
    sf::Time det;           //how long the projectile takes to explode after being launched
    xpl resultBlast;        //the explosion resulting from the weapon (if any)
};

struct playClass            //The playable classes to vary gameplay a bit
{
    std::string name;       //>Hurr watz a nam guize?
    int classVal;           //what value the class is, to order them into the faction array
    //model playermodel;    //placeholder for when I can figure out how to not make that suck ass
    int weapons[];          //what weapons (pulled from the index) do they have
    char * description;     //the description of what the class is and what it's meant to do
    int vclPriority;        //0. can pilot basic vehicles, 1. can pilot a few intermediate vehicles, 2. can pilot everything
    enum modeToggle         //the "battle mode" toggle (default control is L ALT)
    {walk, running, flying};
    bool canStealth;        //if the class can use Stealth or not
    float movespeed;        //how fast the unit moves
    int health;             //base (for most classes) is 100
    int openings[];         //The amount of people who can play as that class left [availible, total]
    dmgType resist[];       //what this class has a tolerance to
    dmgType weak[];         //what this class is weak to
};

struct faction              //the "teams" so to speak
{
    std::string name;
    int facVal;             //what value the faction holds in a list (for selecting and easy calling) 1. KG, 2. FLG, 3. MH, 4. WL, 5. MA, 6. DM
    playClass classlist[];  //the classes that go into the faction, load the "classVal"struct vcl
    std::string desc;            //The description of the faction
};

struct vcl                  //vehicles
{
    std::string name;            //vehicle name
    int skullReq;           //number of Skull gems to construct
    int mtlReq;             //number of metal required to construct
    enum vclType
    {robot, flying, desert};//the type of vehicle
    int priortyReq;         //0 for anyone, 1 for engies & pilots, 2 for just pilots
    float throughGear;      //the time it takes to get from gear
    float geardowntime;     //the ratio of gear accelleration change between gears
    int numberOfGears;      //durr
    float weight;           //hurr
    float speedInGear;      //speed pickup through the gears
    weapon vclWep;          //weapon mounted on the vehicle
};

struct player               //what a player is, which is the info being sent to the server
{
   std::string playerName;  //"Username not taken"
   int clientNumber;        //their client number (first player to join is cn: 0)
   int playerFaction;       //what team they're on
   playClass playerClass;   //what class they are
   float location[];        //where they are [x, y, z]
   float lookdirection[];   //where they're facing [x, y, z]
   int wepEquipped;         //what weapon they have equpped
   int ammoRemain[];        //How much ammo is left in their current mag/total
   bool inVehicle;          //Is this player in a vehicle?
   bool isMoving;           //Is the player moving?
};


#endif // objectDec_cpp
