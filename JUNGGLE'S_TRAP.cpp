#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<stack>
#include<string>
#include<ctime>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;

int score = 0, counter = 1, player_count = 0;
char **simpangan;
static int kehidupan = 3;
vector <class player> lead;

class Graph
{
    public:
        int nodes;
        vector<int>*adj;
        int sp;
        int lp;

    Graph(int n)
    {
        sp=0;
        this->nodes=n;
        adj=new vector<int>[n*n];
    }
    
    void redef_graph(int n1)
    {
        sp=0;
        nodes=n1;
            adj=new vector<int>[nodes*nodes];

    }
    
    void init()
    {
        adj=new vector<int>[nodes*nodes];
    }

    void checkEdge()
    {
        for(int i=0;i<nodes;i++)
        {
            for(int j=0;j<nodes;j++)
            {
                edge(i,j);
            }
        }
    }

    void add_edge(int org,int dest)
    {
        adj[org].push_back(dest);
    }

    void edge(int i,int j)
    {
        if(simpangan[i][j]!='X')
        {
            if(i>0 && simpangan[i-1][j]!='X')
            {
                add_edge((i*nodes)+j,(i-1)*nodes+j);
            }
            
            if(i<nodes-1 && simpangan[i+1][j]!='X')
            {
                add_edge((i*nodes)+j,(i+1)*nodes+j);
            }
            
            if(j>0 && simpangan[i][j-1]!='X')
            {
                add_edge((i*nodes)+j,(i*nodes)+(j-1));
            }
            
            if(j<nodes-1 && simpangan[i][j+1]!='X')
            {
                add_edge((i*nodes)+j,(i*nodes)+(j+1));
            }
        }
    }

    int minEdge(int a, int b)
    {
        vector<bool> visited(nodes*nodes, false);
        vector<int> distance(nodes*nodes, 0);
        queue <int> Q;
        distance[a] = 0;
        Q.push(a);
        visited[a] = true;
        
        while (!Q.empty())
        {
            int x = Q.front();
            Q.pop();
            	for (int i=0; i<adj[x].size(); i++)
            	{
                	if (visited[adj[x][i]])
                    continue;
                	
					distance[adj[x][i]] = distance[x] + 1;
                	Q.push(adj[x][i]);
                	visited[adj[x][i]] = 1;
            	}
        }
        return distance[b];
    }
};

class trap_game
{
	public:
    string player;
    stack <pair<int,int>> S;
    int n , steps;
    
    void randomObstruction(double percent)
    {

        int c=(percent*n*n);
        while(c>0)
        {
            int i=rand()%n;
            int j=rand()%n;
            if(simpangan[i][j]!='X' && simpangan[i][j]!='#' && (i!=0 || j!=0))
            {
                simpangan[i][j]='X';
                c--;
            }
        }
    }
    
    trap_game(int n , string name)
    {
        this->n = n;
        player = name;
        steps = 0;
        simpangan = new char * [n];
        
        for (int i = 0; i < n; ++i )
            simpangan[i] = new char [n];

        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)
             simpangan[i][j]=' ';
        }

        simpangan[0][0]='*';
        simpangan[n-1][n-1]='@';
    }
    
    void redefine(int n1)
    {
        n=n1;
        steps=0;
        simpangan = new char * [n];
        
        for (int i = 0; i < n; ++i )
            simpangan[i] = new char [n];

        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)
             simpangan[i][j]=' ';
        }
        
        simpangan[0][0]='*';
        simpangan[n-1][n-1]='@';
}

void Gambar_simpangan()
{
    cout<<"\n\n LEVEL "<<counter<<"\n\n";
    int i,j=0;
    cout<<"\n\n\n";
    
    for(i=0;i<n;i++)
    {
        cout<<"\t "<<(i+1)<<" ";
    }
    
    cout<<"\n";
    
	for(i=0;i<n;i++)
    {
        cout<<"\t  ___  ";
    }
     	cout<<"\n";
     	while(j<n)
     	{
        	for(i=0;i<n;i++)
        	{	
            	if(simpangan[i][j]!=' ')
                printf("\t| _%c_ |",simpangan[i][j]);
            
				else
                cout<<"\t| ___ |";
        }
        cout<<"\n";
        j++;
     }
    cout<<"\n\n\n\n\n";
}

