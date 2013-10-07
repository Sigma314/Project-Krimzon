#ifndef weaponList_h
#define weaponList_h

#include <SFML/System.hpp>
#include "objectDec.h"

struct weapon triStaff_Blaster;
struct weapon triStaff_Shock;
struct weapon triStaff_gl;

weapon TSB(weapon triStaff_Blaster)
{
triStaff_Blaster.name = "Tristaff Blaster Mode";
triStaff_Blaster.wepDmg = fireDmg;
triStaff_Blaster.indexValue = 0;
triStaff_Blaster.isBuilder = no;
//model TSB_v;
//model TSB_w;
triStaff_Blaster.ammoCount[0] = 5;
triStaff_Blaster.ammoCount[1] = 40;
triStaff_Blaster.ammo = coolantAmmo;
triStaff_Blaster.baseDamage = 20;
triStaff_Blaster.overheatProgress = 25;
triStaff_Blaster.overheatDec = 10;
triStaff_Blaster.overheatDecAtCap = 5;
triStaff_Blaster.range = 100;
triStaff_Blaster.accuracy = 95;
triStaff_Blaster.projSpeed = 2.5f;
triStaff_Blaster.fireDelay = sf::seconds(0.75f);
triStaff_Blaster.reloadTime = sf::seconds(3);
triStaff_Blaster.det = sf::seconds(10);

//the remaining statements are for the resulting explosion marking the end of the projectile's life
triStaff_Blaster.resultBlast.xplDmg = fireDmg;
triStaff_Blaster.resultBlast.rad1 = 1;
triStaff_Blaster.resultBlast.rad2 = 0.8f;
triStaff_Blaster.resultBlast.dur1 = sf::seconds(0.3f);
triStaff_Blaster.resultBlast.dur2 = sf::seconds(1.2f);
triStaff_Blaster.resultBlast.dmgFromCenter = 0;
triStaff_Blaster.resultBlast.dmgAtCenter = 0;
triStaff_Blaster.resultBlast.dmgSpreadRatio = 0;
triStaff_Blaster.resultBlast.dmgFade = sf::seconds(0.01f);

return triStaff_Blaster;
};

weapon TSS(weapon triStaff_Shock)
{
triStaff_Shock.name = "Tristaff Shocker Mode";
triStaff_Shock.wepDmg = blueEco;
triStaff_Shock.indexValue = 1;
triStaff_Shock.isBuilder = no;
//model TSS_v
//model TSS_w
triStaff_Shock.ammoCount[0] = 1;
triStaff_Shock.ammoCount[1] = 0;
triStaff_Shock.ammo = blueAmmo;
triStaff_Shock.baseDamage = 0;
triStaff_Shock.overheatProgress = 100;
triStaff_Shock.overheatDec = 10;
triStaff_Shock.overheatDecAtCap = 10;
triStaff_Shock.range = 15;
triStaff_Shock.accuracy = 100;
triStaff_Shock.projSpeed = 2.5f;
triStaff_Shock.fireDelay = sf::seconds(2.5f);
triStaff_Shock.reloadTime = sf::seconds(2.5f);
triStaff_Shock.det = sf::seconds(0);

//Particle effect analogue
triStaff_Shock.resultBlast.xplDmg = blueEco;
triStaff_Shock.resultBlast.rad1 = 0.5f;
triStaff_Shock.resultBlast.rad2 = 0.1f;
triStaff_Shock.resultBlast.dur1 = sf::seconds(2.5f);
triStaff_Shock.resultBlast.dur2 = sf::seconds(0);
triStaff_Shock.resultBlast.dmgFromCenter = 0;
triStaff_Shock.resultBlast.dmgAtCenter = 0;
triStaff_Shock.resultBlast.dmgSpreadRatio = 0;
triStaff_Shock.resultBlast.dmgFade = sf::seconds(0.01f);

return triStaff_Shock;
};

weapon TSG(weapon triStaff_gl)
{
triStaff_gl.name = "TriStaff Grenade Launcher Mode";
triStaff_gl.wepDmg = darkEco;
triStaff_gl.indexValue = 2;
triStaff_gl.isBuilder = no;
//model TSG_v
//model TSG_w
triStaff_gl.ammoCount[0] = 1;
triStaff_gl.ammoCount[1] = 5;
triStaff_gl.ammo = explosiveAmmo;
triStaff_gl.baseDamage = 20;
triStaff_gl.overheatProgress = 10;
triStaff_gl.overheatDec = 2;
triStaff_gl.overheatDecAtCap = 1;
triStaff_gl.range = 30;
triStaff_gl.accuracy = 50;
triStaff_gl.projSpeed = 0.5f;
triStaff_gl.fireDelay = sf::seconds(1);
triStaff_gl.reloadTime = sf::seconds(2.5f);
triStaff_gl.det = sf::seconds(4);

//for the grenade's explosion
triStaff_gl.resultBlast.xplDmg = darkEco;
triStaff_gl.resultBlast.rad1 = 3;
triStaff_gl.resultBlast.rad2 = 2.8f;
triStaff_gl.resultBlast.dur1 = sf::seconds(0.3f);
triStaff_gl.resultBlast.dur2 = sf::seconds(4);
triStaff_gl.resultBlast.dmgFromCenter = 3.3f;
triStaff_gl.resultBlast.dmgAtCenter = 60;
triStaff_gl.resultBlast.dmgSpreadRatio = 0.333f;
triStaff_gl.resultBlast.dmgFade = sf::seconds(0.3);

return triStaff_gl;
};

#endif // weaponList_cpp
