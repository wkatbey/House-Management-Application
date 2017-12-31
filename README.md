# House-Management-Application
## Introduction

This project aims to demonstrate my knowledge of Object Oriented Design and Elementary Data Structures. 
The user interacts with the program through a console window. The user-interface is comprised of menus. To select an option, the user enters a number or character chain corresponding to the option. 

## Primary Menu
The Primary Menu is the first of such menus. Three options are available to the user: 'My House', 'Connect My House', and 'Exit.' Selecting 'My House' opens a login menu, whereby the user inputs their house's name to access their house. Selecting 'Connect My House' opens subsequent registration forms, whereby the user inputs their house's information. Selecting 'Exit' closes the application.

## House Menu
The House Menu is the most dynamic menu in the program, and allows the user to interact with all the appliances of her house. The options are as follows:

> '+' --- Open/Turn On<p>
> '-' --- Close/Turn Off<p>
> '#' ---  Set Value<p>
> 'A' ---  Arm Alarm<p>
> 'D' --- Disarm Alarm<p>
> 's' --- House Information<p>

> 'K' --- Appliance Code<p>
> 'M' --- Display Menu<p>
> 'H' --- Manual<p>
> 'C' --- Clear Input Buffer<p>
> 'Q' --- Return<p>

To perform any action, the user must input an action: '+', '-', or '#', followed by the appliance code: 'd', 'l', or  'c', the appliances index (0,1,2,etc.), and (if '#' was used) a value for the temperature.
All other operations are <p>
> 'A' - Arm the alarm, if any door is opened while the alarm is armed, the alarm will ring. <p>
> 'D' - Disarm the alarm. If the alarm was previously ringing, this will stop the ringing.<p>
> 's' - Displays the status of all appliances in the house<p>
> 'K' - Displays a map of appliance codes (e.g. c -> conditioner)<p>
> 'H' - Displays a brief set of instructions on how to use the program<p>
> 'C' - Clears the input buffer. Use this when the input buffer is stuck. (i.e. an action isn't performed after input)<p>
> 'Q' - Return to primary menu<p>

## Creating a New House Menu
Creating a new house opens several menus. The first asks for the House's name, followed by the number of each appliance available. The menus appear as follows:<p>

> Enter House Name (Q to return): <p>
> Enter the Number of:<p>
> Doors: <p>
> Lights: <p>
> Air Conditioners: <p>

The houses are stored in an hash table. The appliances are stored within the 'houseType' class as vectors. They could be stored in hash tables. This way, each appliance can be accessed by it's name, rather than it's index in the vector. However, this feature has not been implemented.
