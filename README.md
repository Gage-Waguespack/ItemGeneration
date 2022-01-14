# PartRandomization

| Gage Waguespack|
| :--- |
| s208063 |
| Game Programming|
| Part Randomization|

Developed with Unreal Engine 4

# Description
This project is a part generation system for making guns in Unreal. You are able to add your own custom meshes and
implement this into any loot game however you want!

# How to setup and use
First you want to install the files to the proper path. The .cpp and .h files that you get should each go into your
Source folder in your project files. Once this is done you can open the project and they should be in the c++ classes!
Once you finish adding the scripts you just need to add the PRItem script to an actor, then make a scriptable object
for Bases, Parts, and Accessories. Be sure to have at least one part of each rarity (1 through 4) in each scriptable
object and once you have that, you can add the scriptable objects to their respective slot in the PRItem class on 
your actor. After this, just simply press [Generate Gun] and check each box to see that every part was generated!
