#include <iostream>

void draw_board(char board[3][3]){
    std::cout<<"-------\n";
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            std::cout<<"|"<<board[i][j];
        }
        std::cout<<"|"<<"\n";
    }
     std::cout<<"-------\n";

}
bool is_finished(char board[3][3],char c){
    
    bool diagonal1 = true;
    bool diagonal2 = true;
    bool row = true;
    bool column = true;
    
    for(int i=1;i<3;i++){
        diagonal1 = diagonal1 && c==board[i][i];
    }
    
    for(int i=1; i<3;i++){
       diagonal2 = diagonal2 && c==board[i][2-i];
    }
    
    for(int i=0;i<3;i++){
        row = true;
       for(int j=0;j<3;j++){
           row = row && c==board[i][j];
       }
       if(row){
        break;
       }
    }
    for(int i=0;i<3;i++){
        column = true;
       for(int j=0;j<3;j++){
          column = column && c==board[j][i];
       }
       if(column){
        break;
       }
    }
    
   return diagonal1 || diagonal2 || row || column;
    
}
void make_move(char* board,char c){
    
        int row = 0;
        int column = 0;
        std::cin>>row;
        std::cin>>column;
        
        while(*(board+3*row+column)!=' '){
            std::cout<<"wrong input try again\n";
            std::cin>>row;
            std::cin>>column;
            }
        *(board+3*row+column) = c;
        
       
     
}
 
bool is_board_full(char board[3][3]){
    int counter = 0;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j]!=' '){
                counter++;
            }
        }
    }
    return counter==9;
}

int main(){
    char board[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    draw_board(board);
    while(!is_board_full(board)){
        std::cout<<"player X enter row and column \n";
        make_move(*board,'X');
        draw_board(board);
        if(is_finished(board,'X')){
            std::cout<<"player X wins \n";
            break;
        }
        std::cout<<"player O enter row and column \n";
        make_move(*board,'O');
        draw_board(board);   
        if(is_finished(board,'O')){
            std::cout<<"player O wins \n";
            break;
        }
        }


    }
    


