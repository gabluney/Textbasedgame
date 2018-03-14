//------------------------------------------------------------
// Purpose: Program to simulate the classic 1970s adventure game.
//          Rooms in the maze are described by separate functions.
//          The user finds gold/food as they travel, fights a
//          variety of creatures, and eventually finds the exit.
//
// Authors: John Gauch, Gabrielle Luney
//------------------------------------------------------------

#include <cstdlib>
#include <iostream>
#include <time.h>
using namespace std;

// Food constants
const int CANDY = 0;
const int STEAK = 1;
const int POTION = 2;
const int CANDY_RESTORE = 10;
const int STEAK_RESTORE = 20;
const int POTION_RESTORE = 40;

// Creature constants
const int BUNNY = 0;
const int DWARF = 1;
const int TROLL = 2;
const int BUNNY_DAMAGE = 5;
const int DWARF_DAMAGE = 10;
const int TROLL_DAMAGE = 20;

// Other constants
const int TUITION = 50;
const int BEER = 10;

// Function prototypes
int FindTreasure(const int max_gold);
void EatFood(const int food, int &health);
int FightBattle(const int creature);
char GetDirection();
void Exit(int &gold, int &health);
void Room1(int &gold, int &health);
void Room2(int &gold, int &health);
void Room3(int &gold, int &health);
void Room4(int &gold, int &health);
void Room5(int &gold, int &health);
void Room6(int &gold, int &health);
void Room7(int &gold, int &health);
void Room8(int &gold, int &health);

//------------------------------------------------------------
// Purpose: To calculate how much treasure is found
// Input:   Maximum amount of gold possible
// Output:  Actual amount of gold found
//------------------------------------------------------------
int FindTreasure(const int max_gold)
{
        int gold = 1 + rand() % max_gold;
        if (gold < max_gold / 2)
                cout << "\nYou find " << gold << " gold pieces on the floor.\n";
        else
                cout << "\nYou find a huge mound of " << gold << " gold pieces!\n";
        return gold;
}

//------------------------------------------------------------
// Purpose: To eating food item to restore health.
// Input:   Food item number between [0..2]
// Output:  Health value after eating food.
//------------------------------------------------------------
void EatFood(const int food, int &health)
{
        switch (food)
        {
        case CANDY:
                health = health + CANDY_RESTORE;
                cout << "\nYou find a half eaten energy bar on the floor "
                        << "which restores your health by " << CANDY_RESTORE << endl;
                break;
        case STEAK:
                health = health + STEAK_RESTORE;
                cout << "\nYou find a warm and jucy steak on the table "
                        << "which restores your health by " << STEAK_RESTORE << endl;
                break;
        case POTION:
                health = health + POTION_RESTORE;
                cout << "\nYou find a green glowing potion on a shelf "
                        << "which restores your health by " << POTION_RESTORE << endl;
                break;
        default:
                cout << "\nYour stomach is rumbling, but there is nothing to eat\n";
                break;
        }

        // Check maximum value for health
        if (health > 100)
                health = 100;
}

//------------------------------------------------------------
// Purpose: To simulate battle with a creature
// Input:   Creature number between [0..3]
// Output:  Amount of damage done to your health.
//------------------------------------------------------------
int FightBattle(const int creature)
{
        int damage = 0;
        switch (creature)
        {
        case BUNNY:
                damage = 1 + rand() % BUNNY_DAMAGE;
                cout << "\nYou trip over a cute bunny and do "
                        << damage << " damage to your health.\n";
                break;
        case DWARF:
                damage = 1 + rand() % DWARF_DAMAGE;
                cout << "\nA drunken dwarf hits you with a beer mug and does "
                        << damage << " damage to your health.\n";
                break;
        case TROLL:
                damage = 1 + rand() % TROLL_DAMAGE;
                cout << "\nAn angry troll kicks you in the rear and does "
                        << damage << " damage to your health.\n";
                break;
        default:
                cout << "\nIt is ghostly quiet here, you must be alone\n";
                break;
        }
        return damage;
}

//------------------------------------------------------------
// Purpose: To get direction from user
// Input:   None
// Output:  Character code for N,S,E,W direction
//------------------------------------------------------------
char GetDirection()
{
        cout << "\nWhat direction would you like to go (N,S,E,W): ";
        char direction;
        cin >> direction;
        direction = toupper(direction);
        while ((direction != 'N') && (direction != 'S') &&
                (direction != 'E') && (direction != 'W'))
        {
                cout << "Sorry, You can not go that way...\n";
                cout << "What direction would you like to go (N,S,E,W): ";
                cin >> direction;
                direction = toupper(direction);
        }
        return direction;
}

