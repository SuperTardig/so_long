# so_long
The goal of this 42 school project is to create a small 2d game using the school's graphic library, the MiniLibX. This project is a good introduction to graphical programmation due to it's simplicity and use of basic concepts.
# Mandatory
The mandatory requirements for this project are as follows:
  - The program take a file ending in '.ber' as argument, which contains the map
  - The player needs to collect every collectible before being able to use the exit
  - Movement uses the 'W', 'A', 'S' and 'D' keys that move the player in their respective direction
  - The player cannot go through walls
  - The number of move is displayed in the shell
  - Have a 2d view
  - Have different texture for walls, floor, collectible, player and exit. They could be taken from the internet or made by yourself (I drew mine)
  - Clicking the window exit button or 'ESC' must quit the game cleanely
  - The map must contain 1 exit, 1 starting position and at least 1 collectible
  - It must be rectangular
  - It must be surrounded by walls
# Bonus
The bonus requirements for this project are as follows:
  - Create an enemy patrol which makes you lose the game
  - Add some animations
  - Display the movement count on the screen
 # Usage
 You need to have the MiniLibX installed for the project to work. To play the game you need to:
 1. Clone this repository
 2. Go to the root of the repository and use `make` or `make bonus` (you might have to go change the path of the MiniLibX)
 3. Use `./so_long <map>` or `./so_long_bonus <map>`
