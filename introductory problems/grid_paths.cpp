#include<bits/stdc++.h>
using namespace std;

int isValid(int a,int b,int c) {return (a>=b && a<c ? 1:0);}

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

#define right 0
#define left 1
#define down 2
#define up 3

string s;
int vis[7][7];

int countPaths(int x,int y,int pos){
    //cout<<x<<" "<<y<<endl;
    if(pos==s.size()) return (x==6 && y==0);
    if(x==6 && y==0) return 0;
    if(vis[x][y]) return 0;

    vector<int> visited(4,1);

    for(int i=0;i<4;i++){
        if(isValid(x+dx[i],0,7) && isValid(y+dy[i],0,7)){
            visited[i]=vis[x+dx[i]][y+dy[i]];
        }
    }

    if(visited[down] && visited[up] && !visited[right] && !visited[left]) return 0;
    if(!visited[down] && !visited[up] && visited[right] && visited[left]) return 0;

    if(isValid(x-1,0,7) && isValid(y+1,0,7) && vis[x-1][y+1]==1)
        if(!visited[up] && !visited[right]) return 0;

    if(isValid(x-1,0,7) && isValid(y-1,0,7) && vis[x-1][y-1]==1)
        if(!visited[up] && !visited[left]) return 0;

    if(isValid(x+1,0,7) && isValid(y+1,0,7) && vis[x+1][y+1]==1)
        if(!visited[right] && !visited[down]) return 0;

    if(isValid(x+1,0,7) && isValid(y-1,0,7) && vis[x+1][y-1]==1)
        if(!visited[left] && !visited[down]) return 0;

    vis[x][y]=1;
    int paths=0;
    
        if(s[pos]=='?'){
            for(int i=0;i<4;i++){
                if(isValid(x+dx[i],0,7) && isValid(y+dy[i],0,7)){
                    paths+=countPaths(x+dx[i],y+dy[i],pos+1);
            }
            }
        }
        else if(s[pos]=='R' && y+1<7) paths+=countPaths(x,y+1,pos+1);
        else if(s[pos]=='L' && y-1>=0) paths+=countPaths(x,y-1,pos+1);
        else if(s[pos]=='U' && x-1>=0) paths+=countPaths(x-1,y,pos+1);
        else if(s[pos]=='D' && x+1<7) paths+=countPaths(x+1,y,pos+1);
    vis[x][y]=0;
    return paths;
}

int main(){
    cin>>s;
    cout<<countPaths(0,0,0)<<endl;
}