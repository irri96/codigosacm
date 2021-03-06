vector< pair<int, ii> > EdgeList;   // (weight, two vertices) of the edge
for (int i = 0; i < E; i++) {
  scanf("%d %d %d", &u, &v, &w);            // read the triple: (u, v, w)
  EdgeList.push_back(make_pair(w, ii(u, v)));                // (w, u, v)
  AdjList[u].push_back(ii(v, w));
  AdjList[v].push_back(ii(u, w));
}
sort(EdgeList.begin(), EdgeList.end()); // sort by edge weight O(E log E)
                    // note: pair object has built-in comparison function

int mst_cost = 0;
UnionFind UF(V);                     // all V are disjoint sets initially
for (int i = 0; i < E; i++) {                      // for each edge, O(E)
  pair<int, ii> front = EdgeList[i];
  if (!UF.isSameSet(front.second.first, front.second.second)) {  // check
    mst_cost += front.first;                // add the weight of e to MST
    UF.unionSet(front.second.first, front.second.second);    // link them
} }                       // note: the runtime cost of UFDS is very light

// note: the number of disjoint sets must eventually be 1 for a valid MST
printf("MST cost = %d (Kruskal's)\n", mst_cost);