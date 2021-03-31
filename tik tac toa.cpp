#include<iostream>

using namespace std;

class tiktactoa{
private:
    string First_player;
    string Second_player;
public:
    tiktactoa(string first_player,string second_player){
        First_player=first_player;
        Second_player= second_player;
    }
    char box[3][3]={'1','2','3',
                    '4','5','6',
                    '7','8','9'};
    int row,col,value;
    int current_player = 1;
    char marker;
    void view()
        {
            cout<<"---------"<<endl;

            for(row=0;row<3;row++)
            {
                for(col=0;col<3;col++)
                {
                    cout<<box[row][col]<<" |";
                }

                cout<<endl;
                cout<<"---------";
                cout<<endl;
            }

        }

    void place_value(int value)
        {
            row = value/3;

            if(value % 3== 0)
            {
                row = row - 1;
                col = 2;
            }
           else
            col = ( value % 3) - 1;

          box[row][col] = marker;

        }
   int winner()
    {
         for(int i =0;i <3;i++){

            if(box[i][0]== box[i][1]&& box[i][1] == box[i][2] ) return current_player;

            if(box[0][i]== box[1][i]&& box[1][i] == box[2][i] ) return current_player;

         }
        if(box[0][0]== box[1][1]&& box[1][1] == box[2][2]) return current_player;
        if(box[0][2]== box[1][1]&& box[1][1] == box[2][0]) return current_player;

        return 0;
    }

    void swap_sys()
        {
            if(marker=='x') marker='o';
            else marker='x';

            if(current_player==1)current_player=2;
            else current_player=1;
        }

    void game()
        {
            cout<<"First player chose Marker:";
            cin>> marker;
            view();
            int player_won;
            for(int i=0;i<9;i++)
              {
                  cout<<current_player<<" player turn.Enter your slot: ";
                  cin>>value;

                  place_value(value);
                  view();
                  player_won = winner();
                  if(player_won==1){cout<<First_player<<" Won! Congratulation !"<<endl;break;}
                  if(player_won==2){cout<<Second_player<<" Won! Congratulation !"<<endl;break;}
                  swap_sys();

                  view();
              }
              if(player_won == 0) {cout<<"That is a tie game!";}
        }


};

int main()
    {
        tiktactoa user("Prince","Nion");
        user.game();
    }