int move(int x,int y)
{
    pair<int,int> K;
    char ch;
    int termin=0;
    do
    {
         cout<<"\nUP = 'W'";
         cout<<"\nDOWN = 'S'";
         cout<<"\nLEFT = 'A'";
         cout<<"\nRIGHT = 'D'";
         cout<<"\nUNDO = 'U'";
         cout<<"\nQUIT = 'Q'";
         cout<<"\n";
         cout<<"\nYour Lives : "<<kehidupan;
         cout<<"\nEnter Your Move : ";
         
         ch=getchar();

         switch(ch)
         {
         case 'W':
             {
                 if(y>0 && simpangan[x][y-1]!='X'&& simpangan[x][y-1]!='@')
                   {
                     simpangan[x][y]='_';
                     
                     if(!S.empty())
                     {  
					 K=S.top();
					 }
					 
                     S.push(make_pair(x,y));
                     y-=1;
                     
                     if((K.first==x)&&(K.second==y))
                     {  
					 kehidupan--;
					 }
					 
                     simpangan[x][y] = '*';
                     steps++;
                   }
                   
                else if(simpangan[x][y-1]=='@')
                    {
                        cout<<"\nCONGRATULATION FOR YOUR FREEDOM !";
                        y-=1;
                        break;
                    }
                    
                else
                    cout<<"\nCan't Move up Bro";
                if(kehidupan==0)
                {
                    cout<<"\n"<<player<<" Your Steps : "<<steps;
                    exit(0);
                }
                break;
             }
             
         case 'A':
             {
                 if(x>0 && simpangan[x-1][y]!='X'&& simpangan[x-1][y]!='*')
                    {
                        simpangan[x][y]='_';
                        
                        if(!S.empty())
                        {  
							K=S.top();
						}
						
                        S.push(make_pair(x,y));
                        x-=1;
                        
						if((K.first==x)&&(K.second==y))
                     	{  
						 	kehidupan--;
						}
						
                        simpangan[x][y] = '*';
                        steps++;
                    }
                    
                else if(simpangan[x-1][y]=='@')
                   {
                       cout<<"\nCONGRATULATION FOR YOUR FREEDOM !";
                       x-=1;
                       break;
                   }
                else
                    cout<<"\nCan't Move left Bro";
                
				if(kehidupan==0)
                {
                    cout<<"\n"<<player<<" Your Steps : "<<steps;
                    exit(0);
                }
                
                break;
             }
             
        case 'S':
             {
                 if(y>=0 && y+1<n && simpangan[x][y+1]!='X' && simpangan[x][y+1]!='@')
                    {
                        simpangan[x][y]='_';
                        if(!S.empty())
                        {  
							K=S.top();
						}
						
                        S.push(make_pair(x,y));
                        y+=1;
                        
						if((K.first==x)&&(K.second==y))
                     	{  
						 	kehidupan--;
						}
						
                        simpangan[x][y] = '*';
                        steps++;
                    }
                    
                else if(simpangan[x][y+1]=='@')
                    {
                        cout<<"\nCONGRATULATION FOR YOUR FREEDOM !";
                        y+=1;
                        break;
                    }
                    
                else
                    cout<<"\nCan't Move Down Bro";

                if(kehidupan==0)
                {
                    cout<<"\n"<<player<<" Your Steps : "<<steps;
                    exit(0);
                }
                break;
             }

        case 'D':
             {
                 if(x>=0 && x+1<n && simpangan[x+1][y]!='X' && simpangan[x+1][y]!='@')
                    {
                        simpangan[x][y]='_';
                        if(!S.empty())
                        {  
							K=S.top();
						}
						
                        S.push(make_pair(x,y));
                        x+=1;
                        
						if((K.first==x)&&(K.second==y))
                     	{ 
						 	kehidupan--;
						}
						
                        simpangan[x][y] = '*';
                        steps++;
                    }
                    
                else if(simpangan[x+1][y]=='@')
                    {
                        cout<<"\nCONGRATULATION FOR YOUR FREEDOM !";
                        x+=1;
                        break;
                    }
                    
                else
                    cout<<"\nCan't Move Right Bro";

                if(kehidupan==0)
                {
                    cout<<"\n"<<player<<" Your Steps : "<<steps;
                    exit(0);
                }
                
                break;
             }
             
        case 'U':
            {
                int i,j;
                if(S.empty()==true)
                    {   cout<<"\nUNDO NOT POSSIBLE BRO";
                        break;

                    }
                    else
                    {
                        pair<int,int> P=S.top();
                        i=P.first;
                        j=P.second;
                        S.pop();
                        simpangan[x][y] = '_';
                        simpangan[i][j] = '*';
                        x=i;
                        y=j;
                        steps--;
                    }
                    
                if(kehidupan==0)
                {
                    cout<<"\n"<<player<<" Your Steps : "<<steps;
                    int count_player=0;
                }
                else
                    kehidupan--;
                break;
            }
            
        	case 'Q':
            {
                cout<<"\n"<<player<<" Your Steps : "<<steps;
                termin=1;
                int count_player=0;
            }
        }

        if(termin==0)
        {
        Gambar_simpangan();
        }
        
		else
        {
            break;
        }
        }
		
		while(simpangan[x][y]!='@' && termin==0);
        return(termin);
}

