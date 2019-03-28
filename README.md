# JUNGGLE-S-TRAP

Member :
1. Karina Soraya P	(05111740000003)
2. Atika Rizki N	(05111740000015)
3. Annas Nuril I	(05111740000042)

#

JUNGGLE'S TRAP is a game that use Breadth First Search (BFS) algorithm. This game has a story about a girl or boy that lost in junggle. Then he/she want to go out from junggle. But, in the junggle, there are so many high cliffs, and he/she can't passed the cliff. And the junggle consisting of 5 tier with different track. So, you should help her/him to go out from that junggle.

#

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

	![Gambar Awal](/images/1.jpg)

2. Press Enter
3. You are in LEVEL 1 now. Your position now is marked with a * . Your Goal is to reach the @ in the jungle. 

	![Gambar 2](/images/2.jpg)
