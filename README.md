# Snake
Snake game implemented with a linked list, for gnu / linux (not planning to make it accesable to windows).

# Needs:
ncurses mainly and a gnu based os.

# How to compile
    g++ game.cpp -lncurses -o [filename]
    ./[filename]

# Controls
w -> up

s -> down

a -> left

d -> right

r-> reverse

# How its implemented
Again, its implemented with a linked list. The linked list is comprised of node objects that contain a cordinate, a direction, and a pointer to the father and child node in the list. This whole list manifests the snake. 

How the snake moves: each node grabs the direction from their father node and updates their position with their new direction.

How the snake reverses: each node grabs their childs direction then inverts it, then switches their parent and child node pointers. Finally the head and tail opf the snake are swapped.

Everything else is simply, basic looping throght the linked list and oop stuff.

# Bugs
prob_1:
apples can be place in the snake. For apple detection the head and the apple's position are only checked, so if an apple is placed in the snake the apple will not be eaten but be earased. Thus, the apple will be forever forgoten and lost.

fix_1:
let the tail of the snake relocate the apple (lazy, but less comutation).
Or! check the apple isn't being placed in the whole snake (computation heavy, and isn't more than 5 - 10 lines of code).

prob_2:
the border gets magically earased. Why! dunno (pls help).

fix_2:
nada

# Future
make a menu class with the ability to add buttons with diferent funcs (setting values, onening pages, and etc). (ambitious, but can be used for multiple applictions and might prove to be usfull for a variety of things) (80% chance I will implement this in the future, but might not be for a while (finals are about to jumpsacre me)).

fix the speling erors in here (10% chance of me ever doing this, but be welcome to if you want too.)


# Author
Mason John Hawver, freshman @ wvhs.
