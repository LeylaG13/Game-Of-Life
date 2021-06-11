/// @file board_drawer.h

/**
 * Given a double pointer to 2Darray, prints in terminal and checks for each element if it is dead or alive (0 or 1)
 * based on that changes the color of the cell, blue for alive and white for dead, also clears the terminal before drawing the renewed board 
 * @param[in] array
 * @param[in] rows
 * @param[in] columns
 */
void print(int **array, int rows, int columns);

//Regular text
#define BLK "\e[0;30m" ///< AINSI code to change the color of text to black
#define RED "\e[0;31m" ///< AINSI code to change the color of text to red
#define GRN "\e[0;32m" ///< AINSI code to change the color of text to green
#define YEL "\e[0;33m" ///< AINSI code to change the color of text to yellow
#define BLU "\e[0;34m" ///< AINSI code to change the color of text to blue
#define MAG "\e[0;35m" ///< AINSI code to change the color of text to magenta
#define CYN "\e[0;36m" ///< AINSI code to change the color of text to cyan
#define WHT "\e[0;37m" ///< AINSI code to change the color of text to white

//Regular bold text
#define BBLK "\e[1;30m" ///< AINSI code to change text to bold black
#define BRED "\e[1;31m" ///< AINSI code to change text to bold red
#define BGRN "\e[1;32m" ///< AINSI code to change text to bold green
#define BYEL "\e[1;33m" ///< AINSI code to change text to bold yellow
#define BBLU "\e[1;34m" ///< AINSI code to change text to bold blue
#define BMAG "\e[1;35m" ///< AINSI code to change text to bold magenta
#define BCYN "\e[1;36m" ///< AINSI code to change text to bold cyan
#define BWHT "\e[1;37m" ///< AINSI code to change text to bold white

//Regular underline text
#define UBLK "\e[4;30m" ///< AINSI code to underline text with black
#define URED "\e[4;31m" ///< AINSI code to underline text with red
#define UGRN "\e[4;32m" ///< AINSI code to underline text with green
#define UYEL "\e[4;33m" ///< AINSI code to underline text with yellow
#define UBLU "\e[4;34m" ///< AINSI code to underline text with blue
#define UMAG "\e[4;35m" ///< AINSI code to underline text with magenta
#define UCYN "\e[4;36m" ///< AINSI code to underline text with cyan
#define UWHT "\e[4;37m" ///< AINSI code to underline text with white

//Regular background
#define BLKB "\e[40m" ///< AINSI code to change the background to black
#define REDB "\e[41m" ///< AINSI code to change the background to red
#define GRNB "\e[42m" ///< AINSI code to change the background to green
#define YELB "\e[43m" ///< AINSI code to change the background to yellow
#define BLUB "\e[44m" ///< AINSI code to change the background to blue
#define MAGB "\e[45m" ///< AINSI code to change the background to magenta
#define CYNB "\e[46m" ///< AINSI code to change the background to cyan
#define WHTB "\e[47m" ///< AINSI code to change the background to white

//High intensty background
#define BLKHB "\e[0;100m" ///< AINSI code to change background to bright black
#define REDHB "\e[0;101m" ///< AINSI code to change background to bright red
#define GRNHB "\e[0;102m" ///< AINSI code to change background to bright green
#define YELHB "\e[0;103m" ///< AINSI code to change background to bright yellow
#define BLUHB "\e[0;104m" ///< AINSI code to change background to bright blue
#define MAGHB "\e[0;105m" ///< AINSI code to change background to bright magenta
#define CYNHB "\e[0;106m" ///< AINSI code to change background to bright cyan
#define WHTHB "\e[0;107m" ///< AINSI code to change background to bright white

//High intensty text
#define HBLK "\e[0;90m" ///< AINSI code to change text to bright black
#define HRED "\e[0;91m" ///< AINSI code to change text to bright red
#define HGRN "\e[0;92m" ///< AINSI code to change text to bright green
#define HYEL "\e[0;93m" ///< AINSI code to change text to bright yellow
#define HBLU "\e[0;94m" ///< AINSI code to change text to bright blue
#define HMAG "\e[0;95m" ///< AINSI code to change text to bright magenta
#define HCYN "\e[0;96m" ///< AINSI code to change text to bright cyan
#define HWHT "\e[0;97m" ///< AINSI code to change text to bright white

//Bold high intensity text
#define BHBLK "\e[1;90m" ///< AINSI code to change text to bright bold black
#define BHRED "\e[1;91m" ///< AINSI code to change text to bright bold red
#define BHGRN "\e[1;92m" ///< AINSI code to change text to bright bold green
#define BHYEL "\e[1;93m" ///< AINSI code to change text to bright bold yellow
#define BHBLU "\e[1;94m" ///< AINSI code to change text to bright bold blue
#define BHMAG "\e[1;95m" ///< AINSI code to change text to bright bold magenta
#define BHCYN "\e[1;96m" ///< AINSI code to change text to bright bold cyan
#define BHWHT "\e[1;97m" ///< AINSI code to change text to bright bold white

//Reset
#define reset "\e[0m"              ///< AINSI code to go back to regular text
#define clearscreen "\e[1;1H\e[2J" ///< AINSI code to clear the terminal