void score_play(int shortest , double percent)
{
            int longest = (n*n)-(percent*n*n);
            int avg = (longest+shortest)/2;
            int count=0;
            
            if((steps+1)>avg)
               {
                 score += 40;
               }
               
            else if((steps+1) == avg)
            {
                score+=50;
            }
            
            else if((steps+1)<avg)
            {
                if((steps+1)==shortest)
                    score+=100;
                    
                else
                {
                    count = (steps+1)-shortest;
                    if(count==1)
                        score+=94;
                        
                    else if(count==2)
                        score+=88;
                        
                    else if(count==3)
                        score+=82;
                        
                    else if(count==4)
                        score+=76;
                        
                     else if(count==5)
                        score+=70;
                        
                     else if(count==6)
                        score+=64;
                        
                    else
                        score+=55;

                }
            }
    }
};

class Levels
{
    public:
        double level(int size)
        {
            if(size==8)
                return(.15);
                
            if(size==9)
                return(.2);
                
            if(size==10)
                return(.3);
                
            if(size==11)
                return(.35);
                
            if(size==12)
                return(.3);
        }
};

class player
{
    public:
    string pl_name;
    int pl_score;
};

bool compare(player i1,player i2)
{
    return(i1.pl_score>i2.pl_score);
}

void add_player(string name,int sco,int count_player)
{
    player p1;
    p1.pl_name=name;
    p1.pl_score=sco;
    lead.push_back(p1);
    count_player++;
}

void update_player(string name,int sco,int count_player)
{
    for(int i=0;i<count_player;i++)
    {
        if(lead[i].pl_name==name)
        {
            lead[i].pl_name=sco;
            count_player++;
        }
    }
}

int find_pl(string name,int count_player)
{
    int temp=0;
    for(int i=0;i<count_player;i++)
    {
        if(lead[count_player].pl_name==name)
        {
            temp=1;
        }
    }
    return temp;
}

void create_lead()
{
    sort(lead.begin(),lead.end(),compare);
    ofstream m4("n1.txt");
    
    for(int i=0;i<player_count;i++)
    {
        m4<<lead[i].pl_name<<" "<<lead[i].pl_score<<"\n";
    }
    
    m4.close();
}

void get_player_count()
{
    ifstream m1("n1.txt");
    
    if(!m1.fail())
    {
    string n;
     while(!m1.eof())
     {
         getline(m1,n);
         player_count++;
     }
    }
    
    m1.close();
}

