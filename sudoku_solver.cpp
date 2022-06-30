#include<bits/stdc++.h>
using namespace std;

bool safe(vector<vector<int> > &sudoku, int row, int col, int num)
{
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==num)return false;
    }
    for(int i=0;i<9;i++){
        if(sudoku[i][col]==num)return false;
    }
    for(int i=(row/3)*3;i<((row/3)*3)+3;i++){
        for(int j=(col/3)*3;j<((col/3)*3)+3;j++){
            if(sudoku[i][j]==num)return false;
        }
    }
    return true;
}

bool sudoku_solver(vector<vector<int> > &sudoku,int row,int col){
    if(row==8 && col==9){
        return true;
    }
    if(col==9){
        col=0;
        row++;
    }

    if(sudoku[row][col]>0){
        return sudoku_solver(sudoku,row,col+1);
    }

    for(int num=1;num<=9;num++){
        if(safe(sudoku,row,col,num)){
            sudoku[row][col]=num;
            if(sudoku_solver(sudoku,row,col+1))return true;
        }
        sudoku[row][col]=0;
    }

    return false;
}

int main(){
    vector<vector<int> >sudoku;
    cout<<"Fill the sudoku row by row: "<<endl;
    for(int i=0;i<9;i++){
        vector<int> temp;
        temp.clear();
        for(int j=0;j<9;j++){
            int val;
            cin>>val;
            temp.push_back(val);
        }
        sudoku.push_back(temp);
    }
    cout<<"Processing. . ."<<endl;

    if(sudoku_solver(sudoku,0,0)){
        cout<<"Solved sudoku:"<<endl;
        for(int i=0;i<18;i++){
            cout<<"-";
        }
        cout<<endl;


        for(int i=0;i<9;i++){

            for(int j=0;j<9;j++){
                cout<<sudoku[i][j];
                if(j%3==2)cout<<"|";
                else cout<<" ";
            }
            cout<<endl;
            if(i%3==2){
            for(int i=0;i<18;i++){
            cout<<"-";
        }
        cout<<endl;
        }
        }

    }
    else{
        cout<<"No solution exists!"<<endl;
    }

}

/*
0 0 7 0 0 0 0 6 0
9 1 0 0 8 7 0 0 0
0 0 0 0 5 4 0 0 0
0 0 0 0 7 9 0 0 5
0 0 8 1 0 0 0 3 0
0 0 0 0 0 0 0 1 9
8 0 0 3 0 0 0 0 0
3 0 0 0 0 6 0 5 0
0 0 0 0 0 0 4 7 0
*/