//------------------------------------------------------------
// Purpose: To find the cave exit
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Exit(int &gold, int &health)
{
        cout << "\n------------------------------------------------------------\n";
        cout << "\nYou crawl out of the cave and blink your eyes to\n";
        cout << "adjust to the bright sunshine. Congratulations,\n";
        cout << "you made it out of the cave with " << health << " health!\n";

        if (gold >= TUITION)
        {
                cout << "\nYou empty your pockets and discover " << gold << " gold coins.\n";
                cout << "This will pay for tuition next semester!!!\n";
        }
        else if (gold >= BEER)
        {
                cout << "\nYou notice that you have " << gold << " gold coins in your pocket.\n";
                cout << "This will pay for beer and pizza next semester!!!\n";
        }
        else
        {
                cout << "\nYou check your pocket and find " << gold << " gold coins.\n";
                cout << "Exploring caves sure is a hard way to make money!!!\n";
        }

        // Leave program
        exit(0);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room1(int &gold, int &health)
{
        char dir = 'A';
        cout << "\n------------------------------------------------------------\n";
        cout << "\nYou just stumbled into a hole in the ground. When you\n";
        cout << "shake off the dirt and leaves you realize you are in\n";
        cout << "the entrance to a cave that looks man made. As you\n";
        cout << "take a look around, you decide it might be fun to explore.\n";


        cout << "There is a door to the east\n";
        cout << "Which path will you choose";
        while (dir != 'E')
        {
                dir = GetDirection();
                if (dir != 'E')
                {
                        cout << "You hit a dead end please try again";
                }
        }
        cout << "\nHealth: " << health << " Gold:" << gold << endl;
        Room2(gold, health);
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room2(int &gold, int &health)
{
        char dir = 'A';
        cout << "\n------------------------------------------------------------\n";
        cout << "\nYou have entered the throne room. In the middle\n";
        cout << "of the room there is a giant wooden throne with\n";
        cout << "intricate carvings. As you take a closer look at the\n";
        cout << "carvings, you see that they show trolls chasing humans.\n";
        cout << "Hmmm, maybe this is not a great place to stop for a rest.\n";
        gold = gold + FindTreasure(5);

        cout << "There is a door to the south or you can go back to last room. \n";
        cout << "Which path will you choose";
        while (dir != 'S' && dir != 'W')
        {
                dir = GetDirection();
                if (dir != 'S' && dir != 'W')
                {
                        cout << "You hit a dead end please try again";
                }
        }
        cout << "\nHealth: " << health << " Gold: " << gold << endl;
        if (dir == 'S')
        {
                Room3(gold , health);
        }
        else if (dir == 'W'){
                Room1(gold, health);
        }
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room3(int &gold, int &health)
{
        char dir = 'A';
        cout << "\n------------------------------------------------------------\n";
        cout << "\nYou have entered an abandoned pub. There are piles\n";
        cout << "of dirty dishes and empty beer mugs all over the place.\n";
        cout << "You hear someone coming and duck behind a table to hide.\n";
        cout << "You decide to take your chances and brace for battle.\n";
        cout << "You look around but no enemy is in sight and you let out a sigh of relief.\n";
        health = health - FightBattle(BUNNY);
        cout << "After a slight scare you notice there is a door to the east and to the south, but you may also choose to go back\n";
        cout << "Which path will you choose";
        while (dir != 'S' && dir != 'E' && dir != 'N')
        {
                dir = GetDirection();
                if (dir != 'S' && dir != 'E' && dir != 'N')
                {
                        cout << "You hit a dead end please try again";
                }
        }
        cout << "\nHealth: " << health << " Gold: " << gold << endl;
        if (dir == 'S')
        {
                Room5(gold, health);
        }
        else if (dir == 'N') {
                Room2(gold, health);
        }
        else {
                Room4(gold, health);
        }
}

//------------------------------------------------------------
// Purpose: To visit a room in the cave
// Input:   The gold and health variables
// Output:  None
//------------------------------------------------------------
void Room4(int &gold, int &health)
{
        char dir = 'A';
        cout << "\n------------------------------------------------------------\n";
        cout << "\nYou have entered a huge storage room filled with empty boxes.\n";
        cout << "Looking at the side of one box, you see 'ACME troll food'.\n";
        cout << "You better get out of here before you end up on the menu.\n";
        cout << "You do not escape without attracting the attention of some nasty creatures.\n";
        health = health - FightBattle(TROLL);
        health = health - FightBattle(TROLL);
        health = health - FightBattle(TROLL);

        cout << "Luckily you also find some potion to replenish your health.\n";
        EatFood(POTION, health);
        cout << "After defeating the Trolls, you notice that you have hit a dead end. Please return back through the door to the West and choose a different path.\n";
        while (dir != 'W')
        {
                dir = GetDirection();
                if (dir != 'W')
                {
                        cout << "You hit a dead end please try again";
                 }
         }

        cout << "\nHealth: " << health << " Gold:" << gold << endl;
        Room3 (gold, health);

}


void Room5(int &gold, int &health)
{
        char dir = 'A';
        cout << "\n------------------------------------------------------------\n";
        cout << "\nYou have entered another  storage room filled with boxes.\n";
        cout << "You hope your fate is not like that of the previous room.\n";
        cout << "You really should learn to stop getting your hopes up.\n";
        health = health - FightBattle(TROLL);

        cout << "After defeating that Troll, you see a door to the west or east. \n";
        cout << "Which path will you choose";
        while (dir != 'W' && dir != 'E' && dir !='N')
        {
                dir = GetDirection();
                if (dir != 'W' && dir != 'E' && dir != 'N')
                {
                        cout << "You hit a dead end please try again";
                }
        }
        cout << "\nHealth: " << health << " Gold: " << gold << endl;
        if (dir == 'W')
        {
                Room6(gold , health);
        }
        else if (dir == 'E')
        {
                Room7(gold, health);
        }
        else
        {
            Room3(gold, health);
        }
        cout << "\nHealth: " << health << " Gold: " << gold << endl;

}

void Room6(int &gold, int &health)
{
        char dir = 'A';
        cout << "\n------------------------------------------------------------\n";
        cout << "\nYou have entered a room that looks like it a bedroom of sorts.\n";
        cout << "You look around trying to find treasure and are suprised to meet a face. \n";

        health = health - FightBattle(DWARF);
        cout << "Good thing this monster left behind a little departing gift. You don't really know where he was hiding that steak though.\n";
        EatFood(STEAK, health);
        cout << "You look all around you and notice that you are trapped again, please exit through the door you came through to the East.\n";
        cout << "Which path will you choose";
        while (dir != 'E')
        {
                dir = GetDirection();
                if (dir != 'E')
                {
                        cout << "You hit a dead end please try again";
                 }
        }

        cout << "\nHealth: " << health << " Gold:" << gold << endl;
        Room5 (gold, health);


}

void Room7(int &gold, int &health)
{
        char dir = 'A';
        cout << "\n------------------------------------------------------------\n";
        cout << "\nYou start to wonder if you'll ever make it out alive\n";
        cout << "This room resembles most the other rooms in the cave but you get a sense that you are going the right direction\n";
        cout << "You are happy to find some treasure after looking around.\n.";


        EatFood(CANDY, health);
        cout << "There is only a door to the south, so you should probably take that door unless you want to head back into the previous room. \n";
        cout << "Which path will you choose";
           while (dir != 'S' && dir != 'W')
           {
                dir = GetDirection();
                if (dir != 'S' && dir != 'W')
                {
                        cout << "You hit a dead end please try again";
                }
           }
        cout << "\nHealth: " << health << " Gold: " << gold << endl;
        if (dir == 'S')
        {
                Room8(gold , health);
        }
        else {
                Room5(gold, health);
        }

}

void Room8(int &gold, int &health)
{
        char dir = 'A';
        cout << "\n------------------------------------------------------------\n";
        cout << "\nYou are very glad to see that all your troubles are over and there are exits  all around you.\n";
        cout << " There is a big bag of gold just calling your name so go ahead and take that.\n";

        gold = gold + FindTreasure(100);
        cout << "You may exit out of any door you would like but remember that headed North takes you back into the cave.\n";
        while (dir != 'S' && dir != 'E' && dir != 'N' && dir != 'W')
        {
                dir = GetDirection();
                if (dir != 'S' && dir != 'E' && dir != 'N' && dir != 'W')
                {
                        cout << "You hit a dead end please try again";
                }

        }
        cout << "\nHealth: " << health << " Gold: " << gold << endl;
        if (dir == 'N')
        {
                Room7(gold, health);
        }
        else
            Exit(gold,health);


}
//------------------------------------------------------------
// Purpose: The main program
// Input:   None
// Output:  None
//------------------------------------------------------------
int main()
{
        // Initialize game
        int gold = 0;
        int health = 100;
        srand(time(NULL));

        // Test the room functions
        Room1(gold, health);
        //Room2(gold, health);
        //Room3(gold, health);
        //Room4(gold, health);
        //Room5(gold, health);
        //Room6(gold, health);
        //Room7(gold, health);
        //Room8(gold, health);




        return 0;
}