int find_player(string n1,int score_of_pl,int count_player)
{
    string nam;
    int score_p;
    ifstream m2("n1.txt");
    
    if(!m2.fail())
    {
    while(!m2.eof())
    {
        m2>>nam>>score_p;
        if(nam!="")
        {
        add_player(nam,score_p,count_player);
        }
    }
    
    if(find_pl(n1,count_player)!=1)
    {
        add_player(n1,score_of_pl,count_player);
    }
    
    else if(find_pl(n1,count_player))
    {
        update_player(n1,score_of_pl,count_player);
    }
    
    m2.close();
    }
}

void show_lead()
{
    int count_temp=1;
		for(int i=0;i<player_count;i++)
   		{
       		cout<<lead[i].pl_name<<" "<<lead[i].pl_score<<endl;
       		count_temp++;
   		}
}

int main()
{
     srand(time(NULL));
     string name;
     int n=7;
     double c;
     
     cout<<"----------------------------------------------------------------------------------------------\n";
     cout<<"--------------------------------------- JUNGGLE'S TRAP ---------------------------------------\n";
     cout<<"----------------------------------------------------------------------------------------------\n";
     cout<<"\n";
     cout<<"\nYour Name : ";
     
     cin>>name;
     cout<<endl;
     getchar();
     
     cout<<"HI "<<name<<" "<<"WELCOME TO THE JUNGGLE !"<<endl<<endl;
     cout<<"\nLET ME TELL YOU, HOW TO GO OUT FROM HERE !"<<endl<<endl;
     cout<<"--------------------------------------- READ THIS : ---------------------------------------"<<endl<<endl;     
     cout<<"1. YOU HAVE 3 ADDITIONAL LIVES AND IT WILL REDUCE WHEN YOU TRY TO COPY YOUR PREVIOUS MOVE\n"<<endl;;
	 cout<<"2. THERE ARE 5 JUNGGLES WITH DIFFERENT POINTS\n"<<endl;;
     cout<<"3. AVOID TAKING ROUTES FULL OF OBSTACLES AND GET TO THE PASSENGER ON TIME\n"<<endl;;
     cout<<"4. IF YOU PASSES THE LIMIT OF THE JUNGGLE WHICH IS NOT THE WAY TO GO OUT, YOU WILL DIE\n"<<endl;;
     cout<<"-------------------------------------------------------------------------------------------\n"<<endl;;
     cout<<"\nPRESS ENTER TO PLAY"<<endl;
     
     getchar();
     
     int sp = 0, p_score = 0;
     trap_game JT(n,name);
     Levels lvl;
     Graph junggle(n) ;
     
     while(counter<=5)
     {
        int sp=0;
        char ch;
        c = lvl.level(n);
        while(sp==0)
        {
            JT.redefine(n);
            junggle.redef_graph(n);
            JT.randomObstruction(c);
            junggle.init();
            junggle.checkEdge();
            sp = junggle.minEdge(0,(n*n)-1);
             
			 if(sp!=0)
             {
                JT.Gambar_simpangan();
             }
        }
        
		char lo;
        int p_score, temp = JT.move(0,0);
        
        if(!temp)
        {
        JT.score_play(sp,c);
        cout<<"\nYour total Steps : "<<(JT.steps+1);
        cout<<"\nYour Score : "<<score;
        cout<<"\nMin Steps : "<<sp<<endl;
        cout<<"\n------------------------ PRESS ENTER TO CONTINUE ------------------------"<<endl;
        cin>>lo;
        }
        
        else if(temp)
        {
        	cout<<"\nYour Score : "<<0;
        	cout<<"\nMin Steps : "<<sp<<endl;
        	counter=6;
        	getchar();
        	cout<<"\n------------------------ PRESS ENTER TO CONTINUE ------------------------"<<endl;
        	cin>>lo;
            break;
        }
        counter++;
        n++;
    }
    
    int c_play = 0;
    get_player_count();
    find_player(JT.player,score,c_play);
    create_lead();
    show_lead();
 }
