# JUNGGLE-S-TRAP

Member :
1. Karina Soraya P	(05111740000003)
2. Atika Rizki N	(05111740000015)
3. Annas Nuril I	(05111740000042)

## Description

JUNGGLE'S TRAP is a game that use Breadth First Search (BFS) algorithm. This game has a story about a girl or boy that lost in junggle. Then he/she want to go out from junggle. But, in the junggle, there are so many high cliffs, and he/she can't passed the cliff. And the junggle consisting of 5 tier with different track. So, you should help her/him to go out from that junggle.

## Shortest Path Algorithm

Breadth-first search (BFS) is an algorithm for traversing or searching tree or graph data structures. It starts at the tree root (or some arbitrary node of a graph, sometimes referred to as a 'search key'), and explores all of the neighbor nodes at the present depth prior to moving on to the nodes at the next depth level.

It uses the opposite strategy as depth-first search, which instead explores the highest-depth nodes first before being forced to backtrack and expand shallower nodes.

To avoid processing a node more than once, we use a boolean visited array. For simplicity, it is assumed that all vertices are reachable from the starting vertex.

For example, in the following graph, we start traversal from vertex 2. When we come to vertex 0, we look for all adjacent vertices of it. 2 is also an adjacent vertex of 0. If we don’t mark visited vertices, then 2 will be processed again and it will become a non-terminating process. A Breadth First Traversal of the following graph is 2, 0, 3, 1.

![Gambar](https://cdncontribute.geeksforgeeks.org/wp-content/uploads/bfs-5.png)

*The source code for BFS :*
```cpp
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
```
## How To Play The Game ?

* You need to build the .cpp file

using g++ compiler, the syntax should like below code
```shell
g++ "JUNGGLE'S_TRAP.cpp" -o game
```

* execute the file that have been built
* Then, let's play this game !
1. First, insert your name, like this :

	![Gambar Awal](/Image/0.PNG)

2. Press Enter to play the game
	
	![Gambar 1](/Image/1.PNG)
	
3. Read the instructions carefully. You are in LEVEL 1 now. You have 3 lives. Your position now is marked with a ' * ' . Your Goal is to reach the '@' which is the exit way of the jungle. 'X' is the representative of the cliffs. On the first level there is no cliff.

	![Gambar 2](/Image/2.PNG)

4. Choose your movement according to the instruction under the jungle. Do it step by step, one input for one movement.
   For example : You choose to move right, so you should type D. Your * will move to the next column.
   Do it until you reach the @ so you can out from the jungle and get score. 
	![Gambar 3](/Image/3.PNG)

5. After that, you can move to the next level. In this game there are 5 level. The number of column is increasing for each level.
	![Gambar 4](/Image/4.PNG)
	![Gambar 5](/Image/5.PNG)
	![Gambar 6](/Image/6.PNG)
	![Gambar 7](/Image/7.PNG)
6. Your live can be reduced if you move back to your previous movement. When your live is 0, you lose and out from the game.
7. When you choose a movement that crosses the forest boundary, you will out from the game.

	![Gambar 9](/Image/9.PNG)
	
8. When you reach the end of fifth level, the game will show leaderboard of the player.

	![Gambar 8](/Image/8.PNG)

