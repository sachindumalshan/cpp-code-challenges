// C++ Code Challenges, LinkedIn Learning

// Challenge #10: Playing Tic-Tac-Toe
// Write an application that plays Tic-Tac-Toe against the user.

#include <iostream>
#include <string>
#include <vector>

// ask_for_move()
// Summary: This function asks the user to make a move.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The user's mark: 'X' or 'O'.
// Returns: Nothing.
void ask_for_move(char game[][3], char mark){
    std::string str;
    int row, col;
    do{
        std::cout << "Place your mark (" << mark << ") in row: " << std::flush;
        std::cin >> str;
        row = stoi(str);
        std::cout << "Place your mark (" << mark << ") in column: " << std::flush;
        std::cin >> str;
        col = stoi(str);
    }while(game[row-1][col-1]!=' ');
    game[row-1][col-1] = mark;
    return;
}

// make_move()
// Summary: This AI function makes a move on behalf of the computer in an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
//           mark: The AI's mark: 'X' or 'O'.
// Returns: Nothing.

#define TWO_PLAYERS
void make_move(char game[][3], char mark){ 
    #ifdef TWO_PLAYERS
    ask_for_move(game,mark);
    #else
    
    // Write your code here and comment out the definition of TWO_PLAYERS above

    #endif
    return;
}

// game_state()
// Summary: This function returns the state of a game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: A character encoded as:
//                                  'a': An active game.
//                                  'X': X won.
//                                  'O': O won.
//                                  't': A tie.
int count =0;
int xcount=0, ocount=0;
std::vector <char> letter_type;
char game_state(char game[][3]){
    count++;
    if(count <= 9) return 'a';
    else if(count==10){
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                letter_type.push_back(game[i][j]);            
            }
        }        
        for(int i=0;i<letter_type.size();i++){
                std::cout << letter_type[i] << " ";           
            }
    }
    else if(count == 11){
        // if((letter_type[0] & letter_type[1] & letter_type[2]) == 'X') xcount++;
        // if((letter_type[0] & letter_type[1] & letter_type[2]) == 'O') ocount++;
        // if((letter_type[6] & letter_type[7] & letter_type[8]) == 'X') xcount++;
        // if((letter_type[6] & letter_type[7] & letter_type[8]) == 'O') ocount++;

        // if((letter_type[0] & letter_type[3] & letter_type[6]) == 'X') xcount++;
        // if((letter_type[0] & letter_type[3] & letter_type[6]) == 'O') ocount++;
        // if((letter_type[2] & letter_type[5] & letter_type[8]) == 'X') xcount++;
        // if((letter_type[2] & letter_type[5] & letter_type[8]) == 'O') ocount++;

        // if((letter_type[0] & letter_type[4] & letter_type[8]) == 'X') xcount++;
        // if((letter_type[0] & letter_type[4] & letter_type[8]) == 'O') ocount++;
        // if((letter_type[2] & letter_type[4] & letter_type[6]) == 'X') xcount++;
        // if((letter_type[2] & letter_type[4] & letter_type[6]) == 'O') ocount++;

        // if((letter_type[1] & letter_type[4] & letter_type[7]) == 'X') xcount++;
        // if((letter_type[1] & letter_type[4] & letter_type[7]) == 'O') ocount++;
        // if((letter_type[3] & letter_type[4] & letter_type[5]) == 'X') xcount++;
        // if((letter_type[3] & letter_type[4] & letter_type[5]) == 'O') ocount++;
        
        std::cout << std::endl;
        std::cout << xcount << " " << ocount << std::endl;
    }
    else{
        if(xcount == ocount) return 't';
        else if(xcount > ocount) return 'X';
        else return 'O';
    }
}

// print_game()
// Summary: This function prints an ongoing tic-tac-toe game.
// Arguments:
//           game[3][3]: The state of the game.
// Returns: Nothing.
void print_game(char game[][3]){
    std::cout << std::endl << std::endl;
    std::cout << "    1   2   3\n\n";
    std::cout << "1   " << game[0][0] << " | "<< game[0][1] << " | " << game[0][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "2   " << game[1][0] << " | "<< game[1][1] << " | " << game[1][2] << "\n";
    std::cout << "   " << "---+---+---\n";
    std::cout << "3   " << game[2][0] << " | "<< game[2][1] << " | " << game[2][2] << "\n";

    std::cout << std::endl << std::endl;
    return;
}

// Main function
int main(){
    char game[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char user_mark = 'X', ai_mark = 'O', turn = 'X';
    std::string str;

    std::cout << "Pick your mark (X goes first): " << std::flush;
    std::cin >> str;
    if(str[0]== 'O' || str[0]== 'o'){
        user_mark = 'O';
        ai_mark = 'X';
    }
    std::cout << "      User: " << user_mark << "     AI: " << ai_mark << "\n";    

    print_game(game);

    while(game_state(game)=='a'){
        std::cout << turn << "'s turn...\n";    
        if(turn==user_mark)
            ask_for_move(game,user_mark);
        else
            make_move(game,ai_mark);
        print_game(game);
        turn = turn == 'X' ? 'O' : 'X';
    }
    if(game_state(game)=='t')
        std::cout << "It's a tie.\n\n";
    else    
        std::cout << game_state(game) << " is the winner.\n\n";
    std::cout << std::flush;
    return 0;
}
