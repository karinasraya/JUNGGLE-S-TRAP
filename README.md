# JUNGGLE-S-TRAP

In here, we use BFS algorithm, like this :

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
