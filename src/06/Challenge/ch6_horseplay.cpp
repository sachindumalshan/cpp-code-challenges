// C++ Code Challenges, LinkedIn Learning

// Challenge #6: Horseplay
// Write a function that takes in the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// The locations are expressed as strings in algebraic notation.
// Print the list on the terminal.
// Don't worry about other pieces on the chessboard.

#include <iostream>
#include <vector>
#include <string>

// knight_moves()
// Summary: This function receives a string with the location of a knight in a chessboard and returns a vector of strings with the possible locations it might move to.
// Arguments:
//           knight: The knight's location.
// Returns: An STL vector of strings with the possible locations to move.
std::vector<std::string> knight_moves(std::string knight){
    std::vector<std::string> moves;
    std::vector<std::string> cell_positions;
    int cp_one,cp_two; // Use to get and convert the cell name
    int kbpo, kbpt; // kbpo - knight begin position one | kbpo - knight begin position two

    // Display chess board cell positions as a Matrix
    char column_character[8] = {'a','b','c','d','e','f','g','h'};
    for(int i=8; i > 0; i--){
        for(int j=0; j < 8; j++){
            //std::cout << j << i << " ";
            cell_positions.push_back(std::to_string(j) + std::to_string(i));
        }
        //std::cout << std::endl;
    }

    // Get the knight current position and saved in two variables     
    for(int i=0; i < 8; i++){
        if(knight[0] == column_character[i]) kbpo = i;
    }
    kbpt = knight[1] - '0';

    // if, vertical position movement > change the number | horizontal position movement > change the letter
    // Define possible knight moves as a pattern of (row_offset, col_offset)
    int move_pattern[8][2] = {
        {-1,  2}, { 1,  2}, // Vertical > Horizontal
        {-1, -2}, { 1, -2},
        {-2,  1}, {-2, -1}, // Horizontal > Vertical
        { 2,  1}, { 2, -1}
    };

    for (int i = 0; i < 8; i++) {
        int cp_one = kbpo + move_pattern[i][0]; // Apply row offset
        int cp_two = kbpt + move_pattern[i][1]; // Apply column offset

        // Check if the move is within bounds
        if (cp_one >= 0 && cp_one < 8 && cp_two >= 0 && cp_two < 9) {
            moves.push_back(std::to_string(cp_one) + std::to_string(cp_two));
        }
    }    

    // for vertical > horizontal movement
    // cp_one = kbpo-1; cp_two = kbpt+2;
    // if(cp_one >=0 and cp_one < 8 and cp_two >0 and cp_two < 9)
    //     moves.push_back(std::to_string(cp_one) + std::to_string(cp_two));

    // cp_one = kbpo+1; cp_two = kbpt+2;
    // if(cp_one >=0 and cp_one < 8 and cp_two >0 and cp_two < 9)
    //     moves.push_back(std::to_string(cp_one) + std::to_string(cp_two));

    // cp_one = kbpo-1; cp_two = kbpt-2;
    // if(cp_one >=0 and cp_one < 8 and cp_two >0 and cp_two < 9)  
    //     moves.push_back(std::to_string(cp_one) + std::to_string(cp_two));

    // cp_one = kbpo+1; cp_two = kbpt-2;
    // if(cp_one >=0 and cp_one < 8 and cp_two >0 and cp_two < 9)
    // moves.push_back(std::to_string(cp_one) + std::to_string(cp_two));

    // // for horizontal > vertical movement
    // cp_one = kbpo-2; cp_two = kbpt+1;
    // if(cp_one >=0 and cp_one < 8 and cp_two >0 and cp_two < 9)   
    //     moves.push_back(std::to_string(cp_one) + std::to_string(cp_two));

    // cp_one = kbpo-2; cp_two = kbpt-1;
    // if(cp_one >=0 and cp_one < 8 and cp_two >0 and cp_two < 9)
    //     moves.push_back(std::to_string(cp_one) + std::to_string(cp_two));

    // cp_one = kbpo+2; cp_two = kbpt+1;
    // if(cp_one >=0 and cp_one < 8 and cp_two >0 and cp_two < 9)
    //     moves.push_back(std::to_string(cp_one) + std::to_string(cp_two));

    // cp_one = kbpo+2; cp_two = kbpt-1;
    // if(cp_one >=0 and cp_one < 8 and cp_two >0 and cp_two < 9)
    //     moves.push_back(std::to_string(cp_one) + std::to_string(cp_two));
    
    // Convert the first value of the position into the letter as chess board shows
    // Ex: '08' > 'a8'
    std::string replace_charater_to_string;
    for(int i=0; i < moves.size(); i++){
        // std::cout << moves[i] << std::endl;
        std::string first_charater = moves[i];
        //int first_numeric_value = first_charater[0]-'0';
        for(int j=0; j < 8; j++){
            if(first_charater[0]-'0' == j){
                replace_charater_to_string = column_character[j];
                moves.push_back(replace_charater_to_string + first_charater[1]);
            }
        }
    }

    // Remove the un-conveted values from the array
    moves.erase(moves.begin()+0, moves.begin()+moves.size()/2);

    // Print the position of knight can move 
    // for(int n=0; n < moves.size();n++){
    //     std::cout << moves[n] << std::endl;
    // }

    return moves;
}

// Main function
int main(){
    std::string knight;
    
    std::cout << "Enter the location of the knight: " << std::flush;
    std::cin >> knight;

    std::vector<std::string> the_moves = knight_moves(knight);
    std::cout << std::endl << "Possible moves from " << knight << ": ";

    for (auto element : the_moves)
        std::cout << element << " ";
    std::cout << std::endl << std::endl << std::flush;
    return 0;
}