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
    //std::vector<std::string> moves;
    std::vector<std::string> board_pos;
    char letter[8] = {'a','b','c','d','e','f','g','h'};
    for(int i=8; i>0; i--){
        for(int j=0; j<8; j++){
            //std::cout << letter[j] << i << " ";
            std::cout << j << i << " ";
            board_pos.push_back(std::to_string(j) + std::to_string(i));
            //board_pos.push_back(letter[j] + std::to_string(i));
        }
        std::cout << std::endl;
    }

    // for(int n=0; n<board_pos.size();n++){
    //     std::cout << board_pos[n] << std::endl;
    // }

    std::cout << "==========" << std::endl;

    int e1, e2;
    for(int k=0; k<8;k++){
        if(knight[0] == letter[k]){
            e1 = k;
    }}
    e2 = knight[1] - '0';
    std::cout << "E1:" << knight[0] << "|" << e1 << " E2:" << knight[1] << "|" << e2 << std::endl;
    // vertical = numbers
    // horizontal = letter

    // for vertical > horizontal movement
    //knight = d5
    int pos1,pos2;
    std::string pos;
    std::vector<std::string> new_move;
    std::vector<std::string> available_move;

    // for vertical > horizontal movement
    pos1 = e1-1; pos2 = e2+2;
    if(pos1 >=0 and pos1 < 8 and pos2 >0 and pos2 < 9)
        new_move.push_back(std::to_string(pos1) + std::to_string(pos2));
    pos1 = e1+1; pos2 = e2+2;
    if(pos1 >=0 and pos1 < 8 and pos2 >0 and pos2 < 9)
        new_move.push_back(std::to_string(pos1) + std::to_string(pos2));
    pos1 = e1-1; pos2 = e2-2;
    if(pos1 >=0 and pos1 < 8 and pos2 >0 and pos2 < 9)  
        new_move.push_back(std::to_string(pos1) + std::to_string(pos2));
    pos1 = e1+1; pos2 = e2-2;
    if(pos1 >=0 and pos1 < 8 and pos2 >0 and pos2 < 9)
    new_move.push_back(std::to_string(pos1) + std::to_string(pos2));

    // for horizontal > vertical movement
    pos1 = e1-2; pos2 = e2+1;
    if(pos1 >=0 and pos1 < 8 and pos2 >0 and pos2 < 9)   
        new_move.push_back(std::to_string(pos1) + std::to_string(pos2));
    pos1 = e1-2; pos2 = e2-1;
    if(pos1 >=0 and pos1 < 8 and pos2 >0 and pos2 < 9)
        new_move.push_back(std::to_string(pos1) + std::to_string(pos2));
    pos1 = e1+2; pos2 = e2+1;
    if(pos1 >=0 and pos1 < 8 and pos2 >0 and pos2 < 9)
        new_move.push_back(std::to_string(pos1) + std::to_string(pos2));
    pos1 = e1+2; pos2 = e2-1;
    if(pos1 >=0 and pos1 < 8 and pos2 >0 and pos2 < 9)
        new_move.push_back(std::to_string(pos1) + std::to_string(pos2));
    
    std::cout << "==========" << std::endl;
    std::string c_num;

    for(int n=0; n<new_move.size();n++){
        std::cout << new_move[n] << std::endl;
        std::string temp_letter = new_move[n];
        int c_letter = temp_letter[0]-'0';
        std::cout << c_letter << typeid(c_letter).name() << std::endl;
        for(int i=0; i<8;i++){
            if(c_letter == i){
                c_num = letter[i];
                available_move.push_back(c_num + temp_letter[1]);
                }
        }

    }

    std::cout << "==========" << std::endl;


    // for(int n=0; n<new_move.size();n++){
    //     //std::cout << board_pos[n] << std::endl;
    //     for(int u=0; n<board_pos.size();u++){
    //         if(new_move[n] == board_pos[u]){
    //             available_move.push_back(new_move[n]);
    //             break;
    //         }

    //     }
    // }

    for(int n=0; n<available_move.size();n++){
        std::cout << available_move[n] << std::endl;
    }
    

    //std::string find_verti_hori = std::to_string(e1)+ 

    return available_move;
